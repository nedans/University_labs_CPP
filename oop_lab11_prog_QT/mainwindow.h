#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_FillButton_clicked();

    void on_RowsLineEdit_textEdited(const QString &arg1);

    void on_ColsLineEdit_textEdited(const QString &arg1);

    void on_ClearButton_clicked();

    void on_lineEdit_i_textEdited(const QString &arg1);

    void on_lineEdit_j_textEdited(const QString &arg1);

    void on_NewElementLineEdit_textEdited(const QString &arg1);

    void on_SetValueButton_clicked();

    void on_GetValueButton_clicked();

    void on_actionRead_from_fole_triggered();

    void on_actionWrite_to_file_triggered();

    void on_actionClose_triggered();

    void on_actionFill_triggered();

    void on_actionSet_Value_triggered();

    void on_actionGet_value_triggered();

    void on_actionClear_2_triggered();

private:
    void FillFunction(){
        bool ok1, ok2;

        int rows = ui->RowsLineEdit->text().toInt(&ok1);
        int cols = ui->ColsLineEdit->text().toInt(&ok2);

        if (ok1 && ok2) {
            if (rows > 15 || cols > 15) {
                QMessageBox::warning(this, "Помилка", "Число не може бути більшим від 15!");
            } else if(rows < 0 || cols < 0){
                QMessageBox::warning(this, "Помилка", "Число не може бути меншим від 0!");
            }else if(rows == 0 || cols == 0){
                QMessageBox::warning(this, "Помилка", "Число не може бути рівним 0!");
            }
            else {
                ui->tableWidget->setRowCount(rows);
                ui->tableWidget->setColumnCount(cols);
                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < cols; ++j) {
                        QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(!(i % 2)));
                        ui->tableWidget->setItem(i, j, tbl);
                    }
                }
            }
        } else {
            QMessageBox::warning(this, "Помилка", "Некоректно введені дані!");
        }
    }

    void SetValueFunction(){
        bool ok1, ok2, ok3;

        int i = ui->lineEdit_i->text().toInt(&ok1);
        int j = ui->lineEdit_j->text().toInt(&ok2);
        int value = ui->NewElementLineEdit->text().toInt(&ok3);

        if (ok1 && ok2 && ok3) {
            if (i > ui->tableWidget->rowCount() || j > ui->tableWidget->columnCount()) {
                QMessageBox::warning(this, "Помилка", "Число не може бути більшим ніж максимальний індекс в таблиці!");
            } else if(i < 0 || j < 0 || value < 0){
                QMessageBox::warning(this, "Помилка", "Число не може бути меншим від 0!");
            }else if(i == 0 || j == 0){
                QMessageBox::warning(this, "Помилка", "Число не може бути рівним 0!");
            }else if(value > 100){
                QMessageBox::warning(this, "Помилка", "Число не може бути більшим від 100!");

            }
            else {
                QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(value));
                ui->tableWidget->setItem(i - 1, j - 1, tbl);
            }
        } else {
            QMessageBox::warning(this, "Помилка", "Некоректно введені дані!");
        }
    }

    void GetValueFunction(){
        bool ok1, ok2;

        int i = ui->lineEdit_i->text().toInt(&ok1);
        int j = ui->lineEdit_j->text().toInt(&ok2);

        if (ok1 && ok2) {
            if(i < 0 || j < 0 || i > ui->tableWidget->rowCount() || j > ui->tableWidget->columnCount()){
                QMessageBox::warning(this, "Помилка", "Некоректні індекси рядка та/або стовпця!");
            }else{
                QTableWidgetItem *item = ui->tableWidget->item(i - 1, j - 1);

                QString value = item->text();
                QMessageBox::information(this, "Значення елемента таблиці", "Значення вибраного елемента = "  + value);
            }
        }else{
            QMessageBox::warning(this, "Помилка", "Некоректно введено дані!");
        }
    }

    void ReadFromFileFunction(){
        QString str = QFileDialog::getOpenFileName(this, "Обрати файл", "", "FileWithInformation (*.txt);");

        std::ifstream fp;
        fp.open(str.toStdString());

        size_t rows{0}, cols{0};

        int item{};

        fp >> rows >> cols;

        if (rows > 15 || cols > 15) {
            QMessageBox::warning(this, "Помилка", "Число не може бути більшим від 15!");
        } else if(rows < 0 || cols < 0){
            QMessageBox::warning(this, "Помилка", "Число не може бути меншим від 0!");
        }else if(rows == 0 || cols == 0){
            QMessageBox::warning(this, "Помилка", "Число не може бути рівним 0!");
        }
        else {
            ui->tableWidget->setRowCount(rows);
            ui->tableWidget->setColumnCount(cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    fp >> item;
                    QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(item));
                    ui->tableWidget->setItem(i, j, tbl);
                }
            }
        }

        fp.close();
    }

    void WriteToFileFunction(){
        QString str = QFileDialog::getOpenFileName(this, "Обрати файл", "", "FileForInformation (*.txt);");

        std::ofstream fp;
        fp.open(str.toStdString());

        if (fp.is_open())
        {
            fp << ui->tableWidget->rowCount() << " " << ui->tableWidget->columnCount() << "\n";

            bool flag = 0;
            for(size_t i = 0; i < ui->tableWidget->rowCount(); ++i)
            {
                if(flag)
                    break;
                for(size_t j = 0; j < ui->tableWidget->columnCount(); ++j)
                {
                    QTableWidgetItem *obj = ui->tableWidget->item(i, j);

                    if(!obj)
                    {
                        QMessageBox::warning(this, "Помилка", "Матриця порожня!");
                        flag = true;
                        break;
                    }
                    else
                    {
                        fp << ui->tableWidget->item(i, j)->text().toInt() << " ";
                    }
                }

            }
            fp.close();
        } else {
            QMessageBox::warning(this, "Помилка!", "Не вдалося відкрити файл!");
        }
        fp.close();
    }

private:
    Ui::MainWindow *ui;

};


#endif // MAINWINDOW_H

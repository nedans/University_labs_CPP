#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTableWidget>
#include <QMessageBox>
#include <QPushButton>
#include <fstream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RowsLineEdit_textEdited(const QString &arg1){}

void MainWindow::on_ColsLineEdit_textEdited(const QString &arg1){}

void MainWindow::on_FillButton_clicked()
{
    MainWindow::FillFunction();
}

void MainWindow::on_ClearButton_clicked()
{
    ui->tableWidget->clear();
}

void MainWindow::on_lineEdit_i_textEdited(const QString &arg1){}

void MainWindow::on_lineEdit_j_textEdited(const QString &arg1){}

void MainWindow::on_NewElementLineEdit_textEdited(const QString &arg1){}


void MainWindow::on_SetValueButton_clicked()
{
    MainWindow::SetValueFunction();
}


void MainWindow::on_GetValueButton_clicked()
{
    MainWindow::GetValueFunction();
}

void MainWindow::on_actionRead_from_fole_triggered()
{
    MainWindow::ReadFromFileFunction();
}


void MainWindow::on_actionWrite_to_file_triggered()
{
    MainWindow::WriteToFileFunction();
}

void MainWindow::on_actionClose_triggered()
{
    MainWindow::close();
}

void MainWindow::on_actionFill_triggered()
{
    MainWindow::FillFunction();
}


void MainWindow::on_actionSet_Value_triggered()
{
    MainWindow::SetValueFunction();
}


void MainWindow::on_actionGet_value_triggered()
{
    MainWindow::GetValueFunction();
}


void MainWindow::on_actionClear_2_triggered()
{
    ui->tableWidget->clear();
}


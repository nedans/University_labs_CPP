#include <iostream>
#include <string>
#include <fstream>
#include "CÑhessman.h"

CChessman::CChessman(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) : 
		colour(choosedcolour), position_number(num), position_symbol(sym){}

CKnight::CKnight(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) : CChessman(choosedcolour,sym, num){}

void CKnight::SetPosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num) { CChessman::SetPosition(sym, num); }

std::string CKnight::PrintName() const {
	std::string name{ "CKnight" };
	return name;
}

void CChessman::SetPosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num) {
	position_symbol = sym;
	position_number = num;
}

std::string CChessman::PrintName() const{
	std::string name{ "CChessman" };
	return name;
}

bool CKnight::CanCapturePosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num, std::string filename) const
{
	if (position_symbol == sym && position_number == num) { return false; }

	int x{abs(static_cast<int>(position_symbol) - static_cast<int>(sym))};
	int y{ abs(static_cast<int>(position_number) - static_cast<int>(num)) };
	bool result{ ((x == 2 && y == 1) || (x == 1 && y == 2)) };

	std::ofstream data;
	data.open(filename);
	if (data) {
		data << "CKnight:" << result << "\n";
	}
	else {
		return 0;
	}
	data.close();
	
	return result;
}

CRook::CRook(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) : CChessman(choosedcolour, sym, num) {}

void CRook::SetPosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num) { CChessman::SetPosition(sym, num); }

std::string CRook::PrintName() const {
	std::string name{ "CRook" };
	return name;
}

bool CRook::CanCapturePosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num, std::string filename) const
{
	if (position_symbol == sym && position_number == num) { return false; }

	int x{ abs(static_cast<int>(position_symbol) - static_cast<int>(sym)) };
	int y{ abs(static_cast<int>(position_number) - static_cast<int>(num)) };

	bool result{ ((x == 0) || (y == 0)) };
	std::ofstream data;
	data.open(filename);
	if (data) {
		data << "CRook:" << result << "\n";
	}
	else {
		return 0;
	}
	data.close();

	return result;
}

CQueen::CQueen(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) : CChessman(choosedcolour, sym, num) {}

void CQueen::SetPosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num) { CChessman::SetPosition(sym, num); }

std::string CQueen::PrintName() const {
	std::string name{ "CQueen" };
	return name;
}

bool CQueen::CanCapturePosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num, std::string filename) const
{
	if (position_symbol == sym && position_number == num) { return false; }

	int x{ abs(static_cast<int>(position_symbol) - static_cast<int>(sym)) };
	int y{ abs(static_cast<int>(position_number) - static_cast<int>(num)) };

	bool result{ ((x == 0) || (y == 0) || (x == y)) };

	std::ofstream data;
	data.open(filename);
	if (data) {
		data << "CQueen:" << result << "\n";
	}
	else {
		return 0;
	}
	data.close();

	return result;
}


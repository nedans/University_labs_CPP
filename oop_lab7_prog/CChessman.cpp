#include <iostream>
#include <string>
#include <array>
#include "CÑhessman.h"
#include "CKnight.h"
#include "CRook.h"
#include "CQueen.h"

CChessman::CChessman(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) :
	colour(choosedcolour), position_number(num), position_symbol(sym) {}

CChessman::~CChessman() {}

void CChessman::SetPosition(const POSITION_SYMBOL sym, const POSITION_NUMBER num) {
	position_symbol = sym;
	position_number = num;
}



CKnight::CKnight(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) : CChessman(choosedcolour, sym, num) {}

std::string CKnight::PrintName() const{
	std::string name{ "CKnight" };
	return name;
}

bool CKnight::CanCapturePosition(const unsigned char ucPosition) const {
	int sym{ IndexToPositionSymbol(ucPosition) };
	int num{ IndexToPositionNumber(ucPosition) };

	if ((static_cast<int>(position_symbol) + 1) == sym && static_cast<int>(position_number) == num) { return false; }

	int x{ abs(static_cast<int>(position_symbol) + 1 - sym) };
	int y{ abs(static_cast<int>(position_number) - num) };

	return ((x == 2 && y == 1) || (x == 1 && y == 2));
}



CRook::CRook(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) : CKnight(choosedcolour, sym, num) {}

std::string CRook::PrintName() const {
	std::string name{ "CRook" };
	return name;
}

bool CRook::CanCapturePosition(const unsigned char ucPosition) const {
	int sym{ IndexToPositionSymbol(ucPosition) };
	int num{ IndexToPositionNumber(ucPosition) };

	if ((static_cast<int>(position_symbol) + 1) == sym && static_cast<int>(position_number) == num) { return false; }

	int x{ abs(static_cast<int>(position_symbol) + 1 - sym) };
	int y{ abs(static_cast<int>(position_number) - num) };

	return ((x == 0) || (y == 0));
}



CQueen::CQueen(const COLOUR choosedcolour, const POSITION_SYMBOL sym, const POSITION_NUMBER num) : CChessman(choosedcolour, sym, num) {}

std::string CQueen::PrintName() const {
	std::string name{ "CQueen" };
	return name;
}

bool CQueen::CanCapturePosition(const unsigned char ucPosition) const{
	int sym{ IndexToPositionSymbol(ucPosition) };
	int num{ IndexToPositionNumber(ucPosition) };

	if ((static_cast<int>(position_symbol) + 1) == sym && static_cast<int>(position_number) == num) { return false; }

	int x{ abs(static_cast<int>(position_symbol) + 1 - sym) };
	int y{ abs(static_cast<int>(position_number) - num) };

	return ((x == 0) || (y == 0) || (x == y));
}

int IndexToPositionSymbol(unsigned char ucPosition) {
	return (ucPosition % 8) + 1;
}
int IndexToPositionNumber(unsigned char ucPosition) {
	return ucPosition / 8 + 1;
}

bool CanAnyoneCapturePosition(const CChessman** array, const unsigned char ucPosition, size_t array_size)
{	
	if (!array) { return false; }

	for (size_t i = 0; i < array_size; ++i) {
		if (array[i]->CanCapturePosition(ucPosition)) {
			return true;
		}	
	}
	return false;
}
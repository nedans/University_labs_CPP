#pragma once
#include <fstream>

enum class COLOUR{
	White,
	Black
};

enum class POSITION_SYMBOL {
	a,
	b,
	c,
	d,
	e,
	f,
	g,
	h
};

enum class POSITION_NUMBER {
	one = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8
};

class CChessman {
public:
	CChessman(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);
	void SetPosition(const POSITION_SYMBOL, const POSITION_NUMBER);

	std::string PrintName() const;

protected:
	COLOUR colour;
	POSITION_SYMBOL position_symbol;
	POSITION_NUMBER position_number;
};

class CKnight : public CChessman {
public:
	CKnight(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);

	void SetPosition(const POSITION_SYMBOL, const POSITION_NUMBER);

	std::string PrintName() const;

	bool CanCapturePosition(const POSITION_SYMBOL, const POSITION_NUMBER, std::string filename) const;
};

class CRook : public CChessman {
public:
	CRook(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);

	void SetPosition(const POSITION_SYMBOL, const POSITION_NUMBER);

	std::string PrintName() const;

	bool CanCapturePosition(const POSITION_SYMBOL, const POSITION_NUMBER, std::string filename) const;
};

class CQueen : public CChessman {
public:
	CQueen(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);

	void SetPosition(const POSITION_SYMBOL, const POSITION_NUMBER);

	std::string PrintName() const;

	bool CanCapturePosition(const POSITION_SYMBOL, const POSITION_NUMBER, std::string filename) const;
};
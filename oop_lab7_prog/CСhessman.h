#pragma once

enum class COLOUR {
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
	CChessman() = default;
	CChessman(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);
	void SetPosition(const POSITION_SYMBOL, const POSITION_NUMBER);

	virtual bool CanCapturePosition(const unsigned char ucPosition) const = 0;

	virtual std::string PrintName() const = 0;

	virtual ~CChessman();

	friend bool CanAnyoneCapturePosition(const CChessman** array, const unsigned char ucPosition, size_t array_size);

protected:
	COLOUR colour;
	POSITION_SYMBOL position_symbol{ POSITION_SYMBOL::a };
	POSITION_NUMBER position_number{ POSITION_NUMBER::one };
};


int IndexToPositionSymbol(unsigned char ucPosition);
int IndexToPositionNumber(unsigned char ucPosition);


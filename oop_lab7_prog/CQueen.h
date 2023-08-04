#pragma once

class CQueen : public CChessman {
public:
	CQueen(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);
	~CQueen() = default;

	std::string PrintName() const override;

	bool CanCapturePosition(const unsigned char ucPosition) const override;
};
#pragma once

class CKnight : public CChessman {
public:
	CKnight(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);
	~CKnight() = default;

	std::string PrintName() const override;

	bool CanCapturePosition(const unsigned char ucPosition) const override;
};
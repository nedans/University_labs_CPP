#pragma once

class CRook : public CKnight {
public:
	CRook(const COLOUR, const POSITION_SYMBOL, const POSITION_NUMBER);
	~CRook() = default;
	std::string PrintName() const override;

	bool CanCapturePosition(const unsigned char ucPosition) const override;

};
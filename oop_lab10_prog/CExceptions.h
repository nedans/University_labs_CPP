#pragma once

class CExceptionNonSymbol {

public:
	CExceptionNonSymbol() = default;
	const std::string GetSymbolsExceptioinMessage() const;
};

class CExceptionZeroShiftValue {

public:
	CExceptionZeroShiftValue() = default;
	const std::string GetZeroExceptioinMessage() const;
};

class CExceptionBelowZeroRotateShiftValue {

public:
	CExceptionBelowZeroRotateShiftValue() = default;
	const std::string GetBelowZeroRotateShiftValueExceptionMessage() const;
};

class CInputException {

public:
	CInputException() = default;
	const std::string GetInputExceptioinMessage() const;
};

class COutputException {

public:
	COutputException() = default;
	const std::string GetOutputExceptioinMessage() const;
};
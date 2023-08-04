#pragma once

class CExceptionNonSymbol {

public:
	CExceptionNonSymbol() = default;
	const char* GetSymbolsExceptioinMessage() const;

};

class CExceptionZeroShiftValue {

public:
	CExceptionZeroShiftValue() = default;
	const char* GetZeroExceptioinMessage() const;

};

class CInputException {

public:
	CInputException() = default;
	const char* GetInputExceptioinMessage() const;

};

class COutputException {

public:
	COutputException() = default;
	const char* GetOutputExceptioinMessage() const;

};
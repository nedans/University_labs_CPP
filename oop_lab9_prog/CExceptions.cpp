#include <iostream>
#include "CExceptions.h"

const char* CExceptionZeroShiftValue::GetZeroExceptioinMessage() const {
    return "Shift value cant be equal to zero!";
}

const char* CExceptionNonSymbol::GetSymbolsExceptioinMessage() const {
    return "Data cant contain numbers or symbols!";
}

const char* CInputException::GetInputExceptioinMessage() const
{
    return "Input error!";
}

const char* COutputException::GetOutputExceptioinMessage() const
{
    return "Output error!";
}
#include <iostream>
#include "CExceptions.h"

const std::string CExceptionZeroShiftValue::GetZeroExceptioinMessage() const {
    return "Shift value cant be equal to zero!";
}

const std::string CExceptionBelowZeroRotateShiftValue::GetBelowZeroRotateShiftValueExceptionMessage() const {
    return "Rotate shift value cant be below zero!";
}

const std::string CExceptionNonSymbol::GetSymbolsExceptioinMessage() const {
    return "Data cant contain numbers or symbols!";
}

const std::string CInputException::GetInputExceptioinMessage() const
{
    return "Input error!";
}

const std::string COutputException::GetOutputExceptioinMessage() const
{
    return "Output error!";
}
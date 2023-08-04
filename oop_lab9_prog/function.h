#pragma once

template<typename T, size_t NumOfElements>
size_t FindElementInArray(const T(&array)[NumOfElements], const T& ElementToFind) {
    for (size_t i = 0; i < NumOfElements; ++i) {
        if (ElementToFind == array[i]) {
            return i;
        }
    }

    return NumOfElements;
}
// Copyright 2022 UNN-IASR
#include "fun.h"

int main() {
    const char * str = " Hello world     1000";
    std::cout << "string: " << str << "\n"
    << "\nwithout numbers : "
    << faStr1(str) << " words"
    << "\nlatin letters, first capital, then lowercase : "
    << faStr2(str) << " words"
    << "\naverage word length : "
    << faStr3(str) << " characters";
    return 0;
}

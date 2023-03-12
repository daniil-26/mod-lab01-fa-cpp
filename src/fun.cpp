// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <ctype.h>

unsigned int faStr1 (const char *str) {
    unsigned int count = 0;
    bool word = false, correct = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!word) {
                word = true;
                correct = true;
            }
            if (word && correct && isdigit(str[i]))
                correct = false;
        }
        else if (word) {
            word = false;
            if (correct)
                count++;
        }
    }
    if (word && correct)
        count++;
    return count;
}

unsigned int faStr2 (const char *str) {
    unsigned int count = 0;
    bool word = false, correct = false, first = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (!word) {
                word = true;
                if ('A' <= str[i] && str[i] <= 'Z') {
                    correct = true;
                    first = true;
                }
            }
            else first = false;
            if (word && correct && !first && !('a' <= str[i] && str[i] <= 'z'))
                correct = false;
        }
        else if (word) {
            word = false;
            if (correct) {
                count++;
                correct = false;
            }
        }
    }
    if (word && correct)
        count++;
    return count;
}
unsigned int faStr3 (const char *str) {
    unsigned int count = 0, length = 0, sum = 0;
    bool word = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            word = true;
            length++;
        }
        else if (word) {
            word = false;
            sum += length;
            length = 0;
            count++;
        }
    }
    if (word) {
        sum += length;
        count++;
    }
    return round((float)sum / count);
}

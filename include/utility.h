#pragma once
#include <ctype.h>
bool isValidIdentifiter(char c, int currentPosition) {
    if(currentPosition != 0 ) {
        return isalpha(c) || c == '_';
    }
    else {
        return isalnum(c) || c== '_';
    }
}
#include "strings.h"

unsigned int str_length(String str) {
    int i = 0;
    char c = str[0];
    while (c != '\0') {
        i++;
        c = str[i];
    }
    return i;
}

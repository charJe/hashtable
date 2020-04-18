#include <string.h>
#include <math.h>

int isprime(int num) {
    double sq = sqrt(num);
    if (num < 3 || num % 2 == 0) {
        return 0;
    }
    for (int n = 3; n < sq; n += 2)
        if (num % n == 0)
            return 0;
    return 1;
}

int hashstr(char * str) {
    int hash = 0,
        length = strlen(str);
    for (int i = 0; i < length; ++i) {
        hash += str[i] * (int)pow(31, (i+1));
    }
    return hash;
}

int strequal (char* a, char* b) {
    return strcmp(a, b);
}

int hashint(int num) {
    int hash = 0;
    int i = 1;
    while (num > 0) {
        int digit = num % 10;
        hash += digit * (int)pow(31, i);
        num /= num;
    }
    return hash;
}

int intequal(int a, int b) {
    return a - b;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hashtable.h"

int main(int argc, char** argv) {
    newhashtable(sloths, char*, int, 8, hashstr, strequal);
    puthashnorehash(sloths, "George", 13);
    puthash(sloths, "Johny", 12);
    puthash(sloths, "Fred", 19);
    puthash(sloths, "Calvin", 14);
    puthash(sloths, "Sandra", 21);
    puthash(sloths, "James", 12);
    puthash(sloths, "Dylan", 10);
    puthash(sloths, "Wanda", 22);
    puthash(sloths, "Nancy", 17);
    puthash(sloths, "Dash", 21);
    puthash(sloths, "Logan", 20);
    int age;
    gethash(sloths, "George", age);
    printf("George is %d years old\n", age);
    gethash(sloths, "Dash", age);
    printf("Dash is %d years old\n", age);
    deletehashtable(sloths, free, free);
}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hashtable.h"

int main(int argc, char** argv) {
    /* creating a hashtable named `sloths` */
    newhashtable(sloths, char*, int, 8, hashstr, strequal);
    /* adding to sloths' names and ages */
    puthash(sloths, "George", 13);
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
    /* retriving some sloth's ages and printing them */
    int age;
    gethash(sloths, "George", age);
    printf("George is %d years old\n", age);
    gethash(sloths, "Dash", age);
    printf("Dash is %d years old\n", age);
    /* deleteing the hashtable named `sloths` */
    deletehashtable(sloths, free, free);
}



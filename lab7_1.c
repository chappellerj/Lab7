// Name: Ryan Chappelle
// Date: 05/23/2023
// Title: Lab 7 Step 1
// Description: C program that creates a testInput.txt file

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Needs 3 arguments.");
        return 0;
    }
    // cacheSize
    int someNumber = atoi(argv[1]);
    // how many unique pages
    int capNumber = atoi(argv[2]); 
    FILE *fp;
    char buffer [sizeof(int) + 2];
    int i;
    fp = fopen("testInput10k.txt", "w");
    for (i=0; i<someNumber; i++){
        sprintf(buffer, "%d\n", rand()%capNumber);
        fputs(buffer, fp);
    }
    fclose(fp);
    return 0;
}
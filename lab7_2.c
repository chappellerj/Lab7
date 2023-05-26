// Name: Ryan Chappelle
// Date: 05/23/2023
// Title: Lab 7 Step 2
// Description: C program that reads the output of $cat testInput.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
int pageno;
} ref_page;

int main(int argc, char *argv[]){
    char pageCache[100]; // Cache that holds the input from test file
    while (fgets(pageCache, 100, stdin)){
        int page_num = atoi(pageCache); // Stores number read from file as an int
        printf("%d\n", page_num);
    }
    return 0;
}
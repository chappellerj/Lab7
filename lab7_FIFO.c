// Name: Ryan Chappelle
// Date: 05/23/2023
// Title: Lab 7 Step 3
// Description: C program that uses FIFO for page replacement

// EXPECTED OUTPUT WITH TESTINPUT.TXT W/ CACHESIZE == 3: 5 PAGE FAULTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {//to
    int pageno;
} ref_page;

int main(int argc, char *argv[]){
    int cacheSize = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[cacheSize]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file
    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int placeInArray = 0;
    for (i = 0; i < cacheSize; i++){//initialise cache array
        cache[i].pageno = -1;
    }
    while (fgets(pageCache, 100, stdin)){
        int page_num = atoi(pageCache); // Stores number read from file as an int
        bool foundInCache = false;
        for (i=0; i<cacheSize; i++){
            if (cache[i].pageno == page_num){
                foundInCache = true;
                break; //break out loop because found page_num in cache
            }
        }
        if (foundInCache == false){
            //You may print the page that caused the page fault
            cache[placeInArray].pageno = page_num;
            totalFaults++;
            placeInArray = (placeInArray + 1) % cacheSize; //Need to keep the value within the cacheSize
        }
    }
    printf("%d Total Page Faults\n", totalFaults);
    return 0;
}
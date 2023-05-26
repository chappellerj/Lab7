// Name: Ryan Chappelle
// Date: 05/23/2023
// Title: Lab 7 Step 3
// Description: C program that uses the LRU algorithm for page replacement

// EXPECTED OUTPUT WITH TESTINPUT.TXT W/ CACHESIZE == 3: 4 PAGE FAULTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    int pageno;
    int time;
} ref_page;

int main(int argc, char *argv[]) {
    int cacheSize = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[cacheSize]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file
    int i;

    int totalFaults = 0; // keeps track of the total page faults

    for (i = 0; i < cacheSize; i++){//initialise cache array and time
        cache[i].pageno = -1;
        cache[i].time = -1;
    }
    // index is used to keep track of the overall "time" for comparison
    int index = 0;
    while (fgets(pageCache, 100, stdin)){
        int page_num = atoi(pageCache); // Stores number read from file as an int
        bool foundInCache = false;
        // Search for cache holding page_num
        for (i=0; i<cacheSize; i++){
            // Found
            if (cache[i].pageno == page_num){
                // Set time 
                cache[i].time = index;
                foundInCache = true;
                break; //break out loop because found page_num in cache
            }
        }
        // Not found
        if (foundInCache == false){
            // Find the "oldest" cache.time and keep track of that index for replacement
            for (i = 0; i < cacheSize; i++) {
                // Oldest cache.time
                if (cache[i].time < index) {
                    index = i;
                }
            }
            cache[index].pageno = page_num;
            cache[index].time = index;
            totalFaults++;
        }
        index++;
    }
    printf("%d Total Page Faults\n", totalFaults);
    return 0;
}
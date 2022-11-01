#include <stdio.h>
#include <stdlib.h>


void display_arr(int* start, int* end) {
    printf("[");
    for (int* i=start; i<end; i++) {
        printf("%d,", *i);
    }
    printf("%d]\n", *end);
    fflush(stdout);
}


// END POINTER IS INCLUSIVE; FOR 1 ELEMENT ARR, START=END
void merge(int *start, int *end) {
    // POINTERS TO THE FIRST AND LAST IN AN ARRAY - ASSUME CONTIGUOUS MEM ALLOCATION    
    if (start != end) {
        // need to split further
        int *h = start + (end-start)/2; // not sure whether this will auto-round or error - we'll find out!

        // get sorted subarrays
        merge(start, h);
        merge(h + 1, end);

        // copy first subarray into extra memory
        int bufsize = ((long int) h - (long int) start) / sizeof(int) + 1;
        int *b = malloc(sizeof(int) * (bufsize));
        for (int i=0; i<(bufsize); i++) {
            b[i] = start[i];
        }

        // merge into the front of the original array
        // will only need to finish copying the first half back in afterwards!
        // second half will already be in the right place, as they stayed put
        int* buff_pointer = b;
        int* write_pointer = start;
        h++;
        while (bufsize > 0) {
            // compare the values stored at each pointer
            // if we add from front half, increment b and decrement remaining
            // if we add from back half, increment h
            // DON'T CHECK BEYOND THE END

            if ((h <= end) && (*h < *b)) {
                // take from back
                *write_pointer = *h;
                h++; write_pointer++;
            }
            else {
                // take from front
                *write_pointer = *b;
                b++; write_pointer++; bufsize--;
            }
        }
        free(buff_pointer);
    }
}


int main() {
    int arr[] = {5,4,3,2,1};
    int* start = &(arr[0]);
    int* end = &(arr[4]);

    display_arr(start, end);
    merge(start, end);
    display_arr(start, end);
}
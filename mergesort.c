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


void merge(int *start, int *end) {
    // end pointer is inclusive
    if (start != end) {

        // sort subarrays
        int *h = start + (end-start)/2;
        merge(start, h);
        merge(h + 1, end);

        // copy front subarray into extra memory
        int bufsize = ((long int) h - (long int) start) / sizeof(int) + 1;
        int *b = malloc(sizeof(int) * (bufsize));
        for (int i=0; i<(bufsize); i++) {
            b[i] = start[i];
        }

        // copy buffer pointer so we can free the memory later
        int* buff_pointer = b;

        h++; // h now points to front of the second subarray
        while (bufsize > 0) {
            // compare the values stored at each pointer
            // if we merge from front half, increment b and decrement remaining
            // if we merge from back half, increment h
            // DON'T GO BEYOND END OF THE BUFFER

            if ((h <= end) && (*h < *b)) {
                // take from back
                *start = *h;
                h++; start++;
            }
            else {
                // take from front
                *start = *b;
                b++; start++; bufsize--;
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
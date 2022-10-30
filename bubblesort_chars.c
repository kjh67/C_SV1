#include <stdio.h>
#include <stdbool.h>


// THE ONLY DIFFERENCE IS CHANGING TYPES FROM INT* TO CHAR*

void bubblesort(char arr[], int arrlen) {
    while (arrlen > 0) {
        // remember to decrement len at the end of each iteration
        // can set to 0 if we make no swaps
        bool done = true;
        for (int i=0; i < arrlen-1; i++) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                done = false;
            }
        }
        if (done) {
            arrlen = 0;
        }
        arrlen--;
    }
}

void display_arr(char* arr, int arrlen) {
    for (int i=0; i<arrlen-1; i++) {
        printf("%c,", arr[i]);
    }
    printf("%c\n", arr[arrlen-1]);
}

int main() {
    char i[] = {'c', 'a', 'n', 'p', 'b'};
    // If we try to get the length of the array in the subroutines, get pointer size instead
    // so calculate array size here, and pass around
    int len = sizeof(i) / sizeof(i[0]);
    display_arr(i, len);
    bubblesort(i, len);
    display_arr(i, len);
}
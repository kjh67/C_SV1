#include <string.h>
#include <stdio.h>

int cntlower(char str[]) {
    int count = 0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            count++;
        }
    }
    return count;
}


int main() {
    char test[] = "HELLO four";
    printf("%d\n", cntlower(test));
}
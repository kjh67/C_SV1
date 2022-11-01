#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
  for (int i=start, j=end; i < j; i++, j--) {
    char temp = str[i]; str[i] = str[j]; str[j] = temp;
  }
}


int find_next_start(char str[], int len, int i) { 
  /* TODO */
  // Start will be start of string, or preceded by a space
  for (int count=i; count<len; count++) {
    if (isalpha(str[count])){
      return count;
    }
  }
  return -1;
}

int find_next_end(char str[], int len, int i) {
  /* TODO */
  // Either at the end of the string, or before punctuation
  for (int count=i; count<len; count++) {
    if (!isalpha(str[count])) {
      return count-1;
    }} 
  return len-1;
}

void reverse_words(char s[]) { 
  /* TODO */
  // until i is at the end; get start, get end, reverse, move on!
  int i = 0;
  int len = strlen(s);
  while (i<len && i != -1) {
    int start = find_next_start(s,len,i);
    int end = find_next_end(s,len,start);
    reverse_substring(s, start, end);
    i = end + 1;
  }
}

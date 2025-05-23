#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  // getline() allows you to read a full line of text from the keyboard:
  // tokenize using strtok_r()

  char *line = NULL;
  size_t n = 0;

  printf("Please enter some text: ");

  if (getline(&line, &n, stdin) != -1) {
    printf("Tokens:\n");
    char *ret = NULL;
    char *saveptr = NULL;
    char *str = line;
    while ((ret = strtok_r(str, " ", &saveptr))) {
      printf("%s\n", ret);
      str = NULL;
    }
    free(line);
  } else {
    printf("Failure reading line!\n");
  }

  return 0;
}

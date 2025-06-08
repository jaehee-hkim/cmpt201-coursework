#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 5

char *input_history[MAX_LEN];
int history_count = 0;

void add_to_history(char *input);
void remove_oldest_record();
void print_history();
char *get_input();

int main() {
  while (1) {
    char *input = get_input();
    add_to_history(input);
    if (strcmp(input, "print") == 0) {
      print_history();
    }
  }
  // Free the memory of the input history
  for (int i = 0; i < history_count; i++) {
    free(input_history[i]);
  }
  return 0;
}

char *get_input() {
  char *buffer = NULL;
  size_t bufsize = 0;
  printf("Enter input: ");
  size_t len = getline(&buffer, &bufsize, stdin);
  if (len == -1) {
    exit(1);
  }
  // Remove the newline character at the end of the input
  buffer[len - 1] = '\0';
  return buffer;
}

void add_to_history(char *input) { // can do circular array
  if (history_count >= MAX_LEN) {
    remove_oldest_record();
  }
  input_history[history_count] = input;
  history_count++;
}

void remove_oldest_record() {
  if (history_count > 0) {
    // Free the memory of the oldest record
    free(input_history[0]);
    for (int i = 1; i < history_count; i++) {
      input_history[i - 1] = input_history[i];
    }
    history_count--;
  }
}

void print_history() {
  for (int i = 0; i < history_count; i++) {
    printf("%s\n", input_history[i]);
  }
}

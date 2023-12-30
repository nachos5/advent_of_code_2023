#include "problem_1/problem_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *read_line(FILE *file, int initial_buffer_size) {
  char *buffer;
  int bufferSize = initial_buffer_size;
  int position = 0;
  int ch;

  buffer = (char *)malloc(bufferSize * sizeof(char));
  if (!buffer) {
    perror("Unable to allocate buffer");
    exit(1);
  }

  while ((ch = fgetc(file)) != EOF) {
    if (ch == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position++] = ch;
    }

    if (position >= bufferSize) {
      bufferSize += initial_buffer_size;
      buffer = realloc(buffer, bufferSize);
      if (!buffer) {
        perror("Unable to reallocate buffer");
        exit(1);
      }
    }
  }

  if (position == 0) { // No characters read
    free(buffer);
    return NULL;
  }

  buffer[position] = '\0'; // Handle EOF without newline
  return buffer;
}

char **get_lines(int problem_number, int initial_buffer_size) {
  FILE *fp;
  char *line;
  char **lines;
  int capacity = 100; // Initial capacity for lines.

  char filepath[32];
  sprintf(filepath, "src/problem_%d/input.txt", problem_number);

  fp = fopen(filepath, "r");
  if (fp == NULL) {
    perror("Error opening file.");
    exit(EXIT_FAILURE);
  }

  lines = malloc(capacity * sizeof(char *));
  if (lines == NULL) {
    perror("Failed to allocate memory for lines.");
    fclose(fp);
    exit(EXIT_FAILURE);
  }

  int line_count = 0;
  while ((line = read_line(fp, initial_buffer_size)) != NULL) {
    if (line_count >= capacity) {
      capacity *= 2;
      lines = realloc(lines, capacity * sizeof(char *));
    }
    lines[line_count] = line;
    line_count++;
  }

  return lines;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("%s\n", "Must provide problem number");
    exit(EXIT_FAILURE);
  }

  int problem_number = atoi(argv[1]);

  char **lines = get_lines(problem_number, 36);

  clock_t start = clock();

  switch (problem_number) {
    case 1:
      run_1(lines);
      break;

    default:
      printf("Invalid problem number: %d\n", problem_number);
      exit(EXIT_FAILURE);
  }

  clock_t end = clock();
  double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

  printf("Time taken: %f seconds\n", cpu_time_used);

  return 0;
}

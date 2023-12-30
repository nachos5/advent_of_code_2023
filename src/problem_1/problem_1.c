#include "problem_1.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void run_1(char **lines) {
  char *line;
  int total_sum = 0;

  for (int i = 0; lines[i] != NULL; i++) {
    line = lines[i];

    int first_number = -1;
    int second_number = -1;

    int i = 0;

    while (line[i] != '\0') {
      char current_char = line[i];
      if (isdigit(current_char)) {
        if (first_number == -1) {
          first_number = current_char - '0';
        } else {
          second_number = current_char - '0';
        }
      }
      i++;
    }

    if (first_number != -1) {
      // If only 1 number in this line.
      if (second_number == -1) {
        second_number = first_number;
      }

      // 3 because of null char.
      char two_digits[3];

      // Concatenate the digits.
      sprintf(two_digits, "%d%d", first_number, second_number);

      total_sum += atoi(two_digits);
    }
  }

  printf("Sum: %d\n", total_sum);
}

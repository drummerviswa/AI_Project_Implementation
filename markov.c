#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ROWS 28
#define COLS 28
#define MAX_LINE 100
#define FIRST_LETTER 27
#define END_LETTER 26
#define MAX_COUNTS 27  // Column 27 stores row sum

#define START_LTR_STATE 0
#define NEXT_LTR_STATE 1

unsigned int matrix[ROWS][COLS];

// Check if character is terminal (space, punctuation, etc.)
int is_terminal(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' || ispunct(ch));
}

// Convert character to index (a=0, ..., z=25)
int to_idx(char ch) {
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a';
    return -1;
}

// Fill sum column for each row
void calculate_maximums() {
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < 27; j++) {
            sum += matrix[i][j];
        }
        matrix[i][MAX_COUNTS] = sum; // Save total row sum in column 27
    }
}

// Generate a random number between 0 and max-1
int RANDMAX(int max) {
    return rand() % max;
}

// Roulette selection based on frequencies
char select_letter(int row) {
    int max_val = RANDMAX(matrix[row][MAX_COUNTS]) + 1;
    int sum = 0;

    for (int i = 0; i < MAX_COUNTS; i++) {
        sum += matrix[row][i];
        if (sum >= max_val)
            return i;
    }
    return END_LETTER;
}

// Generate a random word using matrix
void generate_word(void) {
    int sel = select_letter(FIRST_LETTER);

    while (sel != END_LETTER) {
        printf("%c", 'a' + sel);
        sel = select_letter(sel);
    }
    printf("\n");
}

// Read and train from corpus
int read_corpus(char *filename) {
    FILE *fp;
    char line[MAX_LINE + 1];
    int state = START_LTR_STATE;
    char ch, prev_char;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, MAX_LINE, fp) != NULL) {
        for (i = 0; i < MAX_LINE && line[i] != '\0'; i++) {
            ch = tolower(line[i]);
            if (!isalpha(ch) && !is_terminal(ch)) continue;

            switch (state) {
                case START_LTR_STATE:
                    if (!is_terminal(ch)) {
                        prev_char = ch;
                        matrix[FIRST_LETTER][to_idx(ch)]++;
                        state = NEXT_LTR_STATE;
                    }
                    break;

                case NEXT_LTR_STATE:
                    if (is_terminal(ch)) {
                        matrix[to_idx(prev_char)][END_LETTER]++;
                        state = START_LTR_STATE;
                    } else {
                        matrix[to_idx(prev_char)][to_idx(ch)]++;
                        prev_char = ch;
                    }
                    break;
            }
        }
    }

    fclose(fp);
    calculate_maximums();
    return 0;
}

// Main driver
int main(int argc, char *argv[]) {
    srand(time(NULL));  // Initialize random seed

    if (argc != 2) {
        printf("Usage: %s <corpus_file>\n", argv[0]);
        return 1;
    }

    if (read_corpus(argv[1]) != 0) {
        printf("Failed to read corpus file.\n");
        return 1;
    }

    printf("Random words generated from corpus:\n");
    for (int i = 0; i < 10; i++) {
        generate_word();
    }

    return 0;
}

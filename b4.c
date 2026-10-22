#include <stdio.h>

#define MAX 100[cite: 6]
#define SIZE 20[cite: 6]

typedef struct {[cite: 6]
int row, col, value;[cite: 6]
} term;[cite: 6]

void printTriples(term a[]) {[cite: 6]
int i;[cite: 6]

printf("Row\tColumn\tValue\n");[cite: 6]

for (i = 0; i <= a[0].value; i++)[cite: 6]
    printf("%d\t%d\t%d\n",[cite: 6]
           a[i].row, a[i].col, a[i].value);[cite: 6]
}[cite: 6]

void fast_transpose(term a[], term b[]) {[cite: 7]
int row_terms[SIZE] = {0};[cite: 7]
int starting_pos[SIZE] = {0};[cite: 7]
int position[SIZE];[cite: 7]
int i, j, num_cols, num_terms;[cite: 7]

num_cols = a[0].col;[cite: 7]
num_terms = a[0].value;[cite: 7]

b[0].row = a[0].col;[cite: 7]
b[0].col = a[0].row;

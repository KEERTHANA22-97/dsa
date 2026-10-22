#include <stdio.h>

typedef struct {
int degree;
float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b) {
polynomial result;
int i, max_degree;

max_degree = (a.degree > b.degree) ? a.degree : b.degree;[cite: 1]
result.degree = max_degree;[cite: 1]

for (i = 0; i <= max_degree; i++) {[cite: 1]
    float ca = 0, cb = 0;[cite: 1]

    if (i <= a.degree)[cite: 1]
        ca = a.coef[a.degree - i];[cite: 1]

    if (i <= b.degree)[cite: 1]
        cb = b.coef[b.degree - i];[cite: 1]

    result.coef[max_degree - i] = ca + cb;[cite: 1]
}

return result;[cite: 2]
}

void display(polynomial p) {
int i, exponent, printed = 0;[cite: 2]
float c;[cite: 2]

for (i = 0; i <= p.degree; i++) {[cite: 2]
    c = p.coef[i];[cite: 2]
    exponent = p.degree - i;[cite: 2]

    if (c == 0)[cite: 2]
        continue;[cite: 2]

    if (printed && c > 0)[cite: 2]
        printf(" + ");[cite: 2]
    else if (printed && c < 0)[cite: 2]
        printf(" - ");[cite: 2]
    else if (!printed && c < 0)[cite: 2]
        printf("-");[cite: 2]

    if (printed && c < 0)[cite: 2]
        c = -c;[cite: 2]
    else if (!printed && c < 0)[cite: 2]
        c = -c;[cite: 2]

    if (exponent == 0)[cite: 2]
        printf("%.2g", c);[cite: 2]
    else if (exponent == 1) {[cite: 2]
        if (c == 1)[cite: 2]
            printf("x");[cite: 2]
        else[cite: 2]
            printf("%.2gx", c);[cite: 2]
    } else {[cite: 2]
        if (c == 1)[cite: 2]
            printf("x^%d", exponent);[cite: 2]
        else[cite: 2]
            printf("%.2gx^%d", c, exponent);[cite: 2]
    }

    printed = 1;[cite: 2]
}

if (!printed)[cite: 3]
    printf("0");[cite: 3]

printf("\n");[cite: 3]
}

void readPolynomial(polynomial *p) {
int i;[cite: 3]

printf("Enter degree: ");[cite: 3]
scanf("%d", &p->degree);[cite: 3]

if (p->degree < 0 || p->degree > 100) {[cite: 3]
    printf("Invalid degree.\n");[cite: 3]
    p->degree = -1;[cite: 3]
    return;[cite: 3]
}

printf("Enter coefficients from highest degree to constant:\n");[cite: 3]
for (i = 0; i <= p->degree; i++)[cite: 3]
    scanf("%f", &p->coef[i]);[cite: 3]
}

int main() {
polynomial a, b, result;[cite: 3]

printf("First polynomial\n");[cite: 3]
readPolynomial(&a);[cite: 3]
if (a.degree < 0)[cite: 3]
    return 1;[cite: 3]

printf("Second polynomial\n");[cite: 3]
readPolynomial(&b);[cite: 3]
if (b.degree < 0)[cite: 3]
    return 1;[cite: 3]

result = add(a, b);[cite: 3]

printf("Polynomial A: ");[cite: 3]
display(a);[cite: 3]

printf("Polynomial B: ");[cite: 4]
display(b);[cite: 4]

printf("Sum: ");[cite: 4]
display(result);[cite: 4]

return 0;[cite: 4]
}

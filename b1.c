#include <stdio.h>
#include <stdlib.h>

typedef struct {
int roll_no;
char name[20];
float marks;
} Student;

int main(void) {
Student *ptr, *temp;
int n, i;
float sum = 0;
int top = 0;
char choice;

printf("Enter number of students: ");
if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number of students.\n");
    return 1;
}

ptr = (Student *)malloc(n * sizeof(Student));

if (ptr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
}

for (i = 0; i < n; i++) {
    printf("Enter roll, name, marks: ");

    if (scanf("%d %19s %f",
              &ptr[i].roll_no,
              ptr[i].name,
              &ptr[i].marks) != 3) {
        printf("Invalid input.\n");
        free(ptr);
        return 1;
    }
}

do {
    sum = 0;
    top = 0;

    for (i = 0; i < n; i++) {
        sum += ptr[i].marks;

        if (ptr[i].marks > ptr[top].marks) {
            top = i;
        }
    }

    printf("Average marks: %.2f\n", sum / n);

    printf("Topper: %s (Roll %d, Marks %.2f)\n",
           ptr[top].name,
           ptr[top].roll_no,
           ptr[top].marks);

    printf("Add 2 more students? (y/n): ");

    if (scanf(" %c", &choice) != 1) {
        break;
    }

    if (choice == 'y' || choice == 'Y') {
        temp = (Student *)realloc(
            ptr, (n + 2) * sizeof(Student)
        );

        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            free(ptr);
            return 1;
        }

        ptr = temp;

        for (i = n; i < n + 2; i++) {
            printf("Enter roll, name, marks: ");

            if (scanf("%d %19s %f",
                      &ptr[i].roll_no,
                      ptr[i].name,
                      &ptr[i].marks) != 3) {
                printf("Invalid input.\n");
                free(ptr);
                return 1;
            }
        }

        n = n + 2;
    }

} while (choice == 'y' || choice == 'Y');

free(ptr);
return 0;
}

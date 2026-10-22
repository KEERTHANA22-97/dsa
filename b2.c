#include <stdio.h>
#include <stdlib.h>

typedef enum {
FULL_TIME,
CONTRACT
} EmployeeType;

typedef struct {
char name[20];
int emp_id;
EmployeeType type;

union {
    float salary;

    struct {
        float hourly_rate;
        int hours_worked;
    } contract_info;

} pay;
} Employee;

int main(void) {
Employee *e;
int n, i, type_input;
float total_bill = 0, amount;

printf("Enter number of employees: ");

if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number of employees.\n");
    return 1;
}

e = malloc(n * sizeof(Employee));

if (e == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
}

for (i = 0; i < n; i++) {
    printf("\nEnter employee name and ID: ");

    if (scanf("%19s %d",
              e[i].name,
              &e[i].emp_id) != 2) {
        printf("Invalid input.\n");
        free(e);
        return 1;
    }

    printf("Enter type (0=Full-time, 1=Contract): ");

    if (scanf("%d", &type_input) != 1 ||
        (type_input != FULL_TIME && type_input != CONTRACT)) {
        printf("Invalid employee type.\n");
        free(e);
        return 1;
    }

    e[i].type = (EmployeeType)type_input;

    if (e[i].type == FULL_TIME) {
        printf("Enter monthly salary: ");

        if (scanf("%f", &e[i].pay.salary) != 1) {
            printf("Invalid salary input.\n");
            free(e);
            return 1;
        }
    } else {
        printf("Enter hourly rate and hours worked: ");

        if (scanf("%f %d",
                  &e[i].pay.contract_info.hourly_rate,
                  &e[i].pay.contract_info.hours_worked) != 2) {
            printf("Invalid contract details.\n");
            free(e);
            return 1;
        }
    }
}

printf("\n--- EMPLOYEE PAYSLIPS ---\n");

for (i = 0; i < n; i++) {
    if (e[i].type == FULL_TIME) {
        amount = e[i].pay.salary;
    } else {
        amount = e[i].pay.contract_info.hourly_rate *
                 e[i].pay.contract_info.hours_worked;
    }

    printf("\nEmployee: %s\n", e[i].name);
    printf("Employee ID: %d\n", e[i].emp_id);
    printf("Employee Type: %s\n",
           e[i].type == FULL_TIME ? "Full-time" : "Contract");
    printf("Total Pay: %.2f\n", amount);

    total_bill += amount;
}

printf("\nTotal salary bill: %.2f\n", total_bill);

free(e);

return 0;
}

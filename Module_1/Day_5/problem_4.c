#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' students
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    // Read data for each student
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", students[i].name);

        printf("Enter age: ");
        scanf("%d", &students[i].age);

        printf("Enter marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display the stored data for each student
    printf("\nData for all students:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}

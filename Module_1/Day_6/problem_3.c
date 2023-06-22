#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayArray(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for the array of structures
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    // Assuming the array of structures has been initialized

    // Display the array of structures
    displayArray(students, numStudents);

    // Free the dynamically allocated memory
    free(students);

    return 0;
}

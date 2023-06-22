#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchArray(const struct Student *students, int numStudents, const char *name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;  // Return the index of the matching student
        }
    }
    return -1;  // Return -1 if the name is not found
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for the array of structures
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    // Assuming the array of structures has been initialized

    char searchName[20];
    printf("Enter the name to search: ");
    scanf("%s", searchName);

    // Perform the search operation
    int index = searchArray(students, numStudents, searchName);

    if (index != -1) {
        printf("Student Found!\n");
        printf("Roll No: %d\n", students[index].rollno);
        printf("Name: %s\n", students[index].name);
        printf("Marks: %.2f\n", students[index].marks);
    } else {
        printf("Student Not Found!\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}

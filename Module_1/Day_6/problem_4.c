#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Comparison function for qsort
int compareMarks(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;

    // Sort in descending order based on marks
    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    } else {
        return 0;
    }
}

void sortArray(struct Student *students, int numStudents) {
    // Sort the array of structures using qsort
    qsort(students, numStudents, sizeof(struct Student), compareMarks);
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Dynamically allocate memory for the array of structures
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    // Assuming the array of structures has been initialized

    // Sort the array of structures
    sortArray(students, numStudents);

    // Display the sorted array of structures
    printf("Sorted Array of Structures:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}

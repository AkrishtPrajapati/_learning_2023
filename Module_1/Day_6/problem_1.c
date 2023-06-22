#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student *students, int numStudents, const char *input) {
    char *token;
    int i = 0;

    // Tokenize the input string based on space delimiter
    token = strtok(input, " ");

    while (token != NULL && i < numStudents) {
        // Assign roll number
        students[i].rollno = atoi(token);
        
        // Get the next token
        token = strtok(NULL, " ");

        // Assign name
        strcpy(students[i].name, token);

        // Get the next token
        token = strtok(NULL, " ");

        // Assign marks
        students[i].marks = atof(token);

        // Get the next token
        token = strtok(NULL, " ");

        i++;
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Consume the newline character
    getchar();

    // Dynamically allocate memory for the array of structures
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    printf("Enter the student details:\n");
    for (int i = 0; i < numStudents; i++) {
        char input[100];
        fgets(input, sizeof(input), stdin);

        // Remove the newline character from the input
        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        // Initialize the array of structures
        initializeArray(&students[i], 1, input);
    }

    // Display the initialized array of structures
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

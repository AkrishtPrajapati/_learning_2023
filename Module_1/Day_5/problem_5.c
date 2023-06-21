#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

void swapStudents(struct Student *student1, struct Student *student2) {
    struct Student temp;

    // Swap name
    strcpy(temp.name, student1->name);
    strcpy(student1->name, student2->name);
    strcpy(student2->name, temp.name);

    // Swap age
    temp.age = student1->age;
    student1->age = student2->age;
    student2->age = temp.age;

    // Swap marks
    temp.marks = student1->marks;
    student1->marks = student2->marks;
    student2->marks = temp.marks;
}

int main() {
    struct Student student1, student2;

    // Input student1 details
    printf("Enter details for student 1:\n");
    printf("Enter name: ");
    scanf("%s", student1.name);
    printf("Enter age: ");
    scanf("%d", &student1.age);
    printf("Enter marks: ");
    scanf("%f", &student1.marks);

    // Input student2 details
    printf("\nEnter details for student 2:\n");
    printf("Enter name: ");
    scanf("%s", student2.name);
    printf("Enter age: ");
    scanf("%d", &student2.age);
    printf("Enter marks: ");
    scanf("%f", &student2.marks);

    printf("\nBefore swapping:\n");
    printf("Student 1: Name - %s, Age - %d, Marks - %.2f\n", student1.name, student1.age, student1.marks);
    printf("Student 2: Name - %s, Age - %d, Marks - %.2f\n", student2.name, student2.age, student2.marks);

    // Swap the fields using pointers
    swapStudents(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: Name - %s, Age - %d, Marks - %.2f\n", student1.name, student1.age, student1.marks);
    printf("Student 2: Name - %s, Age - %d, Marks - %.2f\n", student2.name, student2.age, student2.marks);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter student name: ");
        scanf(" %s", students[studentCount].name);
        printf("Enter roll number: ");
        scanf("%d", &students[studentCount].rollNumber);
        printf("Enter marks: ");
        scanf("%f", &students[studentCount].marks);
        studentCount++;
        printf("Student added successfully!\n");
    } else {
        printf("Student list is full!\n");
    }
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\nStudent Records:\n");
    int i; // Declare i outside the loop
    for (i = 0; i < studentCount; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int rollNo;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNo);
    int i; // Declare i outside the loop
    for (i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNo) {
            printf("Student Found!\nRoll No: %d, Name: %s, Marks: %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Record System\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}


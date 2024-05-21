#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNumber;
    char name[50];
    char class[20];
    int age;
};


struct Student students[MAX_STUDENTS];
int numStudents = 0;


void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("No more space to add students.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter name: ");
    scanf("%s", newStudent.name);
    printf("Enter Id number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter class: ");
    scanf("%s", newStudent.class);
    printf("Enter age: ");
    scanf("%d", &newStudent.age);

    students[numStudents++] = newStudent;
    printf("Student added successfully.\n");
}


void displayStudents() {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Id Number\tName\tClass\tAge\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t\t%s\t%s\t%d\n", students[i].rollNumber, students[i].name, students[i].class, students[i].age);
    }
}


void searchStudent(int rollNumber) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found:\n");
            printf("Id Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Class: %s\n", students[i].class);
            printf("Age: %d\n", students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}


void deleteStudent(int rollNumber) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {

            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Student deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int choice;
    int rollNumber;

    printf("\n\t---------------------------------------\t");
    printf("\n\tCanadian university of Bangladesh (CUB)\t");
    printf("\n\tSubject Name : DSA II | Course Code : 2205\t");
    printf("\n\tTeacher: A. S. M. Sabiqul Hassan\t");
    printf("\n\tDepartment: BSC in CSE\t");
    printf("\n\t---------------------------------------\t");
    printf("\n\tShahida Arobi          \tId:23105063\n\tMst.Rukaia Tanha\t\tId:23105046\n\tMostofa Khan    \t\tId:23105002\n\tM.A jayed             \tId:23105072\n\t");
    printf("\n\tProject Title : Student Management System\t");
    printf("\n\t-----------------------------------------\n");

    do {

        printf("\n\t1. Add Student\n\t");
        printf("2. All Students\n\t");
        printf("3. Search Student\n\t");
        printf("4. Delete Student\n\t");
        printf("5. Exit\n\t");
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
                printf("Enter Id number to search: ");
                scanf("%d", &rollNumber);
                searchStudent(rollNumber);
                break;
            case 4:
                printf("Enter Id number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(rollNumber);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

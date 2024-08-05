#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define DATA_FILE "students.dat"

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void loadStudents() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        return; // No data file exists, so just return
    }
    while (fscanf(file, "%d %49[^\n] %d\n", &students[studentCount].id, students[studentCount].name, &students[studentCount].age) != EOF) {
        studentCount++;
    }
    fclose(file);
}

void saveStudents() {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%d %s %d\n", students[i].id, students[i].name, students[i].age);
    }
    fclose(file);
}

void createStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }
    Student s;
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter student age: ");
    scanf("%d", &s.age);
    students[studentCount++] = s;
    saveStudents();
    printf("Student added successfully.\n");
}

void readStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
}

void updateStudent() {
    int id, found = 0;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            saveStudents();
            printf("Student updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent() {
    int id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            saveStudents();
            printf("Student deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

int main() {
    loadStudents();
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createStudent(); break;
            case 2: readStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}

#include <stdio.h>
//Let's Code--Shahid
#define MAX_STUDENTS 100
#define NUM_GRADES 5

// Define the union for status
union Status {
    char passFail;
    int gradeCategory;
};

// Define the structure for a student
struct Student {
    char name[50];
    int id;
    float grades[NUM_GRADES];
    float average;
    union Status status;
};

// Function prototypes
void inputStudentData(struct Student *s, int n);
void calculateAverage(struct Student *s, int n);
void determineStatus(struct Student *s, int n);
void displayStudents(const struct Student *s, int n);

int main() {
    int n;
    scanf("%d", &n);
    
    struct Student students[MAX_STUDENTS];
    
    inputStudentData(students, n);
    calculateAverage(students, n);
    determineStatus(students, n);
    displayStudents(students, n);
    
    return 0;
}

// Function to input data for students
void inputStudentData(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].id);
        
        for (int j = 0; j < NUM_GRADES; j++) {
            scanf("%f", &s[i].grades[j]);
        }
    }
}

// Function to calculate the average grade for each student
void calculateAverage(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_GRADES; j++) {
            sum += s[i].grades[j];
        }
        s[i].average = sum / NUM_GRADES;
    }
}

// Function to determine the status of each student based on their average
void determineStatus(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        if (s[i].average >= 85) {
            s[i].status.gradeCategory = 1;  // Excellent
        } else if (s[i].average >= 70) {
            s[i].status.gradeCategory = 2;  // Good
        } else if (s[i].average >= 50) {
            s[i].status.passFail = 'P';     // Pass
        } else {
            s[i].status.passFail = 'F';     // Fail
        }
    }
}

// Function to display the details of each student
void displayStudents(const struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student: %s\n", s[i].name);
        printf("ID: %d\n", s[i].id);
        printf("Grades: ");
        
        for (int j = 0; j < NUM_GRADES; j++) {
            printf("%.1f", s[i].grades[j]);
            if (j < NUM_GRADES - 1) printf(", ");
        }
        
        printf("\nAverage: %.1f\n", s[i].average);

        // Display status based on the average
        if (s[i].average >= 85) {
            printf("Status: Grade Category - %d\n", s[i].status.gradeCategory);
        } else if (s[i].average >= 70) {
            printf("Status: Grade Category - %d\n", s[i].status.gradeCategory);
        } else if (s[i].average >= 50) {
            printf("Status: Pass/Fail - %c\n", s[i].status.passFail);
        } else {
            printf("Status: Pass/Fail - %c\n", s[i].status.passFail);
        }
        printf("\n");
    }
}

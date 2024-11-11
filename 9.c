//Let's Code--Shahid
#include <stdio.h>
#include <string.h>

// Define the structure to hold student information
struct Student {
    char name[51];  // Name of the student (up to 50 characters + 1 for null terminator)
    int roll_number;  // Unique roll number
    float marks[3];  // Marks in three subjects
    float total_marks;  // Total marks
    float average_marks;  // Average marks
};

// Function to calculate total and average marks for each student
void calculate_marks(struct Student *student) {
    student->total_marks = student->marks[0] + student->marks[1] + student->marks[2];
    student->average_marks = student->total_marks / 3.0;
}

// Function to sort students by average marks in descending order
void sort_students(struct Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].average_marks < students[j].average_marks) {
                // Swap the students
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to display student information
void display_students(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll Number: %d, Total Marks: %.2f, Average Marks: %.2f\n",
               students[i].name,
               students[i].roll_number,
               students[i].total_marks,
               students[i].average_marks);
    }
}

int main() {
    int n;

    // Read the number of students
    printf("");
    scanf("%d", &n);

    // Check for valid number of students
    if (n < 1 || n > 100) {
        printf("Invalid number of students.\n");
        return 1;
    }

    // Declare an array of Student structures
    struct Student students[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        printf("", i + 1);
        
        // Clear the input buffer before reading the name
        getchar();
        
        // Read the student's name using fgets
        printf("");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        // Remove newline character from the name if present
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("");
        scanf("%d", &students[i].roll_number);
        
        printf("");
        for (int j = 0; j < 3; j++) {
            scanf("%f", &students[i].marks[j]);
        }

        // Calculate total and average marks for the student
        calculate_marks(&students[i]);
    }

    // Sort students by average marks in descending order
    sort_students(students, n);

    // Display sorted student information
    printf("");
    display_students(students, n);

    return 0;
}

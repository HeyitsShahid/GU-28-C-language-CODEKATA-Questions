//Let's Code--Shahid
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_assessments;
    int *assessments;
    float course_avg;
} Course;

typedef struct {
    int num_courses;
    Course *courses;
    float overall_avg;
} Student;

void input_data(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        scanf("%d", &students[i].num_courses);
        students[i].courses = (Course *)malloc(students[i].num_courses * sizeof(Course));

        for (int j = 0; j < students[i].num_courses; j++) {
            scanf("%d", &students[i].courses[j].num_assessments);
            students[i].courses[j].assessments = (int *)malloc(students[i].courses[j].num_assessments * sizeof(int));

            int sum = 0;
            for (int k = 0; k < students[i].courses[j].num_assessments; k++) {
                scanf("%d", &students[i].courses[j].assessments[k]);
                sum += students[i].courses[j].assessments[k];
            }
            students[i].courses[j].course_avg = (float)sum / students[i].courses[j].num_assessments;
        }
    }
}

void calculate_averages(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        float total = 0;
        for (int j = 0; j < students[i].num_courses; j++) {
            total += students[i].courses[j].course_avg;
        }
        students[i].overall_avg = total / students[i].num_courses;
    }
}

void display_results(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        for (int j = 0; j < students[i].num_courses; j++) {
            printf("Course %d Average: %.2f\n", j + 1, students[i].courses[j].course_avg);
        }
        printf("Overall Average: %.2f\n", students[i].overall_avg);
    }
}

void free_memory(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < students[i].num_courses; j++) {
            free(students[i].courses[j].assessments);
        }
        free(students[i].courses);
    }
}

int main() {
    int num_students;
    scanf("%d", &num_students);

    Student *students = (Student *)malloc(num_students * sizeof(Student));

    input_data(students, num_students);
    calculate_averages(students, num_students);
    display_results(students, num_students);

    free_memory(students, num_students);
    free(students);

    return 0;
}

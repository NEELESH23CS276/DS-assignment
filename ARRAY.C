#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 5

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS];
    int i, j;
    
    // Input marks for each student
    printf("Enter marks for %d students in %d subjects each:\n", NUM_STUDENTS, NUM_SUBJECTS);
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter marks for student %d: ", i + 1);
        for (j = 0; j < NUM_SUBJECTS; j++) {
            scanf("%d", &marks[i][j]);
        }
    }
    
    //  total marks for each student 
    printf("\nTotal marks for each student:\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        int total = 0;
        for (j = 0; j < NUM_SUBJECTS; j++) {
            total += marks[i][j];
        }
        printf("Student %d: %d\n", i + 1, total);
    }
    
    //  average marks for each subject
    printf("\nAverage marks for each subject:\n");
    for (j = 0; j < NUM_SUBJECTS; j++) {
        int total = 0;
        for (i = 0; i < NUM_STUDENTS; i++) {
            total += marks[i][j];
        }
        float average = (float)total / NUM_STUDENTS;
        printf("Subject %d: %.2f\n", j + 1, average);
    }
    
    return 0;
}

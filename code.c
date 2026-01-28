#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 5

struct Student {
    int roll;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
};

struct Student students[MAX];
int count = 0;

void saveToFile() {
    FILE *fp = fopen("results.txt", "w"); 
    if (fp == NULL) {
        printf("Cannot open file for writing!\n");
        return;
    }

    fprintf(fp, "%d\n", count); 

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d\n", students[i].roll);
        fprintf(fp, "%s\n", students[i].name);
        for (int j = 0; j < SUBJECTS; j++)
            fprintf(fp, "%.2f ", students[i].marks[j]);
        fprintf(fp, "\n");
        fprintf(fp, "%.2f %.2f %c\n", students[i].total, students[i].percentage, students[i].grade);
    }

    fclose(fp);
    printf("Data saved successfully!\n");
}

void loadFromFile() {
    FILE *fp = fopen("results.txt", "r");
    if (fp == NULL){
    	printf("File can not be opened");
    		 return;
	}


    fscanf(fp, "%d\n", &count);
    if (count > MAX) count = 0;

    for (int i = 0; i < count; i++) {
        fscanf(fp, "%d\n", &students[i].roll);
        fgets(students[i].name, 50, fp);
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        for (int j = 0; j < SUBJECTS; j++)
        fscanf(fp, "%f", &students[i].marks[j]);
        fscanf(fp, "\n");

        fscanf(fp, "%f %f %c\n", &students[i].total, &students[i].percentage, &students[i].grade);
    }

    fclose(fp);
}

void calculateResult(struct Student *s) {
    s->total= 0;
    for (int i = 0; i < SUBJECTS; i++)
        s->total += s->marks[i];

    s->percentage = s->total / SUBJECTS;

    if (s->percentage >= 90) s->grade = 'A';
    else if (s->percentage >= 80) s->grade = 'B';
    else if (s->percentage >= 70) s->grade = 'C';
    else if (s->percentage >= 60) s->grade = 'D';
    else s->grade = 'F';
}

void addStudent() {
    if (count >= MAX) {
        printf("Cannot add more students!\n");
        return;
    }

    struct Student s;

    while (1) {
        int duplicate = 0;
        printf("Enter Roll Number: ");
        scanf("%d", &s.roll);

        for (int i = 0; i < count; i++) {
            if (students[i].roll == s.roll) {
                printf("This Roll Number already exists! Please enter a different one.\n");
                duplicate = 1;
                break;
            }
        }

        if (duplicate==0) break; 
    }

    printf("Enter Name: ");
    scanf(" %49[^\n]", s.name);

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks for Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }

    calculateResult(&s);
    students[count++] = s;

    printf("Student added successfully!\n");
}

void displayAll() {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nRoll: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Total: %.2f\n", students[i].total);
        printf("Percentage: %.2f%%\n", students[i].percentage);
        printf("Grade: %c\n", students[i].grade);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Record Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Total: %.2f\n", students[i].total);
            printf("Percentage: %.2f%%\n", students[i].percentage);
            printf("Grade: %c\n", students[i].grade);
            return;
        }
    }
    printf("Record not found!\n");
}

void updateStudent() {
    int roll;
    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter new marks:\n");
            for (int j = 0; j < SUBJECTS; j++) {
                printf("Subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
            }
            calculateResult(&students[i]);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

void deleteStudent() {
    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

int main() {
    int choice;
    loadFromFile();

    do {
        printf("\n===== Student Result Management =====\n");
        printf("1. Add Student\n");
        printf("2. Display All\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: saveToFile(); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}
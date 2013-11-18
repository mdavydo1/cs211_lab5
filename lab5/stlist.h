#include <stdio.h>

struct data
{
     unsigned int bnumber;
     char first_name[19];				 //(up to 18 characters, not inluding the NULL)
     char last_name[19];				//(also up to 18 characters, not inluding the NULL)
     char quiz_grades[6];
     char project_grades[5];
     char final_exam_grade;

};

typedef struct data student;


int number_of_students;
student *arr;

void space();
void add_students();
void remove_last_student();
void grades();
void remove_student_by_bnumber();

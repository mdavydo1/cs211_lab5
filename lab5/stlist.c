#include <stdio.h>
#include <stdlib.h>
#include "stlist.h"



static int size=0;
student * store;



void space()
{
	if(store == NULL)
	{
		store = (student*)malloc(sizeof(student));
	}
	else
	{
		student *temp = (student*)malloc(sizeof(student)*(size+1));
		int i;
		for(i=0; i<size; i++)
		{
			temp[i]=store[i];
		}
		free(store);
		store=temp;
		temp=NULL;
	}
	++size;
}




void add_students()
{
	space();
	int i=size-1;
	int check_duplicate;
	
		printf("Input student information:\n");
		unsigned int temp1;
		printf("input the student's B-number: \n");
		scanf("%u", &temp1);
		//store[i].bnumber=temp1;
		//printf("%u\n", store[i].bnumber);
		
		
			for(check_duplicate=0; check_duplicate<size; check_duplicate++)
			{
				if(store[check_duplicate].bnumber != temp1)
				{
					store[i].bnumber=temp1;
					printf("%u\n", store[i].bnumber);
				}
				
				else
				{
					printf("This bnumber was previously input, make another entry: \n");
				}
			}
				
				
		printf("input the student's first name: \n");
		scanf("%s", store[i].first_name);
		printf("%s \n", store[i].first_name);
		
		printf("input the student's last name: \n");
		scanf("%s", store[i].last_name);
		printf("%s \n", store[i].last_name);	
					
		int j;
		int temp4;
		printf("input student's quiz grades \n");
		for(j=0; j < 6; j++)
		{
			scanf("%d", &temp4);
			store[i].quiz_grades[j]=temp4;
			printf("%d\n",store[i].quiz_grades[j]);
		}
			
		printf("input the student's project grades \n");
		for(j=0; j < 5; j++)
		{
			scanf("%d", &temp4);
			store[i].project_grades[j]=temp4;
		}
			
		int temp6;	
		printf("input the student's final exam grade: \n");
		scanf("%d", &temp6);
		printf("%d \n", temp6); 
		store[i].final_exam_grade = temp6;
		
	
	
}

void remove_last_student() 
{

		int i;
		--size;
		student * new;
		new=(student*)malloc(sizeof(student)*size);
		if(size>0)
		{
			for(i=0; i<size; i++)
			{
				new[i]=store[i];
			}
		}
		free(store);
		store=new;
		new=NULL;
		printf("last student deleted:\n");
	
}




void grades()
{
	int i;
	int j; 
	int swapped = 0;
	float quizavg=0;
	float labavg=0;
	float final_grade=0;
	char temp2;
	
	for(i = 0; i < size; i++)
	{
		//PRINT OUT NAME, BNUMBER, AND WHATNOT
		printf("%u\n", store[i].bnumber);
		printf("%s\n", store[i].first_name);
		printf("%s\n", store[i].last_name);
		//printf("%s", store[i].quiz_grades);
		//printf("%s", store[i].project_grades);
		//printf("%c", strore[i].final_exam_grade);
		
		// bubble sort
		do
		{
			swapped = 0;
			for(j = 0; j < 5; j++)
			{
				if(store[i].quiz_grades[j] < store[i].quiz_grades[j+1])
				{
					swapped++;
					temp2=store[i].quiz_grades[j];
					store[i].quiz_grades[j]=store[i].quiz_grades[j+1];
					store[i].quiz_grades[j+1]=temp2;
				}
			}
		}while(swapped > 0);
	
		//quiz averages	
		for(j = 0; j < 5; j++)
		{
		
			quizavg += store[i].quiz_grades[j];
		}
		quizavg = quizavg / 5;
		printf("Quiz Average: %.2f\n", quizavg);
		
		
		
		//lab averages
		for(j = 0; j < 5; j++)
		{
			labavg += store[i].project_grades[j];
		}
		labavg = labavg / 5;
		printf("Lab Average: %.2f\n", labavg);
		
		//final grades
		final_grade = (0.3*quizavg)+(0.5*labavg)+(0.2*(store[i].final_exam_grade));
		printf("final grade: %.2f\n", labavg);
	}
		
}



void remove_student_by_bnumber()
{
	int p;
	int i;
	unsigned int bnum;
	student *tempstr;
	printf("enter the bnumber of the student to be deleted: ");
	scanf("%u", &bnum);

	for(p=0; p < size; p++)
	{	
		if(bnum == store[p].bnumber)
		{
			for(i=p; i<size; i++)
			{
				store[i].bnumber = store[i+1].bnumber;
			}
		
		}
	}
	--size;
	tempstr=(student*)malloc(sizeof(student)*size);
	free(store);
	store=tempstr;
	tempstr=NULL;
	printf("student deleted by bnumber!\n");
}


void print_student_info_by_bnumber()
{
unsigned int bnumscan;
int i;
int j;
float quizavg=0;
float labavg=0;
float final_grade=0;


printf("Enter the bnumber of the student to be viewed: ");
scanf("%u", &bnumscan);
	
	for(i=0; i<size; i++)
	{
		if(store[i].bnumber == bnumscan)
		{
			printf("%u\n", store[i].bnumber);
			printf("%s\n", store[i].first_name);
			printf("%s\n", store[i].last_name);
			
			//quiz averages	
			for(j = 0; j < 5; j++)
			{
		
				quizavg += store[i].quiz_grades[j];
			}
			quizavg = quizavg / 5;
			printf("Quiz Average: %.2f\n", quizavg);
		
		
		
			//lab averages
			for(j = 0; j < 5; j++)
			{
				labavg += store[i].project_grades[j];
			}
			labavg = labavg / 5;
			printf("Lab Average: %.2f\n", labavg);
		
			//final grades
			final_grade = (0.3*quizavg)+(0.5*labavg)+(0.2*(store[i].final_exam_grade));
			printf("final grade: %.2f\n", labavg);
			
			
			if(store[size-1].bnumber != bnumscan)
			{
				printf("No match found!\n");
			}
		}
	}

} 




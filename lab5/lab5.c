#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "stlist.h"

int main()
{
int select=5;

while(select!=0)
{
printf("type 1 to add a student:\n");
printf("type 2 to delete the last student\n");
printf("type 3 to calculate grades\n");
printf("type 4 to delete student by b number\n");
printf("type 0 to exit\n");
scanf("%d",&select);
//space();

	if(select==1)
	{
		add_students();
	}
	if(select==2)
	{

		remove_last_student();
	}
	if(select==3)
	{
		grades();
	}
	if(select==4)
	{
		remove_student_by_bnumber();	
	}
}
return(0);
}

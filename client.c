//header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"server.h"

int main()//main function
{	
	    printf("*******************************************\n");
	    printf("WELCOME TO EMPLOYEE LEAVE MANAGEMENT SYSTEM\n");
	    printf("*******************************************\n");	
		int choiceVar;//choice variable	
		char fileExt[5]=".txt";//file extension
		char fileName[50];//employee file name
	    FILE *filePointer;//file pointer
        int typeOfLeaveVar;//to store type of leave	    
		printf("ENTER YOUR CHOICE ACCORDINGLY\n1.EXIT\nANY NUMERIC KEY TO CONTINUE\n\n");
		scanf("%d",&choiceVar);
		choice(choiceVar);//calling choice function
		printf("Enter your EMPLOYEE ID\n");
	    scanf("%s",fileName);    
	    strcat(fileName,fileExt);//concatenate filename and file extension
	    filePointer=fopen(fileName,"r");//opening the file in read mode
	    while(filePointer==NULL)
		{
			printf("INVALID EMPLOYEE ID\n");
			printf("ERROR,No such employee file exits\n");
			printf("RELOGIN AGAIN FROM FIRST!\n");
			printf("THIS IS DONE TO ENSURE EMPLOYEE SECURITY\n");				
			exit(0);//exit from program
		}
		fclose(filePointer);//closing the file		
		printf("***************LEAVE REQUEST*****************\n");
		printf("Enter the type of leave\n1.Casual leave\n2.Medical leave\n3.Earned leave\n");
        scanf("%d",&typeOfLeaveVar);
        typeOfLeave(typeOfLeaveVar,fileName);//function call   
	
}

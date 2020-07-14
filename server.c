//function definition in server.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"server.h"
void choice(int choiceVar)//choice function
{
    if(choiceVar==1)
        {
            printf("YOU HAVE EXITED\n");
            exit(0);//exit from program
        }
    printf("NEXT.....\n");//continue  
}

void typeOfLeave(int typeOfLeaveVar,char fileName[])
{
    //3 types of leave in this function
    int lineCount=1;//to store the line number where the cursor currently is
    int lineID;//line whose content gets updated
    int leaveDays;//number of leaves taken by employee
    int leaveDaysLeft;//number of leaves remaining for employee
    int updateLeaveDays;//to update number of leaves
    FILE *filePointer;
    char c;//to store each character in file
    switch(typeOfLeaveVar)//switch case with 3 cases
        {
            case 1://casual leave           
            lineID=8;  
            filePointer=fopen(fileName,"r"); 
            while(lineCount<lineID)
            {               
                c=fgetc(filePointer);
                if(c=='\n')
                {
                    lineCount+=1;
                } 
            }           
            leaveDays=(fgetc(filePointer))-48;//convert ascii value to integer
            updateLeaveDays=leaveDays+1;            
            leaveDaysLeft=4-leaveDays; 
            fclose(filePointer);     
            if(leaveDays>=4)//employee allowed upto 4 days casual leave 
            {
                printf("Casual Leave Rejected\n");
                printf("You have exceeded maximium permissible days\n");                
            }
            else
            {
                printf("LEAVE GRANTED\n");
                printf("REMINDER:YOU HAVE ALREADY TAKEN %d days\n",leaveDays); 
                printf("REMINDER:YOU HAVE %d days remaining\n",leaveDaysLeft); 
                updateLeave(lineID,fileName,updateLeaveDays);//calling update leave function             
            }            
            exit(0);
            break;
            case 2://medical leave 
            lineID=10;  
            filePointer=fopen(fileName,"r"); 
            while(lineCount<lineID)
            {               
                c=fgetc(filePointer);
                if(c=='\n')
                {
                    lineCount+=1;
                } 
            }           
            leaveDays=(fgetc(filePointer))-48;//convert ascii value to integer 
            updateLeaveDays=leaveDays+1;
            leaveDaysLeft=7-leaveDays;  
            fclose(filePointer);        
            if(leaveDays>=7)//employee allowed upto 7 days medical leave 
            {
                printf("Medical Leave Rejected\n");
                printf("You have exceeded maximium permissible days\n");                                
            }   
            else
            {
                printf("LEAVE GRANTED\n");
                printf("REMINDER:YOU HAVE ALREADY TAKEN %d days\n",leaveDays);  
                printf("REMINDER:YOU HAVE %d days remaining\n",leaveDaysLeft);
                updateLeave(lineID,fileName,updateLeaveDays);//calling update leave function              
            }            
            exit(0);
            break;
            case 3://earned leave
            lineID=12;  
            filePointer=fopen(fileName,"r"); 
            updateLeaveDays=leaveDays+1;
            while(lineCount<lineID)
            {               
                c=fgetc(filePointer);
                if(c=='\n')
                {
                    lineCount+=1;
                } 
            }           
            leaveDays=(fgetc(filePointer))-48;//convert ascii value to integer 
            leaveDaysLeft=2-leaveDays;  
            fclose(filePointer);        
            if(leaveDays>=2)//employee allowed upto 2 days medical leave
            {
                printf("Earned Leave Rejected\n");
                printf("You have exceeded maximium permissible days\n");                               
            }
            else
            {
                printf("LEAVE GRANTED\n");
                printf("REMINDER:YOU HAVE ALREADY TAKEN %d days\n",leaveDays);
                printf("REMINDER:YOU HAVE %d days remaining\n",leaveDaysLeft); 
                updateLeave(lineID,fileName,updateLeaveDays);//calling update leave function            
            }            
            exit(0);
            break;
            default://if user enters wrong entry
            printf("INVALID ENTRY\n");
            printf("Enter correct entry: ");
            scanf("%d",&typeOfLeaveVar);
            typeOfLeave(typeOfLeaveVar,fileName);
            break;
        }
}
void updateLeave(int lineID,char fileName[],int updateLeaveDays)
{
    int lineCount=1;
    char c;//to store each character in file
    FILE *copyFilePointer,*filePointer;
    copyFilePointer = fopen("copy.txt","w");//opening file in write mode
    filePointer=fopen(fileName,"r");
    while(lineCount<=lineID)
    {
        c=fgetc(filePointer);
        if(lineCount!=lineID && c!=EOF)//to check appropriate conditions 
            fputc(c,copyFilePointer);
        if(c=='\n')//to check for newline 
            lineCount++;         
    }
    char updateLeaveDaysChar= (char)(updateLeaveDays+48);//type casting
    fputc(updateLeaveDaysChar,copyFilePointer);
    fputc('\n',copyFilePointer);
    while((c=fgetc(filePointer))!=EOF)
    {
        fputc(c,copyFilePointer);
    }
    printf("Your file is updated successfully!!!");
    fclose(filePointer);//closing a file
    fclose(copyFilePointer);//closing a file
    remove(fileName);//to remove a file
    rename("copy.txt",fileName);//renaming the new file with old name
}
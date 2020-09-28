#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void addcontact();
void viewcontact();
void searchcontact();
void deletecontact();
void modifycontact();
void byee();
typedef struct contact
{
    char name[10];
    char cast[10];
    long ph_no;
}CONTACT;
void title()
{
    printf("\t\t\t\t\t\t**************************\n");
    printf("\t\t\t\t\t\t*       PHONE-BOOK       *\n");
    printf("\t\t\t\t\t\t**************************\n");
    printf("\n");
}

void heading()
{
    printf("\n");
    printf("\t\t\t\t\t\t|************************|\n");
    printf("\t\t\t\t\t\t|[1]-ADD CONTACT         |\n");
    printf("\t\t\t\t\t\t|[2]-VIEW CONTACT        |\n");
    printf("\t\t\t\t\t\t|[3]-SEARCH CONTACT      |\n");
    printf("\t\t\t\t\t\t|[4]-DELETE CONTACT      |\n");
    printf("\t\t\t\t\t\t|[5]-MODIFY CONTACT      |\n");
    printf("\t\t\t\t\t\t|[6]-EXIT                |\n");
    printf("\t\t\t\t\t\t|************************|\n");
}
int check(char name[10],char cast[10])
{
    CONTACT data;
    FILE *box;
    int check = 0;
    box = fopen("CONTACT","r+");
    if(box == NULL)
    {
        printf("error 0x004");
        exit(1);
    }
    while(fscanf(box,"\n%s %s\n%ld\n",&data.name,&data.cast,&data.ph_no)!=EOF)
    {
        if((strcmp(name,data.name))==0&&(strcmp(cast,data.cast))==0)
        {
            check = 1;
        }
    }
    system("clear");
    if(check == 1)
    { 
       return (1);
    }
    if(check == 0)
        printf("contact dosen't match\n");
}
////////////////////////////////////////////////////////////////////
void gotoxy(int x, int y)//function definition
{ 
    printf("%c[%d;%df",0x1b,y,x);
}

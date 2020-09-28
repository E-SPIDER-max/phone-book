/*
made by pranaya raj neupane(espider)
kathmandu,Nepal
//beginner//
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/home/spyder/Desktop/phonbook/helper.c"

CONTACT data;
FILE *box;
void body()
{
    system("clear");
    title();
    heading();
    printf("\t\t\tCHOOSE: ");
    int ans;
    scanf("%d", &ans);
    switch (ans)
    {
    case 1:
        addcontact();
        break;
    case 2:
        viewcontact();
        break;
    case 3:
        searchcontact();
        break;
    case 4:
        deletecontact();
        break;
    case 5:
        modifycontact();
        break;
    case 6:
        byee();
        break;

    default:
        body();
        break;
    }
}
int main()
{
    system("clear");
        int i;
    system("clear");
    gotoxy(70,10);
    printf("LOADING\n");
    printf("\n\t\t\t\t\t\t\t");
    for(i=0;i<=15;i++)
    {  
        sleep(1);
        printf("||");
        fflush(stdout);
    }
    system("clear");
    gotoxy(70,10);
    printf("Press any key to continue\n");
    getchar();
    body();
    return 0;
}

void addcontact()
{
    char ans;
    system("clear");
    title();
    printf("Full-Name: ");
    scanf("%s %s", &data.name, &data.cast);
    printf("Phone-Number: ");
    scanf("%ld", &data.ph_no);

    box = fopen("CONTACT", "a+");
    fprintf(box, "\n%s %s\n%ld\n", data.name, data.cast, data.ph_no);
    fclose(box);
    system("clear");
    getchar(); //buffer
    printf("Do you want to add more contact\n[y/n]: ");
    scanf("%c", &ans);
    if (ans == 'y')
        addcontact();
    else
        body();
}
void viewcontact()
{
    system("clear");
    title();
    box = fopen("CONTACT", "r+");
    if (box == NULL)
    {
        printf("error 0x004");
        exit(1);
    }
    while (fscanf(box, "\n%s %s\n%ld\n", &data.name, &data.cast, &data.ph_no) != EOF)
    {
        printf("\nName: %s %s\nPH-NO: %ld\n", data.name, data.cast, data.ph_no);
    }
    fclose(box);
    getchar(); //buffer
    getchar(); //hold
    body();
}
void searchcontact()
{
    char name[10];
    int check = 0;
    system("clear");
    title();
    printf("Enter the name: ");
    scanf("%s", &name);
    box = fopen("CONTACT", "r+");
    if (box == NULL)
    {
        printf("error 0x004");
        exit(1);
    }
    while (fscanf(box, "\n%s %s\n%ld\n", &data.name, &data.cast, &data.ph_no) != EOF)
    {
        if ((strcmp(name, data.name)) == 0)
        {
            printf("\nName: %s %s\nPH-NO: %ld\n", data.name, data.cast, data.ph_no);
            check = 1;
        }
    }
    fclose(box);
    if (check == 0)
    {
        printf("contact dosen't found\n");
    }
    getchar(); //buffer
    getchar(); //hold
    body();
}
void deletecontact()
{
    int reciv, duel = 0;
    char name[10], cast[10], ans;
    printf("Enter full-name: ");
    scanf("%s %s", &name, &cast);
    reciv = check(name, cast); //recive 1 if correct
    getchar();                 //buffer

    if (reciv == 1) //continue
    {
        printf("Do you want to delete contact\n%s %s [y/n]: ", name, cast);
        scanf("%c", &ans);
        if (ans = 'y')
        {
            FILE *temp;
            box = fopen("CONTACT", "r+");
            temp = fopen("TEMP", "w");
            while ((fscanf(box, "\n%s %s\n%ld\n", &data.name, &data.cast, &data.ph_no)) != EOF)
            {
                if ((strcmp(name, data.name)) == 0 && (strcmp(cast, data.cast)) == 0)
                {
                    duel++;
                    continue;
                }
                else
                {
                    fprintf(temp, "\n%s %s\n%ld\n", data.name, data.cast, data.ph_no);
                }
            }
            printf("contact deleted successfully\n");
            fclose(box);
            fclose(temp);
            remove("CONTACT");
            rename("TEMP", "CONTACT");
            getchar();//buffer
            getchar();//hold
            body();
        }
    }
}
void modifycontact()
{
    int reciv, ans;
    char name[10], cast[10];
    printf("Enter full-name: ");
    scanf("%s %s", &name, &cast);
    reciv = check(name, cast); //recive 1 if correct
    getchar();//buffer

    if (reciv == 1) //continue
    {
        FILE *temp;
        box = fopen("CONTACT", "r+");
        temp = fopen("TEMP", "w");
        while ((fscanf(box, "\n%s %s\n%ld\n", &data.name, &data.cast, &data.ph_no)) != EOF)
        {
            if ((strcmp(name, data.name)) == 0 && (strcmp(cast, data.cast)) == 0)
            {

                system("clear");
                printf("Modefy\n[1]-name\n[2]-number\n[3]-Both\n");
                scanf("%d",&ans);
                if(ans==1)
                {
                    char newname[10],newcast[10];
                    printf("New-name: ");
                    scanf("%s %s",&newname,&newcast);
                    fprintf(temp, "\n%s %s\n%ld\n", newname, newcast, data.ph_no);
                }
                else if(ans == 2)
                {
                    long new_ph_no;
                    printf("New PH-no: ");
                    scanf("%ld",&new_ph_no);
                    fprintf(temp, "\n%s %s\n%ld\n", data.name, data.cast, new_ph_no);
                }
                else if(ans == 3)
                {
                    char newname[10],newcast[10];
                    long new_ph_no;
                    printf("New-name: ");
                    scanf("%s %s",&newname,&newcast);
                    printf("New PH-no: ");
                    scanf("%ld",&new_ph_no);
                    fprintf(temp, "\n%s %s\n%ld\n", newname, newcast, new_ph_no);
                }
                else
                {
                    system("clear");
                    printf("Are you drunk");
                    getchar();//buffer
                    getchar();//hold
                    exit(1);
                }
            }
            else
            {
                fprintf(temp, "\n%s %s\n%ld\n", data.name, data.cast, data.ph_no);
            }
        }
        printf("contact modifyed successfully\n");
        fclose(box);
        fclose(temp);
        remove("CONTACT");
        rename("TEMP", "CONTACT");
        getchar();//buffer
        getchar();//hold
        body();
    }
}
void byee()
{
    exit(0);
}

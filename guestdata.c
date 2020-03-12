#include<stdio.h>
#include<string.h>   // To input string data
#include<stdlib.h>
#include<windows.h>
 
// Function Declaration
 
void menu();
void add();
void deleteg();
void search();
void edit();
void quit();
void byname();
void byall();
 
struct guest                // Structure For Guest Data
{
    char name[20],address[20],sex[10],contact[10],level[5];
    int age;
}gue;
 
FILE *fpt,*fpo;
 
int main()           // Main Function To Run Program In Execution Part
{
    menu();
}
 
 // End Of Main Function
 
 void menu()
 {
    system("cls");
    int ch;
    printf("\n\t\t\t\t\t\t  Welcome To Guest Record System  ");
    printf("\n\n\n\t\t\t  1.Add record   ");
    printf("\n\t\t\t  2.Delete record  ");
    printf("\n\t\t\t  3.Search record  ");
    printf("\n\t\t\t  4.Edit Record   ");
    printf("\n\t\t\t  5.Exit Program   ");
    printf("\n\n\n\n\n \t\t\t Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            add();
            menu();
            break;
        case 2:
            deleteg();
            menu();
            break;
        case 3:
            search();
            menu();
            break;
        case 4:
            edit();
            menu();
            break;
        case 5:
            quit();
            break;
        default:
        menu();
    }
}
 
// End Of Menu Function
 
void quit()          // Exit Function To End The Program
{
            system("cls");
            printf("\n\t\t Guest Date File Project");
            printf("\n \t\t\t   BY  ");
            printf("\n \t\t\t ~~~~~~ ");
            printf("\n \t\t\t| K_D  |");
            printf("\n \t\t\t ~~~~~~ ");
			Sleep(500);
            exit(0);
}
 
// End Of Exit Function
 
void add()    // Addguest function to write records in the file
{
    system("cls");
    printf("\n\t\t\t \t\t\t Enter Guest Data \t\t  ");
    printf("\n\t\t\t ");
    fpt=fopen("guest.txt","a+");
    printf("\n\n\n\t\t Name : ");
    scanf("%s",gue.name);
    printf("\n\t\t Age : ");
    scanf("%d",&gue.age);
    printf("\n\t\t Sex : ");
    scanf("%s",gue.sex);
    printf("\n\t\t Address : ");
    scanf("%s",gue.address);
    printf("\n\t\t Contact : ");
    scanf("%s",gue.contact);
    printf("\n\t\t Level : ");
    scanf("%s",gue.level);
    fwrite(&gue,sizeof(gue),1,fpt);
    printf("\n\n\n \t\t\t\t Guest Record Written In File Successfully ...");
    fclose(fpt);
    Sleep(400);
    menu();
}
// End Of Addguest function
 
void deleteg()          // Deleteguest Function To Delete The Existing Data Of A Particular Guest       
{
    char naam[10],guest,sure;
    system("cls");
    printf("\n\t\t\t \t\t\t Delete Record Of A Guest  ");
    printf("\n");
    printf("\n\n\n\t\t\t\t Enter the Guest Name To Delete:");      // Data Search By Name
    scanf(" %s",&naam);
    fpt=fopen("guest.txt","r+");
    rewind(fpt);
    while(fread(&gue,sizeof(gue),1,fpt)==1)
        {
            if(strcmp(gue.name,naam)==0)
                {
                    printf("\n\t\t\t\t\t The Guest Record Is Available");
                    printf("\n\n\n \t\t\t Guest Name : %s ",gue.name);
                    printf("\n\t\t\t Guest level : %s",gue.level);
                    guest='n';
                }
        }
    if(guest!='n')
        {
            printf(" \n\n\n\t\t\t !!!! No record is found !!!!");
            Sleep(500);
            menu();
        }
    if(guest=='n')
        {
            printf("\n\n\n\t\t\t Are You Sure To Delete It?(Y/N):");
            scanf(" %c",&sure);
        }
    if(sure=='Y' || sure=='y')
    {
        printf("\n\n \t\t\t Entered Yes");
        fpo=fopen("guest2.txt","r+");  // Creating Temporary File to Copy Rest Data
        rewind(fpt);
        while(fread(&gue,sizeof(gue),1,fpt)==1)
            {
                if(strcmp(gue.name,naam)!=0)
                    {
                        fseek(fpo,0,SEEK_CUR);
                        fwrite(&gue,sizeof(gue),1,fpo);
                    }
            }
        fclose(fpo);
        fclose(fpt);
    	system("del /f guest.txt");
        //remove("guest.txt");
        system("ren guest2.txt guest.txt");
        //rename("guest2.txt","guest.txt");         //Copy All Item From Temporary File To fpt Except That We Want To Delete
        printf("\n\n\n\t\t\t The Guest Record Is Sucessfully Deleted");
    }
Sleep(500);
menu();
}
 
// End Of Deleteguest Function
 
void search()                      // Searchguest Function To Search Guest Data
{
system("cls");
int cr;
printf("\n\t\t\t ");
printf("\n\t\t\t  \t\t\t Search Guest Record  \t\t  ");
    printf("\n\n\n ");   
    printf("\n\t\t\t        Guest      ");
    printf("\n\t\t\t           1.By Name :        ");
    printf("\n\t\t\t           2.All At Time :   ");
    printf("\n\t\t\t ");
    printf("\n\n");
printf("\n\n\t\t\t\t Enter Your Choice : ");
scanf("%d",&cr);
fpt=fopen("guest.txt","r+");                    //open file for reading propose
rewind(fpt);                                          //move pointer at the begining of file
switch(cr)
    {
        case 1:
        {
            byname();
			Sleep(500);
			menu();
            break;
        }
       
        case 2:
        {
            byall();
			Sleep(500);
			menu();
            break;
        }
           
        default:
        printf("\n\n\n\t\t\t\t\t\t !!! Invalid Choice !!!");
        search();
        break;
    }
}
   
    // End Of Searchguest Function
   
void byname()    // Byname Function To Search Guest By Name
{
    char gname[20],guest;
            system("cls");
            printf("\n ");   
            printf("\n  \t\t\t Search Guest By Name");
            printf("\n ");
            printf("\n\n\n\t\t\tEnter The Guest Name : ");
            scanf("%s",gname);
            while(fread(&gue,sizeof(gue),1,fpt)==1)
            {
                if(strcmp(gue.name,gname)==0)
                {
                    printf("\n\n\t\t\t\t\t Guest Found ");
                    Sleep(500);
                    system("cls");
                    printf("\n\n\n\n\t\t\t\t  \t\t  Guest Detail  ");
                    printf("\n\t\t\t\t   Name : %s     ",gue.name);
                    printf("\n\t\t\t\t   Address : %s  ",gue.address);
                    printf("\n\t\t\t\t   Sex : %s      ",gue.sex);
                    printf("\n\t\t\t\t   Age : %d      ",gue.age);
                    printf("\n\t\t\t\t   Contact : %s  ",gue.contact); 
                    printf("\n\t\t\t\t   level : %s    ",gue.level);   
                    guest='f';
                }
            }
        if(guest!='f')  //checks whether conditiion enters inside loop or not
        {
            printf("\n\n\n\n\t\t\t\t !!!! No Record Found !!!! ");
        }
    }
 
     // End Of Byname Function
 
void byall()     // Byall Function To Search Guest Data All At Time
{
            system("cls"); 
			int i=1; 
            printf("\n  \t\t\t Search All At A Time \n\n\n\n\n");
            while(fread(&gue,sizeof(gue),1,fpt)==1)
            {
            		printf("%d",i);
                    printf("\n\t\t\t\t   Name : %s     ",gue.name);
                    printf("\n\t\t\t\t   Address : %s  ",gue.address); 
                    printf("\n\t\t\t\t   Sex : %s      ",gue.sex); 
                    printf("\n\t\t\t\t   Age : %d      ",gue.age);
                    printf("\n\t\t\t\t   Contact : %s  ",gue.contact); 
                    printf("\n\t\t\t\t   level : %s    ",gue.level);
                    printf("\n\n\n ");
                    i++;
                }
                Sleep(500);
}
 
            // End Of Byall Function
           
void edit()  // Editguest Function To Edit Guest Data
{
    system("cls");
    char gname[10];
    int d=0;
	printf("\n\t\t\t  \t\t\t Edit Guest Record ");
	printf("\n\\n\n\n ");
    printf("Enter Guest Name To Be Edited:");
    scanf("%s",gname);
    fpt=fopen("guest.txt","rb+");
while(fread(&gue,sizeof(gue),1,fpt)==1)
{
if(strcmp(gname,gue.name)==0)
    {
                    printf("\n\t\t\t\t   Name : %s     ",gue.name);
                    printf("\n\t\t\t\t   Address : %s  ",gue.address);
                    printf("\n\t\t\t\t   Sex : %s      ",gue.sex);
                    printf("\n\t\t\t\t   Age : %d      ",gue.age);
                    printf("\n\t\t\t\t   Contact : %s  ",gue.contact);
                    printf("\n\t\t\t\t   Level : %s    ",gue.level); 
 
printf("\n\n\n\t\t\t Enter New Name:"); scanf("%s",gue.name);
printf("\n\t\t\t Enter New Address:");scanf("%s",gue.address);
printf("\n\t\t\t Enter New Sex:");scanf("%s",gue.sex);
printf("\n\t\t\t Enter New Age:");scanf("%s",&gue.age);
printf("\n\t\t\t Enter New Contact:");scanf("%s",gue.contact);
printf("\n\t\t\t Enter New Level:");scanf("%s",gue.level);
printf("\n\n\n\t\t\t The Guest Record Is Modified");
fseek(fpt,ftell(fpt)-sizeof(gue),0);
fwrite(&gue,sizeof(gue),1,fpt);
fclose(fpt);
d=1;
}
if(d==0)
{
printf("\n\n\n \t\t\t\t !!!!!! No record found !!!!!!");
}
}
Sleep(500);
menu();
}
 
            // End Of Editguest Function

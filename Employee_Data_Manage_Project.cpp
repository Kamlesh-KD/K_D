#include<stdio.h>
#include<ctype.h>          // To stores input temporarily as resistor
#include<string.h>   // To input string data
#include<stdlib.h>
#include<windows.h>
 
// Function Declaration
 
void password();
void menu();
void addrec();
void deleterec();
void searchrec();
void editrec();
void quit();
void back();
void byname();
void byidentity();
 
struct employee                // Structure For Employee Data
{
    char name[20],address[20],sex[10],contact[10],identity[5],grade[5];
    int age,salary;
}emp;
 
FILE *fpt,*fpo;
 
int main()           // Main Function To Run Program In Execution Part
{
    password();
    menu();
}
 
 // End Of Main Function
 
void password()        // Password Function To Add Security In The Program
 {
    char password[]="K_D";
    char pass[10];
    printf("\n\n \t\t\t\t\t !!!!  Password Protected  !!!!");
    //sleep(500);
    system("cls");
    printf("\n\n \t\t\t\t\t !!!!  Password Protected  !!!!");
    //sleep(200);
    printf("\n\n\n \t\t Enter Password :  ");
    scanf("%s",pass);
    if(strcmp(pass,password)!=0)
    {
        main();
     }
 }
 
 // End Of Password Function
 
 void menu()
 {
    system("cls");
    int ch;
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2 Main Menu  \t\t\t \xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2 1.Add record \t\t \xB2\xB2 ");
    printf("\n\t\t\t \xB2\xB2 2.Delete record\t\t \xB2\xB2 ");
    printf("\n\t\t\t \xB2\xB2 3.Search record\t\t \xB2\xB2 ");
    printf("\n\t\t\t \xB2\xB2 4.Edit Record \t\t \xB2\xB2 ");
    printf("\n\t\t\t \xB2\xB2 5.Exit Program \t\t \xB2\xB2 ");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\n \t\t\t Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            addrec();
            menu();
            break;
        case 2:
            deleterec();
            menu();
            break;
        case 3:
            searchrec();
            menu();
            break;
        case 4:
            editrec();
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
            printf("\n\t\t Employee Date File Project");
            printf("\n \t\t\t   BY  ");
            printf("\n \t\t\t ~~~~~~ ");
            printf("\n \t\t\t| K_D  |");
            printf("\n \t\t\t ~~~~~~ ");
            getchar();
            exit(0);
}
 
// End Of Exit Function
 
void back()      // Back Function To Return The Program To Main Menu
{
    menu();
}
 
// End Of Back Function
 
void addrec()    // Addrec function to write records in the file
{
    int cs;
    system("cls");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2\t\t\t Enter The Data \t\t  \xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    fpt=fopen("employee.txt","a+");
    printf("\n\n\n\t\t Name : ");
    scanf("%s",emp.name);
    printf("\n\t\t Age : ");
    scanf("%d",&emp.age);
    printf("\n\t\t Sex : ");
    scanf("%s",emp.sex);
    printf("\n\t\t Address : ");
    scanf("%s",emp.address);
    printf("\n\t\t Contact : ");
    scanf("%s",emp.contact);
    printf("\n\t\t Identity : ");
    scanf("%s",emp.identity);
    printf("\n\t\t Grade : ");
    scanf("%s",emp.grade);
    printf("\n\t\t Salary : ");
    scanf("%d",&emp.salary);
    fwrite(&emp,sizeof(emp),1,fpt);
    printf("\n\n\n \t\t\t\t Record Written In File Successfully ...");
    fclose(fpt);
   
    //sleep(500);
    printf("\n\n\n\t\t\t\t\t 1. Main Menu");
    printf("\n\t\t\t\t\t~ Other To Exit");
            scanf("%d",&cs);
            if(cs==1)
            {
                menu();
            }
            else
            {
                quit();
            }
}
 
// End Of Addrec function
 
void deleterec()          // Deleterec Function To Delete The Existing Data Of A Particular Employee       
{
    int cs;
    char id[10],employe,sure;
    system("cls");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2\t\t\t Delete Record  \t\t  \xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t\t Enter the Employee Identity to  delete:");      // Data Search By Identity
    scanf(" %s",&id);
    fpt=fopen("employee.txt","r+");
    rewind(fpt);
    while(fread(&emp,sizeof(emp),1,fpt)==1)
        {
            if(strcmp(emp.identity,id)==0)
                {
                    printf("\n\t\t\t\t\t The Employee Record Is Available");
                    printf("\n\n\n \t\t\t Employee Name : %s ",emp.name);
                    printf("\n\t\t\t Employee Grade : %s",emp.grade);
                    employe='n';
                }
        }
    if(employe!='n')
        {
            printf(" \n\n\n\t\t\t !!!! No record is found !!!!");
            menu();
        }
    if(employe=='n')
        {
            printf("\n\n\n\t\t\t Are You Sure To Delete It?(Y/N):");
            scanf(" %c",&sure);
        }
    if(sure=='Y' || sure=='y')
    {
        printf("\n\n \t\t\t Entered Yes");
        fpo=fopen("employee2.txt","a+");  // Creating Temporary File to Copy Rest Data
        rewind(fpt);
        while(fread(&emp,sizeof(emp),1,fpt)==1)
            {
                if(strcmp(emp.identity,id)!=0)
                    {
                        //fseek(fpo,0,SEEK_CUR);
                        fwrite(&emp,sizeof(emp),1,fpo);
                    }
            }
        fclose(fpo);
        fclose(fpt);
        //system("cd ")
    	//system("del /f employee.txt");
        remove("employee.txt");
        //system("ren employee2.txt employee.txt");
        rename("employee2.txt","employee.txt");         //Copy All Item From Temporary File To fpt Except That We Want To Delete
        printf("\n\n\n\t\t\t The Record Is Sucessfully Deleted");
    }
    printf("\n\n\n\t\t\t\t\t 1. Main Menu");
    printf("\n\t\t\t\t\t~ Other To Exit");
    scanf("%d",&cs);
    if(cs==1)
    {
        menu();
    }
    else
    {
        quit();
    }
}
 
// End Of Deleterec Function
 
void searchrec()                      // Searchrec Function To Search Employee Data
{
system("cls");
int cr;
int cs;
printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\t\t\t \xB2\xB2\xB2 \t\t\t Search Record  \t\t  \xB2\xB2\xB2");
printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");   
    printf("\n\t\t\t \xB2\xB2\xB2       Search Employee      \xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2          1.By Name :       \xB2\xB2\xB2 ");
    printf("\n\t\t\t \xB2\xB2\xB2          2.By Identity :   \xB2\xB2\xB2");
    printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
printf("\n\n\t\t\t\t Enter Your Choice : ");
scanf("%d",&cr);
fpt=fopen("employee.txt","r+");                    //open file for reading propose
rewind(fpt);                                          //move pointer at the begining of file
switch(cr)
    {
        case 1:
        {
            byname();
    printf("\n\n\n\t\t\t\t\t 1. Main Menu");
    printf("\n\t\t\t\t\t~ Other To Exit");
            scanf("%d",&cs);
            if(cs==1)
            {
                menu();
            }
            else
             {
                quit();
            }
            break;
        }
       
        case 2:
        {
            byidentity();
    printf("\n\n\n\t\t\t\t\t 1. Main Menu");
    printf("\n\t\t\t\t\t~ Other To Exit");
            scanf("%d",&cs);
            if(cs==1)
            {
                menu();
            }
            else
             {
                quit();
            }
            break;
        }
           
        default:
        printf("\n\n\n\t\t\t\t\t\t !!! Invalid Choice !!!");
        searchrec();
        break;
    }
}
   
    // End Of Searchrec Function
   
void byname()    // Byname Function To Search Employee By Name
{
    char ename[20],employe;
    int i;
            system("cls");
            printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");   
            printf("\n \xB2\xB2\xB2 \t\t\t Search By Name \t\t\xB2\xB2\xB2");
            printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\n\n\n\t\t\tEnter The Employee Name : ");
            scanf("%s",ename);
            while(fread(&emp,sizeof(emp),1,fpt)==1)
            {
                if(strcmp(emp.name,ename)==0)
                {
                    printf("\n\n\t\t\t\t\t Employee Found ");
                    Sleep(500);
                    system("cls");
                    printf("\n\n\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2 \t\t  Employee Detail \t   \xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Name : %s     ",emp.name); for(i=1;i<=(25-strlen(emp.name));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Address : %s  ",emp.address); for(i=1;i<=(25-strlen(emp.address));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Sex : %s      ",emp.sex); for(i=1;i<=(25-strlen(emp.sex));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Age : %d      ",emp.age); for(i=1;i<=23;i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Contact : %s  ",emp.contact); for(i=1;i<=(25-strlen(emp.contact));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Identity : %s ",emp.identity); for(i=1;i<=(25-strlen(emp.identity));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Grade : %s    ",emp.grade); for(i=1;i<=(25-strlen(emp.grade));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Salary : %d",emp.salary);    for(i=1;i<=23;i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    employe='f';
                }
            }
        if(employe!='f')  //checks whether conditiion enters inside loop or not
        {
            printf("\n\n\n\n\t\t\t\t !!!! No Record Found !!!! ");
        }
    }
 
     // End Of Byname Function
 
void byidentity()     // Byidentity Function To Search Employee Data According To Identity Number
{
    char eidentity[20],employe;
    int i;
            system("cls");
            printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");   
            printf("\n \xB2\xB2\xB2 \t\t\t Search By Identity \t\t\xB2\xB2\xB2");
            printf("\n \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\n\n\n\t\t\t\t Enter The Employee Identity : ");
            scanf("%s",eidentity);
            while(fread(&emp,sizeof(emp),1,fpt)==1)
            {
                if(strcmp(emp.identity,eidentity)==0)
                {
                    printf("\n Employee Found ");
                    //sleep(500);
                    system("cls");
                    printf("\n\n\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2 \t\t  Employee Detail \t   \xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Name : %s     ",emp.name); for(i=1;i<=(25-strlen(emp.name));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Address : %s  ",emp.address); for(i=1;i<=(25-strlen(emp.address));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Sex : %s      ",emp.sex); for(i=1;i<=(25-strlen(emp.sex));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Age : %d      ",emp.age); for(i=1;i<=23;i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Contact : %s  ",emp.contact); for(i=1;i<=(25-strlen(emp.contact));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Identity : %s ",emp.identity); for(i=1;i<=(25-strlen(emp.identity));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Grade : %s    ",emp.grade); for(i=1;i<=(25-strlen(emp.grade));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Salary : %d",emp.salary);    for(i=1;i<=23;i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    employe='f';
                }
            }
        if(employe!='f')  
        {
            printf("\n\n\n\n\t\t\t\t !!!! No Record Found !!! ");
        }
}
 
            // End Of Byidentity Function
           
void editrec(void)  // Editrec Function To Edit Employee Data
{
    int cs,i;
    system("cls");
    char eid[10];
    int d;
printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n\t\t\t \xB2\xB2\xB2 \t\t\t Edit Record    \t\t  \xB2\xB2\xB2");
printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("Enter Employee Identity to be edited:");
    scanf("%s",eid);
    fpt=fopen("employee.txt","rb+");
while(fread(&emp,sizeof(emp),1,fpt)==1)
{
if(strcmp(eid,emp.identity)==0)
    {
                    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Name : %s     ",emp.name); for(i=1;i<=(25-strlen(emp.name));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Address : %s  ",emp.address); for(i=1;i<=(25-strlen(emp.address));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Sex : %s      ",emp.sex); for(i=1;i<=(25-strlen(emp.sex));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Age : %d      ",emp.age); for(i=1;i<=23;i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Contact : %s  ",emp.contact); for(i=1;i<=(25-strlen(emp.contact));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Identity : %s ",emp.identity); for(i=1;i<=(25-strlen(emp.identity));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Grade : %s    ",emp.grade); for(i=1;i<=(25-strlen(emp.grade));i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2  Salary : %d",emp.salary);    for(i=1;i<=23;i++) {printf(" ");} printf("\xB2\xB2\xB2");
                    printf("\n\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
 
printf("\n\n\n\t\t\t Enter New Name:"); scanf("%s",emp.name);
printf("\n\t\t\t Enter New Address:");scanf("%s",emp.address);
printf("\n\t\t\t Enter New Sex:");scanf("%s",emp.sex);
printf("\n\t\t\t Enter New Age:");scanf("%s",&emp.age);
printf("\n\t\t\t Enter New Contact:");scanf("%s",emp.contact);
printf("\n\t\t\t Enter New Identity:");scanf("%s",emp.identity);
printf("\n\t\t\t Enter New Grade:");scanf("%s",emp.grade);
printf("\n\t\t\t Enter New Salary:");scanf("%d",&emp.salary);
printf("\n\n\n\t\t\t The record is modified");
fseek(fpt,ftell(fpt)-sizeof(emp),0);
fwrite(&emp,sizeof(emp),1,fpt);
fclose(fpt);
d=1;
}
if(d==0)
{
printf("\n\n\n \t\t\t\t !!!!!! No record found !!!!!!");
}
}
    printf("\n\n\n\t\t\t\t\t 1. Main Menu");
    printf("\n\t\t\t\t\t~ Other To Exit");
            scanf("%d",&cs);
            if(cs==1)
            {
                menu();
            }
            else
             {
                quit();
            }
}
 
            // End Of Editrec Function

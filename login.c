#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct tickets
{
    int ticket;
    int price;
};
void signin();
void signup();
void menu();
int main() 
{
    int sign,s;
    s:
    printf("\n 1.sign in  \n 2.sign up");
    scanf("%d",&sign);
    if(sign==1)
    {
     signin();
 	}
 	else if(sign==2)
 	{
 		signup();
	 }
	 else
	 {
	 	printf("\n Invalid choice");
	 	Sleep(500);
	 	goto s;
	 }
}
void signup()
{
	struct sign
	{
		char name[20],username[20],password[20],contact[10];
	}up;
	system("cls");
	printf("\n Enter Name:");
	scanf("%s",up.name);
	printf("\n Enter contact:");
	scanf("%s",up.contact);
	printf("\n Enter username:");
	scanf("%s",up.username);
	printf("\n Enter Password:");
	scanf("%s",up.password);
	FILE *bot;
    bot=fopen("users.txt","a+");
    fprintf(bot,"\t %s \t %s \t %s \t %s \n",up.name,up.contact,up.username,up.password);
    fclose(bot);
    signin();
}

void signin()
{
	system("cls");
	int ud=0;
	char user[20],pw[20];
	printf("\nEnter username: ");
    scanf("%s", &user);
    printf("\nEnter password: ");
    scanf("%s", &pw);
    bot=fopen("users.txt","r+");
    rewind(bot);
    while(fread(&up,sizeof(up),1,bot)==1)
    {
    	if(strcmp(up.username,user)==0 && strcmp(up.password,pw)==0)
    	{
    		ud++;
		}
	}
	if(ud==1)
	{
		menu();
	}
	else
	{
		printf("\n Invalid Username/Password");
		Sleep(500);
		signin();
	}
}

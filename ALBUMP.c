#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void welcome();
void login();
void menu();
void addnewalbum();
void editalbum();
void viewalbum();
void searchalbum();

struct Album
{
	char year[20];
	char name[30];
	char artist[30];
	char price[20];
}s;

int main()
{
	welcome();
	login();
}

void welcome()
{

	int i;

	
	time_t t;
	time(&t);
	
	system("COLOR 4E");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n                                            WELCOME USER!                        ");
	printf("\n                           _________________________________________________     ");
	printf("\n                          :                                                 :     ");
	printf("\n                          |                                                 |     ");
	printf("\n                          :    ********ALBUM MANAGEMENT SYSTEM*******       :     ");
	printf("\n                          |                                                 |     ");
	printf("\n                          :                                                 :     ");
	printf("\n                          :                                                 |     ");
	printf("\n                          |                                                 :     ");
	printf("\n                          :                                                 |     ");
	printf("\n                          |  Press-ENTER                                    :     ");
	printf("\n                          :                                                 |     ");
	printf("\n                          |_________________________________________________:     ");
	printf("\n\n");
	

    printf("\n\t\t\t\t\t\t\t\tCurrent date and time : %s",ctime(&t));
		
	
	getchar();
	system("cls");



}

void login()
{	
	system("cls");
	char name[20];
	char pass[20];
	char Username[20]="Parul";
	char Password[20]="pkrt";
	int i;
	
	
	printf("\n");
	printf("\n");
	printf("\n"); 
	printf("               -------- ALBUM MANAGEMENT SYTEM---------                          ");
	printf("\n                                                                               ");
	printf("\n                             Please-LOGIN                                      ");
	printf("\n                                                                               ");
	printf("\nUsername :  ");
	scanf(" %s", name    );
	printf("\n                                                                               ");
	printf("\nPassword :  ");
	scanf(" %s", pass    );
	
	
	if (strcmp(name,Username) == 0 && strcmp(pass,Password) == 0)
	
	{
		system("cls");
		printf("\n");
		for(i=0;i<80;i++)
		printf("_");
		printf("\n");
		printf("\n"); 
		printf("                         WELCOME USER!                                                ");
		printf("\n                                                                                    ");
		printf("\n                    You are Logged in.                                                    ");
		printf("\n                                                                                           ");
		printf("\n                                                                                   ");
		printf("\n                                                                                         ");
		printf("\n  Press any key to Continue...                                                      ");
		printf("\n\n");
		for(i=0;i<80;i++)
		printf("_");
		getch();
		system("cls");
	}
	
	else
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                                        OOPS!                                              ");
		printf("\n                   The Username or the Password is Incorrect.                            ");
		printf("\n                                                                                         ");
		printf("\n                                                         Please Try Again !               ");
		getch();
		system("cls");
		login();
	}

void menu();
{
	time_t t;
	time(&t);
	int Password;
	char choice;
	system("cls");
	while(1)
	{
		system("COLOR 09");
		system("cls");
		printf("\n");
	
		printf("\n");
		printf("\n                   _________ALBUM MANAGEMENT SYSTEM_______                  ");
		printf("\n");
		printf("\n                                   MENU                                      ");
		printf("\n\n                       Press  1 :  ADD NEW ALBUM                          ");
		printf("\n\n                       Press  2 :  EDIT EXISTING ALBUM                     ");
		printf("\n\n                       Press  3 :  VIEW ALBUMS                             ");
		printf("\n\n                       Press  4 :  SEARCH ALBUMS                           ");
		printf("\n\n                       Press  5 :  Exit                                    ");
		printf("\n\n");
		for(i=0;i<125;i++)
		printf("_");
	    printf("\n\t\t\t\t\t\t\t\t\tCurrent date and time : %s",ctime(&t));
	    for(i=0;i<125;i++)
		printf("_");
		
		choice=getch();
	
		switch(choice)
		
		{
			case '1':
				addnewalbum();
				break;
			case '2':
				editalbum();
				break;
			case '3':
				viewalbum();
				break;
                        case '4':
				searchalbum();
				break;
			
			case '5':
				system("cls");
				printf("\n\n                      :-)  THANK YOU !!                                     ");
				Sleep(2000);
				exit(0);
				break;
			default:
 				system("cls");
				printf("INVALID KEYWORD. PLEASE ENTER A VALID KEYWORD TO CHOOSE.                        ");
				printf("\n\t\t\t\t\t\t\tPress any key to continue..........                                           ");
				getch();
		}
	}
}
}

void addnewalbum()
{
	system("COLOR E0");
		system("cls");
	FILE *Album;
	
	Album=fopen("Album.txt","a");
	if(Album==0)
	{
		Album=fopen("Album.txt","w");
		system("cls");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\nEnter Album Name: ");
		fflush(stdin);
		scanf("%[^\n]",&s.name);	
		printf("\nEnter Album Year: ");
		scanf("%s",&s.year);
		printf("\nEnter Album Artist: ");
		fflush(stdin);
		scanf("%[^\n]",&s.artist);
		printf("\nEnter Album Price: ");
		scanf("%s",&s.price);
		fwrite(&s,sizeof(s),1,Album);
		fflush(stdin);
		system("cls");
		
		printf("\n\n");
		printf("    Album is Successfully recorded. \n\n");
		printf("\n \t\t\t\t\t    * Press any Key to Continue ");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                 Press ESC to return back to < MAIN MENU >");
		
			break;
	}
	fclose(Album);
}

void editalbum()
{
	system("COLOR 5F");
		system("cls");
	FILE *Album;
	
	char year[20];
	long int size=sizeof(s);
	if((Album=fopen("Album.txt","r+"))==NULL)exit(0);
	system("cls");
	printf("Enter the existing Album Year to EDIT :");
	scanf("%[^\n]",year);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,Album)==1)
	{
		if(strcmp(s.year,year)==00)
		{
			system("cls");
			printf("\n Enter the new Album Year: ");
			scanf("%s",&s.year);
			printf("\n Enter the new Album Name: ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf("\n Enter the new Album Artist: ");
			fflush(stdin);
			scanf("%[^\n]",&s.artist);
			printf("\n Enter the new Album Price: ");
			scanf("%s",&s.price);
			fseek(Album,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,Album);
			fflush(stdin);
			system("cls");
			
			
			printf("\n\n");
			printf("   Album is Successfully edited. \n\n");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                 Press ESC to return back to < MAIN MENU >");
			
         	break;
		}
	}
	fclose(Album);	
}

void viewalbum()
{
	system("COLOR C0");
		system("cls");
	FILE *Album;
	int i,j;
	if((Album=fopen("Album.txt","r"))==NULL)
		exit(0);
	system("cls");
	printf("Album Year\tAlbum Name\tAlbum Artist\tAlbum Price\n");
	for(i=0;i<70;i++)
		printf("_");
	
	while(fread(&s,sizeof(s),1,Album)==1)
	{
		printf("\n%s\t\t%s\t\t%s\t\tRs-%s/-",s.year,s.name,s.artist,s.price);
	}
	printf("\n");
	for(i=0;i<70;i++)
		printf("_");

fclose(Album);
getch();
}


void searchalbum()
{
	system("COLOR 37");
		system("cls");
	FILE *Album;
	char year[20];
	int flag=1;
	Album=fopen("Album.txt","r+");
	if(Album==0)
		exit(0);
	fflush(stdin);
	system("cls");
	printf("SEARCH ");
	printf("\nEnter Album Year :");
	scanf("%s", year);
	while(fread(&s,sizeof(s),1,Album)==1)
	{
		if(strcmp(s.year,year)==0)
		{	
			system("cls");
			printf("SEARCH RESULTS  ");
			printf("\n-----------------------------------");
			printf("\n\n\nYear: %s\n\nName: %s\n\nArtist: %s\n\nPrice: Rs.%s\n-----------------------------------",s.year,s.name,s.artist,s.price);
			printf("\n\n\n\n\n\n\n\n\n\nPress any key to Return Back to < MAIN MENU >");
			flag=0;
			break;
		}
		else if(flag==1)
		{	system("cls");
			printf("OOPS! No Results Found.");
			printf("Please Try Again. ");
		}
	}
	getch();
	fclose(Album);
}










#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ADMIN{
	char name[5][20];
	char roll[5][11];
	char states[28][20];
	long vaccine;
}Admin;
typedef struct USER{
	char state[20];
	char uname[20];
	char adhno[13];
	int dose;
	char dofd[12];
	char dosd[12];
	char pword[20];
}User;
Admin ad={ .name={"GULAFSHAN",
                        "KAUSHIK",
                        "PUSHKAR",
                        "ROHAN",
                        "SAIF"},

         .roll={"CSE099",
                    "CSE100",
                    "CSE101",
                    "CSE102",
                    "CSE103"},
          .states={"Andhra Pradesh","Arunachal Pradesh","Assam","Bihar","Chhattisgarh","Goa","Gujrat","Haryana","Himachal Pradesh","Jharkhand","Karnataka","Kerala","MP","Maharashtra","Manipur","Meghalaya","Mizoram","Odisha","Punjab","Rajasthan","Sikkim","TN","Telangana","Tripura","UP","Uttarakhand","WB"},
          .vaccine=290000
};

User u={"","","",0,"","",""};

char *getpas()
  { static char ch[20];
    int i=0;
    ch[i]='a';
    fflush(stdin);
    while(isalnum(ch[i-1])||ch[0]=='a')
    { ch[i]=getch();
      if(isalnum(ch[i]))
       printf("*");
       else
       break;
       i++;
    }
    ch[i]='\0';
    return ch;
  }
void adminopt();
void show();
void setdate();
int check(char aa[],char pp[20])
{ FILE * fp=fopen("USER.bin","rb+");
   rewind(fp);
   while(fread(&u,sizeof(User),1,fp)!=0)
    {  if((strcmp(aa,u.adhno)==0)&&(strcmp(pp,u.pword)==0))
        { fclose(fp);return 1;}
        if((strcmp(aa,u.adhno)==0))
          {fclose(fp);return 1;}
    }
    return 0;
}


void useropt()
{ char a;
   char adn[13],pa[20];
  FILE * fp;
  fp = fopen("USER.bin","rb+");
    if(fp == NULL)
    {
        fp = fopen("USER.bin","wb+");
        if(fp == NULL)
        {
            printf("Cannot open file");
            exit(1);
        }
    }


  int ch;
  while(1)
  {a='y';
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t1.NEW USER\n\t\t\t\t\t\t\t\t\t\t\t2.EXISTING USER\n");
  printf("\t\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE :-");
  scanf("%d",&ch);
  fflush(stdin);
  switch(ch)
  { case 1:system("cls");
                 fseek(fp,0,SEEK_END);
                do
                {
                  char ach[12];
                  int i;
                  printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t ENTER AADHAR NO. :-");
                  scanf("%s",ach);
                  if(check(ach,"dfg")==0)
                  {
                  strcpy(u.adhno,ach);
                  printf("\t\t\t\t\t\t\t\t\t\t\t ENTER NAME :-");
                  scanf("%s",u.uname);
                  printf("\t\t\t\t\t\t\t\t\t\t\t CHOOSE STATE \n");
                  for(i=0;i<27;i++)
                    printf("\t\t\t\t\t\t\t\t\t\t\t%d . %s\n",i+1,ad.states[i]);
                  scanf("\t\t\t\t\t\t\t\t\t\t\t %d",&i);
                  strcpy(u.state,ad.states[i-1]);
                  printf("\t\t\t\t\t\t\t\t\t\t\t ENTER PASSWORD :-");
                  strcpy(u.pword,getpas());
                  show();
                  printf("\t\t\t\t\t\t\t\t\t\t\t 'y for confirm else 'n' :-");
                  scanf("%c",&a);
                  if(a=='n')
                  printf("\t\t\t\t\t\t\t\t\t\t\t re-enter your data");
                  }
                  else
                   {printf("\t\t\t\t\t\t\t\t\t\t\tSORRY! RECORD EXIST\n");getch();}
                }while(a=='n');
                fwrite(&u,sizeof(User),1,fp);
                printf("\t\t\t\t\t\t\t\t\t\t\tREGISTERED SUCCESSFULLY !!\n");
                getch();
                fflush(stdin);
      break;
      case 2:system("cls");
                  fseek(fp,0,SEEK_SET);
                  printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tENTER AADHAR NO.");
                  scanf("\t\t\t\t\t\t\t\t\t\t\t%s",adn);
                  printf("\t\t\t\t\t\t\t\t\t\t\tENTER PASSWORD :-");
                  strcpy(pa,getpas());
                  if(check(adn,pa)!=0)
                    show();
                  else
                    printf("\t\t\t\t\t\t\t\t\t\t\tENTER VALID AADHAR NO. & PASSWORD");
                   fflush(stdin);
                   getch();
        case 36: break;
        default: printf("ENTER CORRECT CHOICE\n");
  }
  fclose(fp);
  }
}


int main()
{ int ch;
  char pass[20]="abcdef",c='y';
 // char cp[20];


	system("COLOR 0E");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t   WELCOME TO E-VACCINATION SYSTEM  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t        WINNING OVER COVID-19\n ");
	printf("\t\t\t\t\t\t\t\t\t\t\t   TOGETHER WE CAN DEFEAT COVID-19\n ");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t What should you do after vaccination?\n\n ");
	printf("\t\t\t\t\t\t\t\tHere are a few precautions of COVID-19 that all responsible citizens should follow even after vaccination-        \n\n ");
    printf("\t\t\t\t\t\t\t\t1.Continue to maintain social distancing and avoid crowded places.\n ");
	printf("\t\t\t\t\t\t\t\t2. Please wear a mask and sanitize your hands. .\n ");
	printf("\t\t\t\t\t\t\t\t3.Encourage and help others to register for the vaccination.\n\n\n\n ");
	printf("\t\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE......\n");


	getch();
	system("cls");


 do
 {system("cls");

  printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t 1.ADMIN LOGIN");
  printf("\n\t\t\t\t\t\t\t\t\t\t\t 2.USER LOGIN\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t ENTER YOUR CHOICE 1 OR 2\n");
  scanf("%d",&ch);
  fflush(stdin);
  switch(ch)
  { case 1:system("cls");
                while(c=='y')
                {
                 printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t ENTER PASSWORD :");
                 if((strcmp(pass,getpas())==0))
                   adminopt();
                 else
                  printf("\t\t\t\t\t\t\t\t\t\t\t ENTER CORRECT PASSWORD :");
                 printf("to continue enter 'y' else 'n' ");
                fflush(stdin);
                scanf("%c",&c);
                }
      break;
      case 2:
                  useropt();
      break;
      case 36: exit(0);
     default: printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tENTER CORRECT CHOICE\n");

  }
  }while(1);
  return 0;
  }





 void adminopt()
 {
 int c,k=0;
 char adh[13],a='n';
 FILE * fp;
 fp = fopen("USER.bin","rb+");
    if(fp == NULL)
    {
        fp = fopen("USER.bin","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }

 do
 { system("cls");
   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t 1.LIST OF ADMINS\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t 2.LIST OF USERS\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t 3.GIVE VACCINE\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t 4.DELETE USER DATA\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t 5.SEARCH USER\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t 6.ASSIGN DATES\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t 7.EXIT\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t ENTER YOUR CHOICE\n");
   scanf("%d",&c);
   fflush(stdin);

   switch(c)
   {  case 1:
                   system("cls");
                   for(int i=0;i<5;i++)
                   printf("\n\t\t\t\t\t\t\t\t\t\t\t%s-%s\n",ad.name[i],ad.roll[i]);
                   getch();
       break;
       case 2:
                    system("cls");
                    rewind(fp);
                    while(fread(&u,sizeof(User),1,fp)!=0)
                       show();
                    getch();
                     fflush(stdin);
       break;
       case 3:
                   system("cls");
                   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t  ENTER USER'S AADHAR NUMBER :-");
                   scanf("%s",adh);
                   rewind(fp);
                   while(fread(&u,sizeof(User),1,fp)!=0)
                     {
                     	if(strcmp(u.adhno,adh)==0)
                     	  { show();
                     	     printf("GIVE DOSE %d\n",u.dose+1);
                     	     u.dose+=1;
                     	     k=1;
                     	     fseek(fp,-sizeof(User),SEEK_CUR);
                     	     fwrite(&u,sizeof(User),1,fp);
                     	     break;
                     	  }
                     	if(k==0)
                     	 printf("CHECK AADHAR NO.\n");
                     }
                     fflush(stdin);
       break;
       case 4:
                   system("cls");
                   printf("ENTER USER AADHAR NO.\n");
                   scanf("%s",adh);
                   rewind(fp);
                   while(fread(&u,sizeof(User),1,fp)!=0)
                     {   FILE *ft=fopen("TEMP.DAT","wb");
                     	if(strcmp(u.adhno,adh)!=0)
                     	  {
                     	  	fwrite(&u,sizeof(User),1,ft);
                     	  }

                     fclose(fp);
                     fclose(ft);
                     remove("USER.DAT");
                     rename("TEMP.DAT","USER.DAT");
                     fp=fopen("USER.DAT","rb+");
                     }
                     fflush(stdin);

       break;
       case 5:
                   system("cls");
                   rewind(fp);
                   printf("ENTER USER AADHAR NO.\n");
                   scanf("%s",adh);
                   while(fread(&u,sizeof(User),1,fp)!=0)
                     {
                     	if(strcmp(u.adhno,adh)==0)
                     	  show();
                     }
                     fflush(stdin);
       break;
       case 6:
                   system("cls");
                   fflush(stdin);
                   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t ENTER AADHAR NO. TO ALLOT THE DATE :-");
                   scanf("%s",adh);
                   rewind(fp);
                   while(fread(&u,sizeof(User),1,fp)!=0)
                     {
                     	if(strcmp(u.adhno,adh)==0)
                     	{  setdate();
                     	  fseek(fp,-sizeof(User),SEEK_CUR);
                     	  fwrite(&u,sizeof(User),1,fp);
                     	  show(u);
                     	  getch();
                     	 break;
                     	 }
                     }
                     fflush(stdin);
       break;
       case 7: a='y';
       break;
       default: printf("\t\t\t\t\t\t\t\t\t\t\t  RE-ENTER YOUR CHOICE\n");
   }
    }while(a=='n'); fclose(fp);
}
void show()
{
   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t  AADHAR NO. :%s\n",u.adhno);
   printf("\t\t\t\t\t\t\t\t\t\t\t  NAME: %s\n",u.uname);
   printf("\t\t\t\t\t\t\t\t\t\t\t  STATE : %s\n",u.state);
   printf("\t\t\t\t\t\t\t\t\t\t\t  DATE OF 1ST DOSE : %s\n",u.dofd);
   printf("\t\t\t\t\t\t\t\t\t\t\t  DATE OF 2ND DOSE : %s\n",u.dosd);
   printf("\t\t\t\t\t\t\t\t\t\t\t  PASSWORD : %s\n",u.pword);
   printf("\t\t\t\t\t\t\t\t\t\t\t  DOSE TAKEN : %d\n\n",u.dose);
}
void setdate()
{
   system("cls");
   struct tm d={0};
   char sd[12];
   time_t t=time(NULL);
   int dd,mm,yyyy;
   d=*localtime(&t);
   strftime(sd,12,"%d-%m-%Y",&d);
   printf(" TODAY'S DATE : %s\n",sd);
   printf(" ALLOT DATE IN DD, MM, YYYY FORMAT :-");
   scanf("%d%d%d",&dd,&mm,&yyyy);
   d.tm_mday=dd;
   d.tm_mon=mm-1;
   d.tm_year=yyyy-1900;
   strftime(sd,12,"%d-%m-%Y",&d);
   strcpy(u.dofd,sd);
   d.tm_mday+=30;
   t=mktime(&d);
   d=*gmtime(&t);
   strftime(sd,12,"%d-%m-%Y",&d);
   strcpy(u.dosd,sd);
   fflush(stdin);
}







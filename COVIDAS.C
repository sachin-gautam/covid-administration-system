#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>


void choice_page1(void);
void choice_page2(void);
void choice_page3(void);
void choice_page4(void);
void login_input(void);
void login_chk(char[],char[]);
void project_info(void);
void logo(void);
void project_name();
void view_precord(void);
void view_brecord(void);
void p_entry(void);
void b_entry(void);
void p_edit(void);
void b_edit(void);
void p_delete(void);
void add_staff(void);
void change_unamepass(void);
void stat_page(void);
void search_agegroup(void);
void view_agegroup(int,int);
void view_vacrecord();
void view_unvacrecord();
void b_display();
void view_staff();
void login_change_input(int);
void login_change_doctor(char[],char[]);
void login_change_mstaff(char[],char[]);
void login_change_admin(char[],char[]);
void beds(void);
void fill(int,int);
void numbers();
void id_chk(int);
void id_chk_edit(int) ;
void staff_del();

struct admin
{
   char uname[21];
   char pass[21];
}adm;

struct managing_staff
{
   char uname[21];
   char pass[21];
}mstaff;

struct doctor
{
   char uname[21];
   char pass[21];
}doc;

struct patient
{
   char name[40];
   int age;
   char sex[20];
   int id;
   char address[40];
   char contact[15];
   char v_status[4];
   char v_name[30];
   int ward_number;
   int bed_number;
   char adm_date[15];
}pat;

struct staff
{
   char name[50];
   char position[60];
   int year;
   char address[100];
   char contact[15];
}stf;

struct ward
{
  int b1;
  int b2;
  int b3;
  int b4;
  int b5;
  int b6;
  int b7;
  int b8;
  int b9;
  int b10;
  int b11;
  int b12;
  int b13;
  int b14;
  int b15;
};
void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
	system("COLOR 0A");
	setcolor(11);
	project_name();
	choice_page1();
	closegraph();
}
void project_name()
{
	setcolor(11);
	settextstyle(0,0,2);
	outtextxy(105,35,"COVID - ADMINISTRATION SYSTEM");

}

void logo()
{
   int x,y;
   x=getmaxx()+getmaxx()/4;
   y=getmaxy()-25;
   settextstyle(0,0,2);
   setcolor(11);
   outtextxy(105,30,"COVID - ADMINISTRATION SYSTEM");
   setfillstyle(CLOSE_DOT_FILL,RED);
   setcolor(15);
   circle(x/2,y/2,30);
   floodfill(x/2,y/2,WHITE);
   setcolor(15);
   arc(x/2,y/2,0,28,70);
   arc(x/2,y/2,48,76,70);
   arc(x/2,y/2,96,126,70);
   arc(x/2,y/2,146,174,70);
   arc(x/2,y/2,194,222,70);
   arc(x/2,y/2,242,275,70);
   arc(x/2,y/2,300,335,70);
   setfillstyle(SOLID_FILL,YELLOW);
   circle(x/2+72,y/2-19,4);
   floodfill(x/2+72,y/2-19,WHITE);
   setfillstyle(SOLID_FILL,BLUE);
   circle(x/2+34,y/2-66,4);
   floodfill(x/2+34,y/2-66,WHITE);
   setfillstyle(SOLID_FILL,BROWN);
   circle(x/2-26,y/2-70,4);
   floodfill(x/2-26,y/2-70,WHITE);
   setfillstyle(SOLID_FILL,GREEN);
   circle(x/2-70,y/2-26,4);
   floodfill(x/2-70,y/2-26,WHITE);
   setfillstyle(SOLID_FILL,CYAN);
   circle(x/2-67,y/2+34,4);
   floodfill(x/2-67,y/2+34,WHITE);
   setfillstyle(SOLID_FILL,MAGENTA);
   circle(x/2-16,y/2+73,4);
   floodfill(x/2-16,y/2+73,WHITE);
   setfillstyle(SOLID_FILL,RED);
   circle(x/2+55,y/2+49,4);
   floodfill(x/2+55,y/2+49,WHITE);
   setcolor(14);
   arc(x/2,y/2,0,28,50);
   setcolor(1);
   arc(x/2,y/2,48,76,50);
   setcolor(6);
   arc(x/2,y/2,96,126,50);
   setcolor(2);
   arc(x/2,y/2,146,174,50);
   setcolor(3);
   arc(x/2,y/2,194,222,50);
   setcolor(5);
   arc(x/2,y/2,242,275,50);
   setcolor(RED);
   arc(x/2,y/2,300,335,50);
}
void hold(int time)
{
	while(time>0)
	{
		sleep(1);
		time--;
	}
}
void choice_page1()
{
	int choice;
	int i,j=0;
	cleardevice();
	project_name();
	rectangle(10,10,620,450);
	rectangle(15,15,615,445);
	setfillstyle(SOLID_FILL,11);
	floodfill(11,11,11);
	setcolor(BLACK);
	for(i=1;i<=3;i++)
	{
	  rectangle(10,10,15+j,15+j);
	  rectangle(620,10,615-j,15+j);
	  rectangle(10,450,15+j,445-j);
	  rectangle(620,450,615-j,445-j);
	  j=j+5;
	}
	gotoxy(30,7);
	printf("Please make your selection ");
	gotoxy(18,10);
	printf("1.Login");
	gotoxy(18,12);
	printf("2.Project information");
	gotoxy(18,19);
	printf("0.Exit the program");
	gotoxy(18,17);
	printf("Choice : ");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
	  case 1:
		 login_input();
		 break;
	  case 2:
		 project_info();
		 break;
	  case 0:
		 exit(0);
	  default:
			cleardevice();
			gotoxy(30,13);
			printf("!!! Wrong Choice !!!");
			gotoxy(23,14);
			printf("Press enter to return to choice menu");
			getch();
			cleardevice();
			choice_page1();
	}
}
void project_info()
{
	int i;
	cleardevice();
	fflush(stdin);
	logo();
	setcolor(11);
	rectangle(10,10,625,450);
	line(625,400,575,450);
	line(625,395,570,450);
	line(10,60,60,10);
	line(10,65,65,10);
	//line(625,395,570,450);
	//line(625,370,545,450);
	//line(625,350,525,450);
	//line(625,320,495,450);
	gotoxy(8,9);
	printf("COVID AS");
	gotoxy(8,11);
	setcolor(11);
	printf("Prepared By:");
	gotoxy(8,12);
	for(i=0;i<=11;i++)
	 printf("%c",205);
	gotoxy(8,13);
	printf("Archana Khadka");
	gotoxy(8,14);
	printf("Ashok Basnet");
	gotoxy(8,15);
	printf("Sachin Gautam");
	gotoxy(8,18);
	printf("Project Supervisor:");
	gotoxy(8,19);
	for(i=0;i<=18;i++)
	 printf("%c",205);
	gotoxy(8,20);
	printf("Prakash Gautam");
	gotoxy(30,25);
	printf("Press any key to go back");
	fflush(stdin);
	if(getch())
		choice_page1();

}
void login_input()
{
	const int maxch=20;
	char pass[21],uname[21];
	char a,b,o;
	int chpos=0;
	cleardevice();
	fflush(stdin);
	project_name();
	rectangle(10,10,625,450);
	gotoxy(38,7);
	printf("Login page");
	gotoxy(15,13);
	printf("Username : ");
	rectangle(196,183,362,213);
	gotoxy(15,15);
	printf("Password : ");
	rectangle(196,217,362,247);
	gotoxy(26,13);
	while(1)
	{       fflush(stdin);
		b=getch();
		if(b==13)
		{
			break;
		}
		else if(b==8)
		{
			if (chpos>0)
			{
				chpos--;
				uname[chpos]='\0';
				printf("\b \b");
			}
		}
		else if(b==32 || b==9)
			{
				continue;
			}
			else
			{
				if(chpos<maxch)
				{
					uname[chpos]=b;
					printf("%c",uname[chpos]);
					chpos++;
				}

				else
				{
					gotoxy(30,20);
					printf("Exceeds max username length!");
					gotoxy(31,21);
					printf("Press enter to try again ");
					o=getch();
					switch(o)
					{
						case 13:
							login_input();
							break;
						default:
							gotoxy(33,22);
							printf("!!! Wrong Input !!!");
							hold(2);
							login_input();
							break;
					}
					break;
				}
			}
	}
	uname[chpos]= '\0';
	gotoxy(26,15);
	chpos=0;
	while(1)
	{
		a=getch();
		if(a==13)
		{
			break;
		}
		else if(a==8)
		{
			if (chpos>0)
			{
				chpos--;
				pass[chpos]='\0';
				printf("\b \b");
			}
		}
		else if(a==32 || a==9)
			{
				continue;
			}
			else
			{
				if(chpos<maxch)
				{
					pass[chpos]=a;
					chpos++;
					printf("*");
				}
				else
				{
					gotoxy(30,20);
					printf("Exceeds max password length");
					gotoxy(31,21);
					printf("Press enter to try again ");
					o=getch();
					switch(o)
					{
						case 13:
							login_input();
							break;
						default:
							gotoxy(33,22);
							printf("!!! Wrong Input !!!");
							hold(2);
							login_input();
							break;
					}
					break;
				}
			}
	}
	pass[chpos]= '\0';
	printf("\n");
	login_chk(uname,pass);
}
void login_chk(char uname[21],char pass[21])
{
	FILE *fp,*fp1,*fp2,*fa,*fm,*fd;
	char o;
	fp = fopen("admin.dat","rb");
	fp1 = fopen("doctor.dat","rb");
	fp2 = fopen("mstaff.dat","rb");
	if (fp == NULL || fp1 == NULL || fp2 == NULL )
	{
	   struct admin adm = {"admin19","admin19"};
	   struct managing_staff mstaff = {"mstaff19","mstaff19"};
	   struct doctor doc = {"doctor19","doctor19"};
	   fclose(fp);
	   fclose(fp1);
	   fclose(fp2);
	   fp = fopen("admin.dat","wb+");
	   fwrite(&adm,sizeof(adm),1,fp);
	   fclose(fp);
	   fp1 = fopen("mstaff.dat","wb+");
	   fwrite(&mstaff,sizeof(mstaff),1,fp1);
	   fclose(fp1);
	   fp2 = fopen("doctor.dat","wb+");
	   fwrite(&doc,sizeof(doc),1,fp2);
	   fclose(fp);
	   fclose(fp1);
	   fclose(fp2);
	   login_chk(uname,pass);
	}
	else{
	      fclose(fp);
	      fclose(fp1);
	      fclose(fp2);
	      if (strlen(pass)==0 && strlen(uname)==0)
	      {
		gotoxy(30,20);
		printf(" No username and password entered");
		gotoxy(34,21);
		printf("  Press enter to try again ");
		gotoxy(30,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		 choice_page1();
		else if(o==13)
		 login_input();
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 login_input();
		}
	}
	else if (strlen(uname)==0)
	{
		gotoxy(30,20);
		printf("No username entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		 choice_page1();
		else if(o==13)
		 login_input();
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 login_input();
		}
	}
	else if (strlen(pass)==0)
	{
		gotoxy(30,20);
		printf("No password entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		 choice_page1();
		else if(o==13)
		 login_input();
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 login_input();
		}
	}
	else
	{
		fclose(fp);
		fclose(fp1);
		fclose(fp2);
		fa = fopen("admin.dat","rb+");
		fm = fopen("mstaff.dat","rb+");
		fd = fopen("doctor.dat","rb+");
		fread(&adm,sizeof(adm),1,fa);
		fread(&mstaff,sizeof(mstaff),1,fm);
		fread(&doc,sizeof(doc),1,fd);
		if(strcmp(pass,doc.pass)==0 && strcmp(uname,doc.uname)==0)
		{
		 gotoxy(35,22);
		 printf("Login Success");
		 fclose(fd);
		 fclose(fm);
		 fclose(fa);
		 hold(2);
		 cleardevice();
		 choice_page2();
		 }
	    else if(strcmp(pass,mstaff.pass)==0 && strcmp(uname,mstaff.uname)==0)
		{
		 gotoxy(35,22);
		 printf("Login Success");
		 fclose(fd);
		 fclose(fm);
		 fclose(fa);
		 hold(2);
		 cleardevice();
		 choice_page3();
	    }
	    else if(strcmp(pass,adm.pass)==0 && strcmp(uname,adm.uname)==0)
		{
		 gotoxy(35,22);
		 printf("Login Success");
		 fclose(fd);
		 fclose(fm);
		 fclose(fa);
		 hold(2);
		 cleardevice();
		 choice_page4();
	    }
		else
		{
		 gotoxy(35,22);
		 printf("Login Failure");
		 gotoxy(28,23);
		 printf("  Press enter to try again ");
		 gotoxy(29,24);
		 printf("Press backspace to go back ");
		 o=getch();
		 if(o==8)
		 {
		   fclose(fa);
		   fclose(fm);
		   fclose(fd);
		   choice_page1();
		 }
		 else if(o==13)
		 {
		  fclose(fa);
		  fclose(fm);
		  fclose(fd);
		  login_input();
		 }
		 else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 fclose(fa);
		 fclose(fm);
		 fclose(fd);
		 login_input();
		}
	    }
	}
     }
     fclose(fa);
     fclose(fm);
     fclose(fd);
}
void view_precord()
{
     struct patient pat;
     int i;
     int x = getmaxx();
     int y = getmaxy();
     FILE *fp1;
     char ch;
     int gd = DETECT,gm;
     cleardevice();
     initgraph(&gd,&gm,"..\\BGI");
     fp1 = fopen("patient.dat","rb+");
     if(fp1 == NULL)
     {
       printf("Error opening file");
     }
     project_name();
     rectangle(1,1,x-1,y-1);
     line(1,122,x-1,122);
     line(1,168,x-1,168);
     line(163,122,163,y-1);
     line(208,122,208,y-1);
     line(270,122,270,y-1);
     line(338,122,338,y-1);
     line(382,122,382,y-1);
     line(425,122,425,y-1);
     line(462,122,462,y-1);
     line(545,122,545,y-1);
     gotoxy(34,5);
     printf("Patients Records");
     gotoxy(3,9);
     printf("Name");
     gotoxy(23,9);
     printf("Age");
     gotoxy(28,9);
     printf("Sex");
     gotoxy(36,9);
     printf("Patient");
     gotoxy(36,10);
     printf("No.");
     gotoxy(44,9);
     printf("Ward");
     gotoxy(44,10);
     printf("No.");
     gotoxy(50,9);
     printf("Bed");
     gotoxy(50,10);
     printf("No.");
     gotoxy(55,9);
     printf("V.S");
     gotoxy(60,9);
     printf("Vaccine");
     gotoxy(60,10);
     printf("Name");
     gotoxy(70,9);
     printf("Date");
     gotoxy(70,10);
     printf("Admitted");
     i = 0;
     while(fread(&pat,sizeof(pat),1,fp1)!= NULL)
     {
	 gotoxy(3,12+i);
	 printf("%s",pat.name);
	 gotoxy(23,12+i);
	 printf("%d",pat.age);
	 gotoxy(28,12+i);
	 printf("%s",pat.sex);
	 gotoxy(36,12+i);
	 printf("%d",pat.id);
	 gotoxy(44,12+i);
	 printf("%d",pat.ward_number);
	 gotoxy(50,12+i);
	 printf("%d",pat.bed_number);
	 gotoxy(55,12+i);
	 printf("%s",pat.v_status);
	 gotoxy(60,12+i);
	 printf("%s",pat.v_name);
	 gotoxy(70,12+i);
	 printf("%s",pat.adm_date);
	 i = i+2;
     }
     fclose(fp1);
     if(getch());
       choice_page2();
    // while
}
void view_brecord()
{

}

void p_entry()
{
     struct patient pat;
     FILE *fp2;
     int temp;
     char ch;
     cleardevice();
     b_display();
     do
     {
       fp2 = fopen("patient.dat","ab+");
       cleardevice();
       project_name();
       rectangle(10,10,625,450);
       gotoxy(34,7);
       printf("Add patients details");
       fflush(stdin);
       gotoxy(15,10);
       printf("Name : ");
       scanf("%[^\n]",pat.name);
       gotoxy(45,10);
       printf("Age : ");
       scanf("%d",&pat.age);
       gotoxy(15,12);
       printf("Sex : ");
       scanf("%s",pat.sex);
       fflush(stdin);
       gotoxy(45,12);
       printf("Patient No. : ");
       scanf("%d",&temp);
       id_chk(temp);
       pat.id = temp;
       gotoxy(15,14);
       printf("Address : ");
       scanf("%s",pat.address);
       fflush(stdin);
       gotoxy(45,14);
       printf("Contact N0. : ");
       scanf("%s",pat.contact);
       fflush(stdin);
       gotoxy(15,16);
       printf("Ward No. : ");
       scanf("%d",&pat.ward_number);
       if(pat.ward_number<1 || pat.ward_number>5)
       {
	 gotoxy(36,20);
	 printf("Invalid Input");
	 getch();
	 fclose(fp2);
	 p_entry();
       }
       fflush(stdin);
       gotoxy(45,16);
       printf("Bed No. : ");
       scanf("%d",&pat.bed_number);
       if(pat.bed_number<1 || pat.bed_number>15)
       {
	 gotoxy(36,20);
	 printf("Invalid Input");
	 getch();
	 fclose(fp2);
	 p_entry();
       }
       gotoxy(15,18);
       printf("Vaccination Status : ");
       scanf("%s",pat.v_status);
       gotoxy(45,18);
       printf("Vaccine Name : ");
       scanf("%s",pat.v_name);
       gotoxy(15,20);
       printf("Admission Date (YYYY-MM-DD) : ");
       gotoxy(15,22);
       scanf("%s",pat.adm_date);
       fwrite(&pat,sizeof(pat),1,fp2);
       fclose(fp2);
       fflush(stdin);
       gotoxy(25,25);
       printf("Do you want to add more data (Y/N)");
       ch = getch();
     }
      while(ch == 'y'|| ch == 'Y');
      fclose(fp2);
      choice_page3();
}
void b_entry()
{

}
void b_display()
{
  int w=0,b=0,bed,x1=130,y1=290;
  char nav;
  display:
  cleardevice();
  project_name();
  settextstyle(2,0,5);
  gotoxy(35,7);
  printf("Wards and Beds");
  gotoxy(38,14);
  printf("Ward : ");
  rectangle(130,365,150,385);
  setfillstyle(1,RED);
  floodfill(131,366,11);
  gotoxy(21,24);
  printf("- Occupied");
  rectangle(260,365,280,385);
  setfillstyle(1,GREEN);
  floodfill(266,368,11);
  gotoxy(37,24);
  printf("- Free");
  beds();
  //numbers();
  fflush(stdin);
  gotoxy(46,14);
  scanf("%d",&w);
   if(w>=1 && w<=5)
   {
    fill(w,b);
    numbers();
    }
   else
   {
     gotoxy(36,18);
     printf("Invalid Input");
     getch();
     b_display();
   }
   getch();
   gotoxy(27,20);
   printf("Do you want to continue (Y/N)?");
   nav = getch();
   switch(nav)
   {
    case 'y':
      b_display();
      break;
    case 'Y':
      b_display();
      break;
    case 'n':
      break;
    case 'N':
      break;

    default:
      gotoxy(36,18);
      printf("Wrong Input");
      getch();
      b_display();

  }



}
void b_edit()
{
  FILE *fp6,*fu6;
  int w=0,b=0,x1=130,y1=290,f;
  char nav;
  struct patient pat;
  fp6 = fopen("patient.dat","rb");
  fu6 = fopen("b_u.dat","wb");
  display:
  cleardevice();
  project_name();
  settextstyle(2,0,5);
  gotoxy(35,7);
  printf("Wards and Beds");
  gotoxy(38,14);
  printf("Ward : ");
  rectangle(130,365,150,385);
  setfillstyle(1,RED);
  floodfill(131,366,11);
  gotoxy(21,24);
  printf("- Occupied");
  rectangle(260,365,280,385);
  setfillstyle(1,GREEN);
  floodfill(266,368,11);
  gotoxy(37,24);
  printf("- Free");
  beds();
  fflush(stdin);
  gotoxy(46,14);
  scanf("%d",&w);
   if(w>=1 && w<=5)
   {
    fill(w,b);
    numbers();
   }
   else
   {
     gotoxy(36,18);
     printf("Invalid Input");
     getch();
     fclose(fp6);
     fclose(fu6);
     b_edit();
   }
   gotoxy(34,16);
   printf("Bed number : ");
   scanf("%d",&b);
   if(w>=1 && w<=15)
   {
    fill(w,b);
    numbers();
    }
   else
   {
     gotoxy(36,18);
     printf("Invalid Input");
     getch();
     fclose(fp6);
     fclose(fu6);
     b_edit();
   }
   gotoxy(25,18);
   printf("Do you want to free bed %d ? (Y/N)",b);
   nav = getch();
   if(nav == 'y'|| nav == 'Y')
   {
      while(fread(&pat,sizeof(pat),1,fp6))
      {
	 if(w == pat.ward_number && b == pat.bed_number)
	 {
	   pat.ward_number = 0;
	   pat.bed_number = 0;
	   fwrite(&pat,sizeof(pat),1,fu6);
	   f=1;
	 }
	 else
	 {
	   fwrite(&pat,sizeof(pat),1,fu6);
	 }
      }
      fclose(fu6);
      fclose(fp6);
      remove("patient.dat");
      rename("b_u.dat","patient.dat");
      gotoxy(37,20);
      printf("Bed Free");
      getch();
      choice_page3();
   }
   else
   {
     fclose(fu6);
     fclose(fp6);
     choice_page3();
   }
   fclose(fu6);
   fclose(fp6);
}
void n_staff()
{

}
void c_unamepass()
{

}
void choice_page2()
{
	int choice;
	cleardevice();
	project_name();
	rectangle(10,10,625,450);
	gotoxy(33,7);
	printf("Doctor choice page");
	gotoxy(15,13);
	printf("1.Patients Record");
	gotoxy(15,15);
	printf("2.Wards and Beds Information");
	gotoxy(15,17);
	printf("3.Statistics Search");
	gotoxy(15,23);
	printf("0.Exit to main menu");
	gotoxy(15,20);
	printf("Choice : ");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			view_precord();
			break;
		case 2:
			b_display();
			choice_page2();
			break;
		case 3:
			stat_page();
			break;
		case 0:
			choice_page1();
			break;
		default:
			cleardevice();
			gotoxy(30,13);
			printf("!!! Wrong Choice !!!");
			gotoxy(23,14);
			printf("Press enter to return to choice menu");
			getch();
			choice_page2();
	}
}
void choice_page3()
{
	int choice;
	cleardevice();
	project_name();
	rectangle(10,10,625,450);
	gotoxy(30,7);
	printf("Managing staff choice page");
	gotoxy(15,11);
	printf("1.New patient entry");
	gotoxy(15,13);
	printf("2.Edit patient record");
	gotoxy(15,15);
	printf("3.Edit ward and bed information");
	gotoxy(15,17);
	printf("4.Delete patient record");
	gotoxy(15,24);
	printf("0.Exit to main menu");
	gotoxy(15,21);
	printf("Choice : ");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			p_entry();
			break;
		case 2:
			p_edit();
			break;
		case 3:
			b_edit();
			break;
		case 4:
			p_delete();
			break;
		case 0:
			choice_page1();
			break;
		default:
			cleardevice();
			gotoxy(30,13);
			printf("!!! Wrong Choice !!!");
			gotoxy(23,14);
			printf("Press enter to return to choice menu");
			getch();
			choice_page3();
	}
}
void choice_page4()
{
	int choice;
	cleardevice();
	project_name();
	rectangle(10,10,625,450);
	gotoxy(33,7);
	printf("Admin choice page");
	gotoxy(15,13);
	printf("1.Add new staffs");
	gotoxy(15,15);
	printf("2.View staff list");
	gotoxy(15,17);
	printf("3.Change username and password");
	gotoxy(15,19);
	printf("4.Delete staff record");
	gotoxy(15,23);
	printf("0.Exit to main menu");
	gotoxy(15,21);
    fflush(stdin);
    printf("Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
	case 1:
	    add_staff();
	    break;
	case 2:
	    view_staff();
	    break;
	case 3:
	    change_unamepass();
	    break;
	case 4:
	    staff_del();
	    break;
	case 0:
	    choice_page1();
	    break;
	default:
	    cleardevice();
	    gotoxy(30,13);
	    printf("!!! Wrong Choice !!!");
	    gotoxy(23,14);
	    printf("Press enter to return to choice menu");
	    getch();
	    choice_page4();
    }
}
void stat_page()
{
	int choice;
	cleardevice();
	project_name();
	rectangle(10,10,625,450);
	gotoxy(32,7);
	printf("Statistics Search Page");
	gotoxy(17,10);
	printf("1.Search by Age");
	gotoxy(17,12);
	printf("2.Vaccinated Patient");
	gotoxy(17,14);
	printf("3.Unvaccinated Patient");
	gotoxy(17,21);
	printf("0.Exit to choice page");
	gotoxy(17,18);
	printf("Choice : ");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
		case 1:
			search_agegroup();
			break;
		case 2:
			view_vacrecord();
			break;
		case 3:
			view_unvacrecord();
			break;
		case 0:
			choice_page2();
		default:
			cleardevice();
			gotoxy(30,13);
			printf("!!! Wrong Choice !!!");
			gotoxy(23,14);
			printf("Press enter to return to choice menu");
			getch();
			cleardevice();
			stat_page();
	}
}
void search_agegroup()
{
	int choice;
	int l_age,u_age;
	cleardevice();
	project_name();
	rectangle(10,10,625,450);
	gotoxy(32,7);
	printf("Search by age");
	gotoxy(17,12);
	printf("Enter the lower age range: ");
	scanf("%d",&l_age);
	gotoxy(17,14);
	printf("Enter the higher age range: ");
	scanf("%d",&u_age);
	if(l_age<=0)
	{
	  gotoxy(34,18);
	  printf("Invalid Input");
	  getch();
	  search_agegroup();
	}
	else if(l_age>=u_age)
	{
	  gotoxy(34,18);
	  printf("Invalid Input");
	  getch();
	  search_agegroup();
	}
	else
	{
	  view_agegroup(l_age,u_age);
	}
}

void view_agegroup(int l_age, int u_age)
{
     struct patient pat;
     int i;
     int x = getmaxx();
     int y = getmaxy();
     FILE *fp;
     char ch;
     int gd = DETECT,gm;
     cleardevice();
     initgraph(&gd,&gm,"..\\BGI");
     fp = fopen("patient.dat","rb+");
     project_name();
     rectangle(1,1,x-1,y-1);
     line(1,122,x-1,122);
     line(1,168,x-1,168);
     line(163,122,163,y-1);
     line(208,122,208,y-1);
     line(270,122,270,y-1);
     line(336,122,336,y-1);
     line(382,122,382,y-1);
     line(425,122,425,y-1);
     line(462,122,462,y-1);
     line(545,122,545,y-1);
     gotoxy(38,5);
     printf("Age(%d-%d)",l_age,u_age);
     gotoxy(3,9);
     printf("Age");
     gotoxy(23,9);
     printf("Name");
     gotoxy(28,9);
     printf("Sex");
     gotoxy(36,9);
     printf("Patient");
     gotoxy(36,10);
     printf("No.");
     gotoxy(44,9);
     printf("Ward");
     gotoxy(44,10);
     printf("No.");
     gotoxy(50,9);
     printf("Bed");
     gotoxy(50,10);
     printf("No.");
     gotoxy(55,9);
     printf("V.S");
     gotoxy(60,9);
     printf("Vaccine");
     gotoxy(60,10);
     printf("Name");
     gotoxy(70,9);
     printf("Date");
     gotoxy(70,10);
     printf("Admitted");
     i = 0;
     while(fread(&pat,sizeof(pat),1,fp)!= NULL)
     {
       if(pat.age>l_age && pat.age<u_age)
       {
	 gotoxy(3,12+i);
	 printf("%s",pat.name);
	 gotoxy(23,12+i);
	 printf("%d",pat.age);
	 gotoxy(28,12+i);
	 printf("%s",pat.sex);
	 gotoxy(36,12+i);
	 printf("%d",pat.id);
	 gotoxy(44,12+i);
	 printf("%d",pat.ward_number);
	 gotoxy(50,12+i);
	 printf("%d",pat.bed_number);
	 gotoxy(55,12+i);
	 printf("%s",pat.v_status);
	 gotoxy(60,12+i);
	 printf("%s",pat.v_name);
	 gotoxy(70,12+i);
	 printf("%s",pat.adm_date);
	 i = i+2;
	 }
     }
     fclose(fp);
     getch();
     stat_page();
}

void view_vacrecord()
{
     struct patient pat;
     int i;
     int x = getmaxx();
     int y = getmaxy();
     FILE *fp;
     char ch;
     int gd = DETECT,gm;
     cleardevice();
     initgraph(&gd,&gm,"..\\BGI");
     fp = fopen("patient.dat","rb+");
     project_name();
     rectangle(1,1,x-1,y-1);
     line(1,122,x-1,122);
     line(1,168,x-1,168);
     line(163,122,163,y-1);
     line(208,122,208,y-1);
     line(270,122,270,y-1);
     line(336,122,336,y-1);
     line(382,122,382,y-1);
     line(425,122,425,y-1);
     line(462,122,462,y-1);
     line(545,122,545,y-1);
     gotoxy(34,5);
     printf("Vaccinated Patients");
     gotoxy(3,9);
     printf("Age");
     gotoxy(23,9);
     printf("Name");
     gotoxy(28,9);
     printf("Sex");
     gotoxy(36,9);
     printf("Patient");
     gotoxy(36,10);
     printf("No.");
     gotoxy(44,9);
     printf("Ward");
     gotoxy(44,10);
     printf("No.");
     gotoxy(50,9);
     printf("Bed");
     gotoxy(50,10);
     printf("No.");
     gotoxy(55,9);
     printf("V.S");
     gotoxy(60,9);
     printf("Vaccine");
     gotoxy(60,10);
     printf("Name");
     gotoxy(70,9);
     printf("Date");
     gotoxy(70,10);
     printf("Admitted");
     i = 0;
     while(fread(&pat,sizeof(pat),1,fp)!= NULL)
     {
       if((strcmp(pat.v_status,"Yes")==0 || strcmp(pat.v_status,"yes")==0 || strcmp(pat.v_status,"YES")==0 ))
       {
	 gotoxy(3,12+i);
	 printf("%s",pat.name);
	 gotoxy(23,12+i);
	 printf("%d",pat.age);
	 gotoxy(28,12+i);
	 printf("%s",pat.sex);
	 gotoxy(36,12+i);
	 printf("%d",pat.id);
	 gotoxy(44,12+i);
	 printf("%d",pat.ward_number);
	 gotoxy(50,12+i);
	 printf("%d",pat.bed_number);
	 gotoxy(55,12+i);
	 printf("%s",pat.v_status);
	 gotoxy(60,12+i);
	 printf("%s",pat.v_name);
	 gotoxy(70,12+i);
	 printf("%s",pat.adm_date);
	 i = i+2;
	 }
     }
     fclose(fp);
     getch();
     stat_page();

}
void view_unvacrecord()
{
     struct patient pat;
     int i;
     int x = getmaxx();
     int y = getmaxy();
     FILE *fp;
     char ch;
     int gd = DETECT,gm;
     cleardevice();
     initgraph(&gd,&gm,"..\\BGI");
     fp = fopen("patient.dat","rb+");
     project_name();
     rectangle(1,1,x-1,y-1);
     line(1,122,x-1,122);
     line(1,168,x-1,168);
     line(163,122,163,y-1);
     line(208,122,208,y-1);
     line(270,122,270,y-1);
     line(336,122,336,y-1);
     line(382,122,382,y-1);
     line(425,122,425,y-1);
     line(462,122,462,y-1);
     line(545,122,545,y-1);
     gotoxy(34,5);
     printf("Unvaccinated Patients");
     gotoxy(3,9);
     printf("Age");
     gotoxy(23,9);
     printf("Name");
     gotoxy(28,9);
     printf("Sex");
     gotoxy(36,9);
     printf("Patient");
     gotoxy(36,10);
     printf("No.");
     gotoxy(44,9);
     printf("Ward");
     gotoxy(44,10);
     printf("No.");
     gotoxy(50,9);
     printf("Bed");
     gotoxy(50,10);
     printf("No.");
     gotoxy(55,9);
     printf("V.S");
     gotoxy(60,9);
     printf("Vaccine");
     gotoxy(60,10);
     printf("Name");
     gotoxy(70,9);
     printf("Date");
     gotoxy(70,10);
     printf("Admitted");
     i = 0;
     while(fread(&pat,sizeof(pat),1,fp)!= NULL)
     {
       if((strcmp(pat.v_status,"No")==0 || strcmp(pat.v_status,"no")==0 || strcmp(pat.v_status,"NO")==0 ))
       {
	 gotoxy(3,12+i);
	 printf("%s",pat.name);
	 gotoxy(23,12+i);
	 printf("%d",pat.age);
	 gotoxy(28,12+i);
	 printf("%s",pat.sex);
	 gotoxy(36,12+i);
	 printf("%d",pat.id);
	 gotoxy(44,12+i);
	 printf("%d",pat.ward_number);
	 gotoxy(50,12+i);
	 printf("%d",pat.bed_number);
	 gotoxy(55,12+i);
	 printf("%s",pat.v_status);
	 gotoxy(60,12+i);
	 printf("%s",pat.v_name);
	 gotoxy(70,12+i);
	 printf("%s",pat.adm_date);
	 i = i+2;
	 }
     }
     fclose(fp);
     getch();
     stat_page();

}
void add_staff()
{
     struct staff stf;
     FILE *fp;
     char ch;
     cleardevice();
     fp = fopen("staff.dat","ab+");
     do
     {
       cleardevice();
       project_name();
       rectangle(10,10,625,450);
       gotoxy(34,7);
       printf("Add staff details");
       fflush(stdin);
       gotoxy(15,10);
       printf("Name : ");
       scanf("%[^\n]",stf.name);
       gotoxy(15,12);
       printf("Position : ");
       scanf("%s",stf.position);
       gotoxy(15,14);
       printf("Address : ");
       scanf("%s",stf.address);
       fflush(stdin);
       gotoxy(15,16);
       printf("Contact N0. : ");
       scanf("%s",stf.contact);
       gotoxy(15,18);
       printf("Year Joined : ");
       scanf("%d",&stf.year);
       fwrite(&stf,sizeof(stf),1,fp);
       gotoxy(25,25);
       printf("Do you want to add more data (Y/N)");
       ch = getch();
     }
      while(ch == 'y'|| ch == 'Y');
      fclose(fp);
      choice_page4();
}
void view_staff()
{
     struct staff stf;
     int i;
     int x = getmaxx();
     int y = getmaxy();
     FILE *fp;
     char ch;
     int gd = DETECT,gm;
     cleardevice();
     initgraph(&gd,&gm,"..\\BGI");
     fp = fopen("staff.dat","rb+");
     project_name();
     rectangle(1,1,x-1,y-1);
     line(1,122,x-1,122);
     line(1,168,x-1,168);
     line(163,122,163,y-1);
     line(270,122,270,y-1);
     line(382,122,382,y-1);
     line(525,122,525,y-1);
     gotoxy(34,5);
     printf("Staff Records");
     gotoxy(3,9);
     printf("Name");
     gotoxy(23,9);
     printf("Position");
     gotoxy(36,9);
     printf("Contact");
     gotoxy(50,9);
     printf("Address");
     gotoxy(68,9);
     printf("Year Joined");
     i = 0;
     while(fread(&stf,sizeof(stf),1,fp)!= NULL)
     {
	 gotoxy(3,12+i);
	 printf("%s",stf.name);
	 gotoxy(23,12+i);
	 printf("%s",stf.position);
	 gotoxy(36,12+i);
	 printf("%s",stf.contact);
	 gotoxy(50,12+i);
	 printf("%s",stf.address);
	 gotoxy(68,12+i);
	 printf("%d",stf.year);
	 i = i+2;
     }
     fclose(fp);
     if(getch());
       choice_page4();
}

void change_unamepass()
{
	int choice,lc=0;
	cleardevice();
	project_name();
	rectangle(10,10,625,450);
	gotoxy(32,7);
	printf("Change Login Page");
	gotoxy(17,10);
	printf("1.For Doctor");
	gotoxy(17,12);
	printf("2.For Managing Staff");
	gotoxy(17,14);
	printf("3.For Admin");
	gotoxy(17,21);
	printf("0.Exit to choice page");
	gotoxy(17,18);
	printf("Choice : ");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
		case 1:
			lc=1;
			login_change_input(lc);
			break;
		case 2:
			lc=2;
			login_change_input(lc);
			break;
		case 3:
			lc=3;
			login_change_input(lc);
			break;
		case 0:
			choice_page4();
		default:
			cleardevice();
			gotoxy(30,13);
			printf("!!! Wrong Choice !!!");
			gotoxy(23,14);
			printf("Press enter to return to choice menu");
			getch();
			cleardevice();
			stat_page();
	}
}
void login_change_input(int lc)
{
	const int maxch=20;
	char pass[21],uname[21];
	char a,b,o;
	int chpos=0;
	cleardevice();
	fflush(stdin);
	project_name();
	rectangle(10,10,625,450);
	gotoxy(15,9);
	printf("Enter New Credentials");
	gotoxy(15,13);
	printf("Username : ");
	rectangle(196,183,362,213);
	gotoxy(15,15);
	printf("Password : ");
	rectangle(196,217,362,247);
	gotoxy(26,13);
	while(1)
	{       fflush(stdin);
		b=getch();
		if(b==13)
		{
			break;
		}
		else if(b==8)
		{
			if (chpos>0)
			{
				chpos--;
				uname[chpos]='\0';
				printf("\b \b");
			}
		}
		else if(b==32 || b==9)
			{
				continue;
			}
			else
			{
				if(chpos<maxch)
				{
					uname[chpos]=b;
					printf("%c",uname[chpos]);
					chpos++;
				}

				else
				{
					gotoxy(30,20);
					printf("Exceeds max username length!");
					gotoxy(31,21);
					printf("Press enter to try again ");
					o=getch();
					switch(o)
					{
						case 13:
							login_change_input(lc);
							break;
						default:
							gotoxy(33,22);
							printf("!!! Wrong Input !!!");
							hold(2);
							login_change_input(lc);
							break;
					}
					break;
				}
			}
	}
	uname[chpos]= '\0';
	gotoxy(26,15);
	chpos=0;
	while(1)
	{
		a=getch();
		if(a==13)
		{
			break;
		}
		else if(a==8)
		{
			if (chpos>0)
			{
				chpos--;
				pass[chpos]='\0';
				printf("\b \b");
			}
		}
		else if(a==32 || a==9)
			{
				continue;
			}
			else
			{
				if(chpos<maxch)
				{
					pass[chpos]=a;
					chpos++;
					printf("*");
				}
				else
				{
					gotoxy(30,20);
					printf("Exceeds max password length");
					gotoxy(31,21);
					printf("Press enter to try again ");
					o=getch();
					switch(o)
					{
						case 13:
							login_change_input(lc);
							break;
						default:
							gotoxy(33,22);
							printf("!!! Wrong Input !!!");
							hold(2);
							login_change_input(lc);
							break;
					}
					break;
				}
			}
	}
	pass[chpos]= '\0';
	printf("\n");
	if(lc==1)
	  login_change_doctor(uname,pass);
	else if(lc==2)
	  login_change_mstaff(uname,pass);
	else if(lc==3)
	  login_change_admin(uname,pass);

}
void login_change_doctor(char uname[21],char pass[21])
{
	FILE *fp,*fu;
	char o;
	int lc;
	fp = fopen("doctor.dat","rb+");
	fu = fopen("doctor_u.dat","wb");
	if (strlen(pass)==0 && strlen(uname)==0)
	 {
		gotoxy(30,20);
		printf(" No username and password entered");
		gotoxy(34,21);
		printf("  Press enter to try again ");
		gotoxy(30,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();
		 }
		else if(o==13)
		 {
		   lc=1;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=1;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else if (strlen(uname)==0)
	{
		gotoxy(30,20);
		printf("No username entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();
		}
		else if(o==13)
		 {
		   lc=1;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=1;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else if (strlen(pass)==0)
	{
		gotoxy(30,20);
		printf("No password entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();
		}
		else if(o==13)
		 {
		   lc=1;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=1;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else
	{
		 fread(&doc,sizeof(doc),1,fp);
		 if(strcmp(pass,doc.pass)==0 || strcmp(uname,doc.uname)==0)
		 {
		   gotoxy(31,20);
		   printf("Same Username or Password");
		   gotoxy(26,21);
		   printf("  Press enter to try again ");
		   gotoxy(22,22);
		   printf("Press backspace to go back one page ");
		   o=getch();
		   if(o==8)
		   {
		     fclose(fp);
		     fclose(fu);
		     change_unamepass();
		   }
		   else if(o==13)
		   {
		    lc=1;
		    fclose(fp);
		    fclose(fu);
		    login_change_input(lc);
		   }
		   else
		   {
		     gotoxy(36,23);
		     printf("!!! Wrong Input !!!");
		     hold(2);
		     lc=1;
		     fclose(fp);
		     fclose(fu);
		     login_change_input(lc);
		   }
		}


		else
		{
		 strcpy(doc.uname,uname);
		 strcpy(doc.pass,pass);
		 fwrite(&doc,sizeof(doc),1,fu);
		 gotoxy(35,22);
		 printf("Changed sucessfully");
		 fclose(fp);
		 fclose(fu);
		 remove("doctor.dat");
		 rename("doctor_u.dat","doctor.dat");
		 hold(2);
		 choice_page4();
		}
	  }
	  fclose(fp);
	  fclose(fu);
}
void login_change_mstaff(char uname[21],char pass[21])
{
	FILE *fp,*fu;
	char o;
	int lc;
	fp = fopen("mstaff.dat","rb+");
	fu = fopen("mstaff_u.dat","wb");
	if (strlen(pass)==0 && strlen(uname)==0)
	 {
		gotoxy(30,20);
		printf(" No username and password entered");
		gotoxy(34,21);
		printf("  Press enter to try again ");
		gotoxy(30,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();\
		}
		else if(o==13)
		 {
		   lc=2;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=2;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else if (strlen(uname)==0)
	{
		gotoxy(30,20);
		printf("No username entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();
		}
		else if(o==13)
		 {
		   lc=2;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=2;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else if (strlen(pass)==0)
	{
		gotoxy(30,20);
		printf("No password entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();
		}
		else if(o==13)
		 {
		   lc=2;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=2;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else
	{
		 fread(&mstaff,sizeof(mstaff),1,fp);
		 if(strcmp(pass,mstaff.pass)==0 || strcmp(uname,mstaff.uname)==0)
		 {
		   gotoxy(30,20);
		   printf("Same Username or Password");
		   gotoxy(26,21);
		   printf("  Press enter to try again ");
		   gotoxy(22,22);
		   printf("Press backspace to go back one page ");
		   o=getch();
		   if(o==8)
		   {
		     fclose(fp);
		     fclose(fu);
		     change_unamepass();
		   }
		   else if(o==13)
		   {
		    lc=2;
		    fclose(fp);
		    fclose(fu);
		    login_change_input(lc);
		   }
		   else
		   {
		     gotoxy(36,23);
		     printf("!!! Wrong Input !!!");
		     hold(2);
		     lc=2;
		     fclose(fp);
		     fclose(fu);
		     login_change_input(lc);
		   }
		}


		else
		{
		 strcpy(mstaff.uname,uname);
		 strcpy(mstaff.pass,pass);
		 fwrite(&mstaff,sizeof(mstaff),1,fu);
		 gotoxy(35,22);
		 printf("Changed sucessfully");
		 fclose(fp);
		 fclose(fu);
		 remove("mstaff.dat");
		 rename("mstaff_u.dat","mstaff.dat");
		 hold(2);
		 choice_page4();
		}
	  }
	  fclose(fp);
	  fclose(fu);
}
void login_change_admin(char uname[21],char pass[21])
{
	FILE *fp,*fu;
	char o;
	int lc;
	fp = fopen("admin.dat","rb+");
	fu = fopen("admin_u.dat","wb");
	if (strlen(pass)==0 && strlen(uname)==0)
	 {
		gotoxy(30,20);
		printf(" No username and password entered");
		gotoxy(34,21);
		printf("  Press enter to try again ");
		gotoxy(30,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();
		}
		else if(o==13)
		 {
		   lc=3;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=3;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else if (strlen(uname)==0)
	{
		gotoxy(30,20);
		printf("No username entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();
		}
		else if(o==13)
		 {
		   lc=3;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=3;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else if (strlen(pass)==0)
	{
		gotoxy(30,20);
		printf("No password entered");
		gotoxy(26,21);
		printf("  Press enter to try again ");
		gotoxy(22,22);
		printf("Press backspace to go back one page ");
		o=getch();
		if(o==8)
		{
		 fclose(fp);
		 fclose(fu);
		 change_unamepass();\
		}
		else if(o==13)
		 {
		   lc=3;
		   fclose(fp);
		   fclose(fu);
		   login_change_input(lc);
		 }
		else
		{
		 gotoxy(36,23);
		 printf("!!! Wrong Input !!!");
		 hold(2);
		 lc=3;
		 fclose(fp);
		 fclose(fu);
		 login_change_input(lc);
		}
	}
	else
	{

		 fread(&adm,sizeof(adm),1,fp);
		 if(strcmp(pass,adm.pass)==0 || strcmp(uname,adm.uname)==0)
		 {
		   gotoxy(30,20);
		   printf("Same Username or Password");
		   gotoxy(26,21);
		   printf("  Press enter to try again ");
		   gotoxy(22,22);
		   printf("Press backspace to go back one page ");
		   o=getch();
		   if(o==8)
		   {
		     fclose(fp);
		     fclose(fu);
		     change_unamepass();
		   }
		   else if(o==13)
		   {
		    lc=3;
		    fclose(fp);
		    fclose(fu);
		    login_change_input(lc);
		   }
		   else
		   {
		     gotoxy(36,23);
		     printf("!!! Wrong Input !!!");
		     hold(2);
		     lc=3;
		     fclose(fp);
		     fclose(fu);
		     login_change_input(lc);
		   }
		}


		else
		{
		 strcpy(adm.uname,uname);
		 strcpy(adm.pass,pass);
		 fwrite(&adm,sizeof(adm),1,fu);
		 gotoxy(35,22);
		 printf("Changed sucessfully");
		 fclose(fp);
		 fclose(fu);
		 remove("admin.dat");
		 rename("admin_u.dat","admin.dat");
		 hold(2);
		 choice_page4();
		}
	  }
	  fclose(fp);
	  fclose(fu);
}

void beds()
{
  int x1=130,x2=186,y1=290,y2=325;
  rectangle(x1,y1,x2,y2);
  rectangle(x1,y1-35,x2,y2-35);
  rectangle(x1,y1-70,x2,y2-70);
  rectangle(x1,y1-105,x2,y2-105);
  rectangle(x1,y1-140,x2,y2-140);
  rectangle(x1+56,y1-140,x2+56,y2-140);
  rectangle(x1+112,y1-140,x2+112,y2-140);
  rectangle(x1+168,y1-140,x2+168,y2-140);
  rectangle(x1+224,y1-140,x2+224,y2-140);
  rectangle(x1+280,y1-140,x2+280,y2-140);
  rectangle(x1+336,y1-140,x2+336,y2-140);
  rectangle(x1+336,y1-105,x2+336,y2-105);
  rectangle(x1+336,y1-70,x2+336,y2-70);
  rectangle(x1+336,y1-35,x2+336,y2-35);
  rectangle(x1+336,y1,x2+336,y2);
}

void fill(int w,int b)
{   struct patient pat;
    int x1=130,x2=186,y1=290,y2=325;
    int i,j,fc=0;
    FILE *fp7;
    fp7 = fopen("patient.dat","rb");
    if(fp7==NULL)
    {
      setfillstyle(SOLID_FILL,GREEN);
      floodfill(x1+1,y1+1,11);
      floodfill(x1+1,y1-34,11);
      floodfill(x1+1,y1-69,11);
      floodfill(x1+1,y1-104,11);
      floodfill(x1+1,y1-139,11);
      floodfill(x1+57,y1-139,11);
      floodfill(x1+113,y1-139,11);
      floodfill(x1+169,y1-139,11);
      floodfill(x1+225,y1-139,11);
      floodfill(x1+281,y1-139,11);
      floodfill(x1+337,y1-139,11);
      floodfill(x1+337,y1-104,11);
      floodfill(x1+337,y1-69,11);
      floodfill(x1+337,y1-34,11);
      floodfill(x1+337,y1+1,11);
    }
    else
    {
      setfillstyle(SOLID_FILL,GREEN);
      floodfill(x1+1,y1+1,11);
      floodfill(x1+1,y1-34,11);
      floodfill(x1+1,y1-69,11);
      floodfill(x1+1,y1-104,11);
      floodfill(x1+1,y1-139,11);
      floodfill(x1+57,y1-139,11);
      floodfill(x1+113,y1-139,11);
      floodfill(x1+169,y1-139,11);
      floodfill(x1+225,y1-139,11);
      floodfill(x1+281,y1-139,11);
      floodfill(x1+337,y1-139,11);
      floodfill(x1+337,y1-104,11);
      floodfill(x1+337,y1-69,11);
      floodfill(x1+337,y1-34,11);
      floodfill(x1+337,y1+1,11);

      setfillstyle(SOLID_FILL,RED);
      while(fread(&pat,sizeof(pat),1,fp7)!=NULL)
      {
	if(pat.ward_number==w && pat.bed_number==1)
	 floodfill(x1+1,y1+1,11);
	else if(pat.ward_number==w && pat.bed_number==2)
	 floodfill(x1+1,y1-34,11);
	else if(pat.ward_number==w && pat.bed_number==3)
	 floodfill(x1+1,y1-69,11);
	else if(pat.ward_number==w && pat.bed_number==4)
	 floodfill(x1+1,y1-104,11);
	else if(pat.ward_number==w && pat.bed_number==5)
	 floodfill(x1+1,y1-139,11);
	else if(pat.ward_number==w && pat.bed_number==6)
	 floodfill(x1+57,y1-139,11);
	else if(pat.ward_number==w && pat.bed_number==7)
	 floodfill(x1+113,y1-139,11);
	else if(pat.ward_number==w && pat.bed_number==8)
	 floodfill(x1+169,y1-139,11);
	else if(pat.ward_number==w && pat.bed_number==9)
	 floodfill(x1+225,y1-139,11);
	else if(pat.ward_number==w && pat.bed_number==10)
	 floodfill(x1+281,y1-139,11);
	else if(pat.ward_number==w && pat.bed_number==11)
	 floodfill(x1+337,y1-139,11);
	else if(pat.ward_number==w && pat.bed_number==12)
	 floodfill(x1+337,y1-104,11);
	else if(pat.ward_number==w && pat.bed_number==13)
	 floodfill(x1+337,y1-69,11);
	else if(pat.ward_number==w && pat.bed_number==14)
	 floodfill(x1+337,y1-34,11);
	else if(pat.ward_number==w && pat.bed_number==15)
	 floodfill(x1+337,y1+1,11);
	}
      }
      fclose(fp7);


}

void numbers()
{
  int x1=130,x2=186,y1=290,y2=325,i;
  settextstyle(2,0,5);
  outtextxy(x1+25,y1+8,"1");
  outtextxy(x1+25,y1-35+8,"2");
  outtextxy(x1+25,y1-70+8,"3");
  outtextxy(x1+25,y1-105+8,"4");
  outtextxy(x1+25,y1-140+8,"5");
  outtextxy(x1+56+25,y1-140+8,"6");
  outtextxy(x1+112+25,y1-140+8,"7");
  outtextxy(x1+168+25,y1-140+8,"8");
  outtextxy(x1+224+25,y1-140+8,"9");
  outtextxy(x1+280+20,y1-140+8,"10");
  outtextxy(x1+336+20,y1-140+8,"11");
  outtextxy(x1+336+20,y1-105+8,"12");
  outtextxy(x1+336+20,y1-70+8,"13");
  outtextxy(x1+336+20,y1-35+8,"14");
  outtextxy(x1+336+20,y1+8,"15");
}

void p_edit()
{
     struct patient pat;
     FILE *fp4,*fu4;
     char ch;
     int chk_id,f,temp;
     cleardevice();
     fp4 = fopen("patient.dat","rb");
     fu4 = fopen("p_u.dat","wb");
     cleardevice();
     project_name();
     rectangle(10,10,625,450);
     line(10,150,625,150);
     line(317,450,317,150);
     gotoxy(32,5);
     printf("Edit patients details");
     fflush(stdin);
     gotoxy(32,7);
     printf("Enter Patient No. : ");
     scanf("%d",&chk_id);
     while(fread(&pat,sizeof(pat),1,fp4))
     {
       if(chk_id == pat.id)
       {
	 gotoxy(15,9);
	 printf("Record Found");
	 gotoxy(4,12);
	 printf("Name : %s",pat.name);
	 gotoxy(4,13);
	 printf("Patient No. : %d",pat.id);
	 gotoxy(4,14);
	 printf("Ward : %d",pat.ward_number);
	 gotoxy(4,15);
	 printf("Bed : %d",pat.bed_number);
	 gotoxy(4,16);
	 printf("Sex : %s",pat.sex);
	 gotoxy(4,17);
	 printf("Age : %d",pat.age);
	 gotoxy(4,18);
	 printf("Address : %s",pat.address);
	 gotoxy(4,19);
	 printf("Contact No. : %s",pat.contact);
	 gotoxy(4,20);
	 printf("Vaccination status : %s",pat.v_status);
	 gotoxy(4,21);
	 printf("Vaccine name : %s",pat.v_name);
	 gotoxy(4,22);
	 printf("Date admitted : %s",pat.adm_date);
	 gotoxy(54,9);
	 printf("Update Record");
	 fflush(stdin);
	 gotoxy(42,12);
	 printf("Name : ");
	 scanf("%[^\n]",pat.name);
	 gotoxy(42,13);
	 printf("Sex : ");
	 fflush(stdin);
	 scanf("%s",pat.sex);
	 gotoxy(42,14);
	 printf("Age : ");
	 scanf("%d",&pat.age);
	 gotoxy(42,15);
	 printf("Address : ");
	 scanf("%s",pat.address);
	 gotoxy(42,16);
	 printf("Contact No. : ");
	 scanf("%s",pat.contact);
	 gotoxy(42,17);
	 printf("Vaccination status : ");
	 scanf("%s",pat.v_status);
	 gotoxy(42,18);
	 printf("Vaccine name : ");
	 scanf("%s",pat.v_name);
	 fwrite(&pat,sizeof(pat),1,fu4);
	 f=1;
       }
       else
       {
	  fwrite(&pat,sizeof(pat),1,fu4);
       }
     }
      if(f!=1)
      {
	  gotoxy(34,9);
	  printf("Record not found");
	  getch();
	  fclose(fp4);
	  fclose(fu4);
	  choice_page3();
      }
      fclose(fu4);
      fclose(fp4);
      remove("patient.dat");
      rename("p_u.dat","patient.dat");
      gotoxy(42,22);
      printf("Record Updated");
      getch();
      choice_page3();
}
void p_delete()
{
     struct patient pat;
     FILE *fp5,*fu5;
     char ch;
     int chk_id,f;
     cleardevice();
     fp5 = fopen("patient.dat","rb");
     fu5 = fopen("p_d.dat","wb");
     cleardevice();
     project_name();
     rectangle(10,10,625,450);
     line(10,150,625,150);
     line(317,450,317,150);
     gotoxy(32,5);
     printf("Delete patients details");
     fflush(stdin);
     gotoxy(32,7);
     printf("Enter Patient No. : ");
     scanf("%d",&chk_id);
     while(fread(&pat,sizeof(pat),1,fp5))
     {
       if(chk_id == pat.id)
       {
	 f=1;
	 gotoxy(15,9);
	 printf("Record Found");
	 gotoxy(4,12);
	 printf("Name : %s",pat.name);
	 gotoxy(4,13);
	 printf("Patient No. : %d",pat.id);
	 gotoxy(4,14);
	 printf("Ward : %d",pat.ward_number);
	 gotoxy(4,15);
	 printf("Bed : %d",pat.bed_number);
	 gotoxy(4,16);
	 printf("Sex : %s",pat.sex);
	 gotoxy(4,17);
	 printf("Age : %d",pat.age);
	 gotoxy(4,18);
	 printf("Address : %s",pat.address);
	 gotoxy(4,19);
	 printf("Contact No. : %s",pat.contact);
	 gotoxy(4,20);
	 printf("Vaccination status : %s",pat.v_status);
	 gotoxy(4,21);
	 printf("Vaccine name : %s",pat.v_name);
	 gotoxy(4,22);
	 printf("Date admitted : %s",pat.adm_date);
	 gotoxy(54,9);
	 printf("Delete Record");
	 fflush(stdin);
	 gotoxy(42,15);
	 printf("Do you wish to delete the record ?");
	 gotoxy(42,16);
	 printf("( Y / N ) : ");
	 scanf("%c",&ch);
	 if(ch=='y' || ch=='Y')
	 {
	   gotoxy(54,20);
	   printf("Record Deleted");
	   getch();
	   continue;
	 }
       }
       else
       {
	 fwrite(&pat,sizeof(pat),1,fu5);
       }
     }
     if(f!=1)
      {
	  gotoxy(34,9);
	  printf("Record not found");
	  getch();
	  fclose(fu5);
	  fclose(fp5);
	  choice_page3();
      }
      fclose(fu5);
      fclose(fp5);
      remove("patient.dat");
      rename("p_d.dat","patient.dat");
      choice_page3();
}
void id_chk(int temp)
{
  FILE *fp3;
  struct patient pat;
  fp3 = fopen("patient.dat","rb");
  while(fread(&pat,sizeof(pat),1,fp3)==1)
       {
	if(temp == pat.id)
	{
	  gotoxy(36,20);
	  printf("ID exists");
	  getch();
	  fclose(fp3);
	  p_entry();
	}
	else
	  continue;
     }
     fclose(fp3);
  }
void staff_del()
{
     struct staff stf;
     FILE *fp5,*fu5;
     char ch;
     char inp_name[50],chk_name[50];
     char inp_position[50],chk_position[50];
     int f;
     cleardevice();
     fp5 = fopen("staff.dat","rb");
     fu5 = fopen("s_d.dat","wb");
     cleardevice();
     project_name();
     rectangle(10,10,625,450);
     line(10,150,625,150);
     line(317,450,317,150);
     gotoxy(32,5);
     printf("Delete staff details");
     fflush(stdin);
     gotoxy(32,7);
     printf("Enter Staff Name : ");
     gets(chk_name);
     gotoxy(32,8);
     printf("Enter Staff Position : ");
     gets(chk_position);
     while(fread(&stf,sizeof(stf),1,fp5))
     {
       if(strcmp(chk_name,stf.name)==0 && strcmp(chk_position,stf.position)==0 )
       {
	 f=1;
	 gotoxy(15,9);
	 printf("Record Found");
	 gotoxy(4,12);
	 printf("Name : %s",stf.name);
	 gotoxy(4,13);
	 printf("Position : %s",stf.position);
	 gotoxy(4,14);
	 printf("Year joined : %d",stf.year);
	 gotoxy(4,15);
	 printf("Contact : %s",stf.contact);
	 gotoxy(4,16);
	 printf("Address : %s",pat.address);
	 gotoxy(54,9);
	 printf("Delete Record");
	 fflush(stdin);
	 gotoxy(42,15);
	 printf("Do you wish to delete the record ?");
	 gotoxy(42,16);
	 printf("( Y / N ) : ");
	 scanf("%c",&ch);
	 if(ch=='y' || ch=='Y')
	 {
	   gotoxy(54,20);
	   printf("Record Deleted");
	   getch();
	   continue;
	 }
       }
       else
       {
	 fwrite(&stf,sizeof(stf),1,fu5);
       }
     }
     if(f!=1)
      {
	  gotoxy(34,9);
	  printf("Record not found");
	  getch();
	  fclose(fu5);
	  fclose(fp5);
	  remove("s_d.dat");
	  choice_page4();
      }
      fclose(fu5);
      fclose(fp5);
      remove("staff.dat");
      rename("s_d.dat","staff.dat");
      choice_page4();
}









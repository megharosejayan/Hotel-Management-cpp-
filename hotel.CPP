


//Header Files Used

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
#include<iomanip.h>
#include<dos.h>

void checkin();
void checkout();
void viewdetails();
void choice();
void billing(int);
void enterstaff();
void searchstaff();
void showstaff();
void addstaff();
void viewstaff();

//Class

class hotel
{
  public:
  int sno;
  char sname[20];
  char saddr[50];
  long int spno;
  int age;
  long int sal;
  char desg[20];
  char name[20];
  char addr[50];
  long int pno;
  int rno;
  int nod;
  void intro();
  void pass();
  int returnsno();
  void mainmenu();
  void enter()
 {
  nod=0;
  cout<<"Enter name     	:";
  gets(name);
  cout<<"\tEnter address	:";
  gets(addr);
  cout<<"\tPhone Number	     :";
  cin>>pno;
  cout<<"\tno of days :";
  cin>>nod;
 }
 void show()
 {
  cout<<"\n\t Name	  :"<<name;
  cout<<"\n\t Address  	  :"<<addr;
  cout<<"\n\t Phone number:"<<pno;
  cout<<"\n\t No.ofDays   :"<<nod;
 }

}obj;
//end of class//
//password//
void hotel::pass()
{
  char id[10],pass[15];

  for (int i=0;i<3;i++)
  {
    cout<<"\n\n\n\n\n\n\n\t\t\t LOGIN";
    cout<<"\n\t\t\t ~~~~~~~";
    cout<<"\n\t\t\t User Name:";
    gets(id);
    cout<<"\n\t\t\t Password:";
    for(i=0;i<5;i++)
    {
     pass[i]=getch();
     cout<<"*";
    }
    pass[i]='\0';
    getch();
   if ((strcmp(id,"admin")==0)&&(strcmp(pass,"admin")==0))
    {
      cout<<"\n\n\n\t\t\t Login Successfull!!!";
      cout<<"\n\n\n\n\n\n\n\n\t\t\t Press Enter to continue";
      getch();
      mainmenu();
      break;
    }
  else
    {

     cout<<"\n\n\n\t\t\t Invalid Username/Password";

      getch();

     }
    }
   }

 //main menu//
void hotel::mainmenu()
{
 clrscr();
 int a;
 char ch='n';
 do{
    clrscr();
    cout<<"\n\n\t\t\t~~~~~~~~~~~~~~";
    cout<<"\n\t\t\tHOTEL ATLANTIS";
    cout<<"\n\t\t\t~~~~~~~~~~~~~~";

    cout<<"\n\n\t\tAdministrator Menu" ;
    cout<<"\n\t\t~~~~~~~~~~~~~~~~~~";
    cout<<"\n\t\t1.Checkin";
    cout<<"\n\t\t2.Checkout";
    cout<<"\n\t\t3.Viewdetails";
    cout<<"\n\t\t4.Staffrecord";
    cout<<"\n\t\t5.Exit";
    cout<<"\nEnter choice";
    cin>>a,ch;
    switch(a)
   {
    case 1:clrscr();
	   checkin();
	   break;
    case 2:clrscr();
	   checkout();
	   break;
    case 3:clrscr();
	    viewdetails();
	    break;
    case 4:clrscr();
	    choice();
	    break;
    case 5:clrscr();
	   cout<<"Are you sure you want to exit y/n";
	   cin>>ch;
	   if (ch=='y'||ch=='Y')
	   exit(0);
    default:cout<<"\n\t Wrong Choice!!";
	    getch();
   }
  }while(ch=='n'||ch=='N') ;
}
//check in//
void checkin()
{
   int r;
   fstream fs("hotel.dat",ios::in|ios::out|ios::app|ios::binary);
   cout<<"\n\n\t\t\t ~~~~~~~~~~~~";
   cout<<"\n\t\t\t   ATLANTIS";
   cout<<"\n\t\t\t ~~~~~~~~~~~";
   cout<<"\n\t\t\t Check In";
   cout<<"\n\t\t\t~~~~~~~~~";
   cout<<"\n\t Enter room number";
   cin>>r;
   cout<<"\n\t Enter details \n\n\t";
   obj.rno=r;

   obj.enter();obj.show();
 fs.seekg(0,ios::end);
   fs.write((char*)&obj,sizeof(hotel));
   cout<<"\n\t Room booked Successfully";
   cout<<"\n\n\t Press Enter to go back to main menu";
   getch();

 fs.close();
}

void del(int r)
{

  int days=0;
  fstream fs("hotel.dat",ios::in|ios::binary);
  fstream fs1("temp.dat",ios::out|ios::binary);
  while(fs.read((char*)&obj,sizeof(hotel)))
  {
    if (obj.rno==r)
    {
      cout<<obj.nod;
      days=obj.nod;

    }
    else
    {


     fs1.write((char*)&obj,sizeof(hotel));
    }


 } fs.close();
  fs1.close();
  remove("hotel.dat");
  rename("temp.dat","hotel.dat");
  cout<<"\n\t Room vacated!!";
  cout<<"Press enter to continue";
  getch();
  billing(days);
}

void checkout()
{
  clrscr();
  int r;
  char ch;
  cout<<"\n\n\t\t\t~~~~~~~~~~";
  cout<<"\n\t\t\t ATLANTIS";
  cout<<"\n\t\t\t ~~~~~~~~~~";
  cout<<"\n\n\n\t CHECKOUT";
  cout<<"\n\t ~~~~~~~~~~~~";
  cout<<"\n\t Enter room number";
  cin>>r;
  fstream fs("hotel.dat",ios::in|ios::binary);
  while(fs.read((char*)&obj,sizeof(hotel)))
  {
    if(obj.rno==r)
    {
      obj.show();
      cout<<"\n\n\t Do you really want to vacate?(y/n)";
      cin>>ch;
      if(ch=='y'||ch=='Y')
      {
      fs.close();
      del(r);}
    }
  }
  getch();
  fs.close();
}
void hotel :: intro()
{
  cout<<"\n\n\n\n\n\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout<<"\n\t\t\t      ATLANTIS, Vegas";
  cout<<"\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout<<"\n\t\t\t Experience the unexperienced!!!!";
  gotoxy(2,24);
  cout<<"\tAddress: 8120, Vegas block,Las Vegas";
  cout<<"NV 94356, United states";
  gotoxy(2,25);
  cout<<"\tPhone number: +124786";
  gotoxy(28,17);
  cout<<"press enter to continue";
  getch();
  clrscr();
}

void billing(int days)
{
   clrscr();
   int pamt,pf,ramt=115,mamt=20;

   char ch;
   int flag;
   do
   {
     cout<<"\n\n\n\n\n\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~";
     cout<<"\n\t\t\t      ATLANTIS, Vegas";
     cout<<"\n\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~";
     cout<<"\n\tBilling";
     cout<<"\n\t~~~~~~~~~~~~";
     cout<<"\n\n\t No.of days:"<<days;
     cout<<"\n\n\t Include parking fee? (y/n)";
     cin>>ch;
     if(ch=='y'||ch=='Y')
     {
       pf=10;
       pamt=days*10;
       flag=1;
       break;
     }
     else if(ch=='n'||ch=='N')
     {
       pf=0;
       pamt=0;
       flag=1;
       break;
     }
     else
     {
       cout<<"Please enter y/n";
       flag=0;
       getch();
       clrscr();
     }
   }while(flag!=1);
   cout<<"\n\n\t Press enter to generate invoice";
   getch();
   clrscr();
   cout<<"\n\n\t________________";
   cout<<"________________";
   cout<<"________________";
   cout<<"________________";
   cout<<"\n"<<setw(10)<<"|"<<setw(60)<<"|";
   cout<<"\n\t |\t\tATLANTIS       \t\t  |";
   cout<<"\n\t |\t\t~~~~~~~~       \t\t  |";
   cout<<"\n\t |\t\t\t INVOICE\t\t\t  |";
   cout<<"\n\t |\t\t\t ~~~~~~~\t\t\t  |";
   cout<<"\n\t |\t\t\t\t\t\t\t  |";
   cout<<"\n\t |___________________________________|";
   cout<<"\n\t |  ITEM\t\tRATES PER DAY\t\tTOTAL  |";
   cout<<"\n\t |  ~~~~\t\t~~~~~~~~~~~~~\t\t~~~~~  |";
   cout<<"\n"<<setw(10)<<"|"<<"1.Room Rent";
   cout<<setw(17)<<"$115";
   cout<<setw(90)<<"$"<<ramt*days;
   gotoxy(70,13);
   cout<<"|"<<"\n"<<setw(10)<<"|"<<"2.Maintenance";
   cout<<setw(14)<<"$20";
   cout<<setw(20)<<"$"<<mamt*days;
   gotoxy(70,14);
   cout<<"|"<<"\n"<<setw(10)<<"|"<<"3.Parking Fees";
   gotoxy(37,15);
   cout<<"$"<<pf;
   gotoxy(59,15);
   cout<<"$"<<pamt;
   gotoxy(70,15);
   cout<<"|"<<"\n"<<setw(10)<<"|"<<setw(60)<<"|"<<"\n"<<setw(10)<<"|";
   cout<<"---------";
   cout<<"-----------------------------";
   cout<<"--------------------|";
   cout<<"\n"<<setw(10)<<"|"<<setw(45);
   cout<<"GRAND TOTAL:"<<setw(4);
   cout<<"$"<<pamt+(ramt+mamt)*days;
   gotoxy(70,18);
   cout<<"|";
   cout<<"\n"<<setw(10)<<"|"<<"------------------------------------------";
   cout<<"\n"<<setw(10)<<"|"<<setw(43);
   cout<<"Hope You Enjoyed Your Stay.";
   cout<<setw(17)<<"|";
   cout<<"\n"<<setw(10)<<"|"<<setw(41);
   cout<<"Please Visit Again";
   cout<<setw(19)<<"|";
   cout<<"\n"<<setw(10)<<"|";
   cout<<"---------------------------------------------------------------|";
   cout<<"\n\n\n\t Press any key to move to menu";
   getch();
   clrscr();
   obj.mainmenu();
   }



void viewdetails()
{
int a;
clrscr();
cout<<"\n\n\n\n\t~~~~~~~~~~~~~~~~";
cout<<"\n\t\t\t    ATLANTIS";
cout<<"\n\t\t\t~~~~~~~~~~~~~~~~";

cout<<"\n\n\t DETAILS";
int x=11;
int y=12;

fstream fs("hotel.dat",ios::in|ios::out|ios::binary);
gotoxy(1,8);
cout<<"\n\tROOM No "<<"\tname"<<"\t Adress\t"<<"/tphone no";
cout<<"\n\t______________________________________________________";

while(fs.read((char*)&obj,sizeof(hotel)))
{
gotoxy(9,x);
cout<<obj.rno;
gotoxy(24,x);
cout<<obj.name;
gotoxy(36,x);
cout<<obj.addr;
gotoxy(50,x);
cout<<obj.pno;
x+=3,y+=3;
}
cout<<"\n\n\nPress enter to go back to menu";
fs.close();
getch();
}
void choice()
 {  clrscr();
int c;
cout<<"\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\n\t\t\tATLANTIS";
cout<<"\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\nmenu";
cout<<"\n1.Add staff details";
cout<<"\n2.view staff details";
cout<<"\n3.Remove staff details";
cout<<"\n4.Search staff details";
cout<<"\n enter your choice";
cin>>c;
switch(c)
{
 case 1:clrscr();
	addstaff();
	break;
 case 2:clrscr();
	viewstaff();
	break;

 case 3:clrscr();
	searchstaff();
	break;

 default:cout<<"invalid choice";
 }
 }
void enterstaff()
{
  cout<<"\n\n\t\t\t\t ~~~~~~~~~~~~~";
  cout<<"\n\t\t\t ATLANTIS";
  cout<<"\n\t\t\t ~~~~~~~~~~~";

  cout<<"\n\n\n\t Enter staff details";
  cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~";
  cout<<"\n Enter staff number";
  cin>>obj.sno;
  char ch;
  cin.get(ch);
  cout<<"\n Enter name";
  cin.getline(obj.sname,20);
  cout<<"\n Enter address";
  cin.getline(obj.saddr,50);
  cout<<"\n Enter designation";
  cin.getline(obj.desg,30);
  cout<<"\n Enter salary";
  cin>>obj.sal;
  cout<<"\n Enter phone number";
  cin>>obj.spno;
  cout<<"\n Enter age";
  cin>>obj.age;
}
void addstaff()
{
  clrscr();
  cout<<"\n\n\t\t\t ~~~~~~~";
  cout<<"\n\t\t\t ATLANTIS";
  cout<<"\n\t\t\t ~~~~~~~~~~~~~~~~~~~";
  cout<<"\n\n\n\t ADDSTAFF";
  ofstream ofs("staff.dat",ios::out|ios::app|ios::binary);
  cout<<"Enter details of staff";
  enterstaff();
  ofs.write((char*)&obj,sizeof(hotel));
  cout<<"\n Details added";
  cout<<"\n Returning to main menu";
  delay(500);
  ofs.close();
}

void viewstaff()
{
  int a;
  clrscr();
  cout<<"\n\n\n\n\t~~~~~~~~~~~~~~~~";
  cout<<"\n\t\t\t    ATLANTIS";
  cout<<"\n\t\t\t~~~~~~~~~~~~~~~~";

  cout<<"\n\n\t STAFF DETAILS";
  int x=11;
  int y=12;

  fstream fs("staff.dat",ios::in|ios::out|ios::binary);
gotoxy(1,8);
cout<<"\n\tStaff No "<<"\tName"<<"\tAdress"<<"\tDesignation"<<"\tSalary"<<"\tphone no";
cout<<"\n\t______________________________________________________";

while(fs.read((char*)&obj,sizeof(hotel)))
{
gotoxy(9,x);
cout<<obj.sno;
gotoxy(24,x);
cout<<obj.sname;
gotoxy(36,x);
cout<<obj.saddr;
gotoxy(50,x);
cout<<obj.desg;
gotoxy(65,x);
cout<<obj.sal;
gotoxy(72,x);
cout<<obj.spno;
x+=3,y+=3;
}
cout<<"\n\n\nPress enter to go back to menu";
fs.close();
getch();
}
void searchstaff()
{
  cout<<"\n\n\t\t\t ~~~~~~~~~~~~~~~";
  cout<<"\n\t\t\t ATLANTIS";
  cout<<"\n\t\t\t ~~~~~~~~";
  cout<<"\n\n\n\t SEARCHSTAFF";
  int x;
  int flag=0;
  cout<<"Enter the id of the the staff";
  cin>>x;
  ifstream ifs("staff.dat",ios::in|ios::binary);
  while(ifs.read((char*)&obj,sizeof(hotel)))
  {
    if(x==obj.returnsno())
    {
     flag =1;
     showstaff();
    }
  }
  ifs.close();
  if (flag==0)
  cout<<"\n record not found !!";
  cout<<"\n returning to main menu";
  getch();
}

 void showstaff()
 {
  cout<<"\n\n\t\t\t\t ~~~~~~~~~~~~~";
  cout<<"\n\t\t\t ATLANTIS";
  cout<<"\n\t\t\t ~~~~~~~~~~~";

  cout<<"\n\n\n\t Enter staff details";
  cout<<"\n\t ~~~~~~~~~~~~~~~~~~~~";
  cout<<"\n Enter staff number";
  cout<<obj.sno;

  cout<<"\n name";
  cout<<obj.sname;
  cout<<"\n address";
  cout<<obj.saddr;
  cout<<"\n designation";
  cout<<obj.desg;
  cout<<"\n salary";
  cout<<obj.sal;
  cout<<"\n phone number";
  cout<<obj.spno;
  cout<<"\n age";
  cout<<obj.age;
}
int hotel:: returnsno()
{
 return obj.sno;
}

void main()
{
 clrscr();

 obj.intro();
 obj.pass();

 getch();
}






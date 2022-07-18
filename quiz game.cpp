#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string>
using namespace std;
int hours=0, minutes=10, seconds=0;
string ques,a,b,c,d,user_name,teacher_name;
int ques_no,correct=0,wrong=0;
char ans;
void gotoxy(int x, int y);
void result();
void welcome();
void login();
void teacherlogin();
void studentlogin();
void teachermenu();
void studentmenu();
void instructions();
void studentdisplay();
void ins(string ques, string a, string b, string c, string d, char ans);
void addquestion();
void Delete();
void update(int update_ques,  string ques, string a, string b, string c, string d, char ans );
void updatequestion();
void settime();
void teacherdisplay();

struct node{
int question_no;
string question;
string option_a;
string option_b;
string option_c;
string option_d;
char correctanswer;

node* next;
node* prev;

};
node* head, *temp, *l;

int size=0;

int main(){
welcome();
login();



}

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void welcome(void){
char wel[] = " W  E  L  C  O  M  E ";
char wel1[] = " T  O ";
char wel2[] = " Q  U  I  Z    G  A  M  E ";
char wel3[] = "DEVELOPED BY: SP20-BCS-007, SP20-BCS-100, SP20-BCS-064, SP19-BCS-141";
int  j;
gotoxy(40,6);
for (j = 0;j< sizeof(wel) ;j++) {
    Sleep(50);
    cout<< wel[j];
  }

  gotoxy(46,10);
for (j = 0;j< sizeof(wel1) ;j++) {
    Sleep(50);
    cout<< wel1[j];
  }
  gotoxy(37,14);
for (j = 0;j< sizeof(wel2) ;j++) {
    Sleep(50);
    cout<< wel2[j];
  }

   gotoxy(40,25);
for (j = 0;j< sizeof(wel3) ;j++) {
    Sleep(55);
    cout<< wel3[j];
  }
Sleep(1000);
system("CLS");
}

void login(){
string name;
char checklogin;
char p[] = "************WELCOME TO LOGIN PAGE************";
  int j;
  gotoxy(30,6);
  for (j = 0;j< sizeof(p) ;j++) {
    Sleep(50);
    cout<< p[j];
  }
  gotoxy(35,9);
  cout<< "For Teacher login press 1";
  gotoxy(35,11);
  cout<< "For Student login press 2";
  gotoxy(30,13);
  cout<< "*********************************************";
  gotoxy(30,15);
  cout<< "Press 1 and 2 for Login and ESC for exit: ";

do{
  checklogin=getch();

  if(checklogin==49){
    system("CLS");
    teacherlogin();
  }else if(checklogin==50){
   system("CLS");
    studentlogin();
  }else if(checklogin==27){
      system("cls");
     gotoxy(36,6);
        cout<<"======================================="<<endl;
        gotoxy(36,7);
        cout<<"==                                   =="<<endl;
        gotoxy(36,8);
        cout<<"==                                   =="<<endl;
         gotoxy(36,9);
        cout<<"==     Q U I Z     Q U I T E D !     =="<<endl;
        gotoxy(36,10);
        cout<<"==                                   =="<<endl;
        gotoxy(36,11);
        cout<<"==      A L L A H   H A F I Z !      =="<<endl;
        gotoxy(36,12);
        cout<<"==                                   =="<<endl;
        gotoxy(36,13);
        cout<<"==                                   =="<<endl;
        gotoxy(36,14);
        cout<<"======================================="<<endl;
        Sleep(3000);
        system("cls");
  exit(0);
  }else{
  cout<<endl <<"YOU ENTER AN INVALID INPUT: "<<endl;
  cout<<"PRESS KEY: ";
  }
}while(checklogin!=27);
}

void teacherlogin(){
    int key;
    int i=0;
    char ch;
    char password[]="murtaza";
    char s[20];
char p[] = "************WELCOME TO TEACHER'S LOGIN PAGE************";
  int j;
  gotoxy(30,6);
  for (j = 0;j< sizeof(p) ;j++) {
    Sleep(50);
    cout<< p[j];
  }
   gotoxy(35,9);
   cout<<"Enter your name: ";
   cin>>teacher_name;
   gotoxy(35,11);
   cout<<"Enter password: ";

    do{
       ch=getch();
     if(ch!=8&&ch!=13){
         cout<<"*";
         s[i]=ch;
         i++;
        }else if (ch==8){
         cout<<"\b \b";
         i--;
       }else if(ch==13){
        break;
        }
    }while(i>=0);
  if(strcmp(s,password)==0){
   system("CLS");
   teachermenu();
  }else{

      gotoxy(35,13);
      cout<<"Your Password is InCorrect";
      gotoxy(35,15);
      cout<<"For Again Login Press any key and ESC for exit: ";
      ch=getch();
      if(ch!=27){
      system("CLS");
      teacherlogin();
      }else{
          system("CLS");
          login();
      }
  }

}

void studentlogin(){

    int key;
    int i=0;
    char ch;
    char password[]="murtaza";
    char s[20];
char p[] = "************WELCOME TO STUDENTS'S LOGIN PAGE************";
  int j;
  gotoxy(30,6);
  for (j = 0;j< sizeof(p) ;j++) {
    Sleep(50);
    cout<< p[j];
  }
   gotoxy(35,9);
   cout<<"Enter your name: ";
   cin>>user_name;
   gotoxy(35,11);
   cout<<"Enter password: ";

    do{
       ch=getch();
     if(ch!=8&&ch!=13){
         cout<<"*";
         s[i]=ch;
         i++;
        }else if (ch==8){
         cout<<"\b \b";
         i--;
       }else if(ch==13){
        break;
        }
    }while(i>=0);
  if(strcmp(s,password)==0){
   system("CLS");
   studentmenu();
  }else{

      gotoxy(35,13);
      cout<<"Your Password is InCorrect!";
      gotoxy(35,15);
      cout<<"For Again Login Press any key and ESC for exit: ";
      ch=getch();
      if(ch!=27){
      system("CLS");
      studentlogin();
      }else{
          system("CLS");
          login();
      }
  }
}

void teachermenu(){
  char ch;
  int no;
  char p[] = "************WELCOME TO TEACHER'S MENU PAGE************";
  int j;
  gotoxy(30,6);
  for (j = 0;j< sizeof(p) ;j++) {
    Sleep(50);
    cout<< p[j];
  }
  gotoxy(35,9);
  cout<<"PRESS 1: TO ADD QUESTION: ";
  gotoxy(35,11);
  cout<<"PRESS 2: FOR UPDATE QUESTION: ";
  gotoxy(35,13);
  cout<<"PRESS 3: FOR DELETE QUESTION: ";
  gotoxy(35,15);
  cout<<"PRESS 4: TO ADD TIME FOR QUIZ: ";
  gotoxy(35,17);
  cout<<"PRESS 5: TO DISPLAY QUESTIONS YOU ENTER: ";
  gotoxy(35,19);
  cout<<"PRESS ESC: TO EXIT THE MENU: ";
  gotoxy(30,22);
  cout<< "******************************************************";
  gotoxy(30,24);
  cout<<"PRESS KEY: ";

  do{
    ch=getch();
  if(ch==49){
    system("CLS");
    Sleep(100);
    addquestion();
  }else if(ch==50){
    system("CLS");
    Sleep(100);
    updatequestion();
  }else if(ch==51){
    system("CLS");
    Delete();
}else if(ch==52){
    system("CLS");
    settime();

}else if(ch==53){
        system("CLS");
   teacherdisplay();
   cout<<endl<<"Press ESC: TO ESCAPE: ";
   do{
    ch=getch();
   if(ch==27){
   system("CLS");
   teachermenu();
   }else{
   cout<<endl<<"Invalid Input";
   }
   }while(ch!=27);
}else if(ch==27){
    system("CLS");
    login();
}else{
  cout<<endl <<"YOU ENTER AN INVALID INPUT: "<<endl;
  cout<<"PRESS KEY: ";
}
}while(ch!=27);

}

void studentmenu(){
char ch;
  char p[] = "************WELCOME TO STUDENT'S MENU PAGE************";
  int j;
  gotoxy(30,6);
  for (j = 0;j< sizeof(p) ;j++) {
    Sleep(50);
    cout<< p[j];
  }
  gotoxy(35,9);
  cout<<"PRESS 1: TO START QUIZ: ";
  gotoxy(35,11);
  cout<<"PRESS 2: FOR INSTRUCTIONS: ";
  gotoxy(35,13);
  cout<<"PRESS ESC: TO EXIT THE MENU: ";
  gotoxy(30,16);
  cout<< "******************************************************";
  gotoxy(30,18);
  cout<<"PRESS KEY: ";

  do{
  ch=getch();
  if(ch==49){
    system("CLS");
    Sleep(100);
    studentdisplay();
  }else if(ch==50){
     system("CLS");
    Sleep(100);
    instructions();
    do{
        ch=getch();
    if(ch==27){
        system("CLS");
        studentmenu();
    }else{
      cout<<endl <<"YOU ENTER AN INVALID INPUT: "<<endl;
      cout<<"PRESS KEY: ";
    }
    }while(ch!=27);

   }else if(ch==27){
   system("CLS");
   login();
   }else{
   cout<<endl <<"YOU ENTER AN INVALID INPUT: "<<endl;
   cout<<"PRESS KEY: ";
    }
  }while(ch!=27);

}

void instructions(){
gotoxy(30,6);
    cout << "------------------------------------------------";
    gotoxy(30,7);
    cout << "=                INSTRUCTIONS                  =";
    gotoxy(30,8);
    cout << "------------------------------------------------";
    gotoxy(30,9);
    cout << "=  This quiz consists of 10 multiple-choice    =";
    gotoxy(30,10);
    cout << "=  questions. You will need to complete each   =";
    gotoxy(30,11);
    cout << "=  of your attempts in one sitting, as you     =";
    gotoxy(30,12);
    cout << "=  are allotted 30 minutes to complete each    =";
    gotoxy(30,13);
    cout << "=  attempt.                                    =";
    gotoxy(30,14);
    cout << "------------------------------------------------";
    gotoxy(30,15);
    cout << "=                Total Marks = 50              =";
    gotoxy(30,16);
    cout << "------------------------------------------------";
    gotoxy(30,19);
    cout << "PRESS ESC: TO BACK TO STUDENT MENU:";
    gotoxy(30,21);
    cout << "PRESS KEY: ";

}

void studentdisplay(){
    wrong=0;
    correct=0;
    l=head;
    char ch;
    int i=0;
    int timer=10;
    if(l==NULL){
        gotoxy(36,6);
        cout<<"================================================="<<endl;
        gotoxy(36,7);
        cout<<"==                                             =="<<endl;
        gotoxy(36,8);
        cout<<"==                                             =="<<endl;
         gotoxy(36,9);
        cout<<"==NONE OF THE QUIZ HAS BEEN CREATED BY TEACHER!=="<<endl;
        gotoxy(36,10);
        cout<<"==                                             =="<<endl;
        gotoxy(36,11);
        cout<<"==     YOU  HAVE  NO  QUESTIONS  TO  SOLVE     =="<<endl;
        gotoxy(36,12);
        cout<<"==                                             =="<<endl;
        gotoxy(36,13);
        cout<<"==        ARE  YOU  WANT  TO  LOGOUT?          =="<<endl;
        gotoxy(36,14);
        cout<<"==                                             =="<<endl;
        gotoxy(36,15);
        cout<<"==         PRESS  ESC:   FOR  ESCAPE           =="<<endl;
        gotoxy(36,16);
        cout<<"==                                             =="<<endl;
        gotoxy(36,17);
        cout<<"==                                             =="<<endl;
        gotoxy(36,18);
        cout<<"==                                             =="<<endl;
        gotoxy(36,19);
        cout<<"================================================="<<endl;

        do{
           ch=getch();
           if(ch==27){
            system("CLS");
            login();
        }else{
           cout<<"Invalid Input: "<<endl;
           cout<<"PRESS ESC: FOR ESCAPE"<<endl;
        }
        }while(ch!=27);



    }else{
    for(timer;timer>0;timer--){
    gotoxy(30,6);
    cout << "*******************QUIZ STARTS*******************";
    gotoxy(40,8);
    cout<<"TIME FOR QUIZ IS: "<<hours <<":" <<minutes <<":" << seconds;
    gotoxy(40,10);
    cout << "Please attempt all questions:";
    gotoxy(30,14);
    cout << "*************************************************";
        gotoxy(48,12);
        cout<<"GET READY: " <<timer;
        Sleep(1000);
        system("CLS");
    }

    again:
        if (l!=NULL){
           i++;
        while (hours!=0||minutes!=0||seconds!=0){
        gotoxy(100,3);
        cout<< "TIMER: "<<hours <<":" <<minutes <<":" << seconds;
        cout<<endl<<"Question no "<<i <<": " <<l->question <<endl;
        cout<<"A) "<<l->option_a<<endl;
        cout<<"B) "<<l->option_b<<endl;
        cout<<"C) "<<l->option_c<<endl;
        cout<<"D) "<<l->option_d<<endl;
        cout<<endl<<"Enter correct option: ";
       Sleep(1000);
        if (kbhit()==1){
         ch=getch();
         cout<<ch;
         Sleep(500);
         if(ch==l->correctanswer){
            correct++;
        }else{
        wrong++;
        }
        l=l->next;
        system("cls");
        goto again;
        }
        if(minutes==0&&seconds==0){
            hours--;
            minutes=60;
        }if(seconds==0){
            minutes--;
            seconds=60;

        }
            seconds--;
        system("cls");
        }
        gotoxy(40,6);
        cout<<"=========================="<<endl;
         gotoxy(40,7);
        cout<<"======             ======="<<endl;
         gotoxy(40,8);
        cout<<"======             ======="<<endl;
         gotoxy(40,9);
        cout<<"====== TIME  OVER! ======="<<endl;
         gotoxy(40,10);
        cout<<"======             ======="<<endl;
         gotoxy(40,11);
        cout<<"======             ======="<<endl;
         gotoxy(40,12);
        cout<<"=========================="<<endl;
        Sleep(3000);
        l=l->next;
goto again;
}
wrong= i-correct;
system("CLS");
result();
    }
}


void teacherdisplay(){
    l=head;
    int i=0;
    cout <<endl<< "FOLLOWING ARE THE QUESTIONS:";
    while(l!=NULL){
            i++;
        cout<<endl<<"Question no "<<i<< ": "<<l->question<<endl;
        cout<<"A) "<<l->option_a<<endl;
        cout<<"B) "<<l->option_b<<endl;
        cout<<"C) "<<l->option_c<<endl;
        cout<<"D) "<<l->option_d<<endl;
        cout<<"Correct Answer: "<<l->correctanswer<<endl;
        l=l->next;
    }
}


void ins(int ques_no, string ques, string a, string b, string c, string d, char ans){
    l=head;
if(head==NULL){
    head=new node;
    head->question_no=ques_no;
    head->question=ques;
    head->option_a=a;
    head->option_b=b;
    head->option_c=c;
    head->option_d=d;
    head->correctanswer=ans;
    head->next=NULL;
    head->prev=NULL;

}else{
while(l->next!=NULL){
    l=l->next;
}
    temp=new node;
    temp->question_no=ques_no;
    temp->question=ques;
    temp->option_a=a;
    temp->option_b=b;
    temp->option_c=c;
    temp->option_d=d;
    temp->correctanswer=ans;
    temp->next=NULL;
    temp->prev=l;
    l->next=temp;
}
size++;
cout<<"SUCCESSFULLY ENTER"<<endl;
}

void addquestion(){
char ch;
int n,i;
cout<<"How many questions you want to enter: ";
cin>>n;
for(i=1;i<=n;i++){
    getline(cin , ques);
    cout<<"Enter question no " << i<< ": ";
    getline(cin, ques);
    cout<<"Enter option A: ";
    getline(cin, a);
    cout<<"Enter option B: ";
    getline(cin, b);
    cout<<"Enter option C: ";
    getline(cin, c);
    cout<<"Enter option D: ";
    getline(cin, d);
    cout<<endl<<"Correct Answer for Question no "<<i<<": ";
    cin>>ans;
    ins(i,ques,a,b,c,d,ans);
}
do{
cout<<"PRESS ESC: FOR EXIT: "<<endl;
ch=getch();
}while(ch!=27);
if(ch==27){
   system("CLS");
    teachermenu();
}
}

void Delete() {
    int index;
    char ch;
 system("CLS");
teacherdisplay();
if (head==NULL){
        system("cls");
         gotoxy(36,6);
        cout<<"======================================="<<endl;
        gotoxy(36,7);
        cout<<"==                                   =="<<endl;
        gotoxy(36,8);
        cout<<"==                                   =="<<endl;
         gotoxy(36,9);
        cout<<"==YOU HAVE   NO QUESTIONS  TO DELETE!=="<<endl;
        gotoxy(36,10);
        cout<<"==                                   =="<<endl;
        gotoxy(36,11);
        cout<<"==                                   =="<<endl;
        gotoxy(36,12);
        cout<<"======================================="<<endl;
    Sleep(4000);
    system("cls");
    teachermenu();
}
do{
cout<<endl<<"Enter Question No to delete: ";
cin>>index;
    l = head;
    if (index > 0 && index <= size) {
        if (index == 1) {
            if (size == 1) {
                temp = head;
                head = NULL;
                delete(temp);
            }else{
                temp = head;
                head = head->next;
                head->prev = NULL;

                delete(temp);
            }

        } else {
            if (index == size) {
                int counter = 1;
                while(counter != index-1) {
                    counter++;
                    l = l->next;
                }
                temp = l->next;
                l->next = NULL;

                delete(temp);
            } else {
                int counter = 1;
                while(counter != index-1) {
                    counter++;
                    l = l->next;
                }
                temp = l->next;
                l->next = temp->next;
                temp->next->prev = l;
                delete(temp);
            }
        }
                   system("cls");
         gotoxy(36,6);
        cout<<"=========================================="<<endl;
        gotoxy(36,7);
        cout<<"==                                       =="<<endl;
        gotoxy(36,8);
        cout<<"==                                       =="<<endl;
         gotoxy(36,9);
        cout<<"==S U C C E S S F U L L Y  D E L E T E D!=="<<endl;
        gotoxy(36,10);
        cout<<"==                                       =="<<endl;
        gotoxy(36,11);
        cout<<"==                                       =="<<endl;
        gotoxy(36,12);
        cout<<"==========================================="<<endl;
    Sleep(3000);
             size--;
             system("cls");
    }else{

           system("cls");
         gotoxy(36,6);
        cout<<"======================================="<<endl;
        gotoxy(36,7);
        cout<<"==                                   =="<<endl;
        gotoxy(36,8);
        cout<<"==                                   =="<<endl;
         gotoxy(36,9);
        cout<<"==INPUT QUESTION NO. IS NOT AVAILABLE!=="<<endl;
        gotoxy(36,10);
        cout<<"==                                   =="<<endl;
        gotoxy(36,11);
        cout<<"==                                   =="<<endl;
        gotoxy(36,12);
        cout<<"======================================="<<endl;
    Sleep(3000);
    system("cls");
    }
     teacherdisplay();
    cout<<endl<<endl<<"IF you want to delete more Questions?: "<<endl;
  cout<< "PRESS Any key: For YES"<<endl;
  cout<< "PRESS ESC: For NO"<<endl;
  cout<< "PRESS KEY: ";
  ch=getch();
  if (ch!=27){
    Delete();
  }else if (ch==27){
    system("CLS");
    teachermenu();
  }
 }while(ch!=27);
}

void updatequestion(){
   char ch;
   int update_ques;
   teacherdisplay();
    do{
            if (head==NULL){
        gotoxy(36,6);
        cout<<"======================================="<<endl;
        gotoxy(36,7);
        cout<<"==                                   =="<<endl;
        gotoxy(36,8);
        cout<<"==                                   =="<<endl;
         gotoxy(36,9);
        cout<<"==NO QUESTIONS AVAILABLE FOR  UPDATE!=="<<endl;
        gotoxy(36,10);
        cout<<"==                                   =="<<endl;
        gotoxy(36,11);
        cout<<"==                                   =="<<endl;
        gotoxy(36,12);
        cout<<"======================================="<<endl;
                break;
            }
    cout<<"Enter question no you want to update: ";
    cin>>update_ques;
    if (update_ques<=size && update_ques>0){

    getline(cin , ques);
    cout<<"Enter updated question: ";
    getline(cin, ques);
    cout<<"Enter updated option A: ";
    getline(cin, a);
    cout<<"Enter updated option B: ";
    getline(cin, b);
    cout<<"Enter updated option C: ";
    getline(cin, c);
    cout<<"Enter updated option D: ";
    getline(cin, d);
    cout<<"Correct Answer for updated Question: ";
    cin>>ans;
    update(update_ques,ques,a,b,c,d,ans);
    }
    else{
            system("cls");
            gotoxy(36,6);
        cout<<"======================================="<<endl;
        gotoxy(36,7);
        cout<<"==                                   =="<<endl;
        gotoxy(36,8);
        cout<<"==                                   =="<<endl;
         gotoxy(36,9);
        cout<<"==This Question No. is not Available!=="<<endl;
        gotoxy(36,10);
        cout<<"==                                   =="<<endl;
        gotoxy(36,11);
        cout<<"==                                   =="<<endl;
        gotoxy(36,12);
        cout<<"======================================="<<endl;
    Sleep(4000);
    }
    system("cls");
    teacherdisplay();

     cout<<endl<<"IF you want to update more questions: ";
     cout<<endl<<"Press Y: For YES ";
     cout<<endl<< "PRESS ESC: TO EXIT: "<<endl;
      ch=getch();
if(ch=='y'||ch=='Y'){
    updatequestion();
}else{
break;
}
}while(ch!=27);


   Sleep(2000);
    system("CLS");
    teachermenu();

}

void update(int update_ques,  string ques, string a, string b, string c, string d, char ans ){
 l=head;
		while(l->question_no!=update_ques){
			l=l->next;
		}
    l->question=' ';
    l->option_a=' ';
    l->option_b=' ';
    l->option_c=' ';
    l->option_d=' ';
    l->correctanswer=' ';

    l->question=ques;
    l->option_a=a;
    l->option_b=b;
    l->option_c=c;
    l->option_d=d;
    l->correctanswer=ans;

cout<<"Successfully updated";
}

void settime(){
int ch;
cout<<"Enter hours: ";
cin>>hours;
cout<<"Enter minutes: ";
cin>>minutes;
cout<<"Enter seconds: ";
cin>>seconds;
cout<<"Press ESC key: TO ESCAPE ";
do{
ch=getch();
if(ch==27){
    system("CLS");
    teachermenu();
}else{
cout<<endl<<"Invalid Input";
cout<<endl<<"Press Again to ESCAPE";
}
}while(ch!=27);
}





void result(){
    char ch;
    float CGPA;
    float percentage;
    char Grade;
    percentage = (correct*100)/size;
    if (percentage<50){
        Grade='F';
        CGPA = 2.00;
    }else if (percentage >=50 && percentage <=65 ){
        Grade='C';
        CGPA= 2.70;

    }else if (percentage >65 && percentage <=75 ){
        Grade='B';
        CGPA = 3.00;

    }else if (percentage >75 && percentage <=85 ){
        Grade='A';
        CGPA = 3.70;

    }else if (percentage >85 ){
        Grade='A';
        gotoxy(58,14);
        cout<<"+";
        CGPA = 4.00;

    }
    gotoxy(30,6);
    cout << "------------------------------------------------";
    gotoxy(30,7);
    cout << "=                Results Card                  =";
    gotoxy(30,8);
    cout << "------------------------------------------------";

    gotoxy(77,9);
    cout<< "=";
    gotoxy(77,10);
    cout<< "=";
    gotoxy(77,11);
    cout<< "=";
    gotoxy(77,12);
    cout<< "=";
    gotoxy(77,13);
    cout<< "=";
    gotoxy(77,14);
    cout<< "=";
    gotoxy(77,15);
    cout<< "=";


    gotoxy(30,9);
    cout << "=        Student Name: "<< user_name;
    gotoxy(30,10);
    cout << "=        Teacher Name: "<< teacher_name;
    gotoxy(30,11);
    cout<<"=           The Correct MCQS are: "<<correct;
    gotoxy(30,12);
    cout<<"=           The Wrong MCQS are: "<<wrong;
    gotoxy(30,13);
    cout<<"=           Total MCQS are: "<<size;
    gotoxy(30,14);
    cout << "=                  Grades: " << Grade ;
    gotoxy(30,15);
    cout << "=                  CGPA: " << CGPA ;

    gotoxy(30,16);
    cout << "------------------------------------------------";

    cout<<endl<<"Press ESC: TO ESCAPE: "<<endl;
    do{
    ch=getch();
    if(ch==27){
        system("CLS");
        login();
    }else{
    cout<<"Invalid Input: "<<endl;
    cout<<"Press ESC: TO ESCAPE: "<<endl;
    }
    }while(ch!=27);
}


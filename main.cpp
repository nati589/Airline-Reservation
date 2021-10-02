/* Airplane Reservation system
   Accepts user information and assigns a seat
   User makes choice of first class or economy and a ticket is issued. */

#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

inline int classChoice();
inline void ticket(int);
void userinfo(int);
void searching();
void change();
//saves ticket on computer
void print(int);

char firstname[100][30],lastname[100][30];
char gender[100][6];
int f_seat=0;//first class seat number
int e_seat=30;//economy class seat number
int age[100],passID[100];
int seatnum[100];


int main(){
   system("color f0");//changes cmd screen
   cout<<"\t\t=================================================================="<<endl;
   cout<<"\t\t****************** Welcome to Dream Airlines!!! ******************"<<endl;
   cout<<"\t\t********************** Reservation menu. *************************"<<endl;
   cout<<"\t\t=================================================================="<<endl;
   here:
   int ch;
    ch = classChoice();
   switch(ch){
     case 1: if(f_seat>29)//checks if first class is full
                 change();
             else
                 userinfo(f_seat);//passes the seat number to use
             f_seat++;
              break;
     case 2: if (e_seat<100){
               userinfo(e_seat);
               e_seat++;
             }
             else
               cout<<"Flight is fully booked."<<endl;
              break;
     case 3: searching();
              break;
     default: cout<<"Invalid choice."<<endl;
              break;
   }
    char x;
    cout<<"Press R to return or any other key to Exit."<<endl;
    cin>>x;
    if(x=='r'||x=='R'){
       system("cls");
       goto here;
    }
    else
       cout<<"\n\tEnjoy your flight!!!"<<endl;
}
//user chooses seat type
int classChoice(){
    int choice;
    cout<<"\n\t\t*** Please press 1 for First class."<<endl;
    cout<<"\t\t*** Please press 2 for Economy class."<<endl;
    cout<<"\t\t*** Please press 3 to Search for a Passenger."<<endl;
    cout<<"\t\t*** Choice: ";
    cin>>choice;
    system("cls");

    return choice;
}
//if first class is full option to switch provided
void change(){
    int ch;
    cout<<"No available tickets. Would you like to switch to economy class? 1 for yes 2 for no."<<endl;
    cin>>ch;
    if(ch==1)
        main();
    else
        cout<<"Next flight in 3 hours."<<endl;
}
//accepts the information to print the ticket
void userinfo(int seat){//parameter accepts seat number
   cout<<"Enter first name: ";
   cin>>firstname[12];
   cout<<"Enter last name: ";
   cin>>lastname[seat];
   cout<<"Enter your age: ";
   cin>>age[seat];
   cout<<"Enter gender."<<endl;
   cout<<"Press M for male, F for female: ";
   cin>>gender[seat];
   cout<<"Enter Passport number: ";
   cin>>passID[seat];
   system("cls");
   ticket(seat);
}
//prints the ticket
void ticket(int seat){//accepts seat number as parameter
   seatnum[seat] = seat + 1;
   if(seat<30){
     cout<<"===================================================="<<endl;
     cout<<"================= FIRST CLASS ======================"<<endl;
   }
   else{
     cout<<"===================================================="<<endl;
     cout<<"================ ECONOMY CLASS ====================="<<endl;
   }
   cout<<"===================================================="<<endl;
   cout<<"*** Name: "<<firstname[seat]<<" "<<lastname[seat]<<endl;;
   cout<<"*** Age: "<<age[seat]<<endl;
   cout<<"*** Sex: "<<strupr(gender[seat])<<endl;//shows gender in capital letters
   cout<<"*** Passport number: "<<passID[seat]<<endl;
   cout<<"*** Seat number: "<<seatnum[seat]<<endl;
   if(seat%2==0)//seat type based on even or odd values
       cout<<"*** Seat type: Window Seat "<<endl;
      else
       cout<<"*** Seat type: Aisle Seat"<<endl;
   cout<<"===================================================="<<endl;
   cout<<"Copy of your ticket has been saved in Boarding ticket.txt"<<endl;
   print(seat);
}
//search engine function
void searching(){
   int counts=0;
   char str1[30];//stores users search
   cout<<"Enter your search: ";
   cin>>str1;
   system("cls");

   cout<<"\n========= RESULT ==================================="<<endl;
   for(int i=0;i<100;i++){
    if(strnicmp(str1,firstname[i],30)==0||strnicmp(str1,lastname[i],30)==0){//compares search with name list
      counts++;//increases if a search matches
      cout<<"===================================================="<<endl;
      if(i<30)
       cout<<"\t\tFIRST CLASS "<<endl;
      else
       cout<<"\t\tECONOMY CLASS"<<endl;

      cout<<"*** Name: "<<firstname[i]<<" "<<lastname[i]<<endl;;
      cout<<"*** Age: "<<age[i]<<endl;
      cout<<"*** Sex: "<<strupr(gender[i])<<endl;
      cout<<"*** Passport number: "<<passID[i]<<endl;
      cout<<"*** Seat number: "<<seatnum[i]<<endl;
      if(i%2==0)
       cout<<"*** Seat type: Window Seat "<<endl;
      else
       cout<<"*** Seat type: Aisle Seat"<<endl;
      cout<<"====================================================\n"<<endl;
    }
   }
   if(counts==0){
     cout<<"No matching results.\n"<<endl;
   }
}
//saves ticket on users computer
void print(int seat){
   ofstream save;
   save.open("Boarding_ticket.txt");//saved in file name Boarding ticket
   save << "=========================================================="<<endl;
   if(seat<30)
       save << "\t\tFIRST CLASS "<<endl;
   else
       save << "\t\tECONOMY CLASS"<<endl;

   save << "***** Name: "<<firstname[seat]<<" "<<lastname[seat]<<endl;;
   save << "***** Age: "<<age[seat]<<endl;
   save << "***** Sex: "<<strupr(gender[seat])<<endl;
   save << "***** Passport number: "<<passID[seat]<<endl;
   save << "***** Seat number: "<<seatnum[seat]<<endl;
   if(seat%2==0)
     save << "***** Seat type: Window Seat "<<endl;
   else
     save << "***** Seat type: Aisle Seat"<<endl;
   save << "==========================================================\n"<<endl;
}


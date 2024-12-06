#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


                                ////   FUNCTIONS   ////
void declarearray(string eventname[],string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100], const int max_events,const int max_participants_per_event,int tickets[]);
void loadheader();
void displaymenu();
void createevent(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,const int max_events);
void editevent(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count);
void deleteevent(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count);
void displayusers(string eventname[],int &event_count,int eventparticipants[],string registration[][100], const int max_events,const int max_participants_per_event);
void adminpanel(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,const int max_events,const int max_participants_per_event,string registration[][100]);
void displayevents(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[]);
void userregistration(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string registration[][100]);
void bookingoftickets(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string registration[][100],int tickets[]);
void userfeedback(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count ,string feedback[]);
void userpanel(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100],int tickets[]);
  
              // validation functions  //

bool isadmin(string username, string password);
bool isvalidnamelength(string name);
bool isalphabets(string name);
bool isvalidphonenolength(string phoneno);
bool isnumericphoneno(string phoneno);
bool isvalidphoneno(string phoneno);
bool isvaliddate(string date);
bool isvalidtime(string time);
int  stringtointeger(string option);
bool savedata(string eventname[],string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100], const int max_events,int tickets[]);
bool loaddata(string eventname[],string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100], const int max_events, int tickets[]);


 // main function
int main() {

     const int max_events = 500;
     const int max_participants_per_event = 100;

        string eventname[max_events];                                               // for storing event namess
        string eventdate[max_events];                                               // for storing event dates
        string eventtime[max_events];                                               // for storing event time
        string eventlocation[max_events];                                           // for storing event location
        string registration[max_events][max_participants_per_event];                // for storing data of registered students
        string feedback[max_events];                                                // for storing feedback of users
        int tickets[max_events];                                                    // for storing no. of booked tickets
        int eventparticipants[max_events];                                          // for storing no. of participants
        int max_capacity[max_events];                                               // for max capacity of participants
        int event_count;                                                            // for counting the no. of events

    declarearray(eventname,eventdate,eventtime,eventlocation, eventparticipants,max_capacity,event_count,feedback,registration,max_events,max_participants_per_event,tickets);

    int option;
    string username, password;

    system("cls");
    loaddata(eventname,eventdate,eventtime,eventlocation, eventparticipants,max_capacity,event_count,feedback,registration,max_events,tickets);                                                  
    loadheader(); 
    while (true) { 

        displaymenu(); 
                                                // function call
        cout << "Select option(0,1,2): ";
        if (cin >> option && (option == 1 || option == 2 || option == 0)) {                     //input validation
            if (option == 1) {
                cout << "Enter Username: ";
                cin.ignore();
                getline(cin,username);
                cout << "Enter Password: ";
                getline(cin,password);
                if (isadmin(username, password)) {
                    system("cls");
                    adminpanel(eventname, eventdate,eventtime,eventlocation,eventparticipants,max_capacity,event_count,max_events,max_participants_per_event,registration);               // function call
                    cout << endl;
                }
                else {
                    cout << "Invalid Credentials!" << endl;
                }
            }

            else if (option == 2) {
                system("cls");
                userpanel(eventname,eventdate,eventtime,eventlocation,eventparticipants,max_capacity,event_count,feedback,registration,tickets);          // function call

            }

            else if (option == 0) {
                system("cls");
                cout << "Exiting the program............................." << endl;
                cout << "Succesfully exit the program...........THANK YOU!" << endl;
                break;                                                 //exit the loop
            }
        }

        else {
            cout << "INVALID INPUT...Please enter valid input." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    savedata(eventname,eventdate,eventtime,eventlocation, eventparticipants,max_capacity,event_count,feedback,registration,max_events,tickets);
    
    return 0;
}
//function to declare/initiallize the arrays
void declarearray(string eventname[],string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100], const int max_events,const int max_participants_per_event,int tickets[]){
    
    event_count=0;
    for(int i=0;i<max_events;i++){
         eventparticipants[i]=0;
         max_capacity[i]=0;                                      // initiallize arrays
         feedback[i]="";
         for(int j=0;j<max_participants_per_event;j++){
           registration[i][j]="";
        }
    }
 }
 
 //Function to display header of EMS
void loadheader(){
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<setw(54)<<" *******   ***        ***     ******   "<<endl;
    cout<<setw(54)<<" **        ** **    ** **   **      ** "<<endl;
    cout<<setw(54)<<" ******    **   ****   **     *****    "<<endl;
    cout<<setw(54)<<" **        **    **    **   **     **  "<<endl;
    cout<<setw(54)<<" *******   **          **     ******   "<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    cout<< setw(54) <<" WELCOME TO EVENT MANAGEMENT SYSTEM (EMS)"<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    cout<< setw(48) <<"Manage your events with ease!"<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    return ;
}

 // function to display the main menu
void displaymenu(){
    cout<<"MENU:"<<endl;
    cout<<"*****"<<endl;
    cout<<"1. Log in as Admin"<<endl;
    cout<<"2. Proceed as User"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter 1 to log in as admin, Enter 2 to proceed as User, and Enter 0 to exit the program."<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    return ;
}

 // function of creating an event
void createevent(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,const int max_events){
    if(event_count>=max_events){
    cout<<"No more events can be added. Event list is full.";
    return ;
    }
    cin.ignore();

    // validation for event name
    do{
    cout<<"Enter event name: ";
    getline(cin,eventname[event_count]);
    if(!isvalidnamelength(eventname[event_count])){
        cout<<"Event name is too long or short!......Please enter a valid name."<<endl;
    }
  }  while(!isvalidnamelength(eventname[event_count]));


     // validation for event date
    do{
    cout<<"Enter event date(DD/MM/YYYY): ";
    getline(cin,eventdate[event_count]);
    if(!isvaliddate(eventdate[event_count])){
        cout<<"Invalid format of date!"<<endl;
     }
    
    }while(!isvaliddate(eventdate[event_count]));

    // validation for event time
    do{
    cout<<"Enter event time(e.g 12:00pm): ";
    getline(cin,eventtime[event_count]);
    if(!isvalidtime(eventtime[event_count])){
        cout<<"Invalid format of time!"<<endl;
    }
    }while(!isvalidtime(eventtime[event_count]));

    // validation for location
    do{
    cout<<"Enter event location: ";
    getline(cin,eventlocation[event_count]);
    if(!isvalidnamelength(eventlocation[event_count])){
        cout<<"location's name is too long or short!"<<endl;
    }
    }while(!isvalidnamelength(eventlocation[event_count]));
    
    // validate maximum number of participants
    do{
    cout<<"Enter maximum number of participants: ";
    cin>>max_capacity[event_count];
    if(cin.fail() || max_capacity[event_count]>100||max_capacity[event_count]<=0){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid Number of participants!"<<endl;
        cout<<"Please ensure that no. of participants should be in the given limit"<<endl;

    }
    }while(max_capacity[event_count]>100||max_capacity[event_count]<=0);
    
    if(eventname[event_count].empty()||eventdate[event_count].empty()||eventtime[event_count].empty()
    ||eventlocation[event_count].empty()){
       cout<<"All fields must be filled out. or maximum capacity must be positive."<<endl;
       return;
   }
   eventparticipants[event_count]=0;
   event_count++;
   cout<<"Event has been successfully added."<<endl;
}

 // function of editing an event
void editevent(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count){
    int eventnum,newparticipants;
    string newname,newdate,newtime,newlocation,input;
    if(event_count==0){
       cout<<"No events available to edit."<<endl;
       return;
    }
    cout<<"Enter event number want to edit: ";
    cin>>input;

    if(!isnumericphoneno(input)){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum= stringtointeger(input);

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;                    // adjust for zero index

    cout<<"Current Name: "<< eventname[eventnum] <<endl;
    cin.ignore();

    // new name validation
    do{
    cout<<"Enter new event name: ";
    getline(cin,newname);
    if(!isvalidnamelength(newname)){
        cout<<"Event name is not valid(too long or short)!"<<endl;
    }
    }while(!isvalidnamelength(newname));

    if(newname!=""){
    eventname[eventnum]=newname;
    }

    // new date validation
    do{
    cout<<"Enter new event date(DD/MM/YYYY): ";
    getline(cin,newdate);
    if(!isvaliddate(newdate)){
        cout<<"Invalid format of date!"<<endl;
     }
    
    }while(!isvaliddate(newdate));

    if(newdate!=""){
    eventdate[eventnum]=newdate;
    }

    // new time validations
    do{
    cout<<"Enter new event time: ";
    getline(cin,newtime);
     if(!isvalidtime(newtime)){
        cout<<"Invalid format of time!"<<endl;
    }
    }while(!isvalidtime(newtime));

    if(newtime!=""){
    eventtime[eventnum]=newtime;
    }

     // new location validation
    do{
    cout<<"Enter new event location: ";
    getline(cin,newlocation);
    if(!isvalidnamelength(newlocation)){
        cout<<"Event name is too long or short!"<<endl;
    }
    }while(!isvalidnamelength(newlocation));

    if(newlocation!=""){
    eventlocation[eventnum]=newlocation;
    }

    // validate new number of participants
    do{
    cout<<"Enter new no. of event participants: ";
    cin>>newparticipants;
    if(cin.fail()||newparticipants<=0||newparticipants>100){

        cout<<"Please ensure that no. of participants should be in the given limit"<<endl;
    }
    }while(newparticipants<=0||newparticipants>100);
    max_capacity[eventnum]=newparticipants;

    cout<<"Event has been edited successfully!"<<endl;
}

// function of deleting an event
void deleteevent(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count){
    int eventnum;
    string input;
    char choice;
    if(event_count==0){
       cout<<"No events available to delete."<<endl;
       return ;
    }
    cout<<"Enter event number want to delete: ";
    cin>>input;

    if(!isnumericphoneno(input)){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum= stringtointeger(input);

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;
    cout<<"Current Name: "<< eventname[eventnum] <<endl;
    cout<<"Are you really want to delete this event?(YES or NO)"  ;
    cin>>choice;

    if(choice=='y'|| choice=='Y'){
       event_count--;

       for(int i=eventnum;i<event_count;i++){
          eventname[i]=eventname[i+1];
          eventdate[i]=eventdate[i+1];
          eventtime[i]=eventtime[i+1];
          eventlocation[i]=eventlocation[i+1];
          eventparticipants[i]=eventparticipants[i+1];
          max_capacity[i]=max_capacity[i+1];
      }

      cout<<"Event has been successfully deleted!!"<<endl;
    }
    else{

      cout<<"Deletion has been cancelled!!"<<endl;  
    }
}

// function to display registered users

void displayusers(string eventname[],int &event_count,int eventparticipants[],string registration[][100], const int max_events,const int max_participants_per_event){

      // display header
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<setw(42)<<"All Registered Users in our EMS"<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    
    if(event_count==0){
       cout<<"No events, no registered users."<<endl;
       return ;
    }
    
    for(int i=0; i<event_count;i++){
        cout<<"Event Name: "<<eventname[i]<<endl;
        if(eventparticipants[i]==0){
            cout<<"No user is registered!"<<endl;
            cout<<endl;
        }
        else{
            cout<<"       Registered Users      "<<endl;
            cout<<endl;
            for(int j=0;j<max_participants_per_event;j++){
                // only display non-empty 
                if(!registration[i][j].empty())
                cout<<j+1 <<" . "<<registration[i][j]<<endl;
            }
            cout<<endl;
        }
    }
}

// function to display admin panel
void adminpanel(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,const int max_events,const int max_participants_per_event,string registration[][100]){
    int option;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<setw(42)<<"Welcome to Admin Panel"<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<"1. Create an event"<<endl;
    cout<<"2. Edit an event"<<endl;
    cout<<"3. Delete an event"<<endl;
    cout<<"4. Display all registered users"<<endl;
    cout<<"0. Log out admin panel"<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    while(true){
    cout<<"Select option(0,1,2,3,4): ";
    if( cin>>option && (option==1||option==2||option==3||option==4||option==0)){
     switch(option){
     case 1:
       createevent(eventname, eventdate,eventtime, eventlocation,eventparticipants,max_capacity,event_count, max_events);
       break;
     case 2:
       editevent(eventname,eventdate,eventtime ,eventlocation, eventparticipants,max_capacity,event_count);
       break;
     case 3:
       deleteevent(eventname, eventdate,eventtime ,eventlocation, eventparticipants,max_capacity,event_count);
       break;
     case 4:
       displayusers(eventname,event_count,eventparticipants,registration, max_events,max_participants_per_event);
       break;
     case 0:
       cout<<"Exiting the admin panel........."<<endl;
       cout<<"Now you are in main menu. "<<endl;
       cout << endl;
       return ;            // return to main menu
     }
    }
    else{
      cout<<"INVALID INPUT...Please enter valid input."<<endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }
  }
}

// function to check the admin credentials
bool isadmin(string username,string password){
    if((username=="admin67" && password=="event123")|| 
      (username=="admin267"&& password=="manager123")){
        return true;
    }

    return false;
}

// function to check valid length of name
bool isvalidnamelength(string name) {
    if (name.length() < 3 || name.length() > 50) {
        return false;
    }

    return true;
}

// function to check name consist of alphabets
bool isalphabets(string name){
    for(int i=0; i<name.length();i++){
     if(!isalpha(name[i])){
       return false;
    }
 }
 return true;
}

// function to check phoneno consist of numbers
bool isnumericphoneno(string phoneno){
    for(int i=0; i<phoneno.length();i++){
     if(!isdigit(phoneno[i])){
        return false;
    }
 }
 return true;
}

// function to check first numberv of phone no
bool isvalidphoneno(string phoneno){
    if(phoneno[0]!='0')
       return false;
    else
       return true;
}

// function to check the length of phoneno
bool isvalidphonenolength(string phoneno){
    if(phoneno.length()!=11){
        return false;
    }
    return true;
}

// function to check the format of date
bool isvaliddate(string date){
    if(date.length()!=10){
        return false;
    }
    for(int i=0;i<10;i++){
        if(i==2||i==5){
            if(date[i]!='/')
            return false;
        }
        else{
            if(!isdigit(date[i])){
                return false;
            }
        }
    }
    return true;
}

// function to check format of time
bool isvalidtime(string time){
    if(time.length()!=7){
        return false;
    }
    for(int i=0;i<5;i++){
        if(i==2){
            if(time[i]!=':')
            return false;
        }
    else{
        if(!isdigit(time[i]))
        return false;
     }
    }
    for(int i=5; i<7;i++){
        if(!isalpha(time[i]))
        return false;
    }
    return true;
}

int stringtointeger(string option){
    int result=0;
    bool isneg=false;
    int index=0;
    if(option[0]=='-'){
        isneg=true;
        index=1;
    }
    for(int i=index; i<option.length();i++){
        int digit= option[i]-'0';
        result= result*10 + digit;
    }
    if(isneg){
        result=-result;
    }
    return result;
}

// function for displaying events
void displayevents(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[]){

    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<setw(42)<<"EVENTS CALENDER"<<endl;
     for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    if(event_count==0){
       cout<<"No upcoming events."<<endl;
       return ;
    }
    
    for(int i=0; i<event_count;i++){
        cout<<i+1<<".Event's Name: "<<eventname[i]<<endl;
        cout<<"Date: "<<eventdate[i]<<endl;
        cout<<"Time: "<<eventtime[i]<<endl;
        cout<<"Location: "<<eventlocation[i]<<endl;
        if(!feedback[i].empty()){
        cout<<"Feedback: "<<feedback[i]<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    return ;
}

// function for user registration for events
void userregistration(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string registration[][100]){
    int eventnum;
    string firstname,lastname,phoneno,input;

    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<setw(45)<<"USER REGISTRATION FOR UPCOMING EVENTS"<<endl;
     for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    if(event_count==0){
       cout<<"No upcoming events available for registration."<<endl;
       return ;
    }
    cout<<"Enter event number you want to register for: ";
    cin>>input;
    cin.ignore();

    if(!isnumericphoneno(input)){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum= stringtointeger(input);

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;

    cout<<"Event Name: "<< eventname[eventnum] <<endl;
    if(eventparticipants[eventnum] >= max_capacity[eventnum]){
        cout<<"Cannot registered!.....Event is full."<<endl;
        return ;
    }
    cout<<endl;
    cout<<"Enter first name: "<<endl;
    getline(cin,firstname);
    cout<<"Enter Last name: "<<endl;
    getline(cin,lastname);
    cout<<"Enter phone no.: "<<endl;
    getline(cin,phoneno);


    // check first name length
    if(!isvalidnamelength(firstname)){
        cout<<"first name must be 4-50 characters long!"<<endl;
        return ;
    }
 
    // check last name length
    if(!isvalidnamelength(lastname)){
        cout<<"last name must be 4-50 characters long!"<<endl;
        return ;
    }

    // check first name is consist of alphabets or not

    if(!isalphabets(firstname)){
        cout<<"First Name must contain only alphabets!!"<<endl;
        return;
     }

    // check last name is consist of alphabets or not
    if(!isalphabets(lastname)){
        cout<<"Last Name must contain only alphabets!!"<<endl;
        return;
     }
    
    // check phone number length
    if(!isvalidphonenolength(phoneno)){
        cout<<"Phone number must contain 11 digits!!"<<endl;
        return;
    }

    // check phone number starting index
    if(!isvalidphoneno(phoneno)){
        cout<<"Phone number must start with 0!!"<<endl;
        return;
    }

    // check phone no. contain digits or not
    if(!isnumericphoneno(phoneno)){
        cout<<"Phone number must contain only digits!!"<<endl;
        return;
     }
    
    // check any of field is empty or not
    if(firstname.empty()|| lastname.empty()|| phoneno.empty()){
       cout<<"All fields must be filled out."<<endl;
       return;
    }
    bool isalreadyregister=false;
    for(int i=0;i <eventparticipants[eventnum];i++){
         if(registration[eventnum][i]==phoneno){
            isalreadyregister=true; 
            break;
         }
    }
    if(isalreadyregister){
        cout<<"You have already registered."<<endl;
        return;
    }
    registration[eventnum][eventparticipants[eventnum]]=phoneno;
    eventparticipants[eventnum]++;
    cout<<"You have been succesfully registered!"<<endl;

    return ;

}

 // function for the booking of tickets
void bookingoftickets(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string registration[][100],int tickets[]){
    int eventnum,ticket_count;
    string input;
    string phoneno;
    for(int i=0;i<70;i++){
       cout<<"=";
    }
       cout<<endl;
       cout<<setw(40)<<"Booking of tickets form"<<endl;
       for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    if(event_count==0){
       cout<<"No upcoming events available for booking of tickets."<<endl;
       return ;
    }
    cout<<"Enter event number you want to book tickets for: ";
    cin>>input;
    cin.ignore();

    if(!isnumericphoneno(input)){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum= stringtointeger(input);

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;
    if(eventparticipants[eventnum] >= max_capacity[eventnum]){
        cout<<"Cannot book tickets!.....Event is full."<<endl;
        return ;
    }

    cout<<"Enter your registered phone no: ";
    getline(cin,phoneno);
    bool isregistered=false;
    for(int i=0;i<eventparticipants[eventnum];i++){
        if(registration[eventnum][i]==phoneno){
            isregistered=true;
            break;
        }
    }
    if(!isregistered){
        cout<<"You are not registered for this event. You have to register yourself first!"<<endl;
        return ;
    }
    cout<<"Enter number of tickets you want to book: ";
    cin>>ticket_count;
    if(ticket_count<=0){
        cout<<"Invalid no. of tickets."<<endl;
        return;
    }

    int available_tickets=max_capacity[eventnum];
    if(ticket_count > available_tickets){
        cout<<"Onlyy "<<available_tickets<< " spots are available."<<endl;
        return;
    }
    tickets[eventnum]=ticket_count; 
    cout<<"Successfully Booked!"<<endl;

}

// function for providing feedback
void userfeedback(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count ,string feedback[]){
    
    int eventnum;
    string input;
    char choice;
    string user_feedback;

    for(int i=0;i<70;i++){
       cout<<"=";
    }
       cout<<endl;
       cout<<setw(40)<<"User Feedback Form"<<endl;
       for(int i=0;i<70;i++){
        cout<<"=";
    }
      cout<<endl;

    if(event_count==0){
       cout<<"No events available for feedback."<<endl;
       return ;
    }
    cout<<"Enter event number you want to give feedback on: ";
    cin>>input;
    cin.ignore();

    if(!isnumericphoneno(input)){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum= stringtointeger(input);
    
    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;

    cout<<"Event Name: "<< eventname[eventnum] <<endl;
    if(!feedback[eventnum].empty()){

        cout<<"Feedback already existed."<<endl;
        cout<<"Current Feedback:  "<<feedback[eventnum]<<endl;
        cout<<"Do you want to add more feedback? (Y/N):  ";
        cin>>choice;

        cin.ignore();
        if(choice=='Y'||choice=='y'){
           cout<<"Enter your feedback: ";
           getline(cin,user_feedback);
           feedback[eventnum]+= " "+ user_feedback; 
        }
        else if(choice=='n'|| choice=='N'){
            cout<<" OK! "<<endl;
        }
        else{
          cout<<"Invalid choice"<<endl;
          return;
        }
    }
    else{
    
      cout<<"Enter Your Feedback: ";
      getline(cin,user_feedback);
      feedback[eventnum]=user_feedback;
      cout << endl;
      cout<<"THANK YOU FOR YOUR FEEDBACK!"<<endl;
    }   
}

// function to display user menu
void userpanel(string eventname[], string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100],int tickets[]){
     int option;
     for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<setw(40)<<"Event Management System(User)"<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    cout<<"1. Display Event Calender"<<endl;
    cout<<"2. User Registration"<<endl;
    cout<<"3. Booking of tickets for event"<<endl;
    cout<<"4. Feedback"<<endl;
    cout<<"0. Exit the User Menu"<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    while(true){

    cout<<"Select option(0,1,2,3,4): ";
    if(cin>>option && (option==1||option==2||option==3||option==4||option==0)){
     switch(option){

      case 1:
       displayevents(eventname, eventdate, eventtime ,eventlocation, eventparticipants,max_capacity,event_count,feedback);
       break;
      case 2:
       userregistration(eventname, eventdate,eventtime ,eventlocation, eventparticipants,max_capacity,event_count,registration);
       break;
      case 3:
       bookingoftickets(eventname, eventdate,eventtime ,eventlocation, eventparticipants,max_capacity,event_count,registration,tickets);
       break;
      case 4:
       userfeedback(eventname, eventdate,eventtime ,eventlocation, eventparticipants ,max_capacity,event_count,feedback);
       break;
      case 0:
       cout<<"Exiting the user panel........."<<endl;
       cout<<"Now you are in main menu. "<<endl;
       cout << endl;
       return ;                                            //return to main menu

      }
    }

    else{

      cout<<"INVALID INPUT...Please enter valid input."<<endl;
      cin.clear();
      cin.ignore(10000,'\n'); 
      
    }
  } 
}

// function to save data in file
bool savedata(string eventname[],string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100], const int max_events,int tickets[]){
    ofstream fout;
    fout.open("events.txt");
    if(!fout){
        cout<<"File could not open!"<<endl;
        return false;
    }
    fout<<event_count<<endl;
    for(int i=0;i<event_count;i++){
        fout<<eventname[i]<<","
            <<eventdate[i]<<","
            <<eventtime[i]<<","
            <<eventlocation[i]<<","
            <<tickets[i]<<","
            <<max_capacity[i]<<","
            <<eventparticipants[i]<<",";


        for(int j=0;j<eventparticipants[i];j++){
            fout<<registration[i][j];
            if(j<eventparticipants[i]-1)
            fout<<",";
        }


        fout<<feedback[i]<<endl;


 }
   fout.close();
   return true;
}


// function to load data from the file
bool loaddata(string eventname[],string eventdate[],string eventtime[],string eventlocation[], int eventparticipants[],int max_capacity[],int &event_count,string feedback[],string registration[][100], const int max_events,int tickets[]){

    ifstream fin;
    fin.open("events.txt");
    if(!fin){
        cout<<"Error!"<<endl;
        return false;
    }
        fin>>event_count;
        fin.ignore();
        for(int i=0; i<event_count;i++){
            getline(fin, eventname[i],',');
            getline(fin,eventdate[i],',');
            getline(fin,eventtime[i],',');
            getline(fin,eventlocation[i],',');
            fin>>tickets[i];
            fin.ignore();
            fin>>max_capacity[i];
            fin.ignore();
            fin>>eventparticipants[i];
            fin.ignore();
            
            for(int j=0;j<eventparticipants[i];j++){
                if(fin.eof()){
                    break;
                }
                 getline(fin,registration[i][j],',');

            }

            getline(fin, feedback[i]);
            
     }

    if(fin.fail() && !fin.eof()){
        cout<<"Data is not loaded!"<<endl;
        fin.close();
        return false;
    }

    fin.close();
    return true;
}

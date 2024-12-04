#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

                                
struct events{
    string eventname;
    string eventdate;
    string eventtime;                           
    string eventlocation;
    string registration[100];
    string feedback;
    int tickets;
    int eventparticipants;
    int max_capacity;
};


               ////   FUNCTIONS   ////

void declarearray(events array[], int& event_count, const int max_events);
void loadheader();
void displaymenu();
void createevent(events array[], int& event_count, const int max_events);
void editevent(events array[], int& event_count, const int max_events);
void deleteevent(events array[], int& event_count, const int max_events);
void displayusers(events array[], int& event_count, const int max_events);
void adminpanel(events array[], int& event_count, const int max_events);
void displayevents(events array[], int& event_count, const int max_events);
void userregistration(events array[], int& event_count, const int max_events);
void bookingoftickets(events array[], int& event_count, const int max_events);
void userfeedback(events array[], int& event_count, const int max_events);
void userpanel(events array[], int& event_count, const int max_events);
  
              // validation functions  //

bool isadmin(string username, string password);
bool isvalidnamelength(string name);
bool isalphabets(string name);
bool isvalidphonenolength(string phoneno);
bool isnumericphoneno(string phoneno);
bool isvalidphoneno(string phoneno);
bool isvaliddate(string date);
bool isvalidtime(string time);
bool savedata(events array[], int& event_count, const int max_events);
bool loaddata(events array[], int& event_count, const int max_events);


 // main function
int main() {

    const int max_events = 500;
    const int max_participants_per_event = 100;
    events array[max_events];
    int event_count;                                     // for counting the no. of events
                                                                

    declarearray(array,event_count,max_events);

    int option;
    string username, password;

    system("cls");
    loaddata(array,event_count,max_events);                                                  
    loadheader(); 
    while (true) { 

        displaymenu();                           // function call
                                                
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
                    adminpanel(array,event_count,max_events);               // function call
                    cout << endl;
                }
                else {
                    cout << "Invalid Credentials!" << endl;
                }
            }

            else if (option == 2) {
                system("cls");
                userpanel(array,event_count,max_events);                  // function call

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

    savedata(array,event_count,max_events);
    
    return 0;
}


//function to declare/initiallize the arrays
void declarearray(events array[], int& event_count, const int max_events){
    
    event_count=0;
    for(int i=0;i<max_events;i++){
         array[i].eventparticipants=0;
         array[i].max_capacity=0;                                      // initiallize arrays
         array[i].feedback="";
         for(int j=0;j<100;j++){
           array[i].registration[j]="";
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
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;
    cout<<"Enter 1 to log in as admin, Enter 2 to proceed as User, and Enter 0 to exit the program."<<endl;
    for(int i=0;i<70;i++){
        cout<<"=";
    }
    cout<<endl;

    return ;
}


 // function of creating an event
void createevent(events array[], int& event_count, const int max_events){
    if(event_count>=max_events){
    cout<<"No more events can be added. Event list is full.";
    return ;
    }
    cin.ignore();


    // validation for event name
    do{
    cout<<"Enter event name: ";
    getline(cin,array[event_count].eventname);
    if(!isvalidnamelength(array[event_count].eventname)){
        cout<<"Event name is too long or short!......Please enter a valid name."<<endl;
    }
  }  while(!isvalidnamelength(array[event_count].eventname));


     // validation for event date
    do{
    cout<<"Enter event date(DD/MM/YYYY): ";
    getline(cin,array[event_count].eventdate);
    if(!isvaliddate(array[event_count].eventdate)){
        cout<<"Invalid format of date!"<<endl;
     }
    
    }while(!isvaliddate(array[event_count].eventdate));


    // validation for event time
    do{
    cout<<"Enter event time(e.g 12:00pm): ";
    getline(cin,array[event_count].eventtime);
    if(!isvalidtime(array[event_count].eventtime)){
        cout<<"Invalid format of time!"<<endl;
     }
    }while(!isvalidtime(array[event_count].eventtime));


    // validation for location
    do{
    cout<<"Enter event location: ";
    getline(cin,array[event_count].eventlocation);
    if(!isvalidnamelength(array[event_count].eventlocation)){
        cout<<"location's name is too long or short!"<<endl;
     }
    }while(!isvalidnamelength(array[event_count].eventlocation));
    

    // validate maximum number of participants
    do{
    cout<<"Enter maximum number of participants: ";
    cin>>array[event_count].max_capacity;
    if(cin.fail() || array[event_count].max_capacity > 100 || array[event_count].max_capacity <=0){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Invalid Number of participants!"<<endl;
        cout<<"Please ensure that no. of participants should be in the given limit"<<endl;

     }
    }while(array[event_count].max_capacity >100 || array[event_count].max_capacity <=0 );
    
    if(array[event_count].eventname.empty()|| array[event_count].eventdate.empty()|| array[event_count].eventtime.empty()
    || array[event_count].eventlocation.empty()){
       cout<<"All fields must be filled out. or maximum capacity must be positive."<<endl;
       return;
   }

   array[event_count].eventparticipants =0;
   event_count++;
   cout<<"Event has been successfully added."<<endl;
}

 // function of editing an event
void editevent(events array[], int& event_count, const int max_events){
    int eventnum,newparticipants;
    string newname,newdate,newtime,newlocation;

    if(event_count==0){
       cout<<"No events available to edit."<<endl;
       return;
    }
    cout<<"Enter event number want to edit: ";
    cin>>eventnum;

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;                    // adjust for zero index

    cout<<"Current Name: "<< array[eventnum].eventname <<endl;
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
    array[eventnum].eventname = newname;
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
    array[eventnum].eventdate = newdate;
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
    array[eventnum].eventtime=newtime;
    }

     // new location validation
    do{
    cout<<"Enter new event location: ";
    getline(cin,newlocation);
    if(!isvalidnamelength(newlocation)){
        cout<<"location name is too long or short!"<<endl;
    }
    }while(!isvalidnamelength(newlocation));


    if(newlocation!=""){
    array[eventnum].eventlocation = newlocation;
    }

    // validate new number of participants
    do{
    cout<<"Enter new no. of event participants: ";
    cin>>newparticipants;
    if(cin.fail()||newparticipants<=0||newparticipants>100){

        cout<<"Please ensure that no. of participants should be in the given limit"<<endl;
    }
    }while(newparticipants<=0||newparticipants>100);
    array[eventnum].eventparticipants = newparticipants;

    cout<<"Event has been edited successfully!"<<endl;
}

// function of deleting an event
void deleteevent(events array[], int& event_count, const int max_events){
    int eventnum;
    char choice;
    if(event_count==0){
       cout<<"No events available to delete."<<endl;
       return ;
    }
    cout<<"Enter event number want to delete: ";
    cin>>eventnum;

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;
    cout<<"Current Name: "<< array[eventnum].eventname <<endl;
    cout<<"Are you really want to delete this event?(YES or NO)"  ;
    cin>>choice;

    if(choice=='y'|| choice=='Y'){
       event_count--;

       for(int i=eventnum;i<event_count;i++){
          array[i].eventname = array[i+1].eventname;
          array[i].eventdate= array[i+1].eventdate;
          array[i].eventtime= array[i+1].eventtime;
          array[i].eventlocation= array[i+1].eventlocation;
          array[i].eventparticipants= array[i+1].eventparticipants;
          array[i].max_capacity= array[i+1].max_capacity;
      }

      cout<<"Event has been successfully deleted!!"<<endl;
    }
    else{

      cout<<"Deletion has been cancelled!!"<<endl;  
    }
}

// function to display registered users

void displayusers(events array[], int& event_count, const int max_events){

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
        cout<<"Event Name: "<<array[i].eventname<<endl;
        if(array[i].eventparticipants==0){
            cout<<"No user is registered!"<<endl;
            cout<<endl;
        }
        else{
            cout<<"       Registered Users      "<<endl;
            cout<<endl;
            for(int j=0;j<100;j++){
                // only display non-empty 
                if(!array[i].registration[j].empty())
                cout<<j+1 <<" . "<<array[i].registration[j]<<endl;
            }
        }
    }
}

// function to display admin panel
void adminpanel(events array[], int& event_count, const int max_events){
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
       createevent(array,event_count,max_events);
       break;
     case 2:
       editevent(array,event_count,max_events);
       break;
     case 3:
       deleteevent(array,event_count,max_events);
       break;
     case 4:
       displayusers(array,event_count,max_events);
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

// function for displaying events
void displayevents(events array[], int& event_count, const int max_events){

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
        cout<<i+1<<".Event's Name: "<<array[i].eventname<<endl;
        cout<<"Date: "<<array[i].eventdate<<endl;
        cout<<"Time: "<<array[i].eventtime<<endl;
        cout<<"Location: "<<array[i].eventlocation<<endl;
        if(!array[i].feedback.empty()){
        cout<<"Feedback: "<<array[i].feedback<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    return ;
}

// function for user registration for events
void userregistration(events array[], int& event_count, const int max_events){
    int eventnum;
    string firstname,lastname,phoneno;

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
    cin>>eventnum;
    cin.ignore();

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;

    cout<<"Event Name: "<< array[eventnum].eventname <<endl;
    if(array[eventnum].eventparticipants >= array[eventnum].max_capacity){
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
    for(int i=0;i <array[eventnum].eventparticipants;i++){
         if(array[eventnum].registration[i]==phoneno){
            isalreadyregister=true; 
            break;
         }
    }
    if(isalreadyregister){
        cout<<"You have already registered."<<endl;
        return;
    }
    array[eventnum].registration[array[eventnum].eventparticipants]=phoneno;
    array[eventnum].eventparticipants++;
    cout<<"You have been succesfully registered!"<<endl;

    return ;

}

 // function for the booking of tickets
void bookingoftickets(events array[], int& event_count, const int max_events){
    int eventnum,ticket_count;
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
    cin>>eventnum;
    cin.ignore();

    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;
    if(array[eventnum].eventparticipants >= array[eventnum].max_capacity){
        cout<<"Cannot book tickets!.....Event is full."<<endl;
        return ;
    }

    cout<<"Enter your registered phone no: ";
    getline(cin,phoneno);
    bool isregistered=false;
    for(int i=0;i<array[eventnum].eventparticipants;i++){
        if(array[eventnum].registration[i]==phoneno){
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

    int available_tickets=array[eventnum].max_capacity;
    if(ticket_count > available_tickets){
        cout<<"Onlyy "<<available_tickets<< " spots are available."<<endl;
        return;
    }
    
    array[eventnum].tickets=ticket_count;
    cout<<"Successfully Booked!"<<endl;

}


// function for providing feedback
void userfeedback(events array[], int& event_count, const int max_events){
    
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

    if(isvalidphoneno(input)){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum= stoi(input);
    
    if(eventnum<1 ||eventnum>event_count){
        cout<<"Invalid Event Number"<<endl;
        return ;
    }
    eventnum=eventnum-1;

    cout<<"Event Name: "<< array[eventnum].eventname<<endl;
    if(!array[eventnum].feedback.empty()){

        cout<<"Feedback already existed."<<endl;
        cout<<"Current Feedback:  "<<array[eventnum].feedback<<endl;
        cout<<"Do you want to add more feedback? (Y/N):  ";
        cin>>choice;

        cin.ignore();
        if(choice=='Y'||choice=='y'){

           cout<<"Enter your feedback: ";
           getline(cin,user_feedback);
           array[eventnum].feedback +=  " " + user_feedback; 

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
      array[eventnum].feedback = user_feedback;
      cout << endl;
      cout<<"THANK YOU FOR YOUR FEEDBACK!"<<endl;
    }   
}


// function to display user menu
void userpanel(events array[], int& event_count, const int max_events){
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
       displayevents(array,event_count,max_events);
       break;
      case 2:
       userregistration(array,event_count,max_events);
       break;
      case 3:
       bookingoftickets(array,event_count,max_events);
       break;
      case 4:
       userfeedback(array,event_count,max_events);
       break;
      case 0:
       cout<<"Exiting the user panel........."<<endl;                            
       cout<<"Now you are in main menu. "<<endl;
       cout << endl;
       return ;                                                          //return to main menu
                                                  
      }
    }

    else{

      cout<<"INVALID INPUT...Please enter valid input."<<endl;
      cin.clear();
      cin.ignore(10000,'\n'); 
    }
  } 
}


// function to load data from the file
bool loaddata(events array[], int& event_count, const int max_events){

    ifstream fin;
    fin.open("events.txt");
    if(!fin){
        cout<<"Error!"<<endl;
        return false;
    }

        fin>>event_count;
        fin.ignore();

        if(event_count>max_events){
        cout<<"Can't load more events!"<<endl;
    }

        for(int i=0; i<event_count;i++){
            getline(fin, array[i].eventname,',');
            getline(fin,array[i].eventdate,',');
            getline(fin,array[i].eventtime,',');
            getline(fin,array[i].eventlocation,',');
            fin>>array[i].tickets;
            fin.ignore();
            fin>>array[i].max_capacity;
            fin.ignore();
            fin>>array[i].eventparticipants;
            fin.ignore();
            
            for(int j=0;j<array[i].eventparticipants;j++){
                if(fin.eof()){
                     break;
                }
                getline(fin,array[i].registration[j],',');

               }

            getline(fin, array[i].feedback);
            
    }

    if(fin.fail() && !fin.eof())
    {
        cout<<"Data is not loaded!"<<endl;
        fin.close();
        return false;
    }

    fin.close();
    return true;
}


// function to save data in file
bool savedata(events array[], int& event_count, const int max_events){
    ofstream fout;
    fout.open("events.txt");

    if(!fout){
        cout<<"File could not open!"<<endl;
        return false;
    }

    fout<<event_count<<endl;
    for(int i=0;i<event_count;i++){
        fout<<array[i].eventname<<", "
            <<array[i].eventdate<<", "
            <<array[i].eventtime<<", "
            <<array[i].eventlocation<<", "
            <<array[i].tickets<<", "
            <<array[i].max_capacity<<", "
            <<array[i].eventparticipants<<", ";


            for(int j=0;j<array[i].eventparticipants;j++){
               fout<<array[i].registration[j];
               if(j<array[i].eventparticipants-1)
               fout<<",";
           }

        fout<<","<<array[i].feedback<<endl;
 }

   fout.close();
   return true;

}


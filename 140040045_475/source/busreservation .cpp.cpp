#include<iostream>
#include<fstream>
using namespace std;
void fnMainScreen1();//function to create main user interface
void fnMainScreen2();//function to create sub user interface
void fnAdmin();
bool compare(char a[] , char b[]);

void fnPrintLine();// to print *************


class bus
{

    int date;
    int month;
    int seatno;
    char name[30];
    int age;
    char sex;   // (M/F)
    long int ticketno;

public:
    void fnPassengerList();
    void fnReservation(int);
    void fnCancellation();
    void fnEnquiry();
    void getdata();
    int fnSeatno(int ,int ,int );
    void fnShowTicket(int,int,int,int);
    void fnSeatAvailability();
    void fnBusRunningInfo();
    void fnTicketStatus();
    void fnRules();
    void admin();

};                 //class declaration over at this instance
bus b;     //Define a globle bus
//--------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
bool compare(char a[] , char b[])  //this function for compare name
{
    int i=0;
    while(true)
    {
        if(a[i]=='\0'&& b[i]=='\0') return 1;
        if(a[i]=='\0' || b[i]=='\0' || (a[i]<b[i]) || (a[i]>b[i]) )  return 0;
        i++;

    }

}

void bus::  getdata()  // "getdata function" collect information about passenger
{
    fnPrintLine();
    cout<<"\n";
    cout<<"\n\n\t\t\t RESERVATION DETAILS\n";
    cout<<"\n\n\t ENTER THE NAME OF THE PASSENGER:";
    cin>>name;

        cout<<"\n\n\t ENTER THE AGE OF THE PASSENGER:\n\n";

        while (!(cin >> age))
    {
        cout << "INVALID DATA TYPE FOR CHOICE! TRY AGAIN: ";

        cin.clear();
        cin.ignore();
    }



    while(true)
    {
        cout<<"\n\n\t ENTER THE SEX OF THE PASSENGER(m/f):";
        cin>>sex;
        if(sex!='m'&&sex!='f')
        {
            cout<<"\n\t INVALID \n\n";
            continue;
        }
        else break;

    }
    cout<<"\n";
}

//---------------------------------------------------------------------------------------------------------------------------------------

int main()   // MAIN PROGRAM

{
    while(true)
    {

        fnMainScreen1();
        break;
    }
    return 0;
}

// function fnMainscreen1 coded below.
//---------------------------------------------------------------------------------------------------------------------------------------------
void fnMainScreen1()
{
    int choice;
    char c;
    cout<<"\n\n\t\t WELCOME TO BUS TICKET RESERVATION SYSTEM \n";
    cout<<"\n\t\t\t SELECT YOUR CHOICE";
    cout<<"\n\n\t\t IF YOU ARE A CUSTOMER, PRESS '1'\n";
    cout<<"\n\t\t IF YOU ARE A ADMIN, PRESS '2'\n\n";

    while (!(cin >> choice))
    {
        cout << "INVALID DATA TYPE FOR CHOICE! TRY AGAIN: ";

        cin.clear();
        cin.ignore();
  }
    if(choice==2)
    {
        fnAdmin();

    }
    else if(choice==1)
    {
        fnMainScreen2();
    }
    else
    {
        cout<<"INVAILID CHOICE";
        cout<<"\n\n\n PRESS ANY KEY TO GO BACK \n";
        cin>>c;
        fnMainScreen1();
    }
}
// function fnMainscreen2 coded below.
//--------------------------------------------------------------------------------------------------------------------------------------------

void fnMainScreen2()
{
    int choice;
    char c;

    cout<<"\n\n\t\t\t SELECT YOUR CHOICE";
    cout<<"\n\n\t\t 1. TICKET RESERVATION";
    cout<<"\n\t\t 2. TICKET CANCELLATION";
    cout<<"\n\t\t 3. ENQUIRY";
    cout<<"\n\t\t PRESS ANY OTHER NUMERIC KEY TO EXIT ";
    cout<<"\n\n\n\n";
    cin >> choice;
    if (choice>3||choice<1)

     {
         fnMainScreen1();
     }


    switch(choice)
    {
    case 1:

        cout<<"\n\n\t BUS\t FROM\t TO\t\tTIME<hrs>\t FARE<rs>\n";
        cout<<"\n\tDELUX\tMUMBAI\tBANGALORE\t0600\t\t400";
        cout<<"\n\tDELUX\tMUMBAI\tAHEMDABAD\t0830\t\t350";
        cout<<"\n\tDELUX\tMUMBAI\tBHOPAL\t\t0900\t\t310";
        cout<<"\n\tDELUX\tMUMBAI\tGOA\t\t0430\t\t200\n";
        cout<<"\n\n\n";

        cout<<"\n\n\tPRESS 1 TO RESERVE TICKET TO BANGALORE";
        cout<<"\n\n\tPRESS 2 TO RESERVE TICKET TO AHEMDABAD";
        cout<<"\n\n\tPRESS 3 TO RESERVE TICKET TO BHOPAL";
        cout<<"\n\n\tPRESS 4 TO RESERVE TICKET TO GOA";
        cout<<"\n\n\tENTER YOUR CHOICE;\n";
        cin>>choice;


        if(choice>4 || choice<=0)
        {
            cout<<"\n\n\t SORRY THIS CHOICE DOES NOT EXIST\n\n\n";
            cout<<"PRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>c;
            fnMainScreen2();
        }
        else
        {
            b.fnReservation(choice);
        }
        break;

    case 2:
        b.fnCancellation();
        break;
    case 3:
        b.fnEnquiry();

        break;
    default:
        ;
    }//switch closed here
}   // function closed here


//function fnAdmin coded below
//-----------------------------------------------------------------------------------------------------------------
void fnAdmin()
{
    int password;
    char c;
    cout<<"\n ENTER PASSWORD:"<<endl;
    cin>>password; //asking for password from admin...

    if(password==1234)
    {
        b.admin();

    }
    else
    {
        cout<<"WRONG PASSWORD"<<endl;
        cout<<"PRESS ANY KEY TO GO BACK MENU:"<<endl;
        cin>>c;
        fnMainScreen1(); //  for clearing the screen..
    }
}
//function fnReservation coded below
//-----------------------------------------------------------------------------------------------------------------------------


void bus::fnReservation(int choice)
{

    char c;
    while(true)
    {

        cout<<"\n\n\t ENTER DATE(DD):";
        while (!(cin >> b.date))
    {
        cout << "INVALID DATA TYPE FOR date! try again: ";

        cin.clear();
        cin.ignore();
  }
        if(date<1||date>30)
        {
            cout<<"\t\t Invalid\n\n ";
            continue;
        }
        else break;
    }

    while (true)
    {
        cout<<"\n\n\t ENTER MONTH(MM):";
        while (!(cin >> b.month))
    {
        cout << "INVALID DATA TYPE FOR month! try again: ";

        cin.clear();
        cin.ignore();
  }
        if(month<1||month>12)
        {
            cout<<"\n\t Invalid \n\n";
            continue;
        }
        else break;

    }
    b.seatno = fnSeatno( choice, date, month); //function fnseatno() called which allots seats to the passenger

    cout<<"\n\tYour seat number is:- "<<b.seatno<<endl;
    b.ticketno=choice*100 + seatno+date+month;
    cout<<"\n\n\n";
    fnPrintLine();



    fstream fp;

    switch(choice)
    {
    case 1:
    {
        cout<<"\n\n\n\t\t\t MUMBAI TO BANGALORE\n";
        fp.open("bus1.txt",ios::app|ios::out); // file "bus1.txt" creat here in write & append mode
        b.getdata();
        fp.write((char*)&b,sizeof(b));
        fp.close();
        fnShowTicket(1,b.seatno,b.date,b.month); // function fnShowticket is capable of print ticket
        cout<<"\n\n\n\n";
        cout<<"\n\t  press any key to go back to main menu ";
        cin>>c;
        fnMainScreen2();
        break;
    }
    case 2:
    {
        cout<<"\n\n\n \t\t\tMUMBAI TO AHEMDABAD\n";

        fp.open("bus2.txt",ios::app|ios::out);
        b.getdata();
        fp.write((char*)&b,sizeof(b));
        fp.close();
        fnShowTicket(2,b.seatno,b.date,b.month);
        cout<<"\n\n\n\n";
        cout<<"\n\t  press any key to go back to main menu ";
        cin>>c;
        fnMainScreen2();
    }
    case 3:
    {
        cout<<"\n\n\n \t\t\tMUMBAI TO BHOPAL\n";
        fp.open("bus3.txt",ios::app|ios::out);
        b.getdata();
        fp.write((char*)&b,sizeof(b));
        fp.close();
        fnShowTicket(3,b.seatno,b.date,b.month);
        cout<<"\n\n\n";
        cout<<"\n\t  press any key to go back to main menu ";
        cin>>c;
        fnMainScreen2();
    }
    case 4:
    {
        cout<<"\n\n\n\t\t\t MUMBAI TO GOA\n";
        fp.open("bus4.txt",ios::app|ios::out);
        b.getdata();
        fp.write((char*)&b,sizeof(b));
        fp.close();
        cout<<"\n\n\n\n";
        fnShowTicket(4,b.seatno,b.date,b.month);
        cout<<"\n\t  press any key to go back to main menu ";
        cin>>c;
        fnMainScreen2();
    }
    }
}


// function fnCancellation coded below
//---------------------------------------------------------------------------------------------------------------------------------
void bus::fnCancellation()
{
    int seat;
    int urdate;
    int urmonth;
    char p;
    bus c;
    fstream f1,f2; // define file variable

    int temp=1;
    int choice1;

    cout<<"\n\n\t\t CANCELLATION OF RESERVED TICKET\n";
    fnPrintLine();

    cout<<"\n\n\t\t PRESS 1. MUMBAI TO BANGALORE";
    cout<<"\n\t\t PRESS 2. MUMBAI TO AHEMDABAD";
    cout<<"\n\t\t PRESS 3. MUMBAI TO BHOPAL";
    cout<<"\n\t\t PRESS 4. MUMBAI TO GOA";
    cout<<"\n\n\t\t PRESS ANY OTHER KEY TO GO TO MAIN MENU";
    cout<<"\n\n\n\n ENTER YOUR CHOICE:";
    cin>>choice1;
    if(choice1>4 || choice1<1)
        {
            cout<<"\n\n\t SORRY THIS CHOICE DOES NOT EXIST\n\n\n";
            cout<<"PRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnCancellation();
        }

    cout<<"\n\n\t ENTER THE SEAT NUMBER OF THE PASSENGER:"<<endl;
    cin>>seat;
    cout<<"\n\n\t ETER THE DATE OF JORNEY:";
    cin>>urdate;
    cout<<"\n\n\t ENTER THE MONTH OF JORNEY:";
    cin>>urmonth;

    switch(choice1)
    {
    case 1 :
    {
        f2.open("bus5.txt",ios::out);// file "bus5.txt" open in write mode
        f1.open("bus1.txt",ios::in); // file "bus1.txt" open in read mode

        while(f1.read((char*)&c,sizeof(c)))
        {
            if (seatno==seat && date==urdate && month==urmonth )
            {

                fnPrintLine();
                cout<<"\n\n\n\t Ticket No: "<<ticketno;
                cout<<"\n\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 400 \t FROM: mumbai";
                cout<<"\n\t DESTINATION: Bangalore \t TIME: 0600 hrs\n";
                cout<<"\n\tDATE OF JOURNEY: "<<date<<"/"<<month<<endl;
                fnPrintLine();


                temp=0;
            }
            else
            {
                f2.write((char*)&c,sizeof(c));
            }
        } //while loop closed

        f1.close();
        f2.close();
        remove("bus1.txt");
        rename("bus5.txt","bus1.txt");	//replacing "bus5.txt" by "bus1.txt"

        if (temp==1)
        {
            cout<<"\n\n\n\t\t THE SEAT IS EMPTY";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2();
        }
        else
        {
            cout<<"\n\n\n\t\tTHE TICKET HAS BEEN CANCELLED";
            cout<<"\n\t\tYOU WILL BE REFUNDED 70% OF THE FARE";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2();
        }
    }

    break;


    case 2 :
    {
        f1.open("bus2.txt",ios::in);
        f2.open("bus5.txt",ios::out);

        while(f1.read((char*)&c,sizeof(c))) //reading from "bus1.txt"
        {
            if (seatno==seat && date==urdate && month==urmonth )
            {


                cout<<"\n\n\n\t Ticket No: "<<ticketno;
                cout<<"\n\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 400 \t FROM: MUMBAI";
                cout<<"\n\t DESTINATION: AHEMDABAD \t TIME: 0600 hrs";
                cout<<"\n\tDATE OF JOURNEY: "<<date<<"/"<<month<<endl;


                temp=0;
            }
            else
            {
                f2.write((char*)&c,sizeof(c));
            }
        } //while loop closed

        f1.close();
        f2.close();
        remove("bus2.txt");
        rename("bus5.txt","bus2.txt");	//replacing "bus5.txt" by "bus2.txt"

        if (temp==1)
        {
            cout<<"\n\n\n\t\t THE SEAT IS EMPTY";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2();
        }
        else
        {
            cout<<"\n\n\n\t\tTHE TICKET HAS BEEN CANCELLED";
            cout<<"\n\t\tYOU WILL BE REFUNDED 70% OF THE FARE";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2(); //returning to mainscreen2
        }
    }

    break;


    case 3:
    {
        f1.open("bus3.txt",ios::in);
        f2.open("bus5.txt",ios::out);

        while(f1.read((char*)&c,sizeof(c))) //reading from "bus1.txt"
        {
            if (seatno==seat && date==urdate && month==urmonth )
            {


                cout<<"\n\n\n\t Ticket No: "<<ticketno;
                cout<<"\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 400 \t FROM: MUMBAI";
                cout<<"\n\t DESTINATION: BHOPAL \t TIME: 06:00 hrs";
                cout<<"\n\tDATE OF JOURNEY: "<<date<<"/"<<month<<endl;


                temp=0;
            }
            else
            {
                f2.write((char*)&c,sizeof(c));
            }
        } //while loop closed

        f1.close();
        f2.close();
        remove("bus3.txt");
        rename("bus5.txt","bus3.txt");	//replacing "bus5.txt" by "bus3.txt"

        if (temp==1)
        {
            cout<<"\n\n\n\t\t THE SEAT IS EMPTY";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2();
        }
        else
        {
            cout<<"\n\n\n\t\tTHE TICKET HAS BEEN CANCELLED";
            cout<<"\n\t\tYOU WILL BE REFUNDED 70% OF THE FARE";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2();
        }
    }

    break;


    case 4 :
    {
        f1.open("bus4.txt",ios::in);
        f2.open("bus5.txt",ios::out);

        while(f1.read((char*)&c,sizeof(c))) //reading from "bus4.txt"
        {
            if (seatno==seat && date==urdate && month==urmonth )
            {


                cout<<"\n\n\n\t Ticket No: "<<ticketno;
                cout<<"\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 400 \t FROM: MUMBAI";
                cout<<"\n\t DESTINATION: GOA\t TIME: 06:00 hrs";
                cout<<"\n\tDATE OF JOURNEY: "<<date<<"/"<<month<<endl;


                temp=0;
            }
            else
            {
                f2.write((char*)&c,sizeof(c));
            }
        } //while loop closed

        f1.close();
        f2.close();
        remove("bus4.txt");
        rename("bus5.txt","bus4.txt");	//replacing "bus5.txt" by "bus4.txt"

        if (temp==1)
        {
            cout<<"\n\n\n\t\t THE SEAT IS EMPTY";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2();
        }
        else
        {
            cout<<"\n\n\n\t\tTHE TICKET HAS BEEN CANCELLED";
            cout<<"\n\t\tYOU WILL BE REFUNDED 70% OF THE FARE";
            cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
            cin>>p;
            fnMainScreen2();
        }
    }

    break;

    default :
        fnMainScreen2();   //returning to mainscreen2


    }

//function fnSeatno coded below.This function allocates the empty seat to the user.if no empty seat then "SORRY !!! NO SEAT VACANT" appears
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------
}

int bus:: fnSeatno(int choice,int idate,int imonth)
{
    bus s;
    int temp=0;
    char c;
    fstream fp;

    int i=0;

    if(choice==1)
    {
        for(i=1; i<=40; i++)
        {
            fp.open("bus1.txt",ios::in);

            while(fp.read((char*)&s,sizeof(s))) //reading from bus1.txt
            {
                if(s.seatno==i && s.date==idate && s.month==imonth)// it check seatno one by one
                    temp=1;
                if(temp==1)
                    break;
            }

            if(temp==0)
            {
                seatno=i;
                date=idate;
                month=imonth;
                break;
            }

            if(temp==1 && i==40)
            {

                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
                cin>>c;
                fnMainScreen2();
            }

            temp=0;
            fp.close();
        }   //for loop closed here
    }  //


    if(choice==2)
    {
        for(i=1; i<=40; i++)
        {
            fp.open("bus2.txt",ios::in);

            while(fp.read((char*)&s,sizeof(s)))
            {
                if(seatno==i && date==idate && month==imonth)
                    temp=1;
                if(temp==1)
                    break;
            }

            if(temp==0)
            {
                seatno=i;
                date=idate;
                month=imonth;
                break;
            }

            if(temp==1 && i==40)
            {

                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
                cin>>c;
                fnMainScreen2();
            }

            temp=0;
            fp.close();
        }
    }
    if(choice==3)
    {
        for(i=1; i<=40; i++)
        {
            fp.open("bus3.txt",ios::in);

            while(fp.read((char*)&s,sizeof(s)))
            {
                if(seatno==i && date==idate && month==imonth)
                    temp=1;
                if(temp==1)
                    break;
            }

            if(temp==0)
            {
                seatno=i;
                date=idate;
                month=imonth;
                break;
            }

            if(temp==1 && i==40)
            {

                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
                cin>>c;
                fnMainScreen2();
            }

            temp=0;
            fp.close();
        }
    }
    if(choice==4)
    {
        for(i=1; i<=40; i++)
        {
            fp.open("bus4.txt",ios::in);

            while(fp.read((char*)&s,sizeof(s)))
            {
                if(seatno==i && date==idate && month==imonth)
                    temp=1;
                if(temp==1)
                    break;
            }

            if(temp==0)
            {
                seatno=i;
                date=idate;
                month=imonth;
                break;
            }

            if(temp==1 && i==40)
            {

                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n SORRY !!! NO SEAT VACANT";
                cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO MAIN MENU\n";
                cin>>c;
                fnMainScreen2();
            }

            temp=0;
            fp.close();
        }



    }
    return seatno;
}//function close here*/

//When a user completes the formalities required for reservation, he needs to see his ticket. This function gives an outlook of the ticket.
//Including ticket number, every details are shown in an arranged way.

//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

void bus::fnShowTicket(int choice,int seat,int idate,int imonth)
{
    bus t;
    int temp=0;
    fstream   fp;
    switch(choice)
    {
    case 1:
    {
        fp.open("bus1.txt",ios::in);
        if(fp==NULL)
        {
            cout<<"\ncannot open file\n";
        }
        while(fp.read((char*)&t,sizeof(t)) && (temp==0))
        {
            if(t.seatno==seat && t.date==idate && t.month==imonth )
            {
                fnPrintLine();
                cout<<"\n\n\t Ticket NO.:"<<t.ticketno;
                cout<<"\n\t SEAT NO.:"<<t.seatno;
                cout<<"\n\t NAME :"<<name;
                cout<<"\n\t AGE :"<<age;
                cout<<"\n\t SEX :"<<sex;
                cout<<"\n\t DATE:"<<idate;
                cout<<"\n\t MONTH:"<<imonth;
                cout<<"\n\n\t FARE: Rs400 \t FROM : MUMBAI";
                cout<<"\n\t DESTINATION : BANGLORE \t TIME : 40 hours\n";
                fnPrintLine();
                cout<<"\n\n\n";
                cout<<("\t\t Ticket Reserved Successfully\n");
                temp++;//once the data matches we need not to serch further
            }
        }
        fp.close();

    }
    break;
    case 2:
    {
        fp.open("bus2.txt",ios::in);
        while(fp.read((char*)&t,sizeof(t))&&(temp==0))
        {
            if(t.seatno==seat && t.date==idate && t.month==imonth )
            {
                fnPrintLine();
                cout<<"\n\n\t Ticket NO.:"<<ticketno;
                cout<<"\n\t SEAT NO.:"<<seatno;
                cout<<"\n\t NAME :"<<name;
                cout<<"\n\t AGE :"<<age;
                cout<<"\n\t SEX :"<<sex;
                cout<<"\n\t DATE:"<<idate;
                cout<<"\n\t MONTH:"<<imonth;
                cout<<"\n\n\t FARE: Rs500 \t FROM : MUMBAI";
                cout<<"\n\t DESTINATION : AHEMDABAD \t TIME : 45 hours\n";
                fnPrintLine();
                cout<<"\n\n\n";
                cout<<("\t\t Ticket Reserved Successfully\n");
                temp++;
            }
        }
        fp.close();
    }
    break;
    case 3:
    {
        fp.open("bus3.txt",ios::in);
        while(fp.read((char*)&t,sizeof(t))&&(temp==0))
        {
            if(t.seatno==seat && t.date==idate && t.month==imonth)
            {
                fnPrintLine();
                cout<<"\n\n\t Ticket NO.:"<<ticketno;
                cout<<"\n\t SEAT NO.:"<<seatno;
                cout<<"\n\t NAME :"<<name;
                cout<<"\n\t AGE :"<<age;
                cout<<"\n\t SEX :"<<sex;
                cout<<"\n\t DATE:"<<idate;
                cout<<"\n\t MONTH:"<<imonth;
                cout<<"\n\n\t FARE: Rs600 \t FROM : MUMBAI";
                cout<<"\n\t DESTINATION : BHOPAL \t TIME : 35 hours\n";
                fnPrintLine();
                cout<<"\n\n\n";
                cout<<("\t\t Ticket Reserved Successfully\n");
                temp++;
            }
        }
        fp.close();
    }
    break;
    case 4:
    {
        fp.open("bus4.txt",ios::in);
        while(fp.read((char*)&t,sizeof(t))&&(temp==0))
        {
            if(t.seatno==seat && t.date==idate && t.month==imonth)
            {
                fnPrintLine();
                cout<<"\n\n\t Ticket NO.:"<<ticketno;
                cout<<"\n\t SEAT NO.:"<<seatno;
                cout<<"\n\t NAME :"<<name;
                cout<<"\n\t AGE :"<<age;
                cout<<"\n\t SEX :"<<sex;
                cout<<"\n\t DATE:"<<date;
                cout<<"\n\t MONTH:"<<imonth;
                cout<<"\n\n\t FARE: Rs300 \t FROM : MUMBAI";
                cout<<"\n\t DESTINATION : GOA \t TIME : 40 hours\n";
                fnPrintLine();
                cout<<"\n\n\n";
                cout<<("\t\t Ticket Reserved Succeccfully\n");
                temp++;
            }
        }
        fp.close();
        break;
    }
    } // switch closed here
}  // function closed here

// here is the enquiry section which asks user the field to enquire
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------


void bus::fnEnquiry()
{

    char choice2;
    cout<<"\n\n\t WELCOME TO ENQUIRY SECTION";
    cout<<"\n\n\t WE ARE THANKFUL TO HELP YOU\n";

    fnPrintLine();
    cout<<"\n\n\t\t PRESS a: TICKET STATUS";
    cout<<"\n\t\t PRESS b: SEAT AVAILABILITY";
    cout<<"\n\t\t PRESS c: BUS RUNNING INFORMATION";
    cout<<"\n\t\t PRESS d: RULES OF BUS SERVICE";
    cout<<"\n\n\t\t PRESS ANY OTHER KEY TO GO BACK TO MAIN MENU";
    cout<<"\n\n\t\t ENTER YOUR CHOICE:-";
    while (!(cin >> choice2))
    {
        cout << "INVALID DATA TYPE FOR CHOICE! try again: ";

        cin.clear();
        cin.ignore();
  }

    switch(choice2)
    {
    case 'a':
        fnTicketStatus();
        break;
    case 'b':
        fnSeatAvailability();
        break;
    case 'c':
        fnBusRunningInfo();
        break;
    case 'd':
        fnRules();
        break;
    default:

        fnMainScreen2();
    }   //switch closed here
}   //function closed here


//fnSeatavailability enquires the total number of seats available at a particular date in a particular destinated bus
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

void bus::fnSeatAvailability()
{
    int count=0;
    int jorneydate,jorneymonth;
    fstream fp;
    char c;
    char a;
    bus av;
    cout<<"\n\tEnter date of jorney:";
    cin>>jorneydate;

    cout<<"\n\tEnter month of jorney:";
    cin>>jorneymonth;

    cout<<"\n\t Enter the destination";
    cout<<"\n\n\t BANGALORE(B)\t AHEMDABAD(A)\t BHOPAL(p)\t GOA(G)\t";
    while (!(cin >> c))
    {
        cout << "INVALID DATA TYPE FOR destination! try again: ";

        cin.clear();
        cin.ignore();
  }

    if(c=='B'||c=='b')
    {
        fp.open("bus1.txt",ios::in);
        while(fp.read((char*)&av,sizeof(av)))
        {
            if((av.date==jorneydate) && (av.month==jorneymonth) )
            {
                count++;
            }
        }
        fp.close();
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS ="<<40-count;
        if(count==40)
        {
            cout<<"\n\n\n\t SORRY!!NO SEAT AVAILABLE";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }

    else if(c=='A'||c=='a')
    {
        fp.open("bus2.txt",ios::in);
        while(fp.read((char*)&av,sizeof(av)))
        {
            if((av.date==jorneydate) && (av.month==jorneymonth) )
            {

                count++;
            }

        }
        fp.close();
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS ="<<40-count;
        if(count==40)
        {
            cout<<"\n\n\n\t SORRY!!NO SEAT AVAILABLE";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }

    else if(c=='B'||c=='b')
    {
        fp.open("bus3.txt",ios::in);
        while(fp.read((char*)&av,sizeof(av)))
        {
            if((av.date==jorneydate) && (av.month==jorneymonth) )
            {
                count++;
            }


        }
        fp.close();
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS ="<<40-count;
        if(count==40)
        {
            cout<<"\n\n\n\t SORRY!!NO SEAT AVAILABLE";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }

    else if(c=='G'||c=='g')

    {
        fp.open("bus4.txt",ios::in);
        while(fp.read((char*)&av,sizeof(av)))
        {
            if((av.date==jorneydate) && (av.month==jorneymonth) )
            {
                count++;
            }


        }
        fp.close();
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS ="<<40-count;
        if(count==40)
        {
            cout<<"\n\n\n\t SORRY!!NO SEAT AVAILABLE";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }

    else
    {
        cout<<"\n\n\t\t\t WRONG INPUT ";
        cout<<"\n\n\n";
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }
} // function closed here




//fnPassengerList gives the list of the passenger at a certain date of a partcular bus
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

void bus::fnPassengerList()  //FUNCTION PASSENGERLIST
{

    char c;
    char a;
    int count=0;
    int jorney_date,jorney_month;
    fstream fp;
    cout<<"\n\n\n\t\t PASSENGER LIST\n";
    fnPrintLine();
    cout<<"\n\n\t Enter jorney date:";
    cin>>jorney_date;
    cout<<"\n\n\t Enter jorney month:";
    cin>>jorney_month;
    cout<<"\n\n\tENTER THE ROUTE DESTINSTION";
    cout<<"\n\t BANGALORE(B)\t AHEMDABAD(A)\t BHOPAL(P)\t GOA(G)";
    while (!(cin >> c))
    {
        cout << "INVALID DATA TYPE FOR destination! try again: ";

        cin.clear();
        cin.ignore();
  }

    if(c=='b' || c=='B')
    {
        cout<<"\n\n\n\t\t MUMBAI TO BANGALORE\n\n\n";
        fp.open("bus1.txt",ios::in);
        cout<<"\n\n\n SEAT NO\t NAME\t AGE\t SEX\tDATE\n";
        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(date==jorney_date && month==jorney_month)
            {

                cout<<"\n ";
                cout<<seatno<<"\t\t ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"/"<<month<<endl;

                count++;
            }
        } //while closed here
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS= "<<40-count;
        fp.close();
        cout<<"\n\n\t\tPRESS   TO GO BACK TO ADMIN SECTION\n";
        cin>>a;
        admin();
    } //if closed here


    if(c=='a' || c=='A')
    {
        cout<<"\n\n\n\t\t MUMBAI TO AHEMDABAD";
        fp.open("bus2.txt",ios::in);
        cout<<"\n SEAT NO\t NAME\t AGE\t SEX\tDATE\n";
        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(date==jorney_date && month==jorney_month)
            {

                cout<<"\n";
                cout<<seatno<<"\t\t";
                cout<<name<<"\t";
                cout<<age<<"\t";
                cout<<sex<<"\t";
                cout<<date<<"/"<<month<<endl;

                count++;
            }
        } //while closed here
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS= "<<40-count;
        fp.close();
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ADMIN MENU\n";
        cin>>a;
        admin();
    } //if closed here


    if(c=='B' || c=='b')
    {
        cout<<"\n\n\n\t\t MUMBAI TO BHOPAL";
        fp.open("bus3.txt",ios::in);
        cout<<"\n SEAT NO\t NAME\t AGE\t SEX\tDATE\n";
        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(date==jorney_date && month==jorney_month)
            {

                cout<<"\n";
                cout<<seatno<<"\t\t";
                cout<<name<<"\t";
                cout<<age<<"\t";
                cout<<sex<<"\t";
                cout<<date<<"/"<<month<<endl;

                count++;
            }
        } //while closed here
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS= "<<40-count;
        fp.close();
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ADMIN MENU\n";
        cin>>a;
        admin();
    } //if closed here


    if(c=='g' || c=='G')
    {
        cout<<"\n\n\n\t\t MUMBAI TO GOA";
        fp.open("bus4.txt",ios::in);
        cout<<"\n SEAT NO\t NAME\t AGE\t SEX\tDATE\n";
        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(date==jorney_date && month==jorney_month)
            {

                cout<<"\n";
                cout<<seatno<<"\t\t";
                cout<<name<<"\t";
                cout<<age<<"\t";
                cout<<sex<<"\t";
                cout<<date<<"/"<<month<<endl;
                count++;
            }
        } //while closed here
        cout<<"\n\n\n\t TOTAL SEATS= 40";
        cout<<"\n\t REMAINING SEATS= "<<40-count;
        fp.close();
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ADMIN MENU\n";
        cin>>a;
        admin();
    } //if closed here

    else
    {
        cout<<"\n\n\t\t\t WRONG INPUT ";
        cout<<"\n\n\n";
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO main menu\n";
        cin>>a;
        fnMainScreen1();
    }

} //function closed here

//followind coded function is fnTicketStatus() which helps user to be assured of his reserved ticket. He can check his reservation details at any time
//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

void bus::fnTicketStatus()
{
    bus ts;
    int ur_date,ur_month;
    char c;
    int seat;
    char a;
    fstream fp;
    int temp=1;
    cout<<"\n\n\n\t\t\t TICKET STATUS\n";
    fnPrintLine();
    cout<<"\n\n\t ENTER THE SEAT NUMBER ";
    cin>>seat;
    cout<<"Enter jorney date:";
    cin>>ur_date;
    cout<<"enter jorney month:";
    cin>>ur_month;
    cout<<"\n\t ENTER THE ROUTE DESTINATION ";
    cout<<"\n\n\t BANGALORE(B)\t AHEMDABAD(A)\t BHOPAL(P)\t GOA(G)\t";
    while (!(cin >> c))
    {
        cout << "INVALID DATA TYPE FOR destination! try again: ";

        cin.clear();
        cin.ignore();
  }
    if(c=='B'||c=='b')
    {
        fp.open("bus1.txt",ios::in);

        while(fp.read((char*)&ts,sizeof(ts)))
        {
            if(ts.seatno==seat && ts.date==ur_date && ts.month==ur_month)
            {
                temp=0;
                cout<<"\n\n";
                fnPrintLine();

                cout<<"\n\t Ticket No: "<<ticketno;
                cout<<"\n\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 200 \t FROM: mumbai";
                cout<<"\n\t DESTINATION: Bangalore \t TIME: 06:00 hrs\n";

                fnPrintLine();
            }
        }  //while closed here
        fp.close();

        if(temp==1)
        {
            cout<<"\n\n\n\t YOUR TICKET IS NOT RESERVED";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }

    else if(c=='A'||c=='a')
    {
        fp.open("bus2.txt",ios::in);

        while(fp.read((char*)&ts,sizeof(ts)))
        {
            if(ts.seatno==seat && ts.date==ur_date && ts.month==ur_month)
            {
                temp=0;
                cout<<"\n\n";
                fnPrintLine();
                cout<<"\n\t Ticket No: "<<ticketno;
                cout<<"\n\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 200 \t FROM: mumbai";
                cout<<"\n\t DESTINATION: Ahemdabad \t TIME: 0830 hrs\n";

                fnPrintLine();

            }
        }
        fp.close();

        if(temp==1)
        {
            cout<<"\n\n\n\t YOUR TICKET IS NOT RESERVED";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }

    else if(c=='P'||c=='p')
    {
        fp.open("bus3.txt",ios::in);

        while(fp.read((char*)&ts,sizeof(ts)))
        {
            if(ts.seatno==seat && ts.date==ur_date && ts.month==ur_month)
            {
                temp=0;
                cout<<"\n\n";
                fnPrintLine();
                cout<<"\n\t Ticket No: "<<ticketno;
                cout<<"\n\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 200 \t FROM: mumbai";
                cout<<"\n\t DESTINATION: Bhopal \t TIME: 0900 hrs\n";

                fnPrintLine();
            }
        }
        fp.close();

        if(temp==1)
        {
            cout<<"\n\n\n\t YOUR TICKET IS NOT RESERVED";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }


    else if(c=='G'||c=='g')
    {
        fp.open("bus4.txt",ios::in);

        while(fp.read((char*)&ts,sizeof(ts)))
        {
            if(ts.seatno==seat && ts.date==ur_date && ts.month==ur_month)
            {
                temp=0;
                cout<<"\n\n";
                fnPrintLine();
                cout<<"\n\t Ticket No: "<<ticketno;
                cout<<"\n\n\t Seat No: "<<seatno;
                cout<<"\n\tNAME: "<<name;
                cout<<"\n\t AGE: "<<age;
                cout<<"\n\t SEX: "<<sex;
                cout<<"\n\n\t FARE: Rs 200 \t FROM: mumbai";
                cout<<"\n\t DESTINATION: Goa \t TIME: 0430 hrs\n";


                fnPrintLine();
            }
        }
        fp.close();

        if(temp==1)
        {
            cout<<"\n\n\n\t YOUR TICKET IS NOT RESERVED";
        }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }

    else
    {
        cout<<"\n\n\t\t\t WRONG INPUT ";
        cout<<"\n\n\n";
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    }
}
void bus::fnRules()  // function fnRules()
{
    fstream fp;

    char a;
    string line;
    fp.open("rule.txt",ios::in);
    if (fp.is_open())
    {
        while ( getline (fp,line) )
        {
            cout << line << '\n';
        }
        fp.close();
    }
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
}


// bus running information function given below
//-----------------------------------------------------------------------------------------------------------------------

void bus::fnBusRunningInfo()
{
    fstream fp;
    int choice;
    char a;

    cout<<"\n\n\t\t1. Mumbai to Bangalore";
    cout<<"\n\t\t2. Mumbai to Ahemdabad";
    cout<<"\n\t\t3. Mumbai to Bhopal";
    cout<<"\n\t\t4. Mumbai to Goa";

    cout<<" \n\n\tEnter your choice to get the information:  ";
    while (!(cin >> choice))
    {
        cout << "INVALID DATA TYPE FOR destination! try again: ";

        cin.clear();
        cin.ignore();
  }

    switch(choice)
    {

    case 1:
    {
        string line;
        fp.open("bangalore.txt",ios::in);
        if (fp.is_open())
        {
            while ( getline (fp,line) )
            {
                cout << line << '\n';
            }
            fp.close();
        }

        cout << endl << endl;

        cout<<"\n\n\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
        break;
    }

    case 2:
    {
        string line;
        fp.open("ahemdabad.txt",ios::in);
        if (fp.is_open())
        {
            while ( getline (fp,line) )
            {
                cout << line << '\n';
            }
            fp.close();
        }

        cout << endl << endl;

        cout<<"\n\n\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
        break;
    }

    case 3:
    {
        string line;
        fp.open("bhopal.txt",ios::in);
        if (fp.is_open())
        {
            while ( getline (fp,line) )
            {
                cout << line << '\n';
            }
            fp.close();
        }

        cout << endl << endl;

        cout<<"\n\n\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
        break;
    }

    case 4:
    {
        string line;
        fp.open("goa.txt",ios::in);
        if (fp.is_open())
        {
            while ( getline (fp,line) )
            {
                cout << line << '\n';
            }
            fp.close();
        }

        cout << endl << endl;

        cout<<"\n\n\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
        break;
    }
    default :
        cout<<"\n\n\t\t\t WRONG INPUT";
        cout<<"\n\n\n\n\t\tPRESS ANY KEY TO GO BACK TO ENQUIRY SECTION\n";
        cin>>a;
        fnEnquiry();
    } // switch closed here
} // function closed here

//---------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------

void fnPrintLine()
{
    int j;
    for(j=0; j<80; j++)
        cout<<"*";
}
//---------------------------------------------------------------------------------------------------------------------------
//FUNCTION ADMIN GIVEN BELOW
//---------------------------------------------------------------------------------------------------------------------------


void bus::admin()
{
    char c;
    int n;


    cout<<endl<<endl;
    cout<<"\n\t1. DISPLAY PERSONAL DETAILS BY DAY,DATE AND MONTH "<<endl;
    cout<<"\n\t2: SEARCH BY NAME"<<endl;
    cout<<"\n\t3: SEARCH BY TICKET NO."<<endl;
    cout<<"\n\t4: TERMINATE"<<endl;


    cout<<"\n\tENTER YOUR CHOICE: ";

    while (!(cin >> n))
    {
        cout << "INVALID DATA TYPE FOR choice! try again: ";

        cin.clear();
        cin.ignore();
  }


    if(n==1)
    {

        b.fnPassengerList();
    }

    else     if(n==2)
    {

        char pname[30];

        fstream fp;
        cout<<"\n\n\n\t\t PASSENGER LIST BY NAME\n";
        fnPrintLine();
        cout<<"\n\n\t Enter PASSENGER'S NAME :";
        cin>>pname;



        fp.open("bus1.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(compare(name , pname) )
            {
                cout<<"bus1 from mumbai    to  bangalore     ";
                cout<<"\n name\t  AGE\t SEX\tDATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;


            }
        } //while closed here

        fp.close();



        fp.open("bus2.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(compare(name,pname))
            {
                cout<<"bus2 from mumbai        to  ahemdabad     ";
                cout<<"\n  NAME\t AGE\t SEX\t\tDATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;


            }
        } //while closed here

        fp.close();

        fp.open("bus3.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(compare( name, pname))
            {
                cout<<"bus3 from mumbai  to  bhopal     ";
                cout<<"\n  NAME\t AGE\t SEX\t DATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;


            }
        } //while closed here

        fp.close();

        fp.open("bus4.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if( compare( name , pname))
            {
                cout<<"bus4 from  mumbai       to   goa    ";
                cout<<"\n  NAME\t AGE\t SEX\t DATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;


            }
        } //while closed here

        fp.close();
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK \n";
        cin>>c;
        admin();

    }



    else       if(n==3)
    {
        long int Ticketno;


        fstream fp;
        cout<<"\n\n\n\t\t PASSENGER LIST BY TICKETNO\n";
        fnPrintLine();
        cout<<"\n\n\t Enter TICKETNO  :";
        cin>>Ticketno;



        fp.open("bus1.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(Ticketno==ticketno)
            {
                cout<<"bus1 from  mumbai       to    bangalore   ";
                cout<<"\n  NAME\t AGE\t SEX\t DATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;
            }



        } //while closed here

        fp.close();



        fp.open("bus2.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(Ticketno==ticketno)
            {
                cout<<"bus2 from  mumbai       to   ahemdabad    ";
                cout<<"\n  NAME\t AGE\t SEX\t DATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;


            }
        } //while closed here

        fp.close();


        fp.open("bus3.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(Ticketno==ticketno)
            {
                cout<<"bus3 from   mumbai      to    bhopal   ";
                cout<<"\n  NAME\t AGE\t SEX\t DATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;


            }
        } //while closed here

        fp.close();

        fp.open("bus4.txt",ios::in);

        fnPrintLine();
        while(fp.read((char*)&b,sizeof(b)))
        {
            if(Ticketno==ticketno)
            {
                cout<<"bus4 from   mumbai      to     goa  ";
                cout<<"\n  NAME\t AGE\t SEX\t DATE\t MONTH\t SEATNO\t TICKETNO\n";
                cout<<"\n ";
                cout<<name<<"\t ";
                cout<<age<<"\t ";
                cout<<sex<<"\t ";
                cout<<date<<"\t ";
                cout<<month<<"\t";
                cout<<seatno<<"\t";
                cout<<ticketno<<endl;


            }
        } //while closed here

        fp.close();
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK \n";
        cin>>c;
        admin();
    }


    else  if(n==4)
    {
        cout<<"\n\t[THIS WILL LEAD TO LOSS OF ALL DATA RELATED TO CUSTOMER]"<<endl;
        cout<<"\n\tDO YOU STILL WANT TO TERMINET THE PROGRAM?"<<endl;
        cout<<"\n\tIF YES THEN PRESS 'Y'AND FOR NO PRESS 'E'FOR GO TO BACK MENU"<<endl;
        cin>>c;
        if(c=='y'||c=='y')
        {
            fstream fp ;
            fp.open("bus1.txt",ios::out|ios::trunc);
            fp.close();
            fp.open("bus2.txt",ios::out|ios::trunc);
            fp.close();
            fp.open("bus3.txt",ios::out|ios::trunc);
            fp.close();
            fp.open("bus4.txt",ios::out|ios::trunc);
            fp.close();
          cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK \n";
          cin>>c;
          admin();
        }
        if(c=='e'||c=='E') admin();
    }


    else if(n<1 || n>4)
    {
        cout<<"wrong input"<<endl;
        cout<<"\n\n\t\tPRESS ANY KEY TO GO BACK \n";
        cin>>c;
        admin();
    }


}

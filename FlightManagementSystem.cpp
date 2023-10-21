#include<iostream>
#include<string.h>
using namespace std;

int c=0, b=100, pnrd, pnri;
string t_date;


class Flight {
	protected:
		string trip_date;
	public:
		void input_trip_date() {
			cout << "\nEnter Date of Journey(DDMMYYYY) : ";
			getline(cin, trip_date);
			t_date = trip_date;
		}
};


class Location {
public:
    virtual void input_depart_destin() = 0;
    virtual void choices() = 0;
};


class Domestic : virtual public Flight, public Location {
	protected:
		int departure_num, destination_num, choice;
	public:
		void disp_pnr_dom() {
			c++;
	      	pnrd = c;
			cout << "\nPNR: " << pnrd;
		}
		
		void print_flight_choice(string h1, string h2, string p1, string h3,
		 string h4, string p2, string h5, string h6, string p3, int ch) {
			cout<<"\nFlight Details :----";
			switch(ch){
				case 1:
					cout << "\nSpicejet\tTake-off:- " << h1 << " hrs\tLanding:- " << h2 << " hrs\tPrice:- Rs." << p1;
					break;
				case 2:
					cout << "\nIndigo\tTake-off:- " << h3 << " hrs\tLanding:- " << h4 << " hrs\tPrice:- Rs." << p2;
					break;
				case 3:
					cout << "\nGoAir \tTake-off:- " << h5 << " hrs\tLanding:- " << h6 << " hrs\tPrice:- Rs." << p3;
					break;
				default:
					cout<<"\nInvalid Option";
			}
			disp_pnr_dom();
		}
		
		void get_flight_choice(string h1, string h2, string p1, string h3,
		 string h4, string p2, string h5, string h6, string p3) {
			cout << "\nFlights for date "<< t_date <<" are as follows :---";
			cout << "\n1.Spicejet\tTake-off:- " << h1 << " hrs\tLanding:- " << h2 << " hrs\tPrice:- Rs." << p1;
			cout << "\n2.Indigo\tTake-off:- " << h3 << " hrs\tLanding:- " << h4 << " hrs\tPrice:- Rs." << p2;
			cout << "\n3.GoAir \tTake-off:- " << h5 << " hrs\tLanding:- " << h6 << " hrs\tPrice:- Rs." << p3;
			cout << "\nEnter Your Choice : ";
			int ch;
			cin >> ch;
			
			print_flight_choice(h1, h2, p1, h3, h4, p2, h5, h6, p3, ch);
		}
		
		void input_depart_destin() {
			cout << "Date of Journey (ddmmyyyy): " << t_date << endl;
			cout << "\n\nLocations available:\n1) Ahmedabad\n2) Mumbai\n3) Delhi";
			cout << "\nEnter departure location number: ";
			cin >> departure_num;
			cout << "\nEnter destination location number: ";
			cin >> destination_num;
			system("cls");
		}
		
		void choices() {
			if(((departure_num==1) && (destination_num==2)) || ((departure_num==2) && (destination_num==1)))
				get_flight_choice("1800", "1930", "3500", "1200", "1330", "3750", "0600", "0730", "4000");
			else if(((departure_num==2) && (destination_num==3)) || ((departure_num==3) && (destination_num==2)))
				get_flight_choice("1830", "2100", "4500", "1400", "1630", "4750", "0630", "0730", "4000");
			else if(((departure_num==1) && (destination_num==3)) || ((departure_num==3) && (destination_num==1)))
				get_flight_choice("1800", "1930", "3500", "1200", "1330", "3750", "0600", "0730", "4000");
			else {
				system("cls");
				cout << "invalid option";
				exit(0);
			}
		}
};


class International : virtual public Flight, public Location {
	protected:
		int departure_num, destination_num, choice;
	public:
		void disp_pnr_int() {
			b+=1;
         	pnri=b;
			cout << "\nPNR: " << pnri;
		}
		
		void print_flight_choice(string h1, string h2, string p1, string h3,
		 string h4, string p2, string h5, string h6, string p3, int ch) {
			cout<<"Flight Details :----";
			switch(ch){
				case 1:
					cout << "\nEmirates\tTake-off:- " << h1 << " hrs\tLanding:- " << h2 << " hrs\tPrice:- Rs." << p1;
					break;
				case 2:
					cout << "\nQatar Airways\tTake-off:- " << h3 << " hrs\tLanding:- " << h4 << " hrs\tPrice:- Rs." << p2;
					break;
				case 3:
					cout << "\nAir India\tTake-off:- " << h5 << " hrs\tLanding:- " << h6 << " hrs\tPrice:- Rs." << p3;
					break;
				default:
					cout<<"\nInvalid Option";
			}
			disp_pnr_int();
		}
		
		void get_flight_choice(string h1, string h2, string p1, string h3,
		 string h4, string p2, string h5, string h6, string p3) {
			cout << "\nFlights for date "<< t_date <<" are as follows :---";
			cout << "\n1.Emirates\tTake-off:- " << h1 << " hrs\tLanding:- " << h2 << " hrs\tPrice:- Rs." << p1;
			cout << "\n2.Qatar Airways\tTake-off:- " << h3 << " hrs\tLanding:- " << h4 << " hrs\tPrice:- Rs." << p2;
			cout << "\n3.Air India\tTake-off:- " << h5 << " hrs\tLanding:- " << h6 << " hrs\tPrice:- Rs." << p3;
			cout << "\nEnter Your Choice : ";
			int ch;
			cin >> ch;
			
			print_flight_choice(h1, h2, p1, h3, h4, p2, h5, h6, p3, ch);
		}
		
		void input_depart_destin() {
			cout << "Date of Journey (ddmmyyyy): " << t_date << endl;
			cout << "\n\nLocations available:\n1) Melbourn\n2) California\n3) Sweden";
			cout << "\nEnter departure location number: ";
			cin >> departure_num;
			cout << "\nEnter destination location number: ";
			cin >> destination_num;
			system("cls");
		}
		
		void choices() {
			if(((departure_num==1) && (destination_num==2)) || ((departure_num==2) && (destination_num==1)))
				get_flight_choice("0600", "2140", "203000", "0700", "2240", "201000", "0300", "1840", "200000");
			else if(((departure_num==2) && (destination_num==3)) || ((departure_num==3) && (destination_num==2)))
				get_flight_choice("0900", "2020", "100000", "0300", "1720", "90000", "1100", "2220", "103000");
			else if(((departure_num==1) && (destination_num==3)) || ((departure_num==3) && (destination_num==1)))
				get_flight_choice("1500", "1500(next day)", "250000", "2200", "2200(next day)", "240000", "1700", "1700(next day)", "200000");
			else {
				system("cls");
				cout << "invalid option";
				exit(0);
			}
		}
};


class Payment {
	protected:
		int expiry, cvv;
		string card_num, username, password;
		int choice;
	public:
		void get_un_pw() {
			cout << "\nUSERNAME : ";
			getline(cin, username);
			cout << "\nPASSWORD : ";
			getline(cin, username);
		}
		
		int payment() {
			cout << "PAYMENT DETAILS : ";
			cout << "\n1.CREDIT CARD";
			cout << "\n2.DEBIT CARD";
			cout << "\n3.NETBANKING";
	        cout << "\n*****";
			cout << "\nENTER YOUR CHOICE : ";
			cin >> choice;
			
			if(choice == 1)
				cout << "\nENTER CREDIT CARD DETAILS...";
			else if(choice == 2)
				cout << "\nENTER DEBIT CARD DETAILS...";
			
			if(choice == 1 || choice == 2) {
            	cout << "\n\tCARD NUMBER : ";
				cin >> card_num;
            	cout << "\n\tCVV NUMBER :";
				cin >> cvv;
            	cout << "\n\tEXPIRY DATE :";
				cin >> expiry;
			}
			else if(choice == 3) {				
				int bank_num;
				cout << "\nNETBANKING ";
				cout << "\n1.AXIS BANK";
				cout << "\n2.SBI";
				cout << "\n3.KOTAK";
				cout << "\n4.HDFC";
				cout << "\n*****";
				cout << "\nENTER YOUR CHOICE : ";
				cin >> bank_num;
				
				system("cls");
				
				switch(bank_num) {
	    			case 1:	
	    				cout << "AXIS BANK";
	    				get_un_pw();
        				break;
        			case 2: 
        				cout << "SBI";
        				get_un_pw();
        				break;
        			case 3:
        				cout << "KOTAK";
        				get_un_pw();
       					break;
        			case 4:
        				cout << "HDFC";
        				get_un_pw();
        				break;
        			default:
						cout << "\nInvalid option";
        		}
    		}
    		system("cls");
    		cout << "*YOUR TRANSACTION IS SUCCESSFUL*";
		}
};


class Passenger : public Domestic, public International, public Payment {
	protected:
		int age;
		string fname, lname, gender, email, contact;
		
	public:
		void input_personal_details() {
			cout << "Enter Passenger Details..." << endl;
			cout << "First name: ";
			getline(cin, fname);
			cout << "Last Name: ";
			getline(cin, lname);
			cout << "Gender: ";
			getline(cin, gender);
			cout << "Age: ";
			cin >> age;
			cin.ignore();
			cout << "Contact Number: ";
			getline(cin, contact);
			cout << "Email: ";
			getline(cin, email);
		}
		
		void display_personal_details() {
			cout << "First name: " << fname << endl;
			cout << "Last Name: " << lname << endl;
			cout << "Gender: " << gender << endl;
			cout << "Age: " << age << endl;
			cout << "Contact Number: " << contact << endl;
			cout << "Email: " << email << endl;
	 	}
		
		void book_tickets() {
			int type_choice;
			cout << "\nPress 1 for Domestic\nPress 2 for International";
			cout << "\nEnter your choice : ";
			cin >> type_choice;
			
			Flight::input_trip_date();
			system("cls");
			
			switch(type_choice) {
				case 1:
					Domestic::input_depart_destin();
					Domestic::choices();
					break;
				case 2:
					International::input_depart_destin();
					International::choices();
					break;
				default:
					cout << "Invalid choice!";
			}
			
			cout << "\n\n";
			Payment::payment();
		}
};


int main() {
	int exit = 0;
	do {
		cout << "------------------------------------------------------------------------------------";
		cout << "\n                   WELCOME TO FAST AND FURIOUS AIRLINE BOOKING SERVICE                 ";
		cout << "\n                   ***************************************************  ";
		cout << "\n\n------------------------------------------------------------------------------------" << endl;
		Passenger p1;
		p1.input_personal_details();
		
		system("cls");
		cout << "\nPersonal Details:\n";
		p1.display_personal_details();
		p1.book_tickets();
		cout<<"\n\n------------------------------------------------------------------------------------";
		cout<<"\n\n                             *ENJOY YOUR JOURNEY*                             ";
	    cout<<"\n\n------------------------------------------------------------------------------------\n";
	    cout << "\nEnter 1 to exit.";
	    cin >> exit;
	} while(exit != 1);
	
	return 0;
}

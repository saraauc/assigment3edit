#include <iostream>
#include <fstream>
#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include "Queue.h"

using namespace std;

int main()
{
	//Note: I did not know how to use files with that so I used Chatgpt and geek for geeksto help me understand and I rewrote it
	ifstream mechanicsd("mechanicsD.txt"); //  file open
	int nm;      //number of mechanics
	int na;      //number avaliable
	mechanicsd >> nm; // get info from file
	mechanic* mechanics = new mechanic[nm]; // dynamic arry with info inserted
	string name;
	int age, id;
	for (int i = 0; i < nm; i++) { 
		
		mechanicsd >> name >> id >> age >> na;
		mechanics[i] = mechanic(name, id, age);


		for (int k = 0; k < na; k++) {
			int hours, mins;
			mechanicsd >> hours >> mins;
			mechanics[i].addAppointment(Appointment(hours, mins));

		}
	}
	mechanicsd.close();  //close file


	//Note: I did not know how to use files with that so I used Chatgpt to help me understand and I rewrote it
	//same as mechanic but with customer
	ifstream customersd("customersD.txt"); 
	int nc;  //number of customers
	customersd >> nc; 
	customer* customers = new customer[nc]; 
	for (int i = 0; i < nc; i++) { 
		string name;
		int age, id, hours, mins;
		customersd >> name >> id >> age >> hours >> mins;
		customers[i] = customer(name, id, age, -1, Appointment(hours, mins));
	}
	customersd.close();


	//here is where a customer is assigned to an avaliable mechanic
	Queue<customer> Queue(nc); 
	int x = 0;
	for (int i = 0; i < nc; i++) {
		bool assigned = false;
		int Index;
		for (int j = 0; j < nm && !assigned && customers[i].getMechanicID() == -1; j++) { // check to find if a customer does not have a mechanic
			if (mechanics[j].isAvailable(customers[i].getAppointment())) { //check if the mechanic is avaliable within the requested time
				int Index = i % nm; 
				mechanics[Index].addAppointment(customers[i].getAppointment()); // fill mechanic's sheduale
				customers[i].setMechanicID(Index); 
				assigned = true;
			}
		}
		if (!assigned) { // teels us if no mechanic avaliable 
			cout << "No mechanics available for customer " << customers[i].getID() << endl;
		}
	}


	// print customers in order of appointments and their assigned mechanics by arranging the array according to the apointments time
	// using the overloaded operators
	for (int k = 0; k < nc; k++)
	{
		for (int l = k; l < nc; l++)
		{
			if (customers[k] > customers[l])
			{
				customer c = customers[k];
				customers[k] = customers[l];
				customers[l] = c;
			}
		}
	}
	for (int m = 0; m < nc; m++) // push 
	{
		Queue.push(customers[m]);
	}


	for (int i = 0; i < nc; i++) { //final schudual 
		int Index = i % nm;
		cout << "Customer: " << Queue.PK().getName() << " has an appointment at "
			<< Queue.PK().getAppointment().hours << ":" << Queue.PK().getAppointment().mins
			<< " with Mechanic:  " << mechanics[Index].getName() << endl;
		Queue.pop();
	}



	return 0;
}

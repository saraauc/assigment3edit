#include "customer.h"
#include <iostream>
#include<string>
using namespace std;


customer::customer()        //defualt constructor
{
	appointment = { 0, 0 };
	mechanicId = 0;
	
} 

customer::customer(string name, int id, int age, int mechanicId, const Appointment& appointment) : //constructor inherite from other paramterized constructors
	person(name, id, age), mechanicId(mechanicId), appointment(appointment) {}

void customer::setMechanicID(int mechanicId1) {
	mechanicId = mechanicId1;
}

void customer::setAppointment(const Appointment& appointment1) {
	appointment = appointment1;
}

int customer::getMechanicID() {
	return mechanicId;
}

Appointment customer::getAppointment() const {
	return appointment;
}

void customer::printInfo() const {
	cout << "_____________Customer Data_____________" << endl;
	cout << "Name:" << getName() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Appointment Time: " << appointment.hours << "hrs and " << appointment.mins <<"mins"<< endl;
	cout << "Mechanic ID: " << mechanicId << endl;
	
}
// The comming 3 functions compare hours ad minutes to check which appoitmnet is earlier or if same time
bool customer::operator > (const customer& s) const {          // greater than
	if (appointment.hours > s.appointment.hours) {
		return true;
	}
	else if (appointment.hours == s.appointment.hours) { 
		if (appointment.mins > s.appointment.mins)
		{
			return true;
		}
		else
			false;
	}
	return false;
}

bool customer::operator <(const customer& s) const {         // less than
	if (appointment.hours < s.appointment.hours) {
		return true;
	}
	else if (appointment.hours == s.appointment.hours) { 
		if (appointment.mins < s.appointment.mins)
		{
			return true;
		}
		else
			false;
	}
	return false;
}



bool customer::operator==(const customer& s) const {               // equal than
	return appointment.hours == s.appointment.hours && appointment.mins == s.appointment.mins;
}

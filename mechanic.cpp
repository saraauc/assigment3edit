#include "mechanic.h"

mechanic::mechanic() : person() { // defualt constructor 
	for (int i = 0; i < 10; i++) {
		appointments[i].hours = 0;
		appointments[i].mins = 0;
	}
	counter = 0;
}

mechanic::mechanic(string name, int id, int age) : person(name, id, age) //  constructor 
{
	
	for (int i = 0; i < 10; i++) {
		appointments[i].mins = 0;
		appointments[i].hours = 0;
		
	}
	counter = 0;

}
void mechanic::addAppointment(Appointment ap1) {
	appointments[counter++] = ap1;
}

Appointment mechanic::getApp(int i) { // returns  apointment 
	return appointments[i];
}

int mechanic::getCount() const {   //getter
	return counter;
}

void mechanic::setCount(int count1) { // setter 
	counter = count1;
}

bool mechanic::isAvailable(Appointment ap1) const {   // check avalibality using opertators overloaded
	for (int i = 0; i < counter; i++) {
		if (appointments[i].hours == ap1.hours && appointments[i].mins == ap1.mins) {
			return false; 
		}
	}
	return true; 
}


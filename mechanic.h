#include "person.h"
#include<iostream>
#include<string>
using namespace std;

class mechanic : public person 
{
private:
	int counter;
	Appointment appointments[10];
public:
	mechanic(); 
	mechanic(string name, int id, int age); 
	bool isAvailable(Appointment ap1) const; 
	void setCount(int count); 
	int getCount() const; 
	Appointment getApp(int i); 
	void addAppointment(Appointment ap1);
};

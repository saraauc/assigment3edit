#include "person.h"
#include<iostream>
#include<string>
using namespace std;

class customer : public person 
{
private: 
	int mechanicId;
	Appointment appointment;

public:
	customer(); 
	customer(string name, int id, int age, int mechanicId, const Appointment& appointment);
	void setMechanicID(int mechanicId); 
	void setAppointment(const Appointment& appointment);
	int getMechanicID();
	Appointment getAppointment() const;
	bool operator<(const customer& other) const;
	bool operator>(const customer& other) const;
	bool operator==(const customer& other) const;
	void printInfo() const override; 

};

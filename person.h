#include<iostream>
#include<string>
using namespace std;

struct Appointment { 
	int hours;
	int mins;

	Appointment() // appointment struct
	{
		hours = 0;
		mins = 0;
	}
	Appointment(int h, int m) // appointment struct
	{
		hours = h;
		mins = m;
	}
};

class person 
{
protected: 
	string name;
	int id;
	int age;

public:
	person(); // defualt constructor
	person(string name, int id, int age); // prametarized constructor 
	void setName(string name); //setters
	void setAge(int age);
	void setID(int id);
	string getName() const; 
	int getAge()const;
	int getID()const;
	virtual void printInfo()const; // function used to print according to the other classes
};

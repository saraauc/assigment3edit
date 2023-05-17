#include "person.h"
#include<iostream>
#include<string>
using namespace std;

person::person() { // the defualt constructor
	name = "";
	id = 0;
	age = 0;
	
};

person::person(string name1, int id1, int age1) // the parametiazed constructore
{
	name = name1;
	age = age1;
	id = id1;
}
//setters 

void person::setName(string name1) { 
	name = name1;
};

void person::setAge(int age1) {
	age = age1;
};

void person::setID(int id1) {
	id = id1;
};


// getters 
string person::getName()const {
	return name;
};

int person::getAge()const {
	return age;
};

int person::getID() const {
	return id;
};

void person::printInfo()const {   //prints info
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "ID: " << id << endl;
	
};

// Halit Burak Yeşildal 18050111043

#include<iostream>
#include <string>
#include "Eagle.h"
#include "Animal.h"

using namespace std;

Eagle::Eagle() {
	setName("Eagle");
	setAge(1);
	setWeight(1);
	setIsPet(true);
	isFlying = true;
}

Eagle::Eagle(string nameP, int ageP, double weightP, bool isPetP, bool isFlyingP) {
	setName(nameP);
	setAge(ageP);
	setWeight(weightP);
	setIsPet(isPetP);
	isFlying = isFlyingP;
}

Eagle :: ~Eagle(){};

void Eagle::setIsFlying(bool isFlyingP) {
	isFlying = isFlyingP;
}

bool Eagle::getisFlying() {
	return isFlying;
}

void Eagle::makeSound(){
	if (getIsPet())
		cout << "The " + getName() + " is making sound. Hurry up, leave the area :) \a \a \a" << endl;
	else
		cout << "This is not a pet" << endl;
}

void Eagle::fly() {

	if (getIsPet()) {
		if (getisFlying())
			cout << "It's too late to leave the area, the " + getName() + " is coming for you!! " << endl;
		else
			cout << "Leave the area when you have a chance..." << endl;
	}

	else
		cout << "This is not a pet, It cannot fly!!" << endl;
}

void Eagle::printDeatils() {
	string petC = getIsPet() ? "Yes" : "No";
	string flyC = getisFlying() ? "Yes" : "No";
	cout << "Name: " + getName() + "\nAge: " + to_string(getAge()) << endl;
	cout.precision(10);
	cout << "Weight: ";
	cout<< getWeight();

	cout<<"\nIt's a pet? : " + petC + "\nIt's flying? : " + flyC + "\n*****************************" << endl;
}

double Eagle::operator + (Eagle &e) {
	return  e.getWeight()+getWeight();
}

int Eagle::operator - (Eagle &e) {
	return e.getAge()+ getAge();
}

bool Eagle::operator < (Eagle& e) {
	return (this->getName().compare(e.getName()) < 0);
		
}


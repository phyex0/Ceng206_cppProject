// Halit Burak Yeşildal 18050111043

#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {
	this->name = "Animal";
	this->age = 0;
	this->weight = 0;
	this->isPet = true;
}

Animal::Animal(string nameP, int ageP,double weightP,bool isPetP){
	this->name = nameP;
	this->age = ageP;
	this->weight = weightP;
	this->isPet = isPetP;
}

Animal :: ~Animal(){}

void Animal::setName(string nameP) {
	this->name = nameP;
}

void Animal::setAge(int ageP) {
	this->age = ageP;
}

void Animal::setWeight(double weightP) {
	this->weight = weightP;
}

void Animal::setIsPet(bool isPetP) {
	this->isPet = isPetP;
}

string Animal::getName() {
	return this->name;
}

int Animal::getAge() {
	return this->age;
}

double Animal::getWeight() {
	return this->weight;
}

bool Animal::getIsPet() {
	return this->isPet;
}

void Animal::makeSound() {
	if (getIsPet())
		cout << "Animal voice!!! \a" << endl;
	else
		cout << "This is not a pet, there is no sound!!" << endl;
}

void Animal::eatFood() {
	if (getIsPet())
		cout << "Animal (" + getName() + ") ate its food!!!" << endl;
	else
		cout << "This is not a pet!" << endl;
}

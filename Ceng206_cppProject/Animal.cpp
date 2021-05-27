#include <iostream>
#include "Animal.h"

using namespace std;

Animal::Animal() {
	name = "Animal";
	age = 0;
	weight = 0;
	isPet = true;
}

Animal::Animal(string nameP, int ageP,double weightP,bool isPetP){
	name = nameP;
	age = ageP;
	weight = weightP;
	isPet = isPetP;	
}

Animal :: ~Animal(){}

void Animal::setName(string nameP) {
	name = nameP;
}

void Animal::setAge(int ageP) {
	age = ageP;
}

void Animal::setWeight(double weightP) {
	weight = weightP;
}

void Animal::setIsPet(bool isPetP) {
	isPet = isPetP;
}

string Animal::getName() {
	return name;
}

int Animal::getAge() {
	return age;
}

double Animal::getWeight() {
	return weight;
}

bool Animal::getIsPet() {
	return isPet;
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

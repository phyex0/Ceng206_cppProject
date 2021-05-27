#pragma once
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal
{
	public:

		//constructor
		Animal();
		Animal(string nameP, int ageP, double weightP, bool isPetP);

		//deconstructor
		virtual ~Animal();

		//setters
		void setName(string nameP);
		void setAge(int ageP);
		void setWeight(double weightP);
		void setIsPet(bool isPetP);

		//getters
		string getName();
		int getAge();
		double getWeight();
		bool getIsPet();

		virtual void makeSound();
		virtual void eatFood();


	private:
		string name;
		int age;
		double weight;
		bool isPet;
};

#endif
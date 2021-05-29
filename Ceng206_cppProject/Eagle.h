// Halit Burak Yeşildal 18050111043

#pragma once
#ifndef EAGLE_H
#define EAGLE_H

#include <string>
#include <vector>
#include "Animal.h"

using namespace std;

class Eagle : public Animal
{
	public:
		//constructor
		Eagle();
		Eagle(string nameP, int ageP, double weightP, bool isPetP, bool isFlyingP);

		//deconstructor
		virtual ~Eagle();

		//setters
		void setIsFlying(bool isFlyingP);

		//getters
		bool getisFlying();

		void makeSound();
		void fly();
		void printDeatils();
		

		//operator overloading
		double operator + (Eagle &e);
		int operator - (Eagle &e);
		bool operator < (Eagle& e);
		
	private:
		bool isFlying;
};

#endif

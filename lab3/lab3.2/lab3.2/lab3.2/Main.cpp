#include "Car.h"
#include "Minibus.h"
#include "PassengerCar.h"
#include "IFuelConsumer.h"

#include <conio.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Car* car[4];
	
	car[0] = new PassengerCar("Audi","A7",1389,38000,2020,3000);
	car[0]->printInfo();
	car[0]->Ride();
		IFuelConsumer* ifc1 = dynamic_cast<IFuelConsumer*>(car[0]);
	if (ifc1)
		cout << "Расход топлива: " << car[0]->consume(car[0]->getDistancePassed()) << endl;
	
	
	car[1] = new PassengerCar("BMW", "X7", 2898, 12000, 2011, 5300);
	car[1]->printInfo();
	car[1]->Ride();
	IFuelConsumer* ifc2 = dynamic_cast<IFuelConsumer*>(car[1]);
	if (ifc2)
		cout << "Расход топлива: " << car[1]->consume(car[1]->getDistancePassed()) << endl;
	
	
	car[2] = new Minibus("Toyota", "GranAce", 9981, 19000, 2020, 970);
	car[2]->printInfo();
	car[2]->Ride();
	IFuelConsumer* ifc3 = dynamic_cast<IFuelConsumer*>(car[2]);
	if (ifc3)
		cout << "Расход топлива: " << car[2]->consume(car[2]->getDistancePassed()) << endl;
	
	
	car[3] = new Minibus("Citroen", "SpaceTourer", 3084, 22000, 2020, 4600);
	car[3]->printInfo();
	car[3]->Ride();
	IFuelConsumer* ifc4 = dynamic_cast<IFuelConsumer*>(car[3]);
	if (ifc4)
		cout << "Расход топлива: " << car[3]->consume(car[3]->getDistancePassed()) << endl;

	
	cout << endl << "////////////////" << endl;
	for (size_t i = 0; i < 4; ++i)
		cout << typeid(*car[i]).name() << endl;

	return 0;
}

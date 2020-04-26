#include "Jurassic.h"
#include <iostream>
#include <cstring>
using namespace std;

void Jurassic::resize_cage(size_t newCapacity_cage)
{
	Cage* buff_cage = new (nothrow) Cage[newCapacity_cage];
	//if we don't have problems (nothrow) we cppy all the info that we have

	if (buff_cage) {
		for (size_t i = 0; i < fSize_cage; i++)
		{
			buff_cage[i] = fCages[i];
		}
		delete[]fCages;
		fCapacity_cage = newCapacity_cage;
		//fCages will point at buff_cage
		fCages = buff_cage;
		cout << "Resized!" << endl;
	}
	else
	{
		cout << "Not enough memory, can't do the task that you wanted!" << endl;
	}
}

void Jurassic::resize_dinos(size_t newCapacity_dinos)
{
	Dinosaur* buff_dinos = new (nothrow) Dinosaur[newCapacity_dinos];
	//the same applies here

	if (buff_dinos) {
		for (size_t i = 0; i < fSize_dinos; i++)
		{
			buff_dinos[i] = fDinos[i];
		}
		delete[]fDinos;
		fCapacity_dinos = newCapacity_dinos;
		//fDinos will point at buff_dinos
		fDinos = buff_dinos;
		cout << "Resized!" << endl;
	}
	else
	{
		cout << "Not enough memory, can't do the task that you wanted!" << endl;
	}
}

void Jurassic::add_cage(const Cage& newCage)
{
	//we add the new cage to the first free position after the last added element

	if (fCages->isValid_cage()) {
		if (fSize_cage >= fCapacity_cage)
		{
			this->resize_cage(fCapacity_cage * 2);
		}
		fCages[fSize_cage] = newCage;
		fSize_cage++;
	}
	else
	{
		cout << "The cage can't be developed in Jurassic park!" << endl;
	}
}

void Jurassic::add_dinosaur(const Dinosaur& newDinos)
{
	//we add the new dino to the first free posotuon after the last added element
	if (fDinos->isValid_dinos())
	{
		if (fSize_dinos >= fCapacity_dinos)
		{
			this->resize_dinos(fCapacity_dinos * 2);
		}
		fDinos[fSize_dinos] = newDinos;
		fSize_dinos++;
	}
	else
	{
		cout << "The dino is not valid and can't be added to Jurassic park!" << endl;
	}
}

void Jurassic::remove()
{
	for (int i = 0; i < fSize_dinos; i++)
	{
		for (int j = i; j < fSize_dinos - 1; j++)
		{
			fDinos[i] = fDinos[j];
		}
		--fSize_dinos;
	}
	cout << "Dinosaur is removed from the cage!" << endl;

}

void Jurassic::add_food()
{
	cout << "Food is added to the storage!" << endl;
}

//in the beginnig we have random number of cages 
//so that's why we initialize capacity_cages in the default constructor = 8
//I chose the number 8 because 8=2^3
//it's like creating a container of cages and we gotta have an initial capacity

const int EMPTY = 0;
const int START_CAPACITY = 8;

Jurassic::Jurassic()
{
	initialize(EMPTY, START_CAPACITY, EMPTY, EMPTY);
	fCages = new Cage[fCapacity_cage];
	fDinos = nullptr;
}

Jurassic::Jurassic(size_t size_cage, size_t capacity_cage, size_t size_dinos, size_t capacity_dinos)
{
	initialize(EMPTY, capacity_cage, size_dinos, capacity_dinos);
	fCages = new Cage[fCapacity_cage];
	fDinos = new Dinosaur[fCapacity_dinos];
}

void Jurassic::initialize(size_t size_cage, size_t capacity_cage, size_t size_dinos, size_t capacity_dinos)
{
	if (size_cage)
	{
		fSize_cage = size_cage;
	}
	if (capacity_cage)
	{
		fCapacity_cage = capacity_cage;
	}
	if (size_dinos)
	{
		fSize_dinos = size_dinos;
	}
	if (capacity_dinos)
	{
		fCapacity_dinos = capacity_dinos;
	}
}

Jurassic::Jurassic(const Jurassic& other)
	:Jurassic()
	//if it does not initialize the fields in the if statement, then it will use the default constructor and we will not have a problem
{
	if (this != &other)
	{
		this->copyFrom_Jurassic(other);
	}
}

Jurassic& Jurassic::operator=(const Jurassic& other)
{
	if (this != &other)
	{
		delete[]fCages;
		delete[]fDinos;
		this->copyFrom_Jurassic(other);
	}
	return *this;
}

void Jurassic::copyFrom_Jurassic(const Jurassic& other)
{
	//the cages
	fSize_cage = other.fSize_cage;
	fCapacity_cage = other.fCapacity_cage;

	fCages = new Cage[other.fCapacity_cage];

	//here we copy the cages that we have info for them, not the default cages
	//we just don't want to cpy default cages
	for (size_t i = 0; i < other.fSize_cage; i++)
	{
		fCages[i] = other.fCages[i];
	}

	//the dinos
	fSize_dinos = other.fSize_dinos;
	fCapacity_dinos = other.fCapacity_dinos;

	fDinos = new Dinosaur[other.fCapacity_dinos];

	//here applies the same thing but for the dinos
	for (size_t i = 0; i < other.fSize_dinos; i++)
	{
		fDinos[i] = other.fDinos[i];
	}
}

Jurassic::~Jurassic()
{
	delete[]fCages;
	delete[]fDinos;
	cout << "Destructor called!" << endl;
}

void Jurassic::print_Jurassic()const
{
	cout << "The number of the cages is: " << fSize_cage << endl;
	cout << "The capacity of the cages is: " << fCapacity_cage << endl;
	for (size_t i = 0; i < fSize_cage; i++)
	{
		fCages[i].print();
	}

	cout << "The number of the dinos is: " << fSize_dinos << endl;
	cout << "The capacuty of the dinos is: " << fCapacity_dinos << endl;
	for (size_t i = 0; i < fSize_dinos; i++)
	{
		fDinos[i].print_dino();
	}
}

void Jurassic::readFromConsole() {
	cout << "Enter the capacity of the cages: " << endl;
	cin >> fCapacity_cage;
	for (size_t i = 0; i < fCapacity_cage; i++)
	{
		fCages[i].read();
	}
	fSize_cage = fCapacity_cage;

	cout << "Enter the capacity of the dinos: " << endl;
	cin >> fCapacity_dinos;
	for (size_t i = 0; i < fCapacity_dinos; i++)
	{
		fDinos[i].read();
	}
	fSize_dinos = fCapacity_dinos;
}

//checks if the dinos are from the same era

bool Jurassic::valid_dino()
{
	for (size_t i = 0; i < fSize_dinos - 1; i++)
	{
		for (size_t j = 1; j < fSize_dinos; j++)
		{
			if (fDinos[i].getEra() == fDinos[j].getEra())
			{
				return true;
			}
		}
	}
	return false;
}

//checks if the dinos are from the same order
bool Jurassic::valid_dino2()
{
	for (size_t i = 0; i < fSize_dinos - 1; i++)
	{
		for (size_t j = 1; j < fSize_dinos; j++)
		{
			if (fDinos[i].getOrder() == fDinos[j].getOrder())
			{
				return true;
			}
		}
	}
	return false;
}

bool Jurassic::check_climate()
{
	if (fCages->getClimate() == "Terrestrial")
	{
		for (size_t i = 0; i < fSize_dinos; i++)
		{
			if (fDinos[i].getOrder() == "Eats grass" || fDinos[i].getOrder() == "Eats meat")
			{
				return true;
			}
		}
	}
	return false;
}

bool Jurassic::check_climate_aq()
{
	if (fCages->getClimate() == "Aqueous")
	{
		for (size_t i = 0; i < fSize_dinos; i++)
		{
			if (fDinos[i].getOrder() == "It lives in the water")
			{
				return true;
			}
		}
	}
	return false;
}

bool Jurassic::check_climate_ae()
{
	if (fCages->getClimate() == "Aerial")
	{
		for (size_t i = 0; i < fSize_dinos; i++)
		{
			if (fDinos[i].getOrder() == "It flies")
			{
				return true;
			}
		}
	}
	return false;
}
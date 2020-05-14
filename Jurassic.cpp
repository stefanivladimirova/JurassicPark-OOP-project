#include "Jurassic.h"
#include "Cage.h"
#include <iostream>
using namespace std;

void Jurassic::addFood()
{
	cout << "Food was added to the Jurassic park." << endl;
}

const int START_CAPACITY = 16;
//in the beginnig we have random number of cages 
//so that's why we initialize capacity_cages in the default constructor = 16
//I chose the number 16 because 2^4=16
//it's like creating a container of cages and we gotta have an initial capacity

Jurassic::Jurassic()
{
	init(0, START_CAPACITY);
	fCages = new Cage[fCapacity_cage];
}

Jurassic::Jurassic(size_t size_cage, size_t capacity_cage)
{
	init(0, capacity_cage);
	fCages = new Cage[fCapacity_cage];
}

Jurassic::~Jurassic()
{
	del();
	cout << "Destructor called!" << endl;
}

Jurassic::Jurassic(const Jurassic& other)
	:Jurassic()
	//if it does not initialize the fields in the if statement, 
	//then it will use the default constructor and we will not have a problem
{
	if (this != &other)
	{
		this->copyFrom(other);
	}
}

Jurassic& Jurassic::operator=(const Jurassic& other)
{
	if (this != &other)
	{
		delete[]fCages;
		this->copyFrom(other);
	}
	return *this;
}

void Jurassic::read()
{
	size_t size;
	size_t capacity;
	cout << "Enter the capacity of the cages: " << endl;
	cin >> capacity;
	for (size_t i = 0; i < capacity; i++)
	{
		fCages[i].read();
	}
	size = capacity;

	init(size, capacity);
}

void Jurassic::print() const
{
	cout << "The number of the cages is: " << fSize_cage << endl;
	cout << "The capacity of the cages is: " << fCapacity_cage << endl;
	for (size_t i = 0; i < fSize_cage; i++)
	{
		fCages[i].print();
	}
}

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

const int MAX_DINO_SMALL_CAGE = 1;
const int MAX_DINO_MEDIUM_CAGE = 3;
const int MAX_DINO_LARGE_CAGE = 10;

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

void Jurassic::add_dino_to_the_cage(const Cage& cage, Dinosaur& dino)
{
	unsigned int number_of_cage;
	cout << "Where do you want to add a new dino?" << endl;
	cin >> number_of_cage;
	if (number_of_cage > Jurassic::fCapacity_cage)
	{
		cout << "Invalid number, try again!" << endl;
	}

	if (number_of_cage > fSize_cage)
	{
		fCages->read();
		add_cage(cage);
		fCages->print();
	}

	if (fCages->getSize() == "Small")
	{
		int counter_small = 0;
		if (counter_small < 1 && counter_small >= 0)
		{
			if (fCages[number_of_cage].getClimate() == "Terestrial" && dino.getOrder() == "Eats grass")
			{
				fCages[number_of_cage].addDinosaur(dino);
			}
			else if (fCages[number_of_cage].getClimate() == "Terestrial" && dino.getOrder() == "Eats meat")
			{
				fCages[number_of_cage].addDinosaur(dino);
			}
			else if (fCages[number_of_cage].getClimate() == "Aqueous" && dino.getOrder() == "It lives in the water")
			{
				fCages[number_of_cage].addDinosaur(dino);
			}
			else if (fCages[number_of_cage].getClimate() == "Aerial" && dino.getOrder() == "It flies")
			{
				fCages[number_of_cage].addDinosaur(dino);
			}
			else
			{
				add_cage(cage);
			}
		}
		else
		{
			cout << "There is no place for new dinos in the cage because it is full!" << endl;
		}
	}
	else if (fCages->getSize() == "Medium")
	{
		int counter_medium = 0;
		for (size_t i = 0; i < MAX_DINO_MEDIUM_CAGE; i++)
		{
			if (counter_medium < MAX_DINO_MEDIUM_CAGE && counter_medium >= 0)
			{
				for (size_t i = 0; i < MAX_DINO_MEDIUM_CAGE; i++)
				{
					if (fCages[number_of_cage].fDinos[i].getEra() == dino.getEra() &&
						fCages[number_of_cage].fDinos[i].getOrder() == dino.getOrder())
					{
						if (fCages[number_of_cage].getClimate() == "Terestrial" && dino.getOrder() == "Eats grass")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else if (fCages[number_of_cage].getClimate() == "Terestrial" && dino.getOrder() == "Eats meat")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else if (fCages[number_of_cage].getClimate() == "Aqueous" && dino.getOrder() == "It lives in the water")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else if (fCages[number_of_cage].getClimate() == "Aerial" && dino.getOrder() == "It flies")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else
						{
							add_cage(cage);
						}
					}
					else
					{
						cout << "The dinos are not from the same era. The new dino can not be added to the cage." << endl;
					}
				}

			}
			else
			{
				cout << "There is no place for new dinos it the cage because it is full!" << endl;
			}
		}
	}

	else if (fCages->getSize() == "Large")
	{
		int counter_large = 0;
		for (size_t i = 0; i < MAX_DINO_LARGE_CAGE; i++)
		{
			if (counter_large < MAX_DINO_LARGE_CAGE && counter_large >= 0)
			{
				for (size_t i = 0; i < MAX_DINO_LARGE_CAGE; i++)
				{
					if (fCages[number_of_cage].fDinos[i].getEra() == dino.getEra() &&
						fCages[number_of_cage].fDinos[i].getOrder() == dino.getOrder())
					{
						if (fCages[number_of_cage].getClimate() == "Terestrial" && dino.getOrder() == "Eats grass")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else if (fCages[number_of_cage].getClimate() == "Terestrial" && dino.getOrder() == "Eats meat")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else if (fCages[number_of_cage].getClimate() == "Aqueous" && dino.getOrder() == "It lives in the water")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else if (fCages[number_of_cage].getClimate() == "Aerial" && dino.getOrder() == "It flies")
						{
							fCages[number_of_cage].addDinosaur(dino);
						}
						else
						{
							add_cage(cage);
						}
					}
				}
			}
			else
			{
				cout << "There is no place for new dinos it the cage because it is full!" << endl;
			}
		}
	}
	else
	{
		cout << "The size of the cage is invalid!" << endl;
	}
}

void Jurassic::serialize(ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		cout << "The file was not opened!" << endl;
		return;
	}

	//that is for the array of cages
	ofs.write((const char*)&fSize_cage, sizeof(size_t));
	ofs.write((const char*)&fCapacity_cage, sizeof(size_t));

	for (size_t i = 0; i < fSize_cage; i++)
	{
		fCages[i].serialize(ofs);
	}

	if (ofs.good())
	{
		cout << "Successful!" << endl;
	}
	else
	{
		cout << "Not successful!" << endl;
	}
}

void Jurassic::deserialize(ifstream& ifs)
{
	if (!ifs.is_open())
	{
		cout << "the file was not opened!" << endl;
		return;
	}

	//that is for the cages
	ifs.read((char*)&fSize_cage, sizeof(size_t));
	ifs.read((char*)&fCapacity_cage, sizeof(size_t));

	//if we have cages already
	delete[]fCages;
	fCages = new Cage[fCapacity_cage];
	for (size_t i = 0; i < fSize_cage; i++)
	{
		fCages[i].deserialize(ifs);
	}

	if (ifs.good())
	{
		cout << "Successful!" << endl;
	}
	else
	{
		cout << "Not successful!" << endl;
	}
}

void Jurassic::del()
{
	delete[]fCages;
}

void Jurassic::init(size_t size_cage, size_t capacity_cage)
{
	if (size_cage)
	{
		fSize_cage = size_cage;
	}
	else
	{
		fSize_cage = 0;
		cout << "Invalid!" << endl;
	}

	if (capacity_cage)
	{
		fCapacity_cage = capacity_cage;
	}
	else
	{
		fCapacity_cage = 0;
		cout << "Invalid!" << endl;
	}
}

void Jurassic::copyFrom(const Jurassic& other)
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
}

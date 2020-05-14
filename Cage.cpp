#include "Cage.h"
#include <iostream>
using namespace std;

Cage::Cage()
{
	init("", "", 0, 0);
	fDinos = nullptr;
}

Cage::Cage(const char* size_cage, const char* climate, size_t size_dino, size_t capacity_dino)
{
	init(size_cage, climate, size_dino, capacity_dino);
	fDinos = new Dinosaur[fCapacity_dino];
}

Cage::~Cage()
{
	del();
	cout << "Destructor called!" << endl;
}

Cage::Cage(const Cage& other) : Cage()
//if it does not initialize the fields in the if statement, 
//then it will use the default constructor and we will not have a problem
{
	if (this != &other)
	{
		this->copyFrom(other);
	}
}

Cage& Cage::operator=(const Cage& other)
{
	if (this != &other)
	{
		del();
		this->copyFrom(other);
	}
	return *this;
}

const int MAX = 50;
const int MAX_SIZE = 15;

void Cage::read()
{
	char size_cage[MAX_SIZE];
	char climate[MAX];

	cout << "Enter the size of the cage (Small, Medium, Large): " << endl;
	cin.getline(size_cage, MAX_SIZE);
	if (strcmp(size_cage, "Small") == 0 || strcmp(size_cage, "Medium") == 0 || strcmp(size_cage, "Large") == 0)
	{
		cout << "The cages is: " << size_cage << endl;
	}
	else
	{
		cout << "Invalid!" << endl;
	}

	cout << "Enter the climate of the cage(Terrestrial, Aerial, Aqueous): " << endl;
	cin.getline(climate, MAX);
	if (strcmp(climate, "Terrestrial") == 0 || strcmp(climate, "Aerial") == 0 || strcmp(climate, "Aqueous") == 0)
	{
		cout << "The climate is: " << climate << endl;
	}
	else
	{
		cout << "Invalid!" << endl;
	}

	size_t capacity;
	size_t size;
	cout << "Enter the capacity of the dinos: " << endl;
	cin >> capacity;
	for (size_t i = 0; i < capacity; i++)
	{
		fDinos[i].read();
	}
	size = capacity;

	init(size_cage, climate, size, capacity);
}

void Cage::print() const
{
	cout << "The size of the cage is: " << fSize_cage << endl;
	cout << "The climate of the cage is: " << fClimate << endl;
	cout << "The capacity is: " << fCapacity_dino << endl;
	cout << "The size is: " << fSize_dino << endl;

	for (size_t i = 0; i < fSize_dino; i++)
	{
		fDinos[i].print_dino();
	}
}

bool Cage::isValid_cage()
{
	if (strcmp(fSize_cage, "") == 0 || strcmp(fClimate, "") == 0)
	{
		return false;
	}
	return true;
}

const char* Cage::getClimate() const
{
	return fClimate;
}

bool Cage::valid_dino()
{
	for (size_t i = 0; i < fSize_dino - 1; i++)
	{
		for (size_t j = 1; j < fSize_dino; j++)
		{
			if (fDinos[i].getEra() == fDinos[j].getEra())
			{
				return true;
			}
		}
	}
	return false;
}

bool Cage::valid_dino2()
{
	for (size_t i = 0; i < fSize_dino - 1; i++)
	{
		for (size_t j = 1; j < fSize_dino; j++)
		{
			if (fDinos[i].getOrder() == fDinos[j].getOrder())
			{
				return true;
			}
		}
	}
	return false;
}

void Cage::resizeDinos(size_t newCapacity_dinos)
{
	Dinosaur* buff_dinos = new(nothrow)Dinosaur[newCapacity_dinos];
	//the same applies here

	if (buff_dinos) {
		for (size_t i = 0; i < fSize_dino; i++)
		{
			buff_dinos[i] = fDinos[i];
		}
		delete[]fDinos;
		fCapacity_dino = newCapacity_dinos;
		//fDinos will point at buff_dinos
		fDinos = buff_dinos;
		cout << "Resized!" << endl;
	}
	else
	{
		cout << "Not enough memory, can't do the task that you wanted!" << endl;
	}
}

void Cage::addDinosaur(const Dinosaur& newDinos)
{
	//we add the new dino to the first free position after the last added element
	if (fDinos->isValid_dinos())
	{
		if (fSize_dino >= fCapacity_dino)
		{
			this->resizeDinos(fCapacity_dino * 2);
		}

		fDinos[fSize_dino] = newDinos;
		fSize_dino++;
	}
	else
	{
		cout << "The dino is not valid and can't be added to Jurassic park!" << endl;
	}
}

void Cage::remove()
{
	for (int i = 0; i < fSize_dino; i++)
	{
		for (int j = i; j < fSize_dino - 1; j++)
		{
			fDinos[i] = fDinos[j];
		}
		--fSize_dino;
	}
	cout << "Dinosaur is removed from the cage!" << endl;
}

void Cage::serialize(ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		cout << "File was not opened" << endl;
		return;
	}

	//fsize_cage
	size_t lenSize = strlen(fSize_cage);
	ofs.write((const char*)&lenSize, sizeof(size_t));
	ofs.write(fSize_cage, lenSize);

	//fclimate
	size_t lenclimate = strlen(fClimate);
	ofs.write((const char*)&lenclimate, sizeof(size_t));
	ofs.write(fClimate, lenclimate);

	//that is for the array of dinos
	ofs.write((const char*)&fSize_dino, sizeof(size_t));
	ofs.write((const char*)&fCapacity_dino, sizeof(size_t));

	for (size_t i = 0; i < fSize_dino; i++)
	{
		fDinos[i].serialize(ofs);
	}

	if (ofs.good())
	{
		cout << "Successful!" << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void Cage::deserialize(ifstream& ifs)
{
	if (!ifs.is_open())
	{
		cout << "File was not opened" << endl;
		return;
	}

	//fsize_cage
	size_t lensize = 0;
	ifs.read((char*)&lensize, sizeof(size_t));
	fSize_cage = new char[lensize + 1];
	if (fSize_cage)
	{
		ifs.read(fSize_cage, lensize);
		fSize_cage[lensize] = '\0';
	}

	//fclimate
	size_t lenclimate = 0;
	ifs.read((char*)&lenclimate, sizeof(size_t));
	fClimate = new char[lenclimate + 1];
	if (fClimate)
	{
		ifs.read(fClimate, lenclimate);
		fClimate[lenclimate] = '\0';
	}

	//that is for the dinos
	ifs.read((char*)&fSize_dino, sizeof(size_t));
	ifs.read((char*)&fCapacity_dino, sizeof(size_t));

	//if we have dinos already
	delete[]fDinos;
	fDinos = new Dinosaur[fCapacity_dino];
	for (size_t i = 0; i < fSize_dino; i++)
	{
		fDinos[i].deserialize(ifs);
	}

	if (ifs.good())
	{
		cout << "Successful!" << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}
}

void Cage::del()
{
	delete[]fSize_cage;
	delete[]fClimate;
	delete[]fDinos;
}

void Cage::init(const char* size_cage, const char* climate, size_t size_dino, size_t capacity_dino)
{
	if (size_cage)
	{
		fSize_cage = new char[strlen(size_cage) + 1];
		strcpy(fSize_cage, size_cage);
	}
	else
	{
		strcpy(fSize_cage, "");
	}
	if (climate)
	{
		fClimate = new char[strlen(climate) + 1];
		strcpy(fClimate, climate);
	}
	else
	{
		strcpy(fClimate, "");
	}
	if (size_dino)
	{
		fSize_dino = size_dino;
	}
	else
	{
		fSize_cage = 0;
		cout << "Invalid!" << endl;
	}
	if (capacity_dino)
	{
		fCapacity_dino = capacity_dino;
	}
	else
	{
		fCapacity_dino = 0;
		cout << "Invalid!" << endl;
	}
}

void Cage::copyFrom(const Cage& other)
{
	fSize_cage = new char[strlen(other.fSize_cage) + 1];
	strcpy(fSize_cage, other.fSize_cage);

	fClimate = new char[strlen(other.fClimate) + 1];
	strcpy(fClimate, other.fClimate);

	fSize_dino = other.fSize_dino;
	fCapacity_dino = other.fCapacity_dino;

	fDinos = new Dinosaur[other.fCapacity_dino];

	//we want to copy the dinos that we have infor for, 
	//we do not want to copy the default dinos
	for (size_t i = 0; i < fSize_dino; i++)
	{
		fDinos[i] = other.fDinos[i];
	}
}

const char* Cage::getSize() const
{
	return fSize_cage;
}

void Cage::setClimate(char climate[MAX_CLIMATE])
{
	strcpy(fClimate, climate);
}

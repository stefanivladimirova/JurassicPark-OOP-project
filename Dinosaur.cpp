#include "Dinosaur.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 50;
const int MAX_SEX = 7;

void Dinosaur::read()
{
	char name[MAX];
	char sex[MAX_SEX];
	char era[MAX];
	char order[MAX];
	char typeName[MAX];
	char food[MAX];

	cout << "Enter the name of the dinosaur: " << endl;
	cin.getline(name, MAX);

	cout << "Enter the sex of the dinosaur(male or female): " << endl;
	cin.getline(sex, MAX_SEX);
	if (strcmp(sex, "female") == 0 || strcmp(sex, "male") == 0)
	{
		cout << "The gender is: " << sex;
	}
	else
	{
		cout << "Invalid!";
		strcpy(sex, "");
	}

	cout << "Enter the type of the dinosaur(Pleziozavur, Brontozavur, Tiranozavur, etc): " << endl;
	cin.getline(typeName, MAX);

	cout << "Enter the era(Trias, Creda, Yura): " << endl;
	cin.getline(era, MAX);
	if (strcmp(era, "Trias") == 0 || strcmp(era, "Creda") == 0 || strcmp(era, "Yura") == 0)
	{
		cout << "The era is: " << era;
	}
	else
	{
		cout << "Invalid!" << endl;
		strcpy(era, "");
	}


	cout << "Enter the food that the dinosaur eats (grass, meat or fish): " << endl;
	cin.getline(food, MAX);
	if (strcmp(food, "Grass") == 0 || strcmp(food, "Meat") == 0 || strcmp(food, "Fish") == 0)
	{
		cout << "The food that the dinosaur eats is: " << food << endl;
	}
	else
	{
		cout << "Invalid!" << endl;
		strcpy(food, "");
	}

	cout << "Enter the order(Eats grass, eats meat, it flies ot it lives in the water): " << endl;
	cin.getline(order, MAX);
	if (strcmp(order, "Eats grass") == 0 || strcmp(order, "Eats meat") == 0 || strcmp(order, "It flies") == 0 ||
		strcmp(order, "It lives in the water") == 0)
	{
		cout << "The order is: " << order << endl;
	}
	else
	{
		cout << "Invalid!" << endl;
		strcpy(order, "");
	}

	init(name, sex, typeName, era, food, order);

}

void Dinosaur::print_dino()const
{
	cout << "The name of the dinosaur is: " << fName << endl;
	cout << "The sex of the dinosaur is: " << fSex << endl;
	cout << "The name of the type is: " << fTypename << endl;
	cout << "The name of the food that the dinosaur eats is: " << fFood << endl;
	cout << "The order is: " << fOrder << endl;
}

bool Dinosaur::isValid_dinos()
{
	if (strcmp(fName, "") == 0 || strcmp(fSex, "") == 0 || strcmp(fTypename, "") == 0 || strcmp(fEra, "") == 0 || strcmp(fFood, "") == 0 ||
		strcmp(fOrder, "") == 0)
	{
		return false;
	}
	return true;
}

const char* Dinosaur::getEra() const
{
	return fEra;
}

const char* Dinosaur::getOrder() const
{
	return fOrder;
}

void Dinosaur::serialize(ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		cout << "The file was not opened!" << endl;
	}

	//fName
	size_t lenName = strlen(fName);
	ofs.write((const char*)&lenName, sizeof(size_t));
	ofs.write(fName, lenName);

	//fSex
	size_t lenSex = strlen(fSex);
	ofs.write((const char*)&lenSex, sizeof(size_t));
	ofs.write(fSex, lenSex);

	//fTypename
	size_t lenTypeName = strlen(fTypename);
	ofs.write((const char*)&lenTypeName, sizeof(size_t));
	ofs.write(fTypename, lenTypeName);

	//fEra
	size_t lenEra = strlen(fEra);
	ofs.write((const char*)&lenEra, sizeof(size_t));
	ofs.write(fEra, lenEra);

	//fFood
	size_t lenFood = strlen(fFood);
	ofs.write((const char*)&lenFood, sizeof(size_t));
	ofs.write(fFood, lenFood);

	//fOrder
	size_t lenOrder = strlen(fOrder);
	ofs.write((const char*)&lenOrder, sizeof(size_t));
	ofs.write(fOrder, lenOrder);

	if (ofs.good())
	{
		cout << "Successful!" << endl;
	}
	else
	{
		cout << "Not successful!" << endl;
	}
}

void Dinosaur::deserialize(ifstream& ifs)
{
	if (!ifs.is_open())
	{
		cout << "The file was not opened!" << endl;
		return;
	}

	//fName
	size_t lenName = 0;
	ifs.read((char*)&lenName, sizeof(size_t));
	fName = new char[lenName + 1];
	if (fName)
	{
		ifs.read(fName, lenName);
		fName[lenName] = '\0';
	}

	//fSex
	size_t lenSex = 0;
	ifs.read((char*)&lenSex, sizeof(size_t));
	fSex = new char[lenSex + 1];
	if (fSex)
	{
		ifs.read(fSex, lenSex);
		fSex[lenSex] = '\0';
	}

	//fTypename
	size_t lenTypen_name = 0;
	ifs.read((char*)&lenTypen_name, sizeof(size_t));
	fTypename = new char[lenTypen_name + 1];
	if (fTypename)
	{
		ifs.read(fTypename, lenTypen_name);
		fTypename[lenTypen_name] = '\0';
	}

	//fEra
	size_t lenEra = 0;
	ifs.read((char*)&lenEra, sizeof(size_t));
	fEra = new char[lenEra + 1];
	if (fEra)
	{
		ifs.read(fEra, lenEra);
		fEra[lenEra] = '\0';
	}

	//fFood
	size_t lenFood = 0;
	ifs.read((char*)&lenFood, sizeof(size_t));
	fFood = new char[lenFood + 1];
	if (fFood)
	{
		ifs.read(fFood, lenFood);
		fFood[lenFood] = '\0';
	}

	//fOrder
	size_t lenOrder = 0;
	ifs.read((char*)&lenOrder, sizeof(size_t));
	fOrder = new char[lenOrder + 1];
	if (fOrder)
	{
		ifs.read(fOrder, lenOrder);
		fOrder[lenOrder] = '\0';
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

Dinosaur::Dinosaur()
{
	init("", "", "", "", "", "");
}

Dinosaur::Dinosaur(const char* name, const char* sex, const char* typeName, const char* era, const char* food, const char* order)
{
	init(name, sex, typeName, era, food, order);
}

void Dinosaur::init(const char* name, const char* sex, const char* typeName, const char* era, const char* food, const char* order)
{
	if (name)
	{
		fName = new char[strlen(name) + 1];
		strcpy(fName, name);
	}
	else
	{
		strcpy(fName, "");
	}


	if (sex)
	{
		fSex = new char[strlen(sex) + 1];
		strcpy(fSex, sex);
	}
	else
	{
		strcpy(fSex, "");
	}


	if (typeName)
	{
		fTypename = new char[strlen(typeName) + 1];
		strcpy(fTypename, typeName);
	}
	else
	{
		strcpy(fTypename, "");
	}


	if (era)
	{
		fEra = new char[strlen(era) + 1];
		strcpy(fEra, era);
	}
	else
	{
		strcpy(fEra, "");
	}


	if (food)
	{
		fFood = new char[strlen(food) + 1];
		strcpy(fFood, food);
	}
	else
	{
		strcpy(fFood, "");
	}


	if (order)
	{
		fOrder = new char[strlen(order) + 1];
		strcpy(fOrder, order);
	}
	else
	{
		strcpy(fOrder, "");
	}
}

void Dinosaur::del()
{
	delete[]fName;
	delete[]fSex;
	delete[]fTypename;
	delete[]fEra;
	delete[]fFood;
	delete[]fOrder;
}

Dinosaur::~Dinosaur()
{
	cout << "Destructor called!" << endl;
	del();
}

Dinosaur& Dinosaur::operator=(const Dinosaur& other)
{
	if (this != &other)
	{
		delete[]fName;
		delete[]fSex;
		delete[]fTypename;
		delete[]fEra;
		delete[]fFood;
		delete[]fOrder;

		this->copyFrom(other);
	}
	return *this;
}

void Dinosaur::copyFrom(const Dinosaur& other)
{
	fName = new char[strlen(other.fName) + 1];
	strcpy(fName, other.fName);

	fSex = new char[strlen(other.fSex) + 1];
	strcpy(fSex, other.fSex);

	fTypename = new char[strlen(other.fTypename) + 1];
	strcpy(fTypename, other.fTypename);

	fEra = new char[strlen(other.fEra) + 1];
	strcpy(fEra, other.fEra);

	fFood = new char[strlen(other.fFood) + 1];
	strcpy(fFood, other.fFood);

	fOrder = new char[strlen(other.fOrder) + 1];
	strcpy(fOrder, other.fOrder);
}

Dinosaur::Dinosaur(const Dinosaur& other)
	:Dinosaur()
	//if it does not initialize the fields in the if statement, then it will use the default constructor and we will not have a problem
{
	if (this != &other)
	{
		copyFrom(other);
	}
}

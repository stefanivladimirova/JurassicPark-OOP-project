#pragma once
#include "Cage.h"
#include "Dinosaur.h"
#include <fstream>
using namespace std;

class Jurassic
{
public:
	Cage* fCages;
	void addFood();
	Jurassic();
	Jurassic(size_t, size_t);
	~Jurassic();
	Jurassic(const Jurassic& other);
	Jurassic& operator=(const Jurassic& other);

	void read();
	void print()const;

	void resize_cage(size_t newCapacity_cage);
	void add_cage(const Cage& newCage);
	void add_dino_to_the_cage(const Cage& cage, Dinosaur& dino);

	//check if the dino/dinos can live in a particular climate cage
	//dedided to make them in different methods cause it is easier for me
	//the first one checks when the climate is "Terrestrial"

public:
	//bool check_climate();
	//the next one checks if the climate is "Aqueous"
	//bool check_climate_aq();
	//the last one checks if the climate is "Aerial"
	//bool check_climate_ae();

	void serialize(ofstream& ofs) const;
	void deserialize(ifstream& ifs);

private:
	void del();
	void init(size_t size_cage, size_t capacity_cage);
	void copyFrom(const Jurassic& other);

private:
	size_t fSize_cage;
	size_t fCapacity_cage;
};


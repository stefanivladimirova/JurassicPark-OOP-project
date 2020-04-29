#pragma once
#include "CageDinosaur.h"
class Jurassic
{
	size_t fSize_cage;
	size_t fCapacity_cage;

	size_t fSize_dinos;
	size_t fCapacity_dinos;

	Cage* fCages;
	Dinosaur* fDinos;

	void resize_cage(size_t newCapacity_cage);
	void resize_dinos(size_t newCapacity_dinos);

public:
	void add_cage(const Cage& newCage);
	void add_dinosaur(const Dinosaur& newDinos);

	void remove();

	void add_food();

	Jurassic();
	Jurassic(size_t, size_t, size_t, size_t);
	void initialize(size_t, size_t, size_t, size_t);

	Jurassic(const Jurassic& other);
	Jurassic& operator=(const Jurassic& other);

	void copyFrom_Jurassic(const Jurassic& other);
	~Jurassic();

	void print_Jurassic()const;
	void readFromConsole();

	//validates if the dinos are from the same era
	bool valid_dino();

	//validates if the dinos are from the same order
	bool valid_dino2();

	//check if the dino/dinos can live in a particular climate cage
	//dedided to make them in different methods cause it is easier for me
	//the first one checks when the climate is "Terrestrial"
	bool check_climate();

	//the next one checks if the climate is "Aqueous"
	bool check_climate_aq();

	//the last one checks if the climate is "Aerial"
	bool check_climate_ae();

	void serialize(ofstream& ofs) const;
	void deserialize(ifstream& ifs);
};
#pragma once
#include "Dinosaur.h"
#include <fstream>
using namespace std;

const int MAX_CLIMATE = 20;

class Cage
{
public:
	Dinosaur* fDinos;

	Cage();
	Cage(const char* size_cage, const char* climate, size_t size_dino, size_t capacity_dino);
	~Cage();
	Cage(const Cage& other);
	Cage& operator=(const Cage& other);

	void read();
	void print()const;

	bool isValid_cage();

	//I need that to check if the dino can live in a particular cage
	const char* getClimate()const;
	const char* getSize()const;
	void setClimate(char climate[MAX_CLIMATE]);

	//validates if the dinos are from the same era
	bool valid_dino();
	//validates if the dinos are from the same order
	bool valid_dino2();

	void resizeDinos(size_t newCapacity_dinos);
	void addDinosaur(const Dinosaur& newDinos);
	void remove();

	void serialize(ofstream& ofs) const;
	void deserialize(ifstream& ifs);
private:
	void del();
	void init(const char* size_cage, const char* climate, size_t size_dino, size_t capacity_dino);
	void copyFrom(const Cage& other);
private:
	char* fSize_cage;
	char* fClimate;
public:
	size_t fSize_dino;
	size_t fCapacity_dino;
};


#pragma once

class Cage
{
	char* fsize_cage;
	char* fclimate;

public:
	Cage();
	Cage(const char*, const char*);
	void init_cage(const char*, const char*);

	Cage& operator=(const Cage& other);

	void copyFrom_cage(const Cage& other);
	Cage(const Cage& other);

	~Cage();
	void del_cage();

	void read();
	void print();

	bool isValid_cage();

	//I need that to check if the dino can live in a particular cage
	const char* getClimate()const;

	void serialize(ofstream& ofs) const;
	void deserialize(ifstream& ifs);
};

class Dinosaur {
private:
	char* fName;
	char* fSex;
	char* fTypename;
	char* fEra;
	char* fFood;
	char* fOrder;

public:
	Dinosaur();
	Dinosaur(const char*, const char*, const char*, const char*, const char*, const char*);
	void init(const char*, const char*, const char*, const char*, const char*, const char*);

	void del();
	~Dinosaur();

	Dinosaur& operator=(const Dinosaur& other);

	void copyFrom(const Dinosaur& other);
	Dinosaur(const Dinosaur& other);

	void read();
	void print_dino();

	bool isValid_dinos();

	//I need those for the validations from the dinos if they are from the same era and the same order
	const char* getEra()const;
	const char* getOrder()const;

	void serialize(ofstream& ofs) const;
	void deserialize(ifstream& ifs);
};
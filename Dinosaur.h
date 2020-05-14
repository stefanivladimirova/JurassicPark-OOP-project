#pragma once
#include <fstream>
using namespace std;
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
	~Dinosaur();
	Dinosaur& operator=(const Dinosaur& other);
	Dinosaur(const Dinosaur& other);
	void read();
	void print_dino()const;
	bool isValid_dinos();
	//I need those for the validations from the dinos if they are from the same era and the same order
	const char* getEra()const;
	const char* getOrder()const;

	void serialize(ofstream& ofs) const;
	void deserialize(ifstream& ifs);

private:
	void init(const char*, const char*, const char*, const char*, const char*, const char*);
	void del();
	void copyFrom(const Dinosaur& other);
};
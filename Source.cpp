#include <iostream>
#include "Cage.h"
#include "Dinosaur.h"
#include "Jurassic.h"

using namespace std;

int main() {
	//NOTES

	//counts how many dinos I have i particular cage
			//TO DO getnumber na f_dino = 1
			//za da go polzvam za counter
			//za da proveryavam kolko dinos ima v a particular cage
			//if we have space we can add a new dino
			//BUT do the checks for the era climate and order

			//fCages[number_of_cage].fDinos[i];//.getNumber koeto e ravno na 1

			//counter+=fCages[number_of_cage].fDinos[i].getNumber();


			//if count<MAX_DINO_SMALL_CAGE add dino
			//but have to check for the climate, the era and the order




	int num = 0;
	int num1 = 0;
	do
	{
		cout << "If you want to stop the program enter 1, if you want to keep going enter 0!" << endl;
		cin >> num;
		if (num == 1) {
			break;
		}

		//here i am gonna call the funcs, here I am gonna add new dinos, remove dinos, add new cages or food

		//check if the dinos can live together in a particular cage

		//add new cages
		cout << "Do you want to add new cages to the Jurassic park? Enter 0 for yes and 1 for no!" << endl;
		cin >> num1;
		if (num1 == 0) {
			cout << "A new cage is gonna be added to Jurassic park!" << endl;
		}
		else {
			cout << "A new cage is not added to Jurassic park!" << endl;
		}


		//how many cages to add
		cout << "How many cages do you want to add to Jurassic park?" << endl;
		cin >> num1;



		//add new dinos
		cout << "Do you want to add new dinosaurs to the cages? Enter 0 for yes and 1 for no!" << endl;
		cin >> num1;
		if (num1 == 0) {
			cout << "A new dino is added to the cage!" << endl;
		}
		else {
			cout << "A new dino is not added to the cage!" << endl;
		}


		//how many new dinos
		cout << "How many dinos do you want to the cages?" << endl;
		cin >> num1;


		//remove dinos
		cout << "Do you want to remove a dinosaur from the cage? Enter 0 for yes and 1 for no!" << endl;
		cin >> num1;

		//add food to the storage
		cout << "Do you want to add food to the storage of Jurassic park? Enter 0 for yes and 1 for no!" << endl;
		cin >> num1;
		if (num1 == 1) {
			cout << "The food is not added to the storage of Jurassic park." << endl;
		}
		else {

		}
	} while (num == 0);

	return 0;
}
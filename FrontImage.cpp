#include"Interface.h"
#include<conio.h>

void FrontImage::printImage(){

	int garbageValue;
	string line;
	ifstream inFile("frontimage.txt", ios::in);

	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			system("Color 78");
			cout << line << "\n";
		}
		
		_getche();
		inFile.close();
		system("cls");
	}
}
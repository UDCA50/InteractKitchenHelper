#include"Interface.h"

using std::ofstream;

void FrontImage::printImage(){

	return;
	string line;
	ifstream inFile("frontimage.txt", ios::in);

	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			system("Color 78");
			cout << line << "\n";
		}
		_getche();		//하나의 단어를 받는 함수
		inFile.close();
		system("cls");
	}
}
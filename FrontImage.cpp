#include"Interface.h"

using std::ofstream;

void FrontImage::printImage(){

	int garbageValue;
	string line;
	ifstream inFile("frontimage.txt", ios::in);

	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			system("Color 78");
			cout << line << "\n";
		}
		_getche();		//�ϳ��� �ܾ �޴� �Լ�
		inFile.close();
		system("cls");
	}
}
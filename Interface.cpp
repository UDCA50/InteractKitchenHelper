#pragma once
#include"Interface.h"
#include<iostream>
#include<ctime>
using namespace std;
// �ݺ��� iterator ���� �׷����� �̸����� �ٲپ����


Interface::Interface() {
		//printTitleMenu();
		frontImage.printImage();		// �ʱ�ȭ�� ���
		showTodayInformation();
}

void Interface::printTitleMenu(){

	string line;
	ifstream inFile("Titlemenu.txt", ios::in);

	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			system("Color 78");
			std::cout << line;
		}
		inFile.close();
	}
}

void Interface::showFrontMenu(){

	int userInput = 0; 

	std::cout << "=================IIKH System Menu =============" << std::endl;
	std::cout << "1.������ �˻� 2.������ �߰� 3. ������ ���� " << std::endl;
	std::cout << " 4.������ ���� 5. ��� ������ ���� ����" << std::endl;
	std::cout << "6. ����/�Ĵ� ���� 7. ����/�Ĵ� ���� 8. ��������" << std::endl;
	std::cout << "9. ���α׷� ����" << std::endl;
	std::cout << "=================IIKH System Menu =============" << std::endl;
	std::cout << "��ȣ�� �Է��ϼ��� : ";

	std::cin >> userInput;
	cin.clear();
	cin.ignore(10000, '\n');
	std::cout << "your Input is " << userInput << std::endl;


	switch (userInput)
	{
	case 1:
		dataBase.search();
		break;
	case 2:
		dataBase.addRecipe();
		break;
	case 3:
		dataBase.modifyRecipe();
		break;
	case 4:
		dataBase.deleteRecipe();
		break;
	case 5:
		dataBase.showAllRecipesList();
		break;
	case 6:
		// ����/�Ĵ� ����
		showDayPlan();
		break;
	case 7:
		// ����/�Ĵ� ����
		editDayPlan();
		break;
	case 8:
		// ���� ���� ���� 
		saveFileData(this->dataBase,this->planmanager);
		break;
	case 9:
		exit(1);
		break;
	default:
		break;
	}


}


void Interface::showDayPlan(){

	int date;
	int menunum = 0;
	time_t timer;
	struct tm *t;

	timer = time(NULL); // ���� �ð��� �� ������ ���
	t = localtime(&timer); // �� ������ �ð��� �и��Ͽ� ����ü�� �ֱ�

	cout << "Ȯ���� ��¥�� �Է��ϼ���(" << t->tm_mon + 1 << "��/��) :";
	cin >> date;

	while ((date<1 || date>30)) {
		cout << "��ȿ�� ���� �Է��ϼ���(1��~31��) : ";
		cin >> date;
	}

	planmanager.showDailyPlan(date);
	std::cout << "1.��ħ�޴� �󼼺���  2.���ɸ޴� �󼼺���  3.����޴� �󼼺��� " << std::endl << "Ȯ���� �޴��� �ش��ϴ� ���ڸ� �Է��ϼ��� : ";

	std::cin >> menunum;
	while (menunum <1 || menunum > 3) {
		std::cout << "���ڸ� �߸��Է��ϼ̽��ϴ�." << std::endl;
		std::cout << "1.��ħ�޴� �󼼺���  2.���ɸ޴� �󼼺���  3.����޴� �󼼺��� " << std::endl << "Ȯ���� �޴��� �ش��ϴ� ���ڸ� �Է��ϼ��� : ";
		std::cin >> menunum;
	}

	switch (menunum) {
	case 1:
		//showRecipeofdish(planmanager.getDailyPlan(date).getMenu);
		break;

	case 2:
		break;

	case 3:
		break;

	default:
		break;
	}

}


void Interface::editDayPlan()
{
	int day;
	int menu;	// �ָܼ޴�
	Day myDay;
	char *newMenu;	// ������ �޴���
	int newNumber;	// ������ �ο���
	string newPlan;	// ������ �÷�

	/* 1. ��¥ �Է� */
	while (1)
	{
		cout << "<< ����/�Ĵ� ���� >>" << endl << "��¥�� �Է��ϼ���(1 ~ 31) : ";
		cin >> day;

		if (1 <= day && day <= 31)
			break;
		else
			cout << "1���� 31 ������ ���� �Է��ϼ���" << endl;
	}
	myDay = planmanager.getDailyPlan(day);
	myDay.showTodayData();


	/* 2. �޴� */
	while (1)
	{
		cout << endl << "1. ��ħ�޴� �����ϱ�" << endl 
			<< "2. ���ɸ޴� �����ϱ�" << endl 
			<< "3. ����޴� �����ϱ�" << endl
			<< "4. �����߰��ϱ�" << endl 
			<< "5. ���������ϱ�" << endl 
			<< "6. �����޴���" << endl;
		fflush(stdin);

		cin >> menu;

		/* �޴�������Ʈ */
		if (menu == 1 || menu == 2 || menu == 3)
		{
			cout << " 1 > �޴��� ����" << endl;
			dataBase.search();
			myDay.editName(menu, newMenu);

			cout << " 2 > �Ļ��ο� ���� : ";
			cin >> newNumber;
			myDay.editNumber(menu, newNumber);
		}

		/* ����������Ʈ */
		else if (menu == 4)
		{
			cout << " > �����߰�" << endl;
			fflush(stdin);
			cin >> newPlan;
			myDay.editPlan(newPlan);
		}
		else if (menu == 5)
		{
			myDay.editPlan("");
		}

		/* ��Ÿ */
		else if (menu == 6)
		{
			showFrontMenu();
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
	}


	//planmanager.changeDate(myDay, day);
}

void Interface::editDayPlan(const char* dishName){


}

void Interface::showTodayInformation(){


}

void Interface::loadFileData(DataBase &dataBase, PlanManager &planmanager){


}

void Interface::saveFileData(DataBase &dataBase, PlanManager &planmanager){

	//�Ѵ� Day ������ ���Ͽ� ������
	FILE* datefptr;
	datefptr = fopen("saveDayData.txt", "w");

	int date = 1;
	while (date < 32) {
		Day saveDay;
		saveDay = planmanager.getDailyPlan(date);		//���� Day �ν��Ͻ� �޾ƿͼ�
		char** savePlanData = saveDay.getTodayPlan();	// ���� Plan ���� �޾ƿ���
		
		fprintf(datefptr, "%d,%s,%s,%s,%d,%d,%d", date, saveDay.getbreakFastName(),
					saveDay.getLunchName(),saveDay.getdinnerName(),
					saveDay.getbreakFastNumber(),saveDay.getLunchNumber(),saveDay.getDinnerNumber());

		for (int i = 0; i < saveDay.getPlanCount(); i++) {
			fprintf(datefptr, ",%s", savePlanData[i]);
		}
		fprintf(datefptr, "\n");
		delete[] savePlanData;
		date++;
	}
	fclose(datefptr);
// ���� ������ ������ ���Ͽ� ������ 

	FILE* recipefptr;
	recipefptr = fopen("saveRecipeData.txt", "w");
	for (int i = 0; i < dataBase.getRecipeCount(); i++) {
		Recipe myRecipe = dataBase.getRecipebyIndex(i);
		fprintf(recipefptr, "%s\n", myRecipe.getDishName().c_str());
	}
	fclose(recipefptr);
}

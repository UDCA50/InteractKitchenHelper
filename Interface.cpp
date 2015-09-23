#pragma once
#include"Interface.h"
#include<iostream>


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
	int recipeNum;

	std::cout << "=================IIKH System Menu =============" << std::endl;
	std::cout << "1.������ �˻� 2.������ �߰� 3. ������ ���� " << std::endl;
	std::cout << " 4.������ ���� 5. ��� ������ ���� ����" << std::endl;
	std::cout << "6. ����/�Ĵ� ���� 7. ����/�Ĵ� ���� 8. ��������" << std::endl;
	std::cout << "9. ���α׷� ����" << std::endl;
	std::cout << "=================IIKH System Menu =============" << std::endl;
	std::cout << "��ȣ�� �Է��ϼ��� : ";

	std::cin >> userInput;

	std::cout << "your Input is " << userInput << std::endl;

	switch (userInput)
	{
	case 1:
		//������ �˻� 
		dataBase.search();
		break;
	case 2:
		// ������ �߰�
		dataBase.addRecipe();
		break;
	case 3:
		// ������ ����
		dataBase.modifyRecipe(dataBase.getRecipe());
		break;
	case 4:
		// ������ ���� 
		dataBase.deleteRecipe();
		break;
	case 5:
		// ��� ������ ���� ����
		dataBase.showAllRecipesList(dataBase.getRecipe());
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
		saveFileData(this->dataBase, this->planmanager);
		break;
	case 9:
		exit(1);
		break;
	default:
		break;
	}
}


void Interface::showDayPlan(){

	int date, month, day;
	std::cout << "Ȯ���� ��¥�� �Է��ϼ���(��/��) : ";
	std::cin >> date;

	month = date / 100;
	day = date % 100;

	while ((day<1 || day>30) || (month<1 || month>12)) {
		cout << "��¥�� �߸��Է��ϼ̽��ϴ�. Ȯ���� ��¥�� �Է��ϼ���(��/��) : ";
		std::cin >> date;
		month = date / 100;
		day = date % 100;
	}

	planmanager.showDailyPlan(day);
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
		cout << endl << "1. ��ħ�޴� �����ϱ�" << endl << "2. ���ɸ޴� �����ϱ�" << endl << "3. ����޴� �����ϱ�" << endl 
			 << "4. �����߰��ϱ�" << endl << "5. ���������ϱ�" << endl << "6. �����޴���" << endl;
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
	FILE* input;
	input = fopen("DailyRecipe.txt", "w");

	int date = 1;
	while (date > 30) {
		fprintf(input, "%d�� �Ĵ� �� ����\n", date);
		fprintf(input, "���� : ");
		planmanager.getDailyPlan(date);//<-��ü �� todayplan�����ؾߵǴµ� ���Ͷ�Ф�;

		//fprintf(input, planmanager.getDailyPlan(date));
		/*
		for (i = 0; i < planmanager.getDailyPlan(date) .size(); i++) {
		std::cout << todayPlan.at(i);
		}
		*/

		date++;
	}
}

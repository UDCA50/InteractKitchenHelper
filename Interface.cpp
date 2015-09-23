#pragma once
#include"Interface.h"
#include<iostream>
#include<ctime>
using namespace std;


Interface::Interface() {
	
	//loadFileData(dataBase, planmanager);
	frontImage.printImage();		// �ʱ�ȭ�� ���
	showTodayInformation();
}

void Interface::printTitleMenu() {

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

void Interface::showFrontMenu() {

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
		dataBase.searchRecipe();
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
		dataBase.showAllRecipeList();
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


void Interface::showDayPlan() {

	int date, menunum;
	std::cout << "Ȯ���� ��¥�� �Է��ϼ���(1~30) : ";
	std::cin >> date;

	while (date<1 || date>30) {
		cout << "��¥�� �߸��Է��ϼ̽��ϴ�. Ȯ���� ��¥�� �Է��ϼ��� : ";
		std::cin >> date;
	}

	planmanager.showDailyPlan(date);

	std::cout << "1.��ħ�޴� �󼼺���  2.���ɸ޴� �󼼺���  3.����޴� �󼼺��� 4.�����޴��� ���ư��� " << std::endl << "Ȯ���� �޴��� �ش��ϴ� ���ڸ� �Է��ϼ��� : ";
	std::cin >> menunum;

	if (menunum == 4)
		showFrontMenu();

	else {
		while (menunum <1 || menunum > 3) {
			if (menunum == 4){
				showFrontMenu();
			}
			else {
				std::cout << "���ڸ� �߸��Է��ϼ̽��ϴ�." << std::endl;
				std::cout << "1.��ħ�޴� �󼼺���  2.���ɸ޴� �󼼺���  3.����޴� �󼼺��� 4.�����޴��� ���ư���" << std::endl << "Ȯ���� �޴��� �ش��ϴ� ���ڸ� �Է��ϼ��� : ";
				std::cin >> menunum;
			}
		}
	}
	switch (menunum) {
		//showRecipeofdish(planmanager.getOneDay(date).getMealName(����)); -> ����ؾߵ�!!!!
		//planmanager.getOneDay(date).getMealNumber(����) -> �ο���!!!
	case 1:
		if (planmanager.getOneDay(date).getMealName(1).compare("��ħ����") == 0) {
			std::cout << "Ȯ���� �޴��� �����ϴ�." << std::endl;
		}
		break;

	case 2:
		if (planmanager.getOneDay(date).getMealName(2).compare("���ɾ���") == 0) {
			std::cout << "Ȯ���� �޴��� �����ϴ�." << std::endl;
		}
		break;

	case 3:
		if (planmanager.getOneDay(date).getMealName(3).compare("�������") == 0) {
			std::cout << "Ȯ���� �޴��� �����ϴ�." << std::endl;
		}
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
	string newMenu;	// ������ �޴���
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
	myDay = planmanager.getOneDay(day);
	myDay.showTodayData();


	/* 2. �޴� */
	while (1)
	{
		cout << endl << "1. ��ħ�޴� �����ϱ�" << endl
			<< "2. ���ɸ޴� �����ϱ�" << endl
			<< "3. ����޴� �����ϱ�" << endl
			<< "4. �����߰��ϱ�" << endl
			<< "5. ���������ϱ�" << endl
			<< "6. �����޴���" << endl
			<< "Input : ";

		fflush(stdin);
		cin >> menu;

		/* �޴�������Ʈ */
		if (menu == 1 || menu == 2 || menu == 3)
		{
			cout << endl << " 1 > �޴��� ����" << endl;
			newMenu = dataBase.selectOneRecipeName();
			myDay.setMealName(menu, newMenu);

			cout << endl << " 2 > �Ļ��ο� ���� : ";
			cin >> newNumber;
			myDay.editNumber(menu, newNumber);
		}

		/* ����������Ʈ */
		else if (menu == 4)
		{
			cout << endl << " > �����߰�" << endl;
			fflush(stdin);
			std::getline(std::cin, newPlan);
			myDay.addPlan(newPlan);
		}
		else if (menu == 5)
		{
			myDay.deleteAllPlan();
		}

		/* ��Ÿ */
		else if (menu == 6)
		{
			return;
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�" << endl;
		}

		planmanager.changeDay(myDay, day);
	}
}

void Interface::showTodayInformation() {


}

void Interface::loadFileData(DataBase &dataBase, PlanManager &planmanager){
   //�Ѵ� Day ������ ���α׷��� �ҷ���
   Day loadDay;
   FILE* datefptr;
   datefptr = fopen("saveDayData.txt", "r");

   int date = 1;
   while (date < 32) {
      ifstream ifp(datefptr);
      char line[128];
      int count = 0;
      char* context = NULL;
      while (fgets(line, 128, datefptr) != NULL){

         cout << line << endl;
         char* token = strtok_s(line, ",", &context);
         if (token != NULL){//Number
         //��/  loadDay.editNumber = token - 48; //�� ���� �����̱� ������ -48����
		// editNumber(int time, int newNumber) �� �Լ��ε�
		// ó���� �޴� ���ڴ� ���Ͽ� �̰� ������ �ε� ������� ���ڴٴ°��� 
		// �����ʿ���
         }
         while (token){
            count++;
            token = strtok_s(NULL, ",", &context);
            if (count == 1){//��ħ�޴�


            }
            else if (count == 2){//���ɸ޴�

            }
            else if (count == 3){//����޴�

            }
            else if (count == 4){//��ħ �ο� ��


            }
            else if (count == 5){//���� �ο� ��


            }
            else if (count == 6){//���� �ο� ��

            }
            else if (count == 7){//��������1

            }
            else if (count == 8){//��������2

            }
            else if (count == 9){//��������3

               count = 0;
               break;
            }
         }
      } //���پ� �����鼭 �Ľ�


   }

      fclose(datefptr);

}


void Interface::saveFileData(DataBase &dataBase, PlanManager &planmanager){
	//�Ѵ� Day ������ ���Ͽ� ������
	planmanager.saveMonthPlan();
	// ���� ������ ������ ���Ͽ� ������ 
	dataBase.saveDataBase();
}
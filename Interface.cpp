#pragma once
#include"Interface.h"
#include<iostream>
#include<ctime>
using namespace std;


Interface::Interface() {
	
	loadFileData(dataBase, planmanager);
	frontImage.printImage();		// �ʱ�ȭ�� ���
	showTodayInformation();
}




void Interface::showFrontMenu() {

	int userInput = 0;
	dataBase.clearTempRecipe();
	std::cout << "\n\n";
	std::cout << "\t========================IIKH System Menu=====================" << std::endl;
	std::cout << "\t1.Search Recipe\t\t\t\t2.Add Recipe" << std::endl;
	std::cout << endl;
	std::cout << "\t3.Modify Recipe\t\t\t\t4.Delete Recipe" << std::endl;
	std::cout << endl;
	std::cout << "\t5.Show Recipe List\t\t\t6.Show DailyPlan" << std::endl;
	std::cout << endl;
	std::cout << "\t7.modify Plan\t\t\t\t8. Save Status" << std::endl;
	std::cout << endl;
	std::cout << "\t9. exit Program" << endl;
	std::cout << "\t========================IIKH System Menu=====================" << std::endl;
	std::cout << endl;
	std::cout << endl;
	std::cout << "\tSelect Number > ";

	std::cin >> userInput;
	checkNumberInput(userInput);

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
		dataBase.showAllRecipeList(PRINT_LIST_EXITOR);
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

	int date, menunum = 0;
	system("cls");
	std::cout << "\t======================== Show Daily Plan =====================" << std::endl;
	std::cout << "\tInput the Day Number you want to Check(1~30) : ";
	std::cin >> date;
	checkNumberInput(date);

	while (date<1 || date>30) {
		cout << "\tWrong Input Try again !: ";
		std::cin >> date;
		checkNumberInput(date);
	}

	std::cout << std::endl;

	planmanager.showDailyPlan(date);

	while (menunum != 4) {
		std::cout << "\t======================== Select Sub Option =====================" << std::endl;
		std::cout << "\t 1.See BreakFast Detail\t\t 2.See Lunch Detail" << endl 
				<< "\t3.See Dinner Detail\t\t4.Back To Main Menu " << endl 
				<< "Select Option : ";
		std::cin >> menunum;
		cin.clear();
		cin.ignore(10000, '\n');
		checkNumberInput(date);

		std::cout << std::endl;

		if (menunum == 4)
			showFrontMenu();

		else {
			while (menunum <1 || menunum > 3) {
				if (menunum == 4){
					showFrontMenu();
				}
				else {
					cout << "\tWrong Input Try again !: ";
					std::cout << "\t======================== Select Sub Option =====================" << std::endl;
					std::cout << "\t 1.See BreakFast Detail\t\t 2.See Lunch Detail" << endl
						<< "\t3.See Dinner Detail\t\t4.Back To Main Menu " << endl
						<< "Select Option : ";					
					std::cin >> menunum;
					cin.clear();
					cin.ignore(10000, '\n');
					checkNumberInput(date);
					std::cout << std::endl;
				}

			}
		}

		switch (menunum) {
		case 1:
			if (planmanager.getOneDay(date).getMealName(1).compare("��ħ����") == 0) {
				std::cout << "Ȯ���� �޴��� �����ϴ�." << std::endl;

			}
			else {
				std::cout << planmanager.getOneDay(date).getMealNumber(1) << "����� �丮�� �ؾ��մϴ�." << std::endl;
				dataBase.showRecipeOfDish(planmanager.getOneDay(date).getMealName(1));
			}
			break;

		case 2:
			if (planmanager.getOneDay(date).getMealName(2).compare("���ɾ���") == 0) {
				std::cout << "Ȯ���� �޴��� �����ϴ�." << std::endl;
			}
			else{
				std::cout << planmanager.getOneDay(date).getMealNumber(2) << "����� �丮�� �ؾ��մϴ�." << std::endl;
				dataBase.showRecipeOfDish(planmanager.getOneDay(date).getMealName(2));
			}
			break;

		case 3:
			if (planmanager.getOneDay(date).getMealName(3).compare("�������") == 0) {
				std::cout << "Ȯ���� �޴��� �����ϴ�." << std::endl;
			}
			else{
				std::cout << planmanager.getOneDay(date).getMealNumber(3) << "����� �丮�� �ؾ��մϴ�." << std::endl;
				dataBase.showRecipeOfDish(planmanager.getOneDay(date).getMealName(3));
			}
			break;

		default:
			break;
		}

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
		system("cls");
		std::cout << "\t======================== Modify Daily Plan =====================" << std::endl;
		std::cout << "\tInput the Day Number you want to Check(1~30) : ";
		cin >> day;
		checkNumberInput(day);


		if (1 <= day && day <= 31)
			break;
		else
			cout << "\tWrong Input Try again !: ";
	}
	myDay = planmanager.getOneDay(day);
	myDay.showTodayData(day);


	/* 2. �޴� */
	
		std::cout << "\t======================== Select Option =====================" << std::endl;
		cout << endl << "\t1. Modify BreakFast Meal\t\t" << "2. Modify Lunch Meal" << endl
			<< "\t3. Modify Dinner Meal\t\t" << "4. Add ScheDule" << endl
			<< "\t5. Delete ScheDule\t\t" << "6. go Back to Main Menu" << endl
			<< "Select Option : ";

		fflush(stdin);
		cin >> menu;
		checkNumberInput(menu);
		/* �޴�������Ʈ */
		if (menu == 1 || menu == 2 || menu == 3)
		{
			cout << endl << "\t 1> Change Menu :" << endl;
			newMenu = dataBase.selectOneRecipeName();
			if (newMenu.compare("ESCAPE") == 0) {
				return;
			}
			myDay.setMealName(menu, newMenu);

			cout << endl << "\t 2> Change Number of People : ";
			cin >> newNumber;
			checkNumberInput(newNumber);
			myDay.editNumber(menu, newNumber);
		}

		/* ����������Ʈ */
		else if (menu == 4)
		{
			cout << endl << "\t 3> Add Today Schedule " << endl;
			fflush(stdin);
			cout << " > ";
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
			cout << "Wrong Input " << endl;
		}

		planmanager.changeDay(myDay, day);

	
}

void Interface::showTodayInformation() {


}

void Interface::loadFileData(DataBase &dataBase, PlanManager &planmanager){
	//�Ѵ� Day ������ ���α׷��� �ҷ���
	loadDayData(planmanager);
	loadRecipeData(dataBase);

}


void Interface::saveFileData(DataBase &dataBase, PlanManager &planmanager){
	//�Ѵ� Day ������ ���Ͽ� ������
	planmanager.saveMonthPlan();
	dataBase.saveDataBase();
}


void Interface::loadDayData(PlanManager &planmanager){
	FILE* datefptr;
	datefptr = fopen("saveDayData.txt", "r");

		char line[1024];
		char* context = NULL;
		while (fgets(line, 1024, datefptr) != NULL){
			int count = 0;
			int loadDate=1;
			Day loadDay;
			char* token = strtok_s(line, ",", &context);
			loadDate = atoi(token);
			while ((token = strtok_s(NULL, ",", &context)) != NULL){
				count++;
				if (count == 1){//��ħ�޴�
					loadDay.setBreakFastName(token);
				}
				else if (count == 2){//���ɸ޴�
					loadDay.setLunchName(token);
				}
				else if (count == 3){//����޴�
					loadDay.setDinnerName(token);
				}
				else if (count == 4){//��ħ �ο� ��
					loadDay.setBreakFastNumber(atoi(token));
				}
				else if (count == 5){//���� �ο� ��
					loadDay.setLunchNumber(atoi(token));
				}
				else if (count == 6){//���� �ο� ��
					loadDay.setDinnerNumber(atoi(token));
				}
				else if (count >= 7){//���� ����
					char* linefeed;
					if ((  linefeed = strstr(token, "\n")) != NULL) {
						*linefeed = NULL;
					}
					loadDay.setTodayPlan(token);
				}
			}
			planmanager.changeDay(loadDay, loadDate);
		}
		
	std::fclose(datefptr);
}


void Interface::loadRecipeData(DataBase &dataBase){
	FILE* recipeptr;
	recipeptr = fopen("saveRecipeData.txt", "r");

	char line[1024];
	char* context = NULL;
	while (fgets(line, 1024, recipeptr) != NULL){
		Recipe saveRecipe;
		vector<string> recipeString;	// ��ᰳ��, �̸�, ������
		vector<string> ingreString;		// ����̸�, ��ᷮ 
		char* token = strtok_s(line, ",", &context);	//init pharse
		recipeString.push_back(token);
		while ((token = strtok_s(NULL, ",", &context)) != NULL){
		
			if (*token == '|') {
				token = strtok(token, "|");
				ingreString.push_back(token);
				while ((token = strtok(NULL, "|")) != NULL && *token!='\n') {
					ingreString.push_back(token);
				}
				break;
			}

			recipeString.push_back(token);
		}
		saveRecipe.setDishName(recipeString.at(1));
		saveRecipe.setdishExplanation(recipeString.at(2));
		for (int i = 0; i < atoi(recipeString.at(0).c_str()); i++) {
			Ingredient tempIngre(ingreString.at(2 * i), atoi(ingreString.at((2 * i) + 1).c_str()));
			saveRecipe.setFileIngredient(tempIngre);
		}
		dataBase.setRecipe(saveRecipe);
	}
}
#pragma once
#include"Interface.h"
#include<iostream>


Interface::Interface() {
		//printTitleMenu();
		frontImage.printImage();		// 초기화면 출력
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
	std::cout << "1.레서피 검색 2.레서피 추가 3. 레서피 수정 " << std::endl;
	std::cout << " 4.레서피 삭제 5. 모든 레시피 종류 보기" << std::endl;
	std::cout << "6. 일정/식단 보기 7. 일정/식단 수정 8. 상태저장" << std::endl;
	std::cout << "9. 프로그램 종료" << std::endl;
	std::cout << "=================IIKH System Menu =============" << std::endl;
	std::cout << "번호를 입력하세요 : ";

	std::cin >> userInput;

	std::cout << "your Input is " << userInput << std::endl;

	switch (userInput)
	{
	case 1:
		//레서피 검색 
		dataBase.search();
		break;
	case 2:
		// 레서피 추가
		dataBase.addRecipe();
		break;
	case 3:
		// 레서피 수정
		dataBase.modifyRecipe(dataBase.getRecipe());
		break;
	case 4:
		// 레서피 삭제 
		dataBase.deleteRecipe();
		break;
	case 5:
		// 모든 레서피 종류 보기
		dataBase.showAllRecipesList(dataBase.getRecipe());
		break;
	case 6:
		// 일정/식단 보기
		showDayPlan();
		break;
	case 7:
		// 일정/식단 수정
		editDayPlan();
		break;
	case 8:
		// 현재 상태 저장 
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
	std::cout << "확인할 날짜를 입력하세요(월/일) : ";
	std::cin >> date;

	month = date / 100;
	day = date % 100;

	while ((day<1 || day>30) || (month<1 || month>12)) {
		cout << "날짜를 잘못입력하셨습니다. 확인할 날짜를 입력하세요(월/일) : ";
		std::cin >> date;
		month = date / 100;
		day = date % 100;
	}

	planmanager.showDailyPlan(day);
}


void Interface::editDayPlan()
{
	int day;
	int menu;	// 콘솔메뉴
	Day myDay;
	char *newMenu;	// 수정할 메뉴명
	int newNumber;	// 수정할 인원수
	string newPlan;	// 수정할 플랜

	/* 1. 날짜 입력 */
	while (1)
	{
		cout << "<< 일정/식단 수정 >>" << endl << "날짜를 입력하세요(1 ~ 31) : ";
		cin >> day;

		if (1 <= day && day <= 31)
			break;
		else
			cout << "1에서 31 사이의 수만 입력하세요" << endl;
	}
	myDay = planmanager.getDailyPlan(day);
	myDay.showTodayData();


	/* 2. 메뉴 */
	while (1)
	{
		cout << endl << "1. 아침메뉴 수정하기" << endl << "2. 점심메뉴 수정하기" << endl << "3. 저녁메뉴 수정하기" << endl 
			 << "4. 일정추가하기" << endl << "5. 일정삭제하기" << endl << "6. 상위메뉴로" << endl;
		fflush(stdin);
		cin >> menu;

		/* 메뉴수정파트 */
		if (menu == 1 || menu == 2 || menu == 3)
		{
			cout << " 1 > 메뉴명 수정" << endl;
			dataBase.search();
			myDay.editName(menu, newMenu);

			cout << " 2 > 식사인원 수정 : ";
			cin >> newNumber;
			myDay.editNumber(menu, newNumber);
		}
		
		/* 일정수정파트 */
		else if (menu == 4)
		{
			cout << " > 일정추가" << endl;
			fflush(stdin);
			cin >> newPlan;
			myDay.editPlan(newPlan);
		}
		else if (menu == 5)
		{
			myDay.editPlan("");
		}

		/* 기타 */
		else if (menu == 6)
		{
			showFrontMenu();
		}
		else
		{
			cout << "잘못된 입력입니다" << endl;
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
		fprintf(input, "%d일 식단 및 일정\n", date);
		fprintf(input, "일정 : ");
		planmanager.getDailyPlan(date);//<-객체 의 todayplan접근해야되는데 벡터라ㅠㅠ;

		//fprintf(input, planmanager.getDailyPlan(date));
		/*
		for (i = 0; i < planmanager.getDailyPlan(date) .size(); i++) {
		std::cout << todayPlan.at(i);
		}
		*/

		date++;
	}
}

#pragma once
#include"Interface.h"
#include<iostream>
#include<ctime>
using namespace std;
// 반복문 iterator 전부 그럴듯한 이름으로 바꾸어야함


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

	std::cout << "=================IIKH System Menu =============" << std::endl;
	std::cout << "1.레서피 검색 2.레서피 추가 3. 레서피 수정 " << std::endl;
	std::cout << " 4.레서피 삭제 5. 모든 레시피 종류 보기" << std::endl;
	std::cout << "6. 일정/식단 보기 7. 일정/식단 수정 8. 상태저장" << std::endl;
	std::cout << "9. 프로그램 종료" << std::endl;
	std::cout << "=================IIKH System Menu =============" << std::endl;
	std::cout << "번호를 입력하세요 : ";

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
		// 일정/식단 보기
		showDayPlan();
		break;
	case 7:
		// 일정/식단 수정
		editDayPlan();
		break;
	case 8:
		// 현재 상태 저장 
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

	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기

	cout << "확인할 날짜를 입력하세요(" << t->tm_mon + 1 << "월/일) :";
	cin >> date;

	while ((date<1 || date>30)) {
		cout << "유효한 일을 입력하세요(1일~31일) : ";
		cin >> date;
	}

	planmanager.showDailyPlan(date);
	std::cout << "1.아침메뉴 상세보기  2.점심메뉴 상세보기  3.저녁메뉴 상세보기 " << std::endl << "확인할 메뉴에 해당하는 숫자를 입력하세요 : ";

	std::cin >> menunum;
	while (menunum <1 || menunum > 3) {
		std::cout << "숫자를 잘못입력하셨습니다." << std::endl;
		std::cout << "1.아침메뉴 상세보기  2.점심메뉴 상세보기  3.저녁메뉴 상세보기 " << std::endl << "확인할 메뉴에 해당하는 숫자를 입력하세요 : ";
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
		cout << endl << "1. 아침메뉴 수정하기" << endl 
			<< "2. 점심메뉴 수정하기" << endl 
			<< "3. 저녁메뉴 수정하기" << endl
			<< "4. 일정추가하기" << endl 
			<< "5. 일정삭제하기" << endl 
			<< "6. 상위메뉴로" << endl;
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

	//한달 Day 정보를 파일에 저장함
	FILE* datefptr;
	datefptr = fopen("saveDayData.txt", "w");

	int date = 1;
	while (date < 32) {
		Day saveDay;
		saveDay = planmanager.getDailyPlan(date);		//오늘 Day 인스턴스 받아와서
		char** savePlanData = saveDay.getTodayPlan();	// 오늘 Plan 들을 받아오고
		
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
// 현재 레서피 정보를 파일에 저장함 

	FILE* recipefptr;
	recipefptr = fopen("saveRecipeData.txt", "w");
	for (int i = 0; i < dataBase.getRecipeCount(); i++) {
		Recipe myRecipe = dataBase.getRecipebyIndex(i);
		fprintf(recipefptr, "%s\n", myRecipe.getDishName().c_str());
	}
	fclose(recipefptr);
}

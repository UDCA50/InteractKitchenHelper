#pragma once
#include"Day.h"
#include<iostream>


Day::Day(){

	strcpy_s(this->breakFastName, "아침없음");
	strcpy_s(this->lunchName, "점심없음");
	strcpy_s(this->dinnerName, "저녁없음");

	this->breakFastNumber = 1;
	this->lunchNumber = 1;
	this->dinnerNumber = 1;

}

void Day::showTodayData(){
	int number;
	int i;
	std::cout << "일정 : ";
	for (i = 0; i < todayPlan.size(); i++) {
		std::cout << todayPlan.at(i);
	}
	std::cout << std::endl;
	std::cout << "아침 메뉴 : " << breakFastName << std::endl;
	std::cout << "점심 메뉴 : " << lunchName << std::endl;
	std::cout << "저녁 메뉴 : " << dinnerName << std::endl;

}
/*
void Day::showTodayData(){
	int number, menunum;
	int i;
	std::cout << "일정 : ";
	for (i = 0; i < todayPlan.size(); i++) {
		std::cout << todayPlan.at(i);
	}
	std::cout << std::endl;

	std::cout << "아침 메뉴 : " << breakFastName << std::endl;
	std::cout << "점심 메뉴 : " << lunchName << std::endl;
	std::cout << "저녁 메뉴 : " << dinnerName << std::endl;

	std::cout << "1.아침메뉴 상세보기  2.점심메뉴 상세보기  3.저녁메뉴 상세보기 " << std::endl << std::endl << "확인할 메뉴에 해당하는 숫자를 입력하세요 : ";
	std::cin >> menunum;
	while (menunum <1 || menunum > 3) {
		std::cout << "숫자를 잘못입력하셨습니다." << std::endl;
		std::cout << "1.아침메뉴 상세보기  2.점심메뉴 상세보기  3.저녁메뉴 상세보기 " << std::endl << "확인할 메뉴에 해당하는 숫자를 입력하세요 : ";
		std::cin >> menunum;
	}

	switch (menunum) {
	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	default:
		break;
	}// database의 showrecipeofdish 사용할것

}
*/
void Day::editName(int time, char *newName)
{
	if (time == 1)		// 아침
		strcpy_s(this->breakFastName, newName);
	else if (time == 2) // 점심
		strcpy_s(this->lunchName, newName);
	else if (time == 3) // 저녁
		strcpy_s(this->dinnerName, newName);
}

void Day::editNumber(int time, int newNumber)
{
	if (time == 1)		// 아침
		this->breakFastNumber = newNumber;
	else if (time == 2) // 점심
		this->lunchNumber = newNumber;
	else if (time == 3) // 저녁
		this->dinnerNumber = newNumber;
}

void Day::editPlan(string newPlan)
{
	//todayPlan.assign(newPlan.c_str());
}
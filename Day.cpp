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


string Day::getMenu(int num)
{
	if (num == 1)
		return breakFastName;
	else if (num == 2)
		return breakFastName;
	else if (num == 3)
		return breakFastName;
}
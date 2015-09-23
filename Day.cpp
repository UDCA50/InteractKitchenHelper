#pragma once
#include"Day.h"
#include<iostream>


Day::Day() {

	this->breakFastName = "아침없음";
	this->lunchName = "점심없음";
	this->dinnerName = "저녁없음";

	this->breakFastNumber = 1;
	this->lunchNumber = 1;
	this->dinnerNumber = 1;

}

void Day::showTodayData() {
	int number;
	int i;
	//system("cls");
	std::cout << "일정 : ";
	for (i = 0; i < todayPlan.size(); i++) {
		std::cout << endl << i + 1 << "번째 일정 : " << todayPlan.at(i);
	}
	std::cout << std::endl;
	std::cout << "아침 메뉴 : " << breakFastName << std::endl;
	std::cout << "점심 메뉴 : " << lunchName << std::endl;
	std::cout << "저녁 메뉴 : " << dinnerName << std::endl;

}
void Day::setMealName(int time, string newName)
{
	if (time == 1)		// 아침
		this->breakFastName = newName;
	else if (time == 2) // 점심
		this->lunchName = newName;
	else if (time == 3) // 저녁
		this->dinnerName = newName;
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

void Day::addPlan(string newPlan)
{
	todayPlan.push_back(newPlan.c_str());
}

void Day::deleteAllPlan()
{
	todayPlan.clear();
}


string Day::getMealName(int num)
{
	if (num == 1)
		return breakFastName;
	else if (num == 2)
		return lunchName;
	else if (num == 3)
		return dinnerName;
}

int Day::getMealNumber(int num)
{
	if (num == 1)
		return breakFastNumber;
	else if (num == 2)
		return lunchNumber;
	else if (num == 3)
		return dinnerNumber;
}

string* Day::getAllPlan() {
	string* charSet = new string[todayPlan.size()];

	for (int i = 0; i < todayPlan.size(); i++) {

		charSet[i] = todayPlan.at(i);
	}
	return charSet;
}

int Day::getPlanCount() {
	return todayPlan.size();
}

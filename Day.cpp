#define _CRT_SECURE_NO_WARNINGS
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


Day::Day(const Day &myday) {
	breakFastName = myday.breakFastName;
	lunchName = myday.lunchName;
	dinnerName = myday.dinnerName;
	this->breakFastNumber = myday.breakFastNumber;
	this->lunchNumber = myday.lunchNumber;
	this->dinnerNumber = myday.dinnerNumber;
	this->todayPlan = myday.todayPlan;
}

void Day::showTodayData(int date) {
	system("cls");
	std::cout << "\t========================"
		<< date << " - Day"
			<<"=====================" << std::endl;

	std::cout << "\tToday Plan : " << endl;
	for (unsigned int planIter = 0; planIter < todayPlan.size(); planIter++) {
		std::cout << planIter + 1 << ". Plan : " << endl;
		std::cout << todayPlan.at(planIter) << endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\tToday Meal Plan : " << endl;
	std::cout << "\tBreakFast : " << breakFastName  
			<< "("<< this->breakFastNumber <<" people)"<<std::endl;
	std::cout << "\tLunch : " << lunchName 
			<< "(" << this->lunchNumber << " people)" << std::endl;
	std::cout << "\tDinner : " << dinnerName 	
			<< "(" << this->dinnerNumber << " people)" << std::endl;

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

	return NULL;
}

int Day::getMealNumber(int num)
{
	if (num == 1)
		return breakFastNumber;
	else if (num == 2)
		return lunchNumber;
	else if (num == 3)
		return dinnerNumber;

	return -1;
}

string* Day::getAllPlan() {
	string* charSet = new string[todayPlan.size()];

	for (unsigned int planIter = 0; planIter < todayPlan.size(); planIter++) {

		charSet[planIter] = todayPlan.at(planIter);
	}
	return charSet;
}

int Day::getPlanCount() {
	return todayPlan.size();
}
void Day::setBreakFastName(string name){
	breakFastName = name;
}
void Day::setLunchName(string name){
	lunchName = name;
}
void Day::setDinnerName(string name){
	dinnerName = name;
}
void Day::setBreakFastNumber(int number){
	breakFastNumber = number;
}
void Day::setLunchNumber(int number){
	lunchNumber = number;
}
void Day::setDinnerNumber(int number){
	dinnerNumber = number;
}
void Day::setTodayPlan(string plan){
	todayPlan.push_back(plan);
}
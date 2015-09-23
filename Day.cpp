#pragma once
#include"Day.h"
#include<iostream>


Day::Day(){

	//testCase
	todayPlan.push_back("����������1");
	todayPlan.push_back("����������2");
	todayPlan.push_back("����������3");
	//testCase

	strcpy_s(this->breakFastName, "��ħ����");
	strcpy_s(this->lunchName, "���ɾ���");
	strcpy_s(this->dinnerName, "�������");

	this->breakFastNumber = 1;
	this->lunchNumber = 1;
	this->dinnerNumber = 1;

}

void Day::showTodayData(){
	int number;
	int i;
	std::cout << "���� : ";
	for (i = 0; i < todayPlan.size(); i++) {
		std::cout << todayPlan.at(i);
	}
	std::cout << std::endl;
	std::cout << "��ħ �޴� : " << breakFastName << std::endl;
	std::cout << "���� �޴� : " << lunchName << std::endl;
	std::cout << "���� �޴� : " << dinnerName << std::endl;

}
void Day::editName(int time, char *newName)
{
	if (time == 1)		// ��ħ
		strcpy_s(this->breakFastName, newName);
	else if (time == 2) // ����
		strcpy_s(this->lunchName, newName);
	else if (time == 3) // ����
		strcpy_s(this->dinnerName, newName);
}

void Day::editNumber(int time, int newNumber)
{
	if (time == 1)		// ��ħ
		this->breakFastNumber = newNumber;
	else if (time == 2) // ����
		this->lunchNumber = newNumber;
	else if (time == 3) // ����
		this->dinnerNumber = newNumber;
}

void Day::editPlan(string newPlan)
{
	//todayPlan.assign(newPlan.c_str());
}


string Day::getMenu
(int num)
{
	if (num == 1)
		return breakFastName;
	else if (num == 2)
		return breakFastName;
	else if (num == 3)
		return breakFastName;
}



char* Day::getbreakFastName(){

	return breakFastName;
}
char* Day::getLunchName(){
	return lunchName;
}
char* Day::getdinnerName(){
	return dinnerName;
}

int Day::getbreakFastNumber(){
	return breakFastNumber;
}

int Day::getLunchNumber(){
	return lunchNumber;
}
int Day::getDinnerNumber(){
	return dinnerNumber;
}


char** Day::getTodayPlan() {
	char** charSet = new char*[todayPlan.size()];

	for (int i = 0; i < todayPlan.size(); i++) {

		charSet[i] = todayPlan.at(i);
	}
	return charSet;
}

int Day::getPlanCount() {

	return todayPlan.size();
}

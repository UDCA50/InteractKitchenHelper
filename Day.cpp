#pragma once
#include"Day.h"
#include<iostream>


Day::Day(){

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
/*
void Day::showTodayData(){
	int number, menunum;
	int i;
	std::cout << "���� : ";
	for (i = 0; i < todayPlan.size(); i++) {
		std::cout << todayPlan.at(i);
	}
	std::cout << std::endl;

	std::cout << "��ħ �޴� : " << breakFastName << std::endl;
	std::cout << "���� �޴� : " << lunchName << std::endl;
	std::cout << "���� �޴� : " << dinnerName << std::endl;

	std::cout << "1.��ħ�޴� �󼼺���  2.���ɸ޴� �󼼺���  3.����޴� �󼼺��� " << std::endl << std::endl << "Ȯ���� �޴��� �ش��ϴ� ���ڸ� �Է��ϼ��� : ";
	std::cin >> menunum;
	while (menunum <1 || menunum > 3) {
		std::cout << "���ڸ� �߸��Է��ϼ̽��ϴ�." << std::endl;
		std::cout << "1.��ħ�޴� �󼼺���  2.���ɸ޴� �󼼺���  3.����޴� �󼼺��� " << std::endl << "Ȯ���� �޴��� �ش��ϴ� ���ڸ� �Է��ϼ��� : ";
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
	}// database�� showrecipeofdish ����Ұ�

}
*/
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
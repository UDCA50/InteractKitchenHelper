#pragma once
#include"Day.h"


class PlanManager {

private:
	std::vector<Day> monthPlan;	//�Ѵ� ������ �����س���

public:
	PlanManager();
	Day getOneDay(int date);		// �ش� ��¥�� ���� 
	void changeDay(Day freshDay, int date);	//�ش� ��¥�� ��ȹ�� �������ִ� �Լ�
	void showDailyPlan(int date); // �ش� ������ ��ȹ(�Ļ�,����)�� ������
	void saveMonthPlan();		// ���� ������ ���Ͽ� ������
};
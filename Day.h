#pragma once
#include<vector>
#include<string>
using namespace std;

class Day {
private:
	vector<string> todayPlan;		//���� ������ ������ ����

									//���� ��Ī
	string breakFastName;
	string lunchName;
	string dinnerName;

	//�Ļ� �ο���
	int breakFastNumber;
	int lunchNumber;
	int dinnerNumber;

public:
	Day();
	Day(const Day &myday);
	void showTodayData(int date);      // �� ���� (�Ļ�,������) ���

	void setMealName(int time, string newName);	// �Ļ� ���� �޼ҵ�
	void editNumber(int time, int newNum);		// �ο��� ���� �޼ҵ�
	void addPlan(string newPlan);				// �÷� �߰� �޼ҵ�
	void deleteAllPlan();						// �÷� ��ü����

	int getPlanCount();							// ������ �� ���� ��ȯ
	int getMealNumber(int num);					// �Ļ��ο� ��ȯ
	string getMealName(int num);				// �Ļ��̸� ��ȯ 
	string* getAllPlan();						// ���� ������ü ��ȯ


	//memberVar setter
	void setTodayPlan(string plan);
	void setBreakFastName(string name);
	void setLunchName(string name);
	void setDinnerName(string name);
	void setBreakFastNumber(int number);
	void setLunchNumber(int number);
	void setDinnerNumber(int number);
};
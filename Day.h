#pragma once
#include<vector>
#include<string>
using namespace std;
const int NameMaxLength = 10;

class Day{
private:
	std::vector<char*> todayPlan;		//���� ������ ������ ����
	
	//���� ��Ī
	char breakFastName[NameMaxLength];
	char lunchName[NameMaxLength];
	char dinnerName[NameMaxLength];

	//�Ļ� �ο���
	int breakFastNumber;
	int lunchNumber;
	int dinnerNumber;
	
public:
	Day();
	void showTodayData();      //���� ��ȹ(�Ļ�,������) �������
	char** getTodayPlan();		//������ ������ �������� �������
	void editName(int time, char *newName);		// ���ĸ� ���� �޼ҵ� (9/22)
	void editNumber(int time, int newNum);		// �ο��� ���� �޼ҵ�
	void editPlan(string newPlan);				// �÷� ���� �޼ҵ�

	string getMenu(int num);
	char* getbreakFastName();
	char* getLunchName();
	char* getdinnerName();
	int getbreakFastNumber();
	int getLunchNumber();
	int getDinnerNumber();
	int getPlanCount();

};
#pragma once
#include<vector>
#include<string>
using namespace std;
const int NameMaxLength = 10;

class Day{
private:
	std::vector<char*> todayPlan;		//오늘 일정을 저장한 백터
	
	//음식 명칭
	char breakFastName[NameMaxLength];
	char lunchName[NameMaxLength];
	char dinnerName[NameMaxLength];

	//식사 인원수
	int breakFastNumber;
	int lunchNumber;
	int dinnerNumber;
	
public:
	Day();
	void showTodayData();      //오늘 계획(식사,일정을) 출력해줌
	//std::vector gettodayPlan();//??????????어케하죠
	void editName(int time, char *newName);		// 음식명 수정 메소드 (9/22)
	void editNumber(int time, int newNum);		// 인원수 수정 메소드
	void editPlan(string newPlan);				// 플랜 수정 메소드
};
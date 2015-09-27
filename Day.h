#pragma once
#include<vector>
#include<string>
using namespace std;

class Day {
private:
	vector<string> todayPlan;		//오늘 일정을 저장한 백터

									//음식 명칭
	string breakFastName;
	string lunchName;
	string dinnerName;

	//식사 인원수
	int breakFastNumber;
	int lunchNumber;
	int dinnerNumber;

public:
	Day();
	Day(const Day &myday);
	void showTodayData(int date);      // 이 날의 (식사,일정을) 출력

	void setMealName(int time, string newName);	// 식사 수정 메소드
	void editNumber(int time, int newNum);		// 인원수 수정 메소드
	void addPlan(string newPlan);				// 플랜 추가 메소드
	void deleteAllPlan();						// 플랜 전체삭제

	int getPlanCount();							// 일정의 총 개수 반환
	int getMealNumber(int num);					// 식사인원 반환
	string getMealName(int num);				// 식사이름 반환 
	string* getAllPlan();						// 오늘 일정전체 반환


	//memberVar setter
	void setTodayPlan(string plan);
	void setBreakFastName(string name);
	void setLunchName(string name);
	void setDinnerName(string name);
	void setBreakFastNumber(int number);
	void setLunchNumber(int number);
	void setDinnerNumber(int number);
};
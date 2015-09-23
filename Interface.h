#pragma once

#include"DataBase.h"
#include"FrontImage .h"
#include"PlanManager.h"


class Interface {
private:

	FrontImage frontImage;		// 초기화면 정보
	DataBase dataBase;			// 레서피정보
	PlanManager planmanager;	// 전체 일정 정보


	void showTodayInformation();	//오늘의 계획(일정,식단)을 보여주는 클래스
	void showDayPlan();		// 특정날짜의 계획을 보여주는 매소드

	void editDayPlan();		// 특정날짜의 계획을 편집하는 매소드

	void loadFileData(DataBase &dataBase, PlanManager &planmanager);	// 파일에서 정보를 읽음
	void saveFileData(DataBase &dataBase, PlanManager &planmanager);	// 현재 정보를 파일에저장
	void printTitleMenu();
public:
	Interface();
	void showFrontMenu();	// 처음메뉴

};
#include"PlanManager.h"


PlanManager::PlanManager() {

	for (int i = 0; i < 31; i++) {
		Day myDate;
		monthPlan.push_back(myDate);
	}
}

void PlanManager::showDailyPlan(int date) {
	// 해당 날자의 계획(식사,일정)을 보여줌
	monthPlan[date - 1].showTodayData(date);
}


Day PlanManager::getOneDay(int date) {   // 해당 날짜를 리턴해주는 함수 
	Day myday = monthPlan[date - 1];
	return myday;
}

void PlanManager::changeDay(Day freshDay, int date) {//해당 날짜의 계획을 수정해주는 함수
	this->monthPlan[date - 1] = freshDay;
}

void PlanManager::saveMonthPlan() {
	FILE* datefptr;
	datefptr = fopen("saveDayData.txt", "w");

	int date = 1;
	while (date < 32) {
		Day *saveDay = new Day(getOneDay(date));
		string* savePlanData = saveDay->getAllPlan();	// 오늘 Plan 들을 받아오고

		fprintf(datefptr, "%d,%s,%s,%s,%d,%d,%d", date, saveDay->getMealName(1).c_str(),
			saveDay->getMealName(2).c_str(), saveDay->getMealName(3).c_str(),
			saveDay->getMealNumber(1), saveDay->getMealNumber(2), saveDay->getMealNumber(3));

		for (int i = 0; i < saveDay->getPlanCount(); i++) {
			fprintf(datefptr, ",%s", savePlanData[i].c_str());
		}
		fprintf(datefptr, "\n");
		date++;
	}
	fclose(datefptr);
}
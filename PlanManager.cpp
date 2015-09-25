#include"PlanManager.h"


PlanManager::PlanManager() {

	for (int i = 0; i < 31; i++) {
		Day myDate;
		monthPlan.push_back(myDate);
	}
}

void PlanManager::showDailyPlan(int date) {
	// �ش� ������ ��ȹ(�Ļ�,����)�� ������
	monthPlan[date - 1].showTodayData(date);
}


Day PlanManager::getOneDay(int date) {   // �ش� ��¥�� �������ִ� �Լ� 
	Day myday = monthPlan[date - 1];
	return myday;
}

void PlanManager::changeDay(Day freshDay, int date) {//�ش� ��¥�� ��ȹ�� �������ִ� �Լ�
	this->monthPlan[date - 1] = freshDay;
}

void PlanManager::saveMonthPlan() {
	FILE* datefptr;
	datefptr = fopen("saveDayData.txt", "w");

	int date = 1;
	while (date < 32) {
		Day *saveDay = new Day(getOneDay(date));
		string* savePlanData = saveDay->getAllPlan();	// ���� Plan ���� �޾ƿ���

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
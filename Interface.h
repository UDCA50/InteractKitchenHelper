#pragma once

#include"DataBase.h"
#include"FrontImage .h"
#include"PlanManager.h"


class Interface {
private:

	FrontImage frontImage;		// �ʱ�ȭ�� ����
	DataBase dataBase;			// ����������
	PlanManager planmanager;	// ��ü ���� ����


	void showTodayInformation();	//������ ��ȹ(����,�Ĵ�)�� �����ִ� Ŭ����
	void showDayPlan();		// Ư����¥�� ��ȹ�� �����ִ� �żҵ�

	void editDayPlan();		// Ư����¥�� ��ȹ�� �����ϴ� �żҵ�

	void loadFileData(DataBase &dataBase, PlanManager &planmanager);	// ���Ͽ��� ������ ����
	void saveFileData(DataBase &dataBase, PlanManager &planmanager);	// ���� ������ ���Ͽ�����
	void printTitleMenu();
public:
	Interface();
	void showFrontMenu();	// ó���޴�

};
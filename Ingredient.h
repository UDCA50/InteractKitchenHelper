/*
 * �����ǿ� �� ���.
 * Created by �ſ���/������/�ֿ�ȣ
 */

#pragma once
#include<iostream>
#include <string>
using namespace std;

class Ingredient{

private:
	string ingredientName;					//����
	int amount;								//��ᷮ
public:
	Ingredient(string name, int amount);		//������
											//��Ḧ �Է¹��� ��, �̸��� ���� �Է¹���
	string getIngredientName();				//������ ��ȯ��
	int getAmount();						//��ᷮ�� ��ȯ��

	void setName(string name);							//������ setting(���� ��)
	void setAmount(int amount);						//��ᷮ�� setting(���� ��)

};

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
	Ingredient(string name, int amount);			
	Ingredient();
	//getter
	string getIngredientName();				
	int getAmount();					
	//setter
	void setName(string name);							
	void setAmount(int amount);					

};

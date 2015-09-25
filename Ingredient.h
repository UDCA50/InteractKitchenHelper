/*
 * 레시피에 들어갈 재료.
 * Created by 신영현/남성준/최연호
 */

#pragma once
#include<iostream>
#include <string>
using namespace std;

class Ingredient{

private:
	string ingredientName;					//재료명
	int amount;								//재료량
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

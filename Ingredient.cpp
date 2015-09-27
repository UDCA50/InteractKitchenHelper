/*
 * Ingredient Method 구현
 * Created by 신영현/남성준/최연호
 */
#include "Ingredient.h"

Ingredient::Ingredient(string name, int amount)
{
	this->ingredientName = name;
	this->amount = amount;
}

Ingredient::Ingredient()
{
}


string Ingredient::getIngredientName()	//재료명 반환
{
	return ingredientName;
}

int Ingredient::getAmount()
{
	return amount;
}

void Ingredient::setName(string name)
{
	this->ingredientName = name;
}

void Ingredient::setAmount(int amount)
{
	this->amount = amount;
}


//ERRFIX_03: 숫자 유효성 체크
int checkNumberInput(int &numberInput){

	while (!(numberInput >= 0 && numberInput < 10000)){
		cout << "\t Invaild Input Try again !: ";
		std::cin >> numberInput;
		checkNumberInput(numberInput);
	}
	return numberInput;
}

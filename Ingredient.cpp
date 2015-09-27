/*
 * Ingredient Method ����
 * Created by �ſ���/������/�ֿ�ȣ
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


string Ingredient::getIngredientName()	//���� ��ȯ
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


//ERRFIX_03: ���� ��ȿ�� üũ
int checkNumberInput(int &numberInput){

	while (!(numberInput >= 0 && numberInput < 10000)){
		cout << "\t Invaild Input Try again !: ";
		std::cin >> numberInput;
		checkNumberInput(numberInput);
	}
	return numberInput;
}

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



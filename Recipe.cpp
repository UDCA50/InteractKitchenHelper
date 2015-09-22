/*
 * Recipe Method ����
 * Created by �ſ���/������/�ֿ�ȣ
 */

#pragma once
#include "Recipe.h"

//������
Recipe::Recipe(string name)
{
	this->dishName = name;
}



//private���� Method

int Recipe::findNumberOfIngredient(string name) {
	int ingredientNum = 0;
	int i = 0;
	int maxVectorNum;
	maxVectorNum = ingredient.size();
	for (i = 0; i<maxVectorNum; i++) {
		if (ingredient[ingredientNum].getIngredientName().compare(name) == 0) {
			return ingredientNum;
		}
	}
	return -1;	//-1�� return �� ��� �ش� ������ �� ã���� �ϴ� ��ᰡ ���ٴ� ���� �ǹ�
}				//���� ����� ��ȣ�� ��ȯ. (���° �������) //�Ű����� ����


string Recipe::getIngredientName(int ingredientNumber) {
	
	return ingredient[ingredientNumber].getIngredientName();
}		//���° ����� ������ ��ȯ


void Recipe::setIngredientName(string name, int ingredientNumber)
{
	ingredient[ingredientNumber].setName(name);
}

int Recipe::getIngredientAmount(int ingredientNumber) {
	return ingredient[ingredientNumber].getAmount();
}

void Recipe::setIngredientAmount(int amount,int ingredientNumber)
{
	ingredient[ingredientNumber].setAmount(amount);
}

void Recipe::ingredientDelete(int ingredientNumber)
{
	ingredient.erase(ingredient.begin() + (ingredientNumber-1));
}	//��� ��� ����

void Recipe::showIngredient(int ingredientNumber)
{
	cout << "���� : " << ingredient[ingredientNumber].getIngredientName() << endl;
	cout << "��ᷮ : " << ingredient[ingredientNumber].getAmount() << endl;
}

//public���� method
string Recipe::getDishName()
{
	return dishName;
}

vector<Ingredient> Recipe::getIngredient()
{
	return ingredient;
}

string Recipe::getRecipedOfDish()
{
	return recipeOfDish;
}


void Recipe::ingredientAdd(string name, int amount)
{
	ingredient.push_back(Ingredient(name, amount));
	
}

void Recipe::setDishName(string name)
{
	this->dishName = name;
}

void Recipe::setRecipeOfDish(string recipeOfDish)
{
	this->recipeOfDish = recipeOfDish;
}

void Recipe::ingredientModify(int ingredientNumber)
{
	int modifyChoice=0;
	cout << "1. ���� ����\n2.��ᷮ ����\n3.�� ��� ����\n0.���θ޴���..." << endl;
	cout << "���� >> ";
	cin >> modifyChoice;

	switch (modifyChoice)
	{
	case 1:
	{	string modifyName;
	cout << "������ ������ �Է��ϼ���. >>";
	getline(cin, modifyName); //string �Է¹ޱ�
	setIngredientName(modifyName, ingredientNumber);
	break;
	}
	case 2:
	{
		int modifyAmount;
		cout << "������ ��ᷮ�� �Է��ϼ���. >>";
		cin >> modifyAmount;
		setIngredientAmount(modifyAmount, ingredientNumber);
		break;
	}
	case 3:
	{
		ingredientDelete(ingredientNumber);
		break;
	}
	case 0:
	{	break; }
	default:
	{


		cout << "�߸��� ����Դϴ�." << endl;
		break;
	}
	}

}

void Recipe::showAllRecipeInformation()
{
	cout << "�丮�� : " << dishName << endl;
	cout << "*******���*******" << endl;
	for (int i = 0; i < ingredient.size(); i++)
		showIngredient(i);
	cout << "******************" << endl;
	cout << "������ : " << recipeOfDish;
}

void Recipe::showAllIngredient()
{
	
	for (int i = 0; i < ingredient.size(); i++)
	{
		cout << i << ". ���� : " << ingredient[i].getIngredientName() << endl;
		cout << "   ��ᷮ : " << ingredient[i].getAmount() << endl;
	}

}
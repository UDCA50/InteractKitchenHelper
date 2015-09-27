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

Recipe::Recipe(){

}


//private���� Method

int Recipe::findNumberOfIngredient(string name) {
	
	int i = 0;
	int maxVectorNum;
	maxVectorNum = ingredient.size();
	for (i = 0; i<maxVectorNum; i++) {
		if (ingredient[i].getIngredientName().compare(name) == 0) {
			return i;
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

void Recipe::setFileIngredient(Ingredient addIngredient) //interface���� Ingredient�� ����, ���� �������� ���� method 09-24
{
	ingredient.push_back(addIngredient);
}

void Recipe::deleteIngredient(int ingredientNumber)
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

string Recipe::getRecipeOfDish()
{
	return dishExplanation;
}


void Recipe::addIngredient(string name, int amount)
{
	ingredient.push_back(Ingredient(name, amount));
	
}

void Recipe::setDishName(string name)
{
	this->dishName = name;
}

void Recipe::setdishExplanation(string dishExplanation)
{
	this->dishExplanation = dishExplanation;
}

void Recipe::modifyIngredient(int ingredientNumber)
{
	int modifyChoice=0;
	std::cout << "\t========================"<<this->getIngredientName(ingredientNumber)
	<<"=====================" << std::endl;
	//��checkPoint
	cout << "1. ���� ����\n2.��ᷮ ����\n3.�� ��� ����\n0.���θ޴���..." << endl;
	cout << "���� >> ";
	cin >> modifyChoice;

	switch (modifyChoice)
	{
	case 1:
	{	string modifyName;
	cout << "������ ������ �Է��ϼ���. >>";
	cin >> modifyName;
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
		deleteIngredient(ingredientNumber);
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
	cout << "������ : " << dishExplanation;
}

void Recipe::showAllIngredient()
{
	system("cls");
	cout << "\t======================== Ingredient List ====================" << endl;
	for (int i = 0; i < ingredient.size(); i++)
	{
		cout <<"\t" << (i+1) << ". Name : " << ingredient[i].getIngredientName() << endl;
		cout <<"\t" << "   Amount : " << ingredient[i].getAmount() << "g"<< endl;
	}

}
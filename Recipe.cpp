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
	this->dishExplanation = "None";
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
	cout << "\t Ingredient Name : " << ingredient[ingredientNumber].getIngredientName() << endl;
	cout << "\t Ingredient Amount : " << ingredient[ingredientNumber].getAmount() << endl;
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
	system("cls");
	cout << "\t========================"
		<<this->getIngredientName(ingredientNumber)
		<<"=====================" << std::endl;

	cout << "\t1. modify Ingredient Name\t\t2.modify Ingredient Amount" << endl;
	cout << "\t3. delete this Ingredient \t\t0.go Back to Main Menu" << endl;
	cout << "\t========================"
		<< this->getIngredientName(ingredientNumber)
		<< "=====================" << std::endl;

	cout << "\tSelect Option >> ";
	cin >> modifyChoice;

	switch (modifyChoice)
	{
	case 1:
	{	string modifyName;
	cout << "\t Input New Ingredient Name>>";
	cin >> modifyName;
	setIngredientName(modifyName, ingredientNumber);
	break;
	}
	case 2:
	{
		int modifyAmount;
		cout << "\t Input New Ingredient Amount>>";
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


		cout << "Wrong Number !." << endl;
		break;
	}
	}

}

void Recipe::showAllRecipeInformation()
{

	system("cls");
	cout << "\t========================"
		<< dishName
		<< "=====================" << std::endl;
	cout << "\t Ingredient :" << endl;
	for (int i = 0; i < ingredient.size(); i++) {
		showIngredient(i);
	}
	cout << "Cook Procedure : " << dishExplanation;
	cout << "\t========================"
		<< dishName
		<< "=====================" << std::endl;
	
}

void Recipe::showAllIngredient()
{
	cout << "\t======================== Ingredient List ====================" << endl;
	for (int i = 0; i < ingredient.size(); i++)
	{
		cout <<"\t" << (i+1) << ". Name : " << ingredient[i].getIngredientName() << endl;
		cout <<"\t" << "   Amount : " << ingredient[i].getAmount() << "g"<< endl;
	}

}
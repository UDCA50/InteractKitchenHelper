/*
* Recipe Method ����
* Created by �ſ���/������/�ֿ�ȣ


*  ������ �߰� ->
*/

#pragma once
#include"DataBase.h"


DataBase::DataBase()
{
	recipe.push_back(Recipe("��"));
	recipe[0].ingredientAdd("��", 100);
	recipe.push_back(Recipe("������"));
	recipe[1].ingredientAdd("���", 100);

}

//private ����
int DataBase::showNeedToDishReasearch()
{
	int check;
	cout << "*******�޴�����*******" << endl;
	// ���� �˻��� �޴����� ������ �����ִ� �ż��尡 �ʿ��ϴ�
	cout << "1. �˻���� ������ ��˻�" << endl;
	cout << "2. Ư�� ������ ����" << endl;
	cout << "3. ���θ޴��� ..." << endl;
	cout << "**********************" << endl;
	cout << " ���� >> ";
	cin >> check;
	cin.clear();
	cin.ignore(10000, '\n');
	return check;
}
void DataBase::dishResearch(vector<Recipe> tRecipe)
{
	string name;

	tempRecipe.clear();
	

	cout << "�˻��� �丮���� �Է��ϼ���. >> " << endl;
	cin >> name;
	//getline(cin, name);

	for (int i = 0; i < tRecipe.size(); i++)
	{
		if (tRecipe[i].getDishName().find(name) != string::npos)
		{
			tempRecipe.push_back(recipe[i]);
		}
	}

	cout << "***�˻����***" << endl;
	showAllRecipesList(tempRecipe);
	cout << endl;

}

void DataBase::ingredientResearch(vector<Recipe> tRecipe)
{
	
	string ingredient;
	tempRecipe.clear();
	cout << "�˻��� ������ �Է��ϼ��� >>" << endl;
	cin >> ingredient;

	for (int i = 0; i < tRecipe.size(); i++)
	{
		for (int j = 0; i < recipe[i].getIngredient().size(); j++)
		{

			if (tRecipe[i].getIngredient()[j].getIngredientName().find(ingredient) != string::npos)
			{
				tempRecipe.push_back(recipe[i]);
			}
		}
	}

	cout << "***�˻����***" << endl;
	showAllRecipesList(tempRecipe);
	cout << endl;

}
//public ����
void DataBase::addRecipe()
{
	string recipeName;
	int checkLoop=2;

	cout << "<<������ �߰��� �����մϴ�>>" << endl;
	cout << "�����Ǹ��� �Է��ϼ���. >> ";
	cin >> recipeName;
	cin.clear();
	cin.ignore(10000, '\n');
	//getline(cin, recipeName);
	recipe.push_back(Recipe(recipeName));

	while (1)
	{
		
		cout << "��Ḧ �߰��Ͻðڽ��ϱ�? " << endl;
		cout << "1.����߰�  2.�ƴϿ�. 3.���θ޴���..." << endl;
		cout << "���� >> ";
		cin >> checkLoop;
		cin.clear();
		cin.ignore(10000, '\n');

		if (checkLoop == 2)
			break;
		else if (checkLoop == 3)
			return;
		else if(checkLoop==1)
		{
			string ingredientName;
			int ingredientAmount;
			cout << "������ �Է��ϼ��� >> ";
			cin >> ingredientName;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "��ᷮ�� �Է��ϼ��� >> ";
			cin >> ingredientAmount;
			cin.clear();
			cin.ignore(10000, '\n');
			recipe[recipe.size() - 1].ingredientAdd(ingredientName, ingredientAmount);
			cout << "***���� �����***" << endl;
			recipe[recipe.size() - 1].showAllIngredient();
			cout << "******************" << endl;
		} 


	}
	cout << "�������� �߰��Ͻðڽ��ϱ�? " << endl;
	cout << "1.�߰� 2.���� �޴���..." << endl;
	cout << "���� >> ";
	cin >> checkLoop;

	cin.clear();
	cin.ignore(10000, '\n');
	if (checkLoop == 1) {
		string recipeOfDish;
		cout << "�������� �Է��ϼ��� >> ";
		cin >> recipeOfDish;
		cin.clear();
		cin.ignore(10000, '\n');
		recipe[recipe.size() - 1].setRecipeOfDish(recipeOfDish);
	}
	
	return;
}

void DataBase::modifyRecipe()
{
	modifyRecipe(recipe);
}
void DataBase::modifyRecipe(vector<Recipe> recipes)
{
	int choiceDish;
	int choiceMenu;
	cout << "****������ ����****" << endl;
	showAllRecipesList(recipes);
	cout << "******************" << endl;
	cout << "��� �����Ǹ� �����Ͻðڽ��ϱ�? (0: ���θ޴�)" << endl;
	cout << "���� >> "; cin >> choiceDish;

	cout << "***" << choiceDish << ". " << recipes[choiceDish - 1].getDishName() << "***" << endl;	//ex) ***1. ��***
	cout << "1.�丮�� ����   2.��� ����   3.������ ����    0.���� �޴���..." << endl;
	cin >> choiceMenu;

	switch (choiceMenu)
	{
	case 1:
	{
		string name;
		cout << "�����Ͻ� �丮���� �Է��ϼ��� >> ";
		cin >> name;
		for (int i = 0; i < recipe.size(); i++)
		{
			if (recipes[choiceDish - 1].getDishName().compare(recipe[i].getDishName()) == 0)
			{
				recipe[i].setDishName(name);
			}
		}
		
		cout << "�丮�� ������ �Ϸ�Ǿ����ϴ�." << endl;
		break;
	}
	case 2:
	{
		int choiceIngredient;
		recipes[choiceDish - 1].showAllIngredient();
		cout << "�� ��° ��Ḧ �����Ͻðڽðڽ��ϱ�? >> ";
		cin >> choiceIngredient;
		recipe[choiceDish - 1].ingredientModify(choiceIngredient-1);
		break;
	}
	case 3:
	{
		string recipeOfDish;
		cout << "������ �������� �Է��ϼ���. >> ";
		cin >> recipeOfDish;
		recipes[choiceDish - 1].setRecipeOfDish(recipeOfDish);
		break;
	}

	case 0:
		return;

	default:
	{
		cout << "�߸��� ����Դϴ�..." << endl;
		break;
	}
	}

}

void DataBase::showAllRecipesList()
{
	for (int i = 0; i < recipe.size();i++)
		cout << (i + 1) << ". : " << recipe[i].getDishName() << endl;
}
void DataBase::showAllRecipesList(vector<Recipe> recipes)
{
	for (int i = 0; i < recipes.size(); i++)
		cout << (i + 1) << ". : " << recipes[i].getDishName() << endl;
}

void DataBase::search()
{
	int choice=0;
	cout << "1.�丮������ �˻�    2.�������� �˻�    0.���� �޴���..." << endl;
	cout << "���� >> ";
	cin >> choice;
	cin.clear();
	cin.ignore(10000, '\n');

	switch (choice)
	{
	case 1:
	{
		dishSearch();
		break;
	}
	case 2:
	{
		ingredientSearch();
		break;
	}

	case 0:
	{
		return;
	}
	default:
	{
		cout << "�߸��� ����Դϴ�..." << endl;
		break;
	}
	}
}



void DataBase::dishSearch()
{
	int check=1;
	string name;

	cout << "�˻��� �丮���� �Է��ϼ���. >> " << endl;
	cin >> name;
	
	for (int i = 0; i < recipe.size(); i++)
	{
		if (recipe[i].getDishName().find(name) != string::npos)
		{
			tempRecipe.push_back(recipe[i]);
		}
	}
	
	cout << "***�˻����***" << endl;
	showAllRecipesList(tempRecipe);
	cout << endl;

	while (check)
	{
		check = showNeedToDishReasearch();
		if (check == 1)
		{
			dishResearch(tempRecipe);
		}
		else if (check == 2)
		{
			modifyRecipe(tempRecipe);
			return;
		}
		else if (check == 3)
		{
			tempRecipe.clear();
			return;
		}
	}
	
	
}



void DataBase::ingredientSearch()
{
	int check=1;
	string ingredient;
	
	cout << "�˻��� ������ �Է��ϼ��� >>" << endl;
	cin >> ingredient;
	
	for (int i = 0; i < recipe.size(); i++)
	{
		for (int j = 0; j < recipe[i].getIngredient().size(); j++)
		{
			if (recipe[i].getIngredient()[j].getIngredientName().find(ingredient) != string::npos)
			{
				tempRecipe.push_back(recipe[i]);
			}
		}
	}

		cout << "***�˻����***" << endl;
		showAllRecipesList(tempRecipe);
		cout << endl;
		while (check)
		{
			check = showNeedToDishReasearch();
			if (check == 1)
				ingredientResearch(tempRecipe);
			else if (check == 2)
			{
				modifyRecipe(tempRecipe);
				return;
			} else if (check == 3)
			{
				tempRecipe.clear();
				return;
			}
		}

	
}

void DataBase::deleteRecipe()
{
	int choice;
	cout << "****������ ����****" << endl;
	showAllRecipesList(recipe);
	cout << "�����Ͻ� �����Ǹ� �����ϼ��� (0: ���θ޴���...)";
	cout << " ���� >> ";
	cin >> choice;
	if (choice == 0)
		return;
	else deleteRecipe(choice);
}
void DataBase::deleteRecipe(int recipeNumber)
{
	recipe.erase(recipe.begin()+(recipeNumber-1));

	return;
}
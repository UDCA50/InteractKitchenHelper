/*
* Recipe Method ����
* Created by �ſ���/������/�ֿ�ȣ


*  ������ �߰� ->
*/

#pragma once
#include"DataBase.h"


DataBase::DataBase()
{
	recipeList.push_back(Recipe("��"));
	recipeList[0].addIngredient("��", 100);
	recipeList.push_back(Recipe("������"));
	recipeList[1].addIngredient("���", 100);

}

//private ����
int DataBase::selectSearchOption()
{
	int check;
	cout << endl;
	cout << "*******�޴�����*******" << endl;
	cout << "1. �˻���� ������ ��˻�" << endl;
	cout << "2. Ư�� ������ ����" << endl;
	cout << "3. ������ �󼼺���" << endl;
	cout << "4. ���θ޴��� ..." << endl;
	cout << "**********************" << endl;
	cout << "���� >> ";
	cin >> check;
	cout << endl;
	cin.clear();
	cin.ignore(10000, '\n');
	return check;
}

void DataBase::researchDish(vector<Recipe> tRecipe)
{
	string name;

	tempRecipeList.clear();	

	cout << "�˻��� �丮���� �Է��ϼ���. >> ";
	cin >> name;
	//getline(cin, name);

	for (int i = 0; i < tRecipe.size(); i++)
	{
		if (tRecipe[i].getDishName().find(name) != string::npos)
		{
			tempRecipeList.push_back(tRecipe[i]);
		}
	}

	cout << "***�˻����***" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;

}

void DataBase::researchIngredient(vector<Recipe> tRecipe)
{
	
	string ingredient;
	tempRecipeList.clear();
	cout << "�˻��� ������ �Է��ϼ��� >>" << endl;
	cin >> ingredient;

	for (int i = 0; i < tRecipe.size(); i++)
	{
		for (int j = 0; i < recipeList[i].getIngredient().size(); j++)
		{

			if (tRecipe[i].getIngredient()[j].getIngredientName().find(ingredient) != string::npos)
			{
				tempRecipeList.push_back(recipeList[i]);
			}
		}
	}

	cout << "***�˻����***" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;

}

int DataBase::findRecipeNumber(string recipeName)
{
	int i = 0;
	int maxVectorNum = recipeList.size();
	for (; i < maxVectorNum; i++) {
		if (recipeList[i].getDishName().compare(recipeName) == 0) {
			return i;
		}
	}

	return -1; //-1�� ���� �丮���� ���ٴ� ��!
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
	recipeList.push_back(Recipe(recipeName));

	while (1)
	{
		cout << "��Ḧ �߰��Ͻðڽ��ϱ�? " << endl;
		cout << "1.����߰�  2.�����ܰ�� . 3.���θ޴���..." << endl;
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
			recipeList[recipeList.size() - 1].addIngredient(ingredientName, ingredientAmount);
			cout << "***�߰��� �����***" << endl;
			recipeList[recipeList.size() - 1].showAllIngredient();
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
		string dishExplanation;
		cout << "�������� �Է��ϼ��� >> ";
		cin >> dishExplanation;
		cin.clear();
		cin.ignore(10000, '\n');
		recipeList[recipeList.size() - 1].setdishExplanation(dishExplanation);
	}
	
	return;
}

void DataBase::modifyRecipe()
{
	modifyRecipe(recipeList);
}

void DataBase::modifyRecipe(vector<Recipe> recipes)   //�˻��� �ϴٰ� �����ϱ� ��, tempRecipe������ �����϶�
{
	int choiceDish;
	int choiceMenu;
	cout << "****������ ����****" << endl;
	showAllRecipeList(recipes);
	cout << "******************" << endl;
	cout << "��� �����Ǹ� �����Ͻðڽ��ϱ�? (0: ���θ޴�)" << endl;
	cout << "���� >> "; cin >> choiceDish;

	if (choiceDish == 0) {
		tempRecipeList.clear();
		return;
	}

	cout << "***" << choiceDish << ". " << recipes[choiceDish - 1].getDishName() << "***" << endl;   //ex) ***1. ��***
	cout << "1.�丮�� ����   2.��� ����   3.������ ����    0.���� �޴���..." << endl;
	cout << "���� >> ";
	cin >> choiceMenu;

	switch (choiceMenu)
	{
	case 1:
	{
		string name;
		cout << "�����Ͻ� �丮���� �Է��ϼ��� >> ";
		cin >> name;
		for (int i = 0; i < recipeList.size(); i++)
		{
			if (recipes[choiceDish - 1].getDishName().compare(recipeList[i].getDishName()) == 0)
			{
				recipeList[i].setDishName(name);
			}
		}

		cout << "�丮�� ������ �Ϸ�Ǿ����ϴ�." << endl;
		break;
	}
	case 2:
	{
		int choiceIngredient;
		recipeList[choiceDish - 1].showAllIngredient();
		cout << "�� ��° ��Ḧ �����Ͻðڽðڽ��ϱ�? >> ";
		cin >> choiceIngredient;
		recipeList[choiceDish - 1].modifyIngredient(choiceIngredient - 1);
		break;
	}
	case 3:
	{
		string dishExplanation;
		cout << "������ �������� �Է��ϼ���. >> ";
		cin >> dishExplanation;
		for (int i = 0; i < recipeList.size(); i++)
		{
			if (recipes[choiceDish - 1].getDishName().compare(recipeList[i].getDishName()) == 0)
			{
				recipeList[i].setdishExplanation(dishExplanation);
			}
		}

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
void DataBase::searchRecipe()
{
	int choice = 0;
	cout << "1.�丮������ �˻�    2.�������� �˻�    0.���� �޴���..." << endl;
	cout << "���� >> ";
	cin >> choice;
	cin.clear();
	cin.ignore(10000, '\n');

	switch (choice)
	{
	case 1:
	{
		searchRecipebyName();
		break;
	}
	case 2:
	{
		searchRecipebyIngre();
		break;
	}

	case 0:
	{
		tempRecipeList.clear();
		return;
	}
	default:
	{
		cout << "�߸��� ����Դϴ�..." << endl;
		break;
	}
	}
}

void DataBase::searchRecipebyName()
{
	int check = 1;
	string name;

	cout << "�˻��� �丮���� �Է��ϼ���. >> ";
	cin >> name;

	for (int i = 0; i < recipeList.size(); i++)
	{
		if (recipeList[i].getDishName().find(name) != string::npos)
		{
			tempRecipeList.push_back(recipeList[i]);
		}
	}

	cout << "***�˻����***" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;

	while (check)
	{
		check = selectSearchOption();

		if (check == 1)
		{
			researchDish(tempRecipeList);
		} else if (check == 2)
		{
			modifyRecipe(tempRecipeList);
			return;
		} else if (check == 3) {
			selectOneRecipe(tempRecipeList);
			
		} else if (check == 4)
		{
			tempRecipeList.clear();
			return;
		}
	}


}
void DataBase::searchRecipebyIngre()
{
	int check = 1;
	string ingredient;

	cout << "�˻��� ������ �Է��ϼ��� >>" << endl;
	cin >> ingredient;

	for (int i = 0; i < recipeList.size(); i++)
	{
		for (int j = 0; j < recipeList[i].getIngredient().size(); j++)
		{
			if (recipeList[i].getIngredient()[j].getIngredientName().find(ingredient) != string::npos)
			{
				tempRecipeList.push_back(recipeList[i]);
			}
		}
	}

	cout << "***�˻����***" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;
	while (check)
	{
		check = selectSearchOption();
		if (check == 1)
			researchIngredient(tempRecipeList);
		else if (check == 2)
		{
			modifyRecipe(tempRecipeList);
			return;
		}
		else if (check == 3)
		{
			tempRecipeList.clear();
			return;
		}
	}


}

void DataBase::deleteRecipe()
{
	int choice;
	cout << "****������ ����****" << endl;
	showAllRecipeList(recipeList);
	cout << "�����Ͻ� �����Ǹ� �����ϼ��� (0: ���θ޴���...)";
	cout << " ���� >> ";
	cin >> choice;
	if (choice == 0)
		return;
	else deleteRecipe(choice);
}
void DataBase::deleteRecipe(int recipeNumber)
{
	recipeList.erase(recipeList.begin() + (recipeNumber - 1));

	return;
}



//show ����
void DataBase::selectOneRecipe(vector<Recipe> tRecipe)
{
	int choice;
	
	cout << "���� >> ";
	cin >> choice;

	showRecipeOfDish(tRecipe[choice-1].getDishName());
	
}

void DataBase::showRecipeOfDish(string dishName)
{
	int recipeNum;
	recipeNum = findRecipeNumber(dishName);

	if (recipeNum == -1)
		cout << "***��û�� �丮���� �����ϴ� " << endl << endl;

	cout << "�丮�� : " << recipeList[recipeNum].getDishName() << endl;
	recipeList[recipeNum].showAllIngredient();
	cout << "������ : " << recipeList[recipeNum].getRecipeOfDish() << endl << endl;

}
void DataBase::showAllRecipeList()
{

	for (int i = 0; i < recipeList.size();i++)
		cout << (i + 1) << ". : " << recipeList[i].getDishName() << endl;

	int choice;

	cout << endl;
	cout << "*********************" << endl;
	cout << "1.Ư�� ������ ���� " << endl;
	cout << "2. ���� �޴��� ..." << endl;
	cout << "*********************" << endl;
	cout << " ���� >> ";
	cin >> choice;
	if (choice == 1) selectOneRecipe(recipeList);
	else return;
	
}
void DataBase::showAllRecipeList(vector<Recipe> recipes)
{
	for (int i = 0; i < recipes.size(); i++)
		cout << (i + 1) << ". : " << recipes[i].getDishName() << endl;
}

string DataBase::selectOneRecipeName() //�丮 �̸� ��ȯmethod
{
	string forChangeMenu;
	int getNum = 0;
	showAllRecipeList();
	for (;;) {
		cout << "Menu ���� >> ";
		cin >> getNum;
		if (getNum == -1)
		{
			cout << "�߸��� �Է��Դϴ�.";
		}
		else
		{
			return recipeList[getNum - 1].getDishName();
		}
	}
}
 


void DataBase::saveDataBase() {

	FILE* recipefptr;
	recipefptr = fopen("saveRecipeData.txt", "w");
	for (int i = 0; i < recipeList.size(); i++) {

		Recipe myRecipe = recipeList.at(i);
		fprintf(recipefptr, "%s,%d,%s|", myRecipe.getDishName().c_str(),
			myRecipe.getIngredient().size(), myRecipe.getRecipeOfDish().c_str());

		for (int i = 0; i < myRecipe.getIngredient().size(); i++)  {
			fprintf(recipefptr, "%s,%d,", myRecipe.getIngredient().at(i).getIngredientName().c_str(),
				myRecipe.getIngredient().at(i).getAmount());

		}
		fprintf(recipefptr, "\n");
	}
	fclose(recipefptr);
}
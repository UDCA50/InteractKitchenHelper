/*
* Recipe Method ����
* Created by �ſ���/������/�ֿ�ȣ
*/

#pragma once
#include"DataBase.h"


DataBase::DataBase()
{
	recipe.push_back(Recipe("��"));
	recipe[0].ingredientAdd("��", 100);
}

//private ����
int DataBase::showNeedToDishReasearch()
{
	int check;
	cout << "*******�޴�����*******" << endl;
	cout << "1. ��˻�" << endl;
	cout << "2. Ư�� ������ ����" << endl;
	cout << "3. ���θ޴��� ..." << endl;
	cout << "**********************" << endl;
	cout << " ���� >> ";
	cin >> check;
	
	return check;
}

//public ����
void DataBase::addRecipe()
{
	string recipeName;
	int checkLoop;

	cout << "<<������ �߰��� �����մϴ�>>" << endl;
	cout << "�����Ǹ��� �Է��ϼ���. >> ";
	getline(cin, recipeName);
	recipe.push_back(Recipe(recipeName));

	while (1)
	{
		
		cout << "��Ḧ �߰��Ͻðڽ��ϱ�? " << endl;
		cout << "1.����߰�  2.���θ޴���...";
		cin >> checkLoop;
		if (checkLoop)
			return;
		else
		{
			string ingredientName;
			int ingredientAmount;
			cout << "������ �Է��ϼ��� >> ";
			getline(cin, ingredientName);
			cout << "��ᷮ�� �Է��ϼ��� >> ";
			cin >> ingredientAmount;
			recipe[recipe.size() - 1].ingredientAdd(ingredientName, ingredientAmount);
			cout << "***���� �����***" << endl;
			recipe[recipe.size() - 1].showAllIngredient();
			cout << "******************" << endl;
		}


	}
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
		getline(cin, name);
		recipes[choiceDish - 1].setDishName(name);
		cout << "�丮�� ������ �Ϸ�Ǿ����ϴ�." << endl;
		break;
	}
	case 2:
	{
		int choiceIngredient;
		recipes[choiceDish - 1].showAllIngredient();
		cout << "�� ��° ��Ḧ �����Ͻðڽðڽ��ϱ�? >> ";
		cin >> choiceIngredient;
		recipe[choiceDish - 1].ingredientModify(choiceIngredient);
		break;
	}
	case 3:
	{
		string recipeOfDish;
		cout << "������ �������� �Է��ϼ���. >> ";
		getline(cin, recipeOfDish);
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


void DataBase::showAllRecipesList(vector<Recipe> recipes)
{
	for (int i = 0; i < recipes.size(); i++)
		cout << (i + 1) << ". : " << recipes[i].getDishName() << endl;
}

void DataBase::search()
{
	int choice;
	cout << "1.�丮������ �˻�    2.�������� �˻�    0.���� �޴���..." << endl;
	cout << "���� >> ";
	cin >> choice;
	
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
	while (check) {


		cout << "�˻��� �丮���� �Է��ϼ���. >> " << endl;
		getline(cin, name);

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
		check = showNeedToDishReasearch();
		if (check == 1)
			continue;
		else if (check == 2)
			modifyRecipe(tempRecipe);
		else if (check == 3)
		{
			tempRecipe.clear();
			return;
		}
			
	}
	
}

void DataBase::ingredientSearch()
{
	int check;
	string ingredient;
	while (check)
	{


		cout << "�˻��� ������ �Է��ϼ��� >>" << endl;
		getline(cin, ingredient);

		for (int i = 0; i < recipe.size(); i++)
		{
			for (int j = 0; i < recipe[i].getIngredient().size(); j++)
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
		check = showNeedToDishReasearch();
		if (check == 1)
			continue;
		else if (check == 2)
			modifyRecipe(tempRecipe);
		else if (check == 3)
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
	if (choice == 0)
		return;
	else deleteRecipe(choice);
}
void DataBase::deleteRecipe(int recipeNumber)
{
	recipe.erase(recipe.begin()+(recipeNumber-1));
}
/*
void DataBase::addRecipe() {
		char* makeNewRecipe;
		char* dicision = new char[4];
		cout << "�����Ǹ� �߰��մϴ�." << endl;
		cout << "�����Ǹ� ���� �޴����� �Է��ϼ��� : ";
		cin >> makeNewRecipe;
		Recipe myRecipe(makeNewRecipe);
		recipe.push_back(myRecipe);
		recipeCount++;
		//recipeCount ���� �����ϴ� Recipe ���� �����ϰ� �ٲپ���� 


		cout << "��Ḧ �߰��Ͻðڽ��ϱ�? Yes/No";
		cin >> dicision;
		if (strcmp(dicision,"Yes")){
			int exit = 0;
			char* name;
			int amount;
			cout << "������ -1�� �Է��ϸ� ����˴ϴ�." << endl;
			while(exit != -1){
				cout << "����� �̸�.(ex : ���� 60)" << endl;
				cin >> name;
				cout << ", ������ ���ʴ�� �Է��ϼ���" << endl;
				cin >> amount;
				recipe[recipeCount-1].ingredientAdd(name, amount);
				if (amount == -1){
					exit = -1;
				}
			}

		}
		else{ //�ϴ��� No�� �ԷµǸ� �ش� �Լ� exit
			return;
		}

		//recipe[recipeCount-1].recipeOfDishAdd(makeNewRecipe);
		//��recipe�� �ش� �Լ��� ������ ���� ����


	}											//������ �߰� ����
	//�̸��� �Է¹޾Ƽ� recipe[num].Recipe(name);
	//��Ḧ �߰��Ұ������� ���θ� ����� �߰��ϸ�
	//recipe[count].ingredientAdd(name, amount)!!<-�ݺ�
	//������ �߰� recipe[count].recipeOfDishAdd(recipeOfDish);

DataBase::DataBase(){
	recipeCount = 0;
}

void DataBase::modifyRecipe(){
	int wantResetNum;
	int resetMenuNum;
	char* resetDishName;
	int numberOfDish = 0;
	for (int i = 0; i< this->recipe.size(); i++){
		//showAllRecipeInformation(i);
		// ���Լ������� �ȵ�����
	}

	cout << "�����ϰ� ���� �������� ��ȣ�� �Է��ϼ��� :";
	cin >> wantResetNum;
	cout << "�����ϰ� ���� �޴��� �Է��ϼ���" << endl << "1.������ �̸� ����" << "2.��� ����" << endl << "3.������ ����";
	cin >> resetMenuNum;
	if (resetMenuNum == 1){
		cout << "�缳�� �� �������� �̸��� �Է��ϼ��� :";
		cin >> resetDishName;
		recipe[wantResetNum].setDishName(resetDishName);
	}
	else if (resetMenuNum == 2){
		int resetNum;
		for (int i = 0; i< this->recipe.size(); i++){
			cout << i << ". ";
			//cout << showIngredient(i) << endl
			//�� showIngredient() �� ������ ���� ����
		}

		cout << "������ ����� ��ȣ�� �Է��ϼ��� :";
		cin >> resetNum;
		//recipe[wantResetNum].IngredientModify(resetNum);
		//�� IngredientModify() �� ������ ���� ����
	}
	else if (resetMenuNum == 3){
		char* newRecipe;
		cout << "�ٽ� ������ �������� �Է��ϼ��� : ";
		cin >> newRecipe;
		recipe[resetMenuNum].setRecipeOfDish(newRecipe);
	}
	else{
		cout << "�߸��� �Է��Դϴ�." << endl;
	}
	
}
//������ ����
//��� ������ �̸� ��� for�� showAllRecipes();
//���° ���������� ����
//�̸��� ����(�ش� ������ �����ǿ� ���� ���� ��ü ���)
//1.�̸� ����-> recipe[num].setDishName(name)
//2.��� ����-> ���° ������� ����
//recipe[num].IngredientModify(ingredientnumber);
//3.������ ����-> recipe[num].setRecipeOfDish(recipeOfDish);


//show ����
void showAllRecipesList(){

}//��� �����Ǹ���Ʈ �����ֱ�


//������ method����
char* dishSearch(char* search){


}//��ġ �� showNeedToReaserch();

char* ingredientSearch(char* search){

}//��ġ �� showNeedToReasearch();

void deleteRecipe(int recipeNumber){


}//������ ����
*/

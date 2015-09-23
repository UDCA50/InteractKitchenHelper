/*
* Recipe Method 구현
* Created by 신영현/남성준/최연호


*  레서피 추가 ->
*/

#pragma once
#include"DataBase.h"


DataBase::DataBase()
{
	recipeList.push_back(Recipe("밥"));
	recipeList[0].addIngredient("밥", 100);
	recipeList.push_back(Recipe("계란라면"));
	recipeList[1].addIngredient("계란", 100);

}

//private 영역
int DataBase::selectSearchOption()
{
	int check;
	cout << endl;
	cout << "*******메뉴선택*******" << endl;
	cout << "1. 검색결과 내에서 재검색" << endl;
	cout << "2. 특정 레시피 수정" << endl;
	cout << "3. 레시피 상세보기" << endl;
	cout << "4. 메인메뉴로 ..." << endl;
	cout << "**********************" << endl;
	cout << "선택 >> ";
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

	cout << "검색할 요리명을 입력하세요. >> ";
	cin >> name;
	//getline(cin, name);

	for (int i = 0; i < tRecipe.size(); i++)
	{
		if (tRecipe[i].getDishName().find(name) != string::npos)
		{
			tempRecipeList.push_back(tRecipe[i]);
		}
	}

	cout << "***검색결과***" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;

}

void DataBase::researchIngredient(vector<Recipe> tRecipe)
{
	
	string ingredient;
	tempRecipeList.clear();
	cout << "검색할 재료명을 입력하세요 >>" << endl;
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

	cout << "***검색결과***" << endl;
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

	return -1; //-1은 같은 요리명이 없다는 것!
}

//public 영역
void DataBase::addRecipe()
{
	string recipeName;
	int checkLoop=2;

	cout << "<<레시피 추가를 시작합니다>>" << endl;
	cout << "레시피명을 입력하세요. >> ";
	cin >> recipeName;
	cin.clear();
	cin.ignore(10000, '\n');
	//getline(cin, recipeName);
	recipeList.push_back(Recipe(recipeName));

	while (1)
	{
		cout << "재료를 추가하시겠습니까? " << endl;
		cout << "1.재료추가  2.다음단계로 . 3.메인메뉴로..." << endl;
		cout << "선택 >> ";
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
			cout << "재료명을 입력하세요 >> ";
			cin >> ingredientName;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "재료량을 입력하세요 >> ";
			cin >> ingredientAmount;
			cin.clear();
			cin.ignore(10000, '\n');
			recipeList[recipeList.size() - 1].addIngredient(ingredientName, ingredientAmount);
			cout << "***추가된 재료목록***" << endl;
			recipeList[recipeList.size() - 1].showAllIngredient();
			cout << "******************" << endl;
		} 


	}
	cout << "조리법을 추가하시겠습니까? " << endl;
	cout << "1.추가 2.메인 메뉴로..." << endl;
	cout << "선택 >> ";
	cin >> checkLoop;
	cin.clear();
	cin.ignore(10000, '\n');


	if (checkLoop == 1) {
		string dishExplanation;
		cout << "조리법을 입력하세요 >> ";
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

void DataBase::modifyRecipe(vector<Recipe> recipes)   //검색을 하다가 수정하기 즉, tempRecipe에서의 수정일때
{
	int choiceDish;
	int choiceMenu;
	cout << "****레시피 수정****" << endl;
	showAllRecipeList(recipes);
	cout << "******************" << endl;
	cout << "어느 레시피를 수정하시겠습니까? (0: 메인메뉴)" << endl;
	cout << "선택 >> "; cin >> choiceDish;

	if (choiceDish == 0) {
		tempRecipeList.clear();
		return;
	}

	cout << "***" << choiceDish << ". " << recipes[choiceDish - 1].getDishName() << "***" << endl;   //ex) ***1. 밥***
	cout << "1.요리명 수정   2.재료 수정   3.조리법 수정    0.메인 메뉴로..." << endl;
	cout << "선택 >> ";
	cin >> choiceMenu;

	switch (choiceMenu)
	{
	case 1:
	{
		string name;
		cout << "변경하실 요리명을 입력하세요 >> ";
		cin >> name;
		for (int i = 0; i < recipeList.size(); i++)
		{
			if (recipes[choiceDish - 1].getDishName().compare(recipeList[i].getDishName()) == 0)
			{
				recipeList[i].setDishName(name);
			}
		}

		cout << "요리명 변경이 완료되었습니다." << endl;
		break;
	}
	case 2:
	{
		int choiceIngredient;
		recipeList[choiceDish - 1].showAllIngredient();
		cout << "몇 번째 재료를 수정하시겠시겠습니까? >> ";
		cin >> choiceIngredient;
		recipeList[choiceDish - 1].modifyIngredient(choiceIngredient - 1);
		break;
	}
	case 3:
	{
		string dishExplanation;
		cout << "변경할 조리법을 입력하세요. >> ";
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
		cout << "잘못된 경로입니다..." << endl;
		break;
	}
	}
}
void DataBase::searchRecipe()
{
	int choice = 0;
	cout << "1.요리명으로 검색    2.재료명으로 검색    0.메인 메뉴로..." << endl;
	cout << "선택 >> ";
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
		cout << "잘못된 경로입니다..." << endl;
		break;
	}
	}
}

void DataBase::searchRecipebyName()
{
	int check = 1;
	string name;

	cout << "검색할 요리명을 입력하세요. >> ";
	cin >> name;

	for (int i = 0; i < recipeList.size(); i++)
	{
		if (recipeList[i].getDishName().find(name) != string::npos)
		{
			tempRecipeList.push_back(recipeList[i]);
		}
	}

	cout << "***검색결과***" << endl;
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

	cout << "검색할 재료명을 입력하세요 >>" << endl;
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

	cout << "***검색결과***" << endl;
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
	cout << "****레시피 삭제****" << endl;
	showAllRecipeList(recipeList);
	cout << "삭제하실 레시피를 선택하세요 (0: 메인메뉴로...)";
	cout << " 선택 >> ";
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



//show 영역
void DataBase::selectOneRecipe(vector<Recipe> tRecipe)
{
	int choice;
	
	cout << "선택 >> ";
	cin >> choice;

	showRecipeOfDish(tRecipe[choice-1].getDishName());
	
}

void DataBase::showRecipeOfDish(string dishName)
{
	int recipeNum;
	recipeNum = findRecipeNumber(dishName);

	if (recipeNum == -1)
		cout << "***요청한 요리명이 없습니다 " << endl << endl;

	cout << "요리명 : " << recipeList[recipeNum].getDishName() << endl;
	recipeList[recipeNum].showAllIngredient();
	cout << "조리법 : " << recipeList[recipeNum].getRecipeOfDish() << endl << endl;

}
void DataBase::showAllRecipeList()
{

	for (int i = 0; i < recipeList.size();i++)
		cout << (i + 1) << ". : " << recipeList[i].getDishName() << endl;

	int choice;

	cout << endl;
	cout << "*********************" << endl;
	cout << "1.특정 레시피 보기 " << endl;
	cout << "2. 메인 메뉴로 ..." << endl;
	cout << "*********************" << endl;
	cout << " 선택 >> ";
	cin >> choice;
	if (choice == 1) selectOneRecipe(recipeList);
	else return;
	
}
void DataBase::showAllRecipeList(vector<Recipe> recipes)
{
	for (int i = 0; i < recipes.size(); i++)
		cout << (i + 1) << ". : " << recipes[i].getDishName() << endl;
}

string DataBase::selectOneRecipeName() //요리 이름 반환method
{
	string forChangeMenu;
	int getNum = 0;
	showAllRecipeList();
	for (;;) {
		cout << "Menu 선택 >> ";
		cin >> getNum;
		if (getNum == -1)
		{
			cout << "잘못된 입력입니다.";
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
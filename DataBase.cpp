/*
* Recipe Method 구현
* Created by 신영현/남성준/최연호


*  레서피 추가 ->
*/

#pragma once
#include"DataBase.h"


DataBase::DataBase()
{
	recipe.push_back(Recipe("밥"));
	recipe[0].ingredientAdd("밥", 100);
	recipe.push_back(Recipe("계란라면"));
	recipe[1].ingredientAdd("계란", 100);

}

//private 영역
int DataBase::showNeedToDishReasearch()
{
	int check;
	cout << "*******메뉴선택*******" << endl;
	// 현재 검색된 메뉴들의 내용을 보여주는 매서드가 필요하다
	cout << "1. 검색결과 내에서 재검색" << endl;
	cout << "2. 특정 레시피 수정" << endl;
	cout << "3. 메인메뉴로 ..." << endl;
	cout << "**********************" << endl;
	cout << " 선택 >> ";
	cin >> check;
	cin.clear();
	cin.ignore(10000, '\n');
	return check;
}
void DataBase::dishResearch(vector<Recipe> tRecipe)
{
	string name;

	tempRecipe.clear();
	

	cout << "검색할 요리명을 입력하세요. >> " << endl;
	cin >> name;
	//getline(cin, name);

	for (int i = 0; i < tRecipe.size(); i++)
	{
		if (tRecipe[i].getDishName().find(name) != string::npos)
		{
			tempRecipe.push_back(recipe[i]);
		}
	}

	cout << "***검색결과***" << endl;
	showAllRecipesList(tempRecipe);
	cout << endl;

}

void DataBase::ingredientResearch(vector<Recipe> tRecipe)
{
	
	string ingredient;
	tempRecipe.clear();
	cout << "검색할 재료명을 입력하세요 >>" << endl;
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

	cout << "***검색결과***" << endl;
	showAllRecipesList(tempRecipe);
	cout << endl;

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
	recipe.push_back(Recipe(recipeName));

	while (1)
	{
		
		cout << "재료를 추가하시겠습니까? " << endl;
		cout << "1.재료추가  2.아니요. 3.메인메뉴로..." << endl;
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
			recipe[recipe.size() - 1].ingredientAdd(ingredientName, ingredientAmount);
			cout << "***현재 재료목록***" << endl;
			recipe[recipe.size() - 1].showAllIngredient();
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
		string recipeOfDish;
		cout << "조리법을 입력하세요 >> ";
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
	cout << "****레시피 수정****" << endl;
	showAllRecipesList(recipes);
	cout << "******************" << endl;
	cout << "어느 레시피를 수정하시겠습니까? (0: 메인메뉴)" << endl;
	cout << "선택 >> "; cin >> choiceDish;

	cout << "***" << choiceDish << ". " << recipes[choiceDish - 1].getDishName() << "***" << endl;	//ex) ***1. 밥***
	cout << "1.요리명 수정   2.재료 수정   3.조리법 수정    0.메인 메뉴로..." << endl;
	cin >> choiceMenu;

	switch (choiceMenu)
	{
	case 1:
	{
		string name;
		cout << "변경하실 요리명을 입력하세요 >> ";
		cin >> name;
		for (int i = 0; i < recipe.size(); i++)
		{
			if (recipes[choiceDish - 1].getDishName().compare(recipe[i].getDishName()) == 0)
			{
				recipe[i].setDishName(name);
			}
		}
		
		cout << "요리명 변경이 완료되었습니다." << endl;
		break;
	}
	case 2:
	{
		int choiceIngredient;
		recipes[choiceDish - 1].showAllIngredient();
		cout << "몇 번째 재료를 수정하시겠시겠습니까? >> ";
		cin >> choiceIngredient;
		recipe[choiceDish - 1].ingredientModify(choiceIngredient-1);
		break;
	}
	case 3:
	{
		string recipeOfDish;
		cout << "변경할 조리법을 입력하세요. >> ";
		cin >> recipeOfDish;
		recipes[choiceDish - 1].setRecipeOfDish(recipeOfDish);
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
	cout << "1.요리명으로 검색    2.재료명으로 검색    0.메인 메뉴로..." << endl;
	cout << "선택 >> ";
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
		cout << "잘못된 경로입니다..." << endl;
		break;
	}
	}
}



void DataBase::dishSearch()
{
	int check=1;
	string name;

	cout << "검색할 요리명을 입력하세요. >> " << endl;
	cin >> name;
	
	for (int i = 0; i < recipe.size(); i++)
	{
		if (recipe[i].getDishName().find(name) != string::npos)
		{
			tempRecipe.push_back(recipe[i]);
		}
	}
	
	cout << "***검색결과***" << endl;
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
	
	cout << "검색할 재료명을 입력하세요 >>" << endl;
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

		cout << "***검색결과***" << endl;
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
	cout << "****레시피 삭제****" << endl;
	showAllRecipesList(recipe);
	cout << "삭제하실 레시피를 선택하세요 (0: 메인메뉴로...)";
	cout << " 선택 >> ";
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
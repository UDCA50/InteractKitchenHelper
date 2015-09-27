#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"DataBase.h"


DataBase::DataBase()
{
	
}

//private 영역
int DataBase::selectSearchOption()
{
	int check;
	cout << endl;
	cout << "\t======================== Select Sub-Option =====================" << endl;
	cout << "\t1.Re-Search in Result \t 2.modify Reicpe" << endl;
	cout << "\t3.See Recipe Detail \t 4.back to Main" << endl;
	cout << "\tOption>> ";
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

	cout << "\tRecipe Name ?>> ";
	cin >> name;
	
	for ( unsigned int recipIter = 0; recipIter < tRecipe.size(); recipIter++)
	{
		if (tRecipe[recipIter].getDishName().find(name) != string::npos)
		{
			tempRecipeList.push_back(tRecipe[recipIter]);
		}
	}

	system("cls");
	cout << "\t======================== Search Result =====================" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;

}

void DataBase::researchIngredient(vector<Recipe> tRecipe)
{
	
	string ingredient;
	tempRecipeList.clear();
	cout << "\tIngredient Name ? >> ";
	cin >> ingredient;

	for (unsigned int recipIter = 0; recipIter < tRecipe.size(); recipIter++)
	{
		for (unsigned int ingreIter = 0; ingreIter < tRecipe[recipIter].getIngredient().size(); ingreIter++)
		{

			if (tRecipe[recipIter].getIngredient()[ingreIter].getIngredientName().find(ingredient) != string::npos)
			{
				tempRecipeList.push_back(tRecipe[recipIter]);
			}
		}
	}

	cout << "\t======================== reSearch Result =====================" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;
}
//여기까지 수정함

int DataBase::findRecipeNumber(string recipeName)
{
	int maxVectorNum = recipeList.size();
	for ( int recipIter = 0 ; recipIter < maxVectorNum; recipIter++) {
		if (recipeList[recipIter].getDishName().compare(recipeName) == 0) {
			return recipIter;
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
	system("cls");
	std::cout << endl;
	std::cout << endl;
	std::cout << "\t========================modify Recipe=====================" << std::endl;
	showAllRecipeList(recipes);
	cout << "\tSelect Recipe(0: back to Main)>> ";
	cin >> choiceDish;

	if (choiceDish == 0) {
		tempRecipeList.clear();
		return;
	}

	system("cls");
	cout << "\t========================" << choiceDish << ". " << recipes[choiceDish - 1].getDishName() 
		 << "========================" << endl;
	//checkPoint ★
	cout << "\t 1.change Recipe Name\t\t2.change Ingredient" << endl;
	cout << "\t 3.change Introduction\t\t 0.Back to Main" << endl;
	cout << "\tSelectOption >> ";
	cin >> choiceMenu;

	switch (choiceMenu)
	{
	case 1:
	{
		string name;
		cout << "\tInput New Name>> ";
		cin >> name;
		for (unsigned int recipIter = 0; recipIter < recipeList.size(); recipIter++)
		{
			if (recipes[choiceDish - 1].getDishName().compare(recipeList[recipIter].getDishName()) == 0)
			{
				recipeList[recipIter].setDishName(name);
			}
		}
		system("cls");
		cout << endl;
		cout << endl;
		cout << "\t======================== change Complete ====================" << endl;
		break;
	}
	case 2:
	{
		int choiceIngredient;
		recipeList[choiceDish - 1].showAllIngredient();
		cout << "\tSelect Ingredient Number >> ";
		cin >> choiceIngredient;
		recipeList[choiceDish - 1].modifyIngredient(choiceIngredient - 1);
		break;
	}
	case 3:
	{
		string dishExplanation;
		cout << "변경할 조리법을 입력하세요. >> ";
		cin >> dishExplanation;
		for (unsigned int recipIter = 0; recipIter < recipeList.size(); recipIter++)
		{
			if (recipes[choiceDish - 1].getDishName().compare(recipeList[recipIter].getDishName()) == 0)
			{
				recipeList[recipIter].setdishExplanation(dishExplanation);
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
	system("cls");
	std::cout << endl;
	std::cout << endl;
	std::cout << "\t========================Seacrh Recipe=====================" << std::endl;
	cout << "\t1. search by Name\t\t2.search by Ingredient" << endl;
	std::cout << endl;
	cout << "\t0.back to main menu" << endl;
	std::cout << "\t========================Seacrh Recipe=====================" << std::endl;
	cout << "\tSearch>> ";
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

	cout << "\tInput Recipe Name>> ";
	cin >> name;

	for (unsigned int recipIter = 0; recipIter < recipeList.size(); recipIter++)
	{
		if (recipeList[recipIter].getDishName().find(name) != string::npos)
		{
			tempRecipeList.push_back(recipeList[recipIter]);
		}
	}

	system("cls");
	cout << "\t======================== Search Result =====================" << endl;
	showAllRecipeList(tempRecipeList);
	cout << endl;

	while (check)
	{
		check = selectSearchOption();

		if (check == 1){
			researchDish(tempRecipeList);
		} 
		else if (check == 2){
			modifyRecipe(tempRecipeList);
			return;
		}
		else if (check == 3) {
			selectOneRecipe(tempRecipeList);
			
		} 
		else if (check == 4){
			tempRecipeList.clear();
			return;
		}
	}


}
void DataBase::searchRecipebyIngre()
{
	int check = 1;
	string ingredient;

	cout << "\tInput Ingredient Name>> ";
	cin >> ingredient;

	for (unsigned int recipIter = 0; recipIter < recipeList.size(); recipIter++)
	{
		for (unsigned int ingreIter = 0; ingreIter < recipeList[recipIter].getIngredient().size(); ingreIter++)
		{
			if (recipeList[recipIter].getIngredient()[ingreIter].getIngredientName().find(ingredient) != string::npos)
			{
				tempRecipeList.push_back(recipeList[recipIter]);
			}
		}
	
	}
	system("cls");
	cout << "\t======================== Search Result =====================" << endl;
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

	for (unsigned int recipIter = 0; recipIter < recipeList.size();recipIter++)
		cout << (recipIter + 1) << ". : " << recipeList[recipIter].getDishName() << endl;

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
	int recipeCount = 0;
	for (unsigned int recipIter = 0; recipIter < recipes.size(); recipIter++){
		cout << "\t" << (recipIter + 1) << ". : " << recipes[recipIter].getDishName() << endl;
		recipeCount++;
	}
	if (recipeCount == 0) {
		cout << "\t" << "NO Result" << endl;
	}
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
	for (unsigned int recipIter = 0; recipIter < recipeList.size(); recipIter++) {

		Recipe myRecipe = recipeList.at(recipIter);
		fprintf(recipefptr, "%d,%s,%s,|", myRecipe.getIngredient().size(), myRecipe.getDishName().c_str(),
			myRecipe.getRecipeOfDish().c_str());

		for (unsigned int ingreIter = 0; ingreIter < myRecipe.getIngredient().size(); ingreIter++)  {
			fprintf(recipefptr, "%s|%d|", myRecipe.getIngredient().at(ingreIter).getIngredientName().c_str(),
				myRecipe.getIngredient().at(ingreIter).getAmount());
		}
		fprintf(recipefptr, "\n");
	}
	fclose(recipefptr);
}
void DataBase::setRecipe(Recipe myrecipe) { // 09.24 추가함수 interface에서 레시피명 추가하기 위함
	recipeList.push_back(myrecipe);
}

void DataBase::clearTempRecipe(){
	this->tempRecipeList.clear();
}
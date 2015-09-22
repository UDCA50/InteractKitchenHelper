/*
* Recipe Method 구현
* Created by 신영현/남성준/최연호
*/

#pragma once
#include"DataBase.h"


DataBase::DataBase()
{
	recipe.push_back(Recipe("밥"));
	recipe[0].ingredientAdd("밥", 100);
}

//private 영역
int DataBase::showNeedToDishReasearch()
{
	int check;
	cout << "*******메뉴선택*******" << endl;
	cout << "1. 재검색" << endl;
	cout << "2. 특정 레시피 수정" << endl;
	cout << "3. 메인메뉴로 ..." << endl;
	cout << "**********************" << endl;
	cout << " 선택 >> ";
	cin >> check;
	
	return check;
}

//public 영역
void DataBase::addRecipe()
{
	string recipeName;
	int checkLoop;

	cout << "<<레시피 추가를 시작합니다>>" << endl;
	cout << "레시피명을 입력하세요. >> ";
	getline(cin, recipeName);
	recipe.push_back(Recipe(recipeName));

	while (1)
	{
		
		cout << "재료를 추가하시겠습니까? " << endl;
		cout << "1.재료추가  2.메인메뉴로...";
		cin >> checkLoop;
		if (checkLoop)
			return;
		else
		{
			string ingredientName;
			int ingredientAmount;
			cout << "재료명을 입력하세요 >> ";
			getline(cin, ingredientName);
			cout << "재료량을 입력하세요 >> ";
			cin >> ingredientAmount;
			recipe[recipe.size() - 1].ingredientAdd(ingredientName, ingredientAmount);
			cout << "***현재 재료목록***" << endl;
			recipe[recipe.size() - 1].showAllIngredient();
			cout << "******************" << endl;
		}


	}
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
		getline(cin, name);
		recipes[choiceDish - 1].setDishName(name);
		cout << "요리명 변경이 완료되었습니다." << endl;
		break;
	}
	case 2:
	{
		int choiceIngredient;
		recipes[choiceDish - 1].showAllIngredient();
		cout << "몇 번째 재료를 수정하시겠시겠습니까? >> ";
		cin >> choiceIngredient;
		recipe[choiceDish - 1].ingredientModify(choiceIngredient);
		break;
	}
	case 3:
	{
		string recipeOfDish;
		cout << "변경할 조리법을 입력하세요. >> ";
		getline(cin, recipeOfDish);
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


void DataBase::showAllRecipesList(vector<Recipe> recipes)
{
	for (int i = 0; i < recipes.size(); i++)
		cout << (i + 1) << ". : " << recipes[i].getDishName() << endl;
}

void DataBase::search()
{
	int choice;
	cout << "1.요리명으로 검색    2.재료명으로 검색    0.메인 메뉴로..." << endl;
	cout << "선택 >> ";
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
		cout << "잘못된 경로입니다..." << endl;
		break;
	}
	}
}

void DataBase::dishSearch()
{
	int check=1;
	string name;
	while (check) {


		cout << "검색할 요리명을 입력하세요. >> " << endl;
		getline(cin, name);

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


		cout << "검색할 재료명을 입력하세요 >>" << endl;
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

		cout << "***검색결과***" << endl;
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
	cout << "****레시피 삭제****" << endl;
	showAllRecipesList(recipe);
	cout << "삭제하실 레시피를 선택하세요 (0: 메인메뉴로...)";
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
		cout << "레시피를 추가합니다." << endl;
		cout << "레시피를 만들 메뉴명을 입력하세요 : ";
		cin >> makeNewRecipe;
		Recipe myRecipe(makeNewRecipe);
		recipe.push_back(myRecipe);
		recipeCount++;
		//recipeCount 값을 수정하는 Recipe 값과 동일하게 바꾸어야함 


		cout << "재료를 추가하시겠습니까? Yes/No";
		cin >> dicision;
		if (strcmp(dicision,"Yes")){
			int exit = 0;
			char* name;
			int amount;
			cout << "수량을 -1을 입력하면 종료됩니다." << endl;
			while(exit != -1){
				cout << "재료의 이름.(ex : 마늘 60)" << endl;
				cin >> name;
				cout << ", 수량을 차례대로 입력하세요" << endl;
				cin >> amount;
				recipe[recipeCount-1].ingredientAdd(name, amount);
				if (amount == -1){
					exit = -1;
				}
			}

		}
		else{ //일단은 No가 입력되면 해당 함수 exit
			return;
		}

		//recipe[recipeCount-1].recipeOfDishAdd(makeNewRecipe);
		//★recipe에 해당 함수가 구현되 있지 않음


	}											//레시피 추가 영역
	//이름을 입력받아서 recipe[num].Recipe(name);
	//재료를 추가할것인지의 여부를 물어본뒤 추가하면
	//recipe[count].ingredientAdd(name, amount)!!<-반복
	//조리법 추가 recipe[count].recipeOfDishAdd(recipeOfDish);

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
		// ★함수구현이 안되있음
	}

	cout << "수정하고 싶은 레시피의 번호를 입력하세요 :";
	cin >> wantResetNum;
	cout << "수정하고 싶은 메뉴를 입력하세요" << endl << "1.레시피 이름 수정" << "2.재료 수정" << endl << "3.조리법 수정";
	cin >> resetMenuNum;
	if (resetMenuNum == 1){
		cout << "재설정 할 레시피의 이름을 입력하세요 :";
		cin >> resetDishName;
		recipe[wantResetNum].setDishName(resetDishName);
	}
	else if (resetMenuNum == 2){
		int resetNum;
		for (int i = 0; i< this->recipe.size(); i++){
			cout << i << ". ";
			//cout << showIngredient(i) << endl
			//★ showIngredient() 가 구현되 있지 않음
		}

		cout << "수정할 재료의 번호를 입력하세요 :";
		cin >> resetNum;
		//recipe[wantResetNum].IngredientModify(resetNum);
		//★ IngredientModify() 가 구현되 있지 않음
	}
	else if (resetMenuNum == 3){
		char* newRecipe;
		cout << "다시 설정할 조리법을 입력하세요 : ";
		cin >> newRecipe;
		recipe[resetMenuNum].setRecipeOfDish(newRecipe);
	}
	else{
		cout << "잘못된 입력입니다." << endl;
	}
	
}
//레시피 수정
//모든 레시피 이름 출력 for문 showAllRecipes();
//몇번째 레시피인지 묻고
//이름과 재료명(해당 선택한 레시피에 대한 정보 전체 출력)
//1.이름 수정-> recipe[num].setDishName(name)
//2.재료 수정-> 몇번째 재료인지 묻고
//recipe[num].IngredientModify(ingredientnumber);
//3.조리법 수정-> recipe[num].setRecipeOfDish(recipeOfDish);


//show 영역
void showAllRecipesList(){

}//모든 레시피리스트 보여주기


//실질적 method영역
char* dishSearch(char* search){


}//서치 후 showNeedToReaserch();

char* ingredientSearch(char* search){

}//서치 후 showNeedToReasearch();

void deleteRecipe(int recipeNumber){


}//레시피 삭제
*/

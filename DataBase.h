#pragma once
#include "Recipe.h"

class DataBase{
private:
	vector<Recipe> recipeList;		// 여러 레서피 정보를 저장한 DB
	vector<Recipe> tempRecipeList;  // 검색된 레서피 정보를 임시저장하는 DB
	
	void searchRecipebyName();      			//이름으로 레서피 검색 매소드
	void searchRecipebyIngre(); 			//재료로 레서피 검색
	void deleteRecipe(int recipeNumber);	//특정 레서피를 삭제

	int selectSearchOption();   //레서피검색후 추가동작을 입력받는 매소드

	void researchDish(vector<Recipe> tRecipe);	//요리명을 재검색하는 매소드
	void researchIngredient(vector<Recipe> tRecipe);	//재료를 재검색하는 매소드
	
	int findRecipeNumber(string recipeName);		//해당이름의 레서피를 검색하는 매소드

	
public:
	DataBase();	

	//set영역
	void addRecipe();							//레시피 추가
	void modifyRecipe();						//레서피 수정
	void modifyRecipe(vector<Recipe> recipes);	//레시피 수정
	void searchRecipe();						//레서피를 검색함
	void deleteRecipe();						//레서피를 삭제함

	void selectOneRecipe(vector<Recipe> tRecipe);	//자세히 볼 레서피 1개 선택하기
	void showRecipeOfDish(string dishName);			//특정 레서피 상세보기
	void showAllRecipeList();						//레서피리스트 보기
	void showAllRecipeList(vector<Recipe> recipes);	//레서피리스트 보기(temp 리스트 안에서)

	string selectOneRecipeName();				//하나의 레서피 선택해 이름반환
	void saveDataBase();					//현재 레서피를 파일에 저장함

	
	void setRecipeList(); //Interface에서 recipeList에 접근하기 위한 함수 .... 이걸 어떻게 만들까

	void setRecipe(Recipe myrecipe);
};

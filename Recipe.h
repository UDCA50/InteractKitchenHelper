/*
 * 요리에 대한 정보들을 담고있는 header.
 * Created by 신영현/남성준/최연호
 */

#include "Ingredient.h"
#include<vector>


class Recipe{

private:
	string dishName;								//요리명
	vector<Ingredient> ingredient;					//재료
	string  dishExplanation;						//조리법
	
	int findNumberOfIngredient(string name);		//현재 재료의 번호를 반환. (몇번째인지) 
	
	void setIngredientName(string name, int ingredientNumber);		//재료명 수정		
	void setIngredientAmount(int amount, int ingredientNumber);			//재료량 설정

	int getIngredientAmount(int ingredientNumber);		 //재료량 반환.
	string getIngredientName(int ingredientNumber);		// 재료이름 반환 

	void deleteIngredient(int ingredientNumber); 	//재료 삭제
	void showIngredient(int ingredientNumber);		//재료정보를 보여주기

public:
	Recipe(string name);			

	//getter
	string getDishName();			//요리명 얻기 ->list 출력에 필요
	string getRecipeOfDish();
	vector<Ingredient> getIngredient();

	//setter
	void setDishName(string name);						//요리명변경
	void setdishExplanation(string dishExplanation);	//조리법 변경
	void addIngredient(string name, int amount);		//재료 추가
	void modifyIngredient(int ingredientNumber);	//재료 수정/삭제
	
	//show영역
	void showAllRecipeInformation();	//레서피 모든 정보 출력
	void showAllIngredient();		//한 레시피의 모든 재료들 출력하기. 
};
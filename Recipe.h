/*
 * 요리에 대한 정보들을 담고있는 header.
 * Created by 신영현/남성준/최연호
 */

#include "Ingredient.h"
#include<vector>


class Recipe{

private:
	string dishName;									//요리명
	vector<Ingredient> ingredient;					//재료
	string  recipeOfDish;							//요리조리법
	
	int findNumberOfIngredient(string name);			//현재 재료의 번호를 반환. (몇번째 재료인지) 
													//매개변수 재료명
	
	string getIngredientName(int ingredientNumber);							//몇번째 재료의 재료명을 반환
	void setIngredientName(string name, int ingredientNumber);				//재료명 수정
																			//재료명을 매개변수로 얻어서 ingredientName 수정
																			//setName()
	int getIngredientAmount(int ingredientNumber);							//몇번째 재료의 재료량을 반환.
	void setIngredientAmount(int amount,int ingredientNumber);			//현재 재료의 재료량을 설정(수정)
										//몇번째 조리법을 반환.

	void ingredientDelete(int ingredientNumber); 	//재료 삭제

	void showIngredient(int ingredientNumber);		//몇번째 재료정보를 보여주기 ->getIngredientName/getIngredientAmount 이용

public:
	Recipe(string name);				//생성자
									//요리명을 입력받음
	string getRecipedOfDish();

	//gt영역
	string getDishName();			//요리명 얻기 ->list 출력에 필요
	vector<Ingredient> getIngredient();
	//set영역
	void ingredientAdd(string name, int amount);		//재료 추가
													//이름 ,양 set 이때 ingredientCount++;
	void setDishName(string name);					//요리의 이름을 입력(수정)
	void ingredientModify(int ingredientNumber);	//재료 수정/삭제
													//재료의 번수를 매개변수로 받아서
													//재료명 변경->setIngredientName, 양->setIngredientAmount
	void setRecipeOfDish(string recipeOfDish);

	//show영역
	void showAllRecipeInformation();	//dishName출력, for문으로 재료명/량 모두출력, recipeOfDish출력
	void showAllIngredient();		//한 레시피의 모든 재료들 출력하기. 
};
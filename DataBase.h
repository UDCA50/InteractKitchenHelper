#include "Recipe.h"

class DataBase{
private:
	vector<Recipe> recipe;		//실제 recipe벡터
	vector<Recipe> tempRecipe;  //서치 과정을 통한 임시 벡터
	
	int showNeedToDishReasearch();               		// <1.재검색 2.수정 3.메인back 4. 일정추가>		
														// "EnumDefinition.h"에 1,2,3,4정의를 하고

	void dishResearch(vector<Recipe> tRecipe);
	void ingredientResearch(vector<Recipe> tRecipe);
public:
	DataBase();				//생성자

	//set영역
	void addRecipe();							//레시피 추가 영역
												//이름을 입력받아서 recipe[num].setDishName(name);
												//재료를 추가할것인지의 여부를 물어본뒤 추가하면
												//recipe[count].ingredientAdd(name, amount)!!<-반복
												//조리법 추가 recipe[count].recipeOfDishAdd(recipeOfDish);

	void modifyRecipe();
	void modifyRecipe(vector<Recipe> recipes);				//레시피 수정
										//모든 레시피 이름 출력 for문 showAllRecipes();
										//몇번째 레시피인지 묻고
										//이름 수정-> recipe[num].setDishName(name)
										//재료 수정-> 몇번째 재료인지 묻고
										//recipe[num].IngredientModify(ingredientnumber);
										//조리법 수정-> recipe[num].setRecipeOfDish(recipeOfDish);


	//show 영역
	void showAllRecipesList();
	void showAllRecipesList(vector<Recipe> recipes);							//모든 레시피리스트 보여주기
	

	//실질적 method영역
	void search();	//서치 ->dish/ingredient
	
	void dishSearch();      			//서치 후 showNeedToReaserch();
													
	void ingredientSearch(); 			//서치 후 showNeedToReasearch();

	void deleteRecipe();

	void deleteRecipe(int recipeNumber);			//레시피 삭제


	/*
	Recipe showRecipeOfDish(string dishName);			//dishName를 매개변수로 받아서
	//getRecipe();
	Recipe getRecipe();*/ //연계기능

	int getRecipeCount();
	Recipe getRecipebyIndex(int vectorIndex);

};

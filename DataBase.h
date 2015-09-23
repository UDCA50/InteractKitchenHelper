#include "Recipe.h"

class DataBase{
private:
	vector<Recipe> recipe;		//���� recipe����
	vector<Recipe> tempRecipe;  //��ġ ������ ���� �ӽ� ����
	
	int showNeedToDishReasearch();               		// <1.��˻� 2.���� 3.����back 4. �����߰�>		
														// "EnumDefinition.h"�� 1,2,3,4���Ǹ� �ϰ�

	void dishResearch(vector<Recipe> tRecipe);
	void ingredientResearch(vector<Recipe> tRecipe);
public:
	DataBase();				//������

	//set����
	void addRecipe();							//������ �߰� ����
												//�̸��� �Է¹޾Ƽ� recipe[num].setDishName(name);
												//��Ḧ �߰��Ұ������� ���θ� ����� �߰��ϸ�
												//recipe[count].ingredientAdd(name, amount)!!<-�ݺ�
												//������ �߰� recipe[count].recipeOfDishAdd(recipeOfDish);

	void modifyRecipe();
	void modifyRecipe(vector<Recipe> recipes);				//������ ����
										//��� ������ �̸� ��� for�� showAllRecipes();
										//���° ���������� ����
										//�̸� ����-> recipe[num].setDishName(name)
										//��� ����-> ���° ������� ����
										//recipe[num].IngredientModify(ingredientnumber);
										//������ ����-> recipe[num].setRecipeOfDish(recipeOfDish);


	//show ����
	void showAllRecipesList();
	void showAllRecipesList(vector<Recipe> recipes);							//��� �����Ǹ���Ʈ �����ֱ�
	

	//������ method����
	void search();	//��ġ ->dish/ingredient
	
	void dishSearch();      			//��ġ �� showNeedToReaserch();
													
	void ingredientSearch(); 			//��ġ �� showNeedToReasearch();

	void deleteRecipe();

	void deleteRecipe(int recipeNumber);			//������ ����


	/*
	Recipe showRecipeOfDish(string dishName);			//dishName�� �Ű������� �޾Ƽ�
	//getRecipe();
	Recipe getRecipe();*/ //������

	int getRecipeCount();
	Recipe getRecipebyIndex(int vectorIndex);

};

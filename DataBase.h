#pragma once
#include "Recipe.h"

class DataBase{
private:
	vector<Recipe> recipeList;		// ���� ������ ������ ������ DB
	vector<Recipe> tempRecipeList;  // �˻��� ������ ������ �ӽ������ϴ� DB
	
	void searchRecipebyName();      			//�̸����� ������ �˻� �żҵ�
	void searchRecipebyIngre(); 			//���� ������ �˻�
	void deleteRecipe(int recipeNumber);	//Ư�� �����Ǹ� ����

	int selectSearchOption();   //�����ǰ˻��� �߰������� �Է¹޴� �żҵ�

	void researchDish(vector<Recipe> tRecipe);	//�丮���� ��˻��ϴ� �żҵ�
	void researchIngredient(vector<Recipe> tRecipe);	//��Ḧ ��˻��ϴ� �żҵ�
	
	int findRecipeNumber(string recipeName);		//�ش��̸��� �����Ǹ� �˻��ϴ� �żҵ�

	
public:
	DataBase();	

	//set����
	void addRecipe();							//������ �߰�
	void modifyRecipe();						//������ ����
	void modifyRecipe(vector<Recipe> recipes);	//������ ����
	void searchRecipe();						//�����Ǹ� �˻���
	void deleteRecipe();						//�����Ǹ� ������

	void selectOneRecipe(vector<Recipe> tRecipe);	//�ڼ��� �� ������ 1�� �����ϱ�
	void showRecipeOfDish(string dishName);			//Ư�� ������ �󼼺���
	void showAllRecipeList();						//�����Ǹ���Ʈ ����
	void showAllRecipeList(vector<Recipe> recipes);	//�����Ǹ���Ʈ ����(temp ����Ʈ �ȿ���)

	string selectOneRecipeName();				//�ϳ��� ������ ������ �̸���ȯ
	void saveDataBase();					//���� �����Ǹ� ���Ͽ� ������

	
	void setRecipeList(); //Interface���� recipeList�� �����ϱ� ���� �Լ� .... �̰� ��� �����

	void setRecipe(Recipe myrecipe);
};

/*
 * �丮�� ���� �������� ����ִ� header.
 * Created by �ſ���/������/�ֿ�ȣ
 */

#include "Ingredient.h"
#include<vector>


class Recipe{

private:
	string dishName;								//�丮��
	vector<Ingredient> ingredient;					//���
	string  dishExplanation;						//������
	
	int findNumberOfIngredient(string name);		//���� ����� ��ȣ�� ��ȯ. (���°����) 
	
	void setIngredientName(string name, int ingredientNumber);		//���� ����		
	void setIngredientAmount(int amount, int ingredientNumber);			//��ᷮ ����

	int getIngredientAmount(int ingredientNumber);		 //��ᷮ ��ȯ.
	string getIngredientName(int ingredientNumber);		// ����̸� ��ȯ 

	void deleteIngredient(int ingredientNumber); 	//��� ����
	void showIngredient(int ingredientNumber);		//��������� �����ֱ�

public:
	Recipe(string name);			

	//getter
	string getDishName();			//�丮�� ��� ->list ��¿� �ʿ�
	string getRecipeOfDish();
	vector<Ingredient> getIngredient();

	//setter
	void setDishName(string name);						//�丮����
	void setdishExplanation(string dishExplanation);	//������ ����
	void addIngredient(string name, int amount);		//��� �߰�
	void modifyIngredient(int ingredientNumber);	//��� ����/����
	
	//show����
	void showAllRecipeInformation();	//������ ��� ���� ���
	void showAllIngredient();		//�� �������� ��� ���� ����ϱ�. 
};
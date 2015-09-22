/*
 * �丮�� ���� �������� ����ִ� header.
 * Created by �ſ���/������/�ֿ�ȣ
 */

#include "Ingredient.h"
#include<vector>


class Recipe{

private:
	string dishName;									//�丮��
	vector<Ingredient> ingredient;					//���
	string  recipeOfDish;							//�丮������
	
	int findNumberOfIngredient(string name);			//���� ����� ��ȣ�� ��ȯ. (���° �������) 
													//�Ű����� ����
	
	string getIngredientName(int ingredientNumber);							//���° ����� ������ ��ȯ
	void setIngredientName(string name, int ingredientNumber);				//���� ����
																			//������ �Ű������� �� ingredientName ����
																			//setName()
	int getIngredientAmount(int ingredientNumber);							//���° ����� ��ᷮ�� ��ȯ.
	void setIngredientAmount(int amount,int ingredientNumber);			//���� ����� ��ᷮ�� ����(����)
										//���° �������� ��ȯ.

	void ingredientDelete(int ingredientNumber); 	//��� ����

	void showIngredient(int ingredientNumber);		//���° ��������� �����ֱ� ->getIngredientName/getIngredientAmount �̿�

public:
	Recipe(string name);				//������
									//�丮���� �Է¹���
	string getRecipedOfDish();

	//gt����
	string getDishName();			//�丮�� ��� ->list ��¿� �ʿ�
	vector<Ingredient> getIngredient();
	//set����
	void ingredientAdd(string name, int amount);		//��� �߰�
													//�̸� ,�� set �̶� ingredientCount++;
	void setDishName(string name);					//�丮�� �̸��� �Է�(����)
	void ingredientModify(int ingredientNumber);	//��� ����/����
													//����� ������ �Ű������� �޾Ƽ�
													//���� ����->setIngredientName, ��->setIngredientAmount
	void setRecipeOfDish(string recipeOfDish);

	//show����
	void showAllRecipeInformation();	//dishName���, for������ ����/�� ������, recipeOfDish���
	void showAllIngredient();		//�� �������� ��� ���� ����ϱ�. 
};
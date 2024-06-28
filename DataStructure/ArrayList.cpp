#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"

enum eINPUT {
	eCREATE_ARRAY = 1,
	eDELETE_ARRAY,
	eINSERT_ELEMENT,
	eDELETE_ELEMENT,
	ePRINT_ELEMENT,
	eEXIT
};

typedef struct ArrayListNode
{
	int Data;
};

typedef struct ArrayList
{
	int maxLength;
	int currentLength;
	ArrayListNode* pElement;
};

int SelectUI();
ArrayList* CreateArray(int maxLength);
void DeleteArray(ArrayList* Arraylist);
void InsertElement(ArrayList* Arraylist);
void DeleteElement(ArrayList* Arraylist);
void PrintElement(ArrayList* Arraylist);

int main()
{
	bool ProgramExit = false;
	ArrayList *Arraylist = NULL;

	while (!ProgramExit)
	{
		switch (SelectUI())
		{
		case eCREATE_ARRAY:
			if (Arraylist == NULL)
			{
				int maxLength = 0;

			MAXLENGTH:
				printf("생성할 배열의 최대 원소 갯수 : "), scanf_s("%d", &maxLength);
				if (maxLength > 0)
					Arraylist = CreateArray(maxLength);
				else
				{
					printf("생성할 배열의 최대 원소 갯수를 다시 입력하세요! (1 이상)\n");
					system("pause");
					system("cls");

					goto MAXLENGTH;
				}					
			}
			else
			{
				printf("이미 배열을 생성하였습니다.\n");
				system("pause");
				system("cls");
			}
			break;
		case eDELETE_ARRAY:
			if (Arraylist != NULL)
				DeleteArray(Arraylist);
			else
			{
				printf("삭제할 배열이 존재하지 않습니다.\n");
				system("pause");
				system("cls");
			}
			break;
		case eINSERT_ELEMENT:
			if (Arraylist == NULL)
			{
				printf("원소를 추가할 배열이 존재하지 않습니다.\n");
				system("pause");
				system("cls");
			}
			else if (Arraylist->currentLength < Arraylist->maxLength)
				InsertElement(Arraylist);
			else
			{
				printf("더 이상 원소를 추가할 수 없습니다.\n");
				system("pause");
				system("cls");
			}
			break;
		case eDELETE_ELEMENT:
			if (Arraylist == NULL)
			{
				printf("원소를 삭제할 배열이 존재하지 않습니다.\n");
				system("pause");
				system("cls");
			}
			else if (Arraylist->currentLength > 0)
				DeleteElement(Arraylist);
			else
			{
				printf("더 이상 삭제할 원소가 존재하지 않습니다.\n");
				system("pause");
				system("cls");
			}
			break;
		case ePRINT_ELEMENT:
			if (Arraylist == NULL)
			{
				printf("출력할 원소 및 배열이 존재하지 않습니다.\n");
				system("pause");
				system("cls");
			}
			else
				PrintElement(Arraylist);
			break;
		case eEXIT:
			DeleteArray(Arraylist);
			ProgramExit = true;
			break;
		default:break;
		}
		system("cls");
	}

	return 0;
}

int SelectUI()
{
	int input = 0;

	printf("====Stack System====\n");
	printf("1. Create Array\n");
	printf("2. Delete Array\n");
	printf("3. Insert Element\n");
	printf("4. Delete Element\n");
	printf("5. Print Element\n");
	printf("6. Exit\n");
	printf("====================\n");
	printf("입력 : "), scanf_s("%d", &input);

	return input;
}

ArrayList* CreateArray(int maxLength)
{
	ArrayList* NewArrayList = new ArrayList;
	NewArrayList->currentLength = 0;
	NewArrayList->maxLength = maxLength;
	NewArrayList->pElement = new ArrayListNode[maxLength];

	return NewArrayList;
}

void DeleteArray(ArrayList* Arraylist)
{
	delete[] Arraylist->pElement;
	delete Arraylist;

	Arraylist = NULL;
}

void InsertElement(ArrayList* Arraylist)
{
	int Insert_Index = 0, Input_Data = 0;

	printf("삽입할 데이터 입력 : "), scanf_s("%d", &Input_Data);

INSERT_INDEX:
	printf("삽입할 인덱스 입력 : "), scanf_s("%d", &Insert_Index);
	
	if (Arraylist->currentLength < Insert_Index || Insert_Index < 0)
	{
		printf("삽입할 인덱스 값이 존재하지 않습니다. 다시 입력해주세요!\n");
		system("pause");
		system("cls");

		goto INSERT_INDEX;
	}
	else if (Arraylist->currentLength - 1 >= Insert_Index)
	{			
		for (int i = Arraylist->currentLength - 1; i >= Insert_Index; i--)
			Arraylist->pElement[i + 1].Data = Arraylist->pElement[i].Data;
	}

	Arraylist->pElement[Insert_Index].Data = Input_Data;
	Arraylist->currentLength++;
}

void DeleteElement(ArrayList* Arraylist)
{
	int Delete_Index = 0;

DELETE_INDEX:
	printf("삭제할 인덱스 입력 : "), scanf_s("%d", &Delete_Index);

	if (Arraylist->currentLength > Delete_Index && Delete_Index > -1)
	{
		for (int i = Delete_Index + 1; i < Arraylist->maxLength; i++)
			Arraylist->pElement[i - 1].Data = Arraylist->pElement[i].Data;
	}
	else
	{
		printf("삭제할 인덱스 값이 존재하지 않습니다. 다시 입력해주세요!\n");
		system("pause");
		system("cls");
		
		goto DELETE_INDEX;
	}		

	Arraylist->currentLength--;
}

void PrintElement(ArrayList* Arraylist)
{
	printf("원소 최대 길이 : %d\n", Arraylist->maxLength);
	printf("현재 원소 길이 : %d\n", Arraylist->currentLength);
	printf("원소 데이터 : ");
	for (int i = 0; i < Arraylist->currentLength; i++)
	{		
		printf("%d", Arraylist->pElement[i].Data);

		if ((i + 1) != Arraylist->currentLength)
			printf(", ");
		else printf("\n");
	}
	system("pause");
	system("cls");
}

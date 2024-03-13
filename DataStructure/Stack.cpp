#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"

enum eINPUT {
	PUSH = 1,
	POP		,
	EXIT
};

typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;

int SelectUI();
Node* NodePush(Node* Top);
Node* NodePop(Node* Top);

int main()
{
	Node* Top = NULL;
	bool ProgramExit = false;

	while (!ProgramExit)
	{
		switch (SelectUI())
		{
			case PUSH:
				Top = NodePush(Top);
				break;
			case POP:
				Top = NodePop(Top);
				system("pause");
				break;
			case EXIT:
				while(Top != NULL)
					Top = NodePop(Top);
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
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Exit\n");
	printf("====================\n");
	printf("입력 : "), scanf_s("%d", &input);

	return input;
}

Node* NodePush(Node* Top)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	printf("데이터 입력 : "), scanf_s("%d", &NewNode->Data);
	NewNode->Next = Top;
	return NewNode;
}

Node* NodePop(Node* Top)
{
	Node* TempTop = NULL;

	if (Top != NULL)
	{
		printf("Pop : %d\n", Top->Data);
		TempTop = Top->Next;
		free(Top);
	}
	else printf("삭제할 데이터가 없습니다.\n");

	return TempTop;
}
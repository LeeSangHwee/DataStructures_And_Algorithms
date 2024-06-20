#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"

enum eINPUT {
	ENQUQUE = 1,
	DEQUQUE,
	EXIT
};

typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;

int SelectUI();
Node* EnQuque(Node* Front);
Node* DeQuque(Node* Front);

int main()
{
	Node *Front = NULL, *Rear = NULL;
	bool ProgramExit = false;

	while (!ProgramExit)
	{
		switch (SelectUI())
		{
		case ENQUQUE:
			Rear = EnQuque(Rear);
			if (Front == NULL)
				Front = Rear;
			break;
		case DEQUQUE:
			Front = DeQuque(Front);
			system("pause");
			break;
		case EXIT:
			while (Rear != NULL)
				Rear = DeQuque(Rear);
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
	printf("1. EnQuque\n");
	printf("2. DeQuque\n");
	printf("3. Exit\n");
	printf("====================\n");
	printf("입력 : "), scanf_s("%d", &input);

	return input;
}

Node* EnQuque(Node* Rear)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	printf("데이터 입력 : "), scanf_s("%d", &NewNode->Data);
	NewNode->Next = Rear;
	return NewNode;
}

Node* DeQuque(Node* Front)
{
	Node* TempFront = NULL;

	if (Front == NULL)
		printf("삭제할 데이터가 없습니다.\n");
	else
	{
		printf("DeQuque : %d\n", Front->Data);
		TempFront = Front->Next;
		free(Front);
	}
	return TempFront;
}
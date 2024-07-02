#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"

enum eINPUT {
	eINSERT = 1,
	eDELETE,
	ePRINT,
	eEXIT
};

typedef struct Node
{
	int Data;
	struct Node* Previous;
	struct Node* Next;
}Node;

int SelectUI();
Node* Insert_Node(Node* Head);
Node* Delete_Node(Node* Head);
void Print_Node(Node* Head);
void Exit_Program(Node* Head);

int main()
{
	bool ProgramExit = false;
	Node* Head = NULL;

	while (!ProgramExit)
	{
		switch (SelectUI())
		{
		case eINSERT://지금은 Head에 추가하는 방식임 원하는 위치에 추가하는 방식을 넣고싶으면 삭제를 응용하면됨
			Head = Insert_Node(Head);
			break;
		case eDELETE:
			if (Head == NULL) printf("삭제할 노드가 존재하지 않습니다!\n");
			else Head = Delete_Node(Head);
			break;
		case ePRINT:
			if (Head == NULL) printf("출력할 노드가 존재하지 않습니다!\n");
			else printf("노드 리스트 : "), Print_Node(Head), printf("\n");
			break;
		case eEXIT:
			Exit_Program(Head);
			ProgramExit = true;
			break;
		default:break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}

int SelectUI()
{
	int input = 0;

	printf("====Doubly Linked List System====\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Print\n");
	printf("4. Exit\n");
	printf("====================\n");
	printf("입력 : "), scanf_s("%d", &input);

	return input;
}

Node* Insert_Node(Node* Head)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	printf("삽입할 노드 입력 : "), scanf_s("%d", &(NewNode->Data));
	NewNode->Previous = NULL;
	NewNode->Next = Head;	

	if(Head != NULL)
		Head->Previous = NewNode;

	return NewNode;
}

Node* Delete_Node(Node* Head)
{
DELETE_INPUT:
	int input;
	printf("삭제할 노드의 데이터 입력 : "), scanf_s("%d", &input);

	Node* ReturnNode = NULL;
	Node* SearchNode = Head;

	while (true)
	{
		if (SearchNode == NULL)
		{
			printf("삭제하려는 노드가 존재하지 않습니다! 다시 입력해주세요.\n");
			system("pause");
			system("cls");

			goto DELETE_INPUT;
		}
		else if (SearchNode->Data == input)
		{
			if (SearchNode->Previous == NULL)
			{
				if (SearchNode->Next != NULL) // 탐색된 원소가 맨 왼쪽일 경우
				{
					SearchNode->Next->Previous = NULL;
					ReturnNode = SearchNode->Next;
				}					
				else if (SearchNode->Next == NULL) // 탐색된 원소가 하나만 존재할 경우
					ReturnNode = NULL;					
			}
			else if (SearchNode->Previous != NULL)
			{
				if (SearchNode->Next != NULL)  // 탐색된 원소가 리스트 중간에 있는 경우
				{
					SearchNode->Previous->Next = SearchNode->Next;
					SearchNode->Next->Previous = SearchNode->Previous;
				}
				else if (SearchNode->Next == NULL)  // 탐색된 원소가 맨 오른쪽일 경우
					SearchNode->Previous->Next = NULL;

				ReturnNode = Head;
			}
			free(SearchNode);
			return ReturnNode;
		}
		SearchNode = SearchNode->Next;
	}
	return NULL;
}

void Print_Node(Node* Head)
{
	if (Head != NULL)
	{
		Print_Node(Head->Next);
		printf("%d ", Head->Data);
	}
}

void Exit_Program(Node* Head)
{
	if (Head != NULL)
	{
		Exit_Program(Head->Next);
		free(Head);
	}
}

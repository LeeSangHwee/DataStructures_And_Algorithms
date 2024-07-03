#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"

enum eINPUT {
	eINSERT = 1,
	eDELETE,
	ePRINT,
	eEXIT
};

enum eINSERT {
	eFIRST_INSERT = 1,
	eMIDDLE_INSERT,
	eLAST_INSERT
};

typedef struct Node
{
	int Data;
	struct Node* Next;
}Node;

int SelectUI();
Node* InsertNode(Node* List_ptr, Node** Head);
void Delete_Node(Node** List_ptr, Node** Head);
void Print_Node(Node* List_ptr, Node* Head);
void Exit_Program(Node* List_ptr, Node* Head);

int main()
{
	bool ProgramExit = false;
	Node* Head = NULL;
	Node* List_ptr = NULL;

	while (!ProgramExit)
	{
		switch (SelectUI())
		{
		case eINSERT:
			List_ptr = InsertNode(List_ptr, &Head);
			if (Head == NULL) Head = List_ptr;
			break;
		case eDELETE:
			if (List_ptr == NULL) printf("삭제할 노드가 존재하지 않습니다!\n");
			else Delete_Node(&List_ptr, &Head);
			break;
		case ePRINT:
			if (List_ptr == NULL) printf("출력할 노드가 존재하지 않습니다!\n");
			else printf("노드 리스트 : "), Print_Node(List_ptr, Head), printf("\n");
			break;
		case eEXIT:
			Exit_Program(List_ptr, Head);
			ProgramExit = true;
			break;
		default: break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}

int SelectUI()
{
	int input = 0;

	printf("====Circular Linked List System====\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Print\n");
	printf("4. Exit\n");
	printf("====================\n");
	printf("입력 : "), scanf_s("%d", &input);
	system("cls");

	return input;
}

Node* InsertNode(Node* List_ptr, Node** Head)
{
	int input = 0;

	while (1 > input || input > 3)
	{
		printf("====Select Insert Method====\n");
		printf("1. First_Insert\n");
		printf("2. Middle_Insert\n");
		printf("3. Last_Insert\n");

		printf("====================\n");
		printf("입력 : "), scanf_s("%d", &input);
		system("cls");
	}

	// 신규 노드 생성
	Node* NewNode = (Node*)malloc(sizeof(Node));	
	printf("삽입할 노드 입력 : "), scanf_s("%d", &(NewNode->Data));
	// 노드가 하나도 존재하지 않을 경우
	if (List_ptr == NULL)
	{
		NewNode->Next = List_ptr;
		List_ptr = NewNode;
	}		
	// 노드가 하나라도 존재할 경우
	else
	{
		switch (input)
		{
		// 리스트 첫번째 위치에 삽입
		case eFIRST_INSERT:
			NewNode->Next = List_ptr;
			(*Head)->Next = NewNode;
			List_ptr = NewNode;
			break;
		// 리스트 중간에 삽입
		case eMIDDLE_INSERT:
			{
			MIDDLE_INSERT_INPUT:
				int input = 0;
				printf("삽입할 노드의 이전 데이터 값 입력 : "), scanf_s("%d", &input);

				Node* TempNode = List_ptr;
				while (true)
				{
					if(TempNode->Data == input)
					{
						NewNode->Next = TempNode->Next;
						TempNode->Next = NewNode;
						break;
					}
					else if (TempNode == *Head)
					{
						printf("현재 찾고 있는 이전 데이터의 값이 존재하지 않습니다! 다시 입력해주세요.");
						system("pause");
						system("cls");

						goto MIDDLE_INSERT_INPUT;
					}
					TempNode = TempNode->Next;
				}
			}
			break;
		// 리스트 마지막에 삽입
		case eLAST_INSERT:
			{
				NewNode->Next = List_ptr;
				(*Head)->Next = NewNode;
				*Head = NewNode;
			}
			break;
		default:break;
		}
	}
	return List_ptr;
}

void Delete_Node(Node** List_ptr, Node** Head)
{
DELETE_INPUT:
	int input;
	printf("삭제할 노드의 데이터 입력 : "), scanf_s("%d", &input);

	Node* TempNode = *Head;
	Node* SearchNode = *List_ptr;

	while (true)
	{
		if (SearchNode->Data == input)
		{
			// 삭제 노드가 List_ptr 인 경우
			if (SearchNode == *List_ptr)
				*List_ptr = SearchNode->Next;
			// 삭제 노드가 Head 인 경우
			else if (SearchNode == *Head)
				*Head = TempNode;

			TempNode->Next = SearchNode->Next;
			free(SearchNode);
			break;
		}
		else if (SearchNode == *Head)
		{
			printf("삭제할 노드가 존재하지 않습니다! 다시 입력해주세요.\n");
			system("pause");
			system("cls");

			goto DELETE_INPUT;
		}

		TempNode = SearchNode;
		SearchNode = SearchNode->Next;
	}
}

void Print_Node(Node* List_ptr, Node* Head)
{
	if (List_ptr != Head)
		Print_Node(List_ptr->Next, Head);	

	printf("%d ", List_ptr->Data);
}

void Exit_Program(Node* List_ptr, Node* Head)
{
	if (List_ptr != Head)
		Exit_Program(List_ptr->Next, Head);

	free(List_ptr);
}

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
		case eINSERT://������ Head�� �߰��ϴ� ����� ���ϴ� ��ġ�� �߰��ϴ� ����� �ְ������ ������ �����ϸ��
			Head = Insert_Node(Head);
			break;
		case eDELETE:
			if(Head == NULL) printf("������ ��尡 �������� �ʽ��ϴ�!\n");
			else Head = Delete_Node(Head);
			break;
		case ePRINT:
			if (Head == NULL) printf("����� ��尡 �������� �ʽ��ϴ�!\n");
			else printf("��� ����Ʈ : "), Print_Node(Head), printf("\n");
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

	printf("====Singly Linked List System====\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Print\n");
	printf("4. Exit\n");
	printf("====================\n");
	printf("�Է� : "), scanf_s("%d", &input);

	return input;
}

Node* Insert_Node(Node* Head)
{	
	Node* NewNode = (Node*)malloc(sizeof(Node));
	printf("������ ��� �Է� : "), scanf_s("%d", &(NewNode->Data));
	NewNode->Next = Head;
		
	return NewNode;
}

Node* Delete_Node(Node* Head)
{
DELETE_INPUT:
	int input;
	printf("������ ����� ������ �Է� : "), scanf_s("%d", &input);
	
	Node* TempNode = NULL;
	Node* SearchNode = Head;

	while (true)
	{
		if (SearchNode == NULL)
		{
			printf("������ ��尡 �������� �ʽ��ϴ�! �ٽ� �Է����ּ���.\n");
			system("pause");
			system("cls");

			goto DELETE_INPUT;
		}
		else if (SearchNode->Data == input)
		{
			if (TempNode == NULL)
			{
				if (SearchNode->Next != NULL) // Ž���� ���Ұ� �� ������ ���
					TempNode = SearchNode->Next;
				else if (SearchNode->Next == NULL) // Ž���� ���Ұ� �ϳ��� ������ ���
					TempNode = NULL;
			}
			else if (TempNode != NULL)
			{
				if (SearchNode->Next != NULL)  // Ž���� ���Ұ� ����Ʈ �߰��� �ִ� ���
					TempNode->Next = SearchNode->Next;
				else if (SearchNode->Next == NULL)  // Ž���� ���Ұ� �� �������� ���
					TempNode->Next = NULL;										

				TempNode = Head;
			}

			free(SearchNode);
			return TempNode;
		}

		TempNode = SearchNode;
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

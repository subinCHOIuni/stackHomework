##pragma once
typedef char* element;

typedef struct stackNode {	//��� ����ü ����
	element data;  //������ �ʵ�
	struct stackNode* link;  //������
} stackNode;

stackNode* top;  //������ LIFO

int isStackEmpty();	//������ ����ִ��� Ȯ���Ѵ�.
void push(element item); //������ top�� ���Ҹ� �����Ѵ�.
element pop(); //������ top�� ���Ҹ� �����Ѵ�..
void printStack(); //������ ���Ҹ� ����Ѵ�.
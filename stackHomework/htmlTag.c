#include<stdio.h>
#include "htmlTag.h"


int isStackEmpty() {
	if (top == NULL) //������ ������ ���
		return 1;
	else return 0;  //�ƴ� ���
}

void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

	temp->data = item;
	temp->link = top;
	top = temp;
}


element pop() {
	element item;
	stackNode* temp = top;

	if (isStackEmpty()) {		// ������ ���� ����Ʈ�� ���
		printf("\n\n empty \n");
		return 0;
	}
	else {					// ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;	// top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);			// ������ ����� �޸� ��ȯ
		return item;		// ������ ���� ��ȯ
	}
}

// ������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack() {
	stackNode* p = top;
	printf("\n stack [ ");
	while (p) {
		printf("%s ", p->data);
		p = p->link;
	}
	printf("] ");
}


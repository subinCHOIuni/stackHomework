#include<stdio.h>
#include "htmlTag.h"


int isStackEmpty() {
	if (top == NULL) //스택이 공백인 경우
		return 1;
	else return 0;  //아닌 경우
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

	if (isStackEmpty()) {		// 스택이 공백 리스트인 경우
		printf("\n\n empty \n");
		return 0;
	}
	else {					// 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = temp->link;	// top 위치를 삭제 노드 아래로 이동
		free(temp);			// 삭제된 노드의 메모리 반환
		return item;		// 삭제된 원소 반환
	}
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
	stackNode* p = top;
	printf("\n stack [ ");
	while (p) {
		printf("%s ", p->data);
		p = p->link;
	}
	printf("] ");
}


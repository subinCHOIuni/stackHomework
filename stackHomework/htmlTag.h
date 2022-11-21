##pragma once
typedef char* element;

typedef struct stackNode {	//노드 구조체 정의
	element data;  //데이터 필드
	struct stackNode* link;  //포인터
} stackNode;

stackNode* top;  //스택은 LIFO

int isStackEmpty();	//스택이 비어있는지 확인한다.
void push(element item); //스택의 top에 원소를 삽입한다.
element pop(); //스택의 top의 원소를 삭제한다..
void printStack(); //스택의 원소를 출력한다.

#define _CRT_SECURE_NO_WARNINGS  
#pragma warning(disable : 6031)
#include<stdio.h>
#include<malloc.h>
#include <string.h>
#include "htmlTag.h"
#define MAX 100

int main(void) {
	char html[MAX] = { 0 };
	char* p, * q, * token, * stack_token, html_edit[MAX * 10] = { '\0' }, * r, * str;
	int i = 0;
	r = html_edit;

	while (1) {
		// HTML�ڵ� �Է�
		gets(html);

		token = strtok(html, " ");

		while (token != NULL) {
			if (token[0] != '.') {
				strcpy(r, token);
				r += strlen(token);
				*r = ' '; r++;
			}

			p = token;
			q = p + strlen(token);

			//html���� ���� ��ū �˻�
			if (*p == '<') {  // '<'�� �����ϴ� ��ū�ΰ�?	
				// '<'���� �����ϴ� ��ū�� ���
				if (*(q - 2) == '/') {     // '/>�� ������ ��ū�ΰ�? (������ �ι�° ��ġ�� �ִ� ���� Ȯ��) 

				}

				else {
					if (*(q - 1) == '>') {
						stack_token = (char*)malloc(strlen(token) + 1);
						stack_token[0] = '<';
						stack_token[1] = '/';
						for (i = 2, p += (i - 1); p <= q; i++, p++) {
							stack_token[i] = *p;
						}
					}
					else {
						stack_token = (char*)malloc(strlen(token) + 2);
						stack_token[0] = '<';
						stack_token[1] = '/';
						for (i = 2, p += (i - 1); p < q; i++, p++) {
							stack_token[i] = *p;
						}
						stack_token[i] = '>';
						stack_token[i + 1] = '\0';
					}

					push(stack_token);

				}
			}

			else {  //  '<'�� �������� �ʴ� ��� 
				if (*(q - 2) == '/') {     // '/>�� ������ ��ū�ΰ�? (������ �ι�° ��ġ�� �ִ� ���� Ȯ��) 
					pop(); //������ pop�Ͽ� ����
				}
				else {
					if (token[0] == '.') { //��ū�� '.'�ΰ�?
						r -= 1;  //������ ������ '.' ��ū ����


						while (!isStackEmpty()) { // ������ �����̾ƴѰ�?
							str = pop(); //������ pop�Ͽ� ��� ���ڿ��� �߰�
							strcpy(r, str);
							r += strlen(str);
							*r = ' '; r++;
						}

						// ������ ���ڿ� ���
						printf("\nhtml_edit: %s\n\n", html_edit);

						return 0;
					}
				}
			}
			token = strtok(q + 1, " ");

		}

		//token �� NULL�� ��� => �����±� ������ �ڸ� 
		str = pop();
		// ��ū�� ��� ���ڿ��� ����
		strcpy(r, str);
		r += strlen(str);
		*r = ' '; r++;

	}
}
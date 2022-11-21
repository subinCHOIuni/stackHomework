
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
		// HTML코드 입력
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

			//html에서 다음 토큰 검사
			if (*p == '<') {  // '<'로 시작하는 토큰인가?	
				// '<'으로 시작하는 토큰인 경우
				if (*(q - 2) == '/') {     // '/>로 끝나는 토큰인가? (끝에서 두번째 위치에 있는 문자 확인) 

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

			else {  //  '<'로 시작하지 않는 경우 
				if (*(q - 2) == '/') {     // '/>로 끝나는 토큰인가? (끝에서 두번째 위치에 있는 문자 확인) 
					pop(); //스택을 pop하여 삭제
				}
				else {
					if (token[0] == '.') { //토큰이 '.'인가?
						r -= 1;  //마지막 복사한 '.' 토큰 삭제


						while (!isStackEmpty()) { // 스택이 공백이아닌가?
							str = pop(); //스택을 pop하여 출력 문자열에 추가
							strcpy(r, str);
							r += strlen(str);
							*r = ' '; r++;
						}

						// 생성된 문자열 출력
						printf("\nhtml_edit: %s\n\n", html_edit);

						return 0;
					}
				}
			}
			token = strtok(q + 1, " ");

		}

		//token 이 NULL인 경우 => 종료태그 삽입할 자리 
		str = pop();
		// 토큰을 출력 문자열에 복사
		strcpy(r, str);
		r += strlen(str);
		*r = ' '; r++;

	}
}
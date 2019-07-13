#include "Stack.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
void BracketMatch(const char* src, int size)
{
	Stack stack;
	StackInit(&stack);
	char ch;
	char leftBracket;
	for (int i = 0; i < size; i++) {
		char ch = src[i];
		switch (ch) {
			case '(':
			case '{':
			case '[':
				StackPush(&stack, ch);
				break;
			case ')':
			case '}':
			case ']':
				if (StackIsEmpty(&stack)) {
					printf("�����Ŷ�\n");
					StackDestroy(&stack);
					return;
				}
				leftBracket = getTop(&stack);
				StackPop(&stack);

				if (leftBracket == '(' && ch != ')') {
					printf("���Ų�ƥ��\n");
					return;
				}
				if (leftBracket == '{' && ch != '}') {
					printf("���Ų�ƥ��\n");
					return;
				}
				if (leftBracket == '[' && ch != ']') {
					printf("���Ų�ƥ��\n");
					return;
				}
			default:
				break;
		}
	}
	if (!StackIsEmpty(&stack)) {
		printf("�����Ŷ�\n");
		return;
	}
	printf("��������ƥ��\n");
}

void TestBracket()
{
	const char * seqs[] = {
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}"
	};

	for (int i = 0; i < 4; i++) {
		BracketMatch(seqs[i], strlen(seqs[i]));
	}
}



//�沨�����ʽ
typedef enum {
	OPERAND,
	OPERATOR
}Type;
typedef enum {
	ADD,
	SUB,
	MUL,
	DIV
}Operator;
typedef struct {
	Type type;
	int operand;
	Operator operator;
}Element;

int Run(Operator operator, int a, int b)
{
	switch (operator) {
		case ADD:
			return a + b;
		case SUB:
			return a - b;
		case MUL:
			return a * b;
		case DIV:
			return a / b;
		default:
			assert(0);
	}
}
int ReversePolishNotion(Element expersion[], int size)
{
	Stack stack;
	StackInit(&stack);
	int op1, op2;
	int result;

	for (int i = 0; i < size; i++) {
		Element e = expersion[i];
		switch (e.type) {
		case OPERAND:
			StackPush(&stack, e.operand);
			break;

		case OPERATOR:
			op1 = getTop(&stack);   //ȡ����һ��������
			StackPop(&stack);	//��ջ
			op2 = getTop(&stack);		//ȡ���ڶ���������
			StackPop(&stack);		//��ջ
			result = Run(e.operator, op1, op2);		 //�����������м���
			StackPush(&stack, result);		//����������������������ջ
			break;
		default:
			assert(0);
		}
	}
	assert(getSize(&stack) == 1);
	result = getTop(&stack);

	return result;
}


void TestRPN()
{
	// 1 + 2 + 3
	// 1 2 + 3 +
	Element expression[] = {
		{
			OPERAND,
			1,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERAND,
			2,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERATOR,
			-1,	// �����ʵû���ã����д
			ADD
		},
		{
			OPERAND,
			3,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERATOR,
			-1,	// �����ʵû���ã����д
			ADD
		}
	};

	int result = ReversePolishNotion(expression, 5);

	printf("result = %d\n", result);
}


#pragma once
#include "Stack.h"
#include <string.h>
#include <stdio.h>

int IsValid(char* arr1, char*arr2, int size)
{
	//����һ���Ƚ�ջ
	Stack stack;
	//��ʼ��ջ
	StackInit(&stack);

	//��������ָ��ֱ�ָ����ջ���кͳ�ջ����
	char*input = arr1;
	char*output = arr2;

	//����ջ���е�ÿһ��Ԫ�ؽ��бȽ�
	while (*input != '\0') {

		//����ջ����ָ��input��ָ���Ԫ����ջ
		StackPush(&stack, *input);
		//�ٽ�����ջ��Ԫ��ȡ������Ϊ�˽��бȽϣ�
		StackDataType temp = getTop(&stack);

		//������Ԫ�غͳ�ջ����ָ��output��ָ��Ԫ����ȣ�����Ԫ�س�ջ
		while (temp == *output) {
			StackPop(&stack);
			//֤��output��ǰ��ָ��Ԫ�ؿ��ԺϷ���ջ��output++���Ƚ���һ��Ԫ��
			output++;
			//����ȡջ��Ԫ�����ʱoutput��ָ��Ԫ�ؽ��бȽ�
			if (!StackIsEmpty(&stack)) {
				temp = getTop(&stack);
			}
		}
		//������Ԫ�غͳ�ջ����ָ��output��ָ��Ԫ�ز���ȣ��ͽ���ջ���е���һ��Ԫ����ջ������output��ָ��Ԫ�ؽ��бȽ�
		input++;
	}
	//�����֤����ջ���е�ÿһ��Ԫ�ض����ԺϷ���ջ
	if (*output == '\0') {
		return 1;
	}
	return 0;
}

void TestValid()
{
	 char *in = "abcdefg";
	 char *out1 = "decfbga";
	 char *out2 = "fegdacb";
	 char *out3 = "efdgbca";
	 char *out4 = "cdbefag";

	printf("%s\n", IsValid(in, out1, strlen(in)) ? "�Ϸ�" : "���Ϸ�");
	printf("%s\n", IsValid(in, out2, strlen(in)) ? "�Ϸ�" : "���Ϸ�");
	printf("%s\n", IsValid(in, out3, strlen(in)) ? "�Ϸ�" : "���Ϸ�");
	printf("%s\n", IsValid(in, out4, strlen(in)) ? "�Ϸ�" : "���Ϸ�");
}
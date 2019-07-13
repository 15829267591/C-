#pragma once
#include "Stack.h"
#include <string.h>
#include <stdio.h>

int IsValid(char* arr1, char*arr2, int size)
{
	//定义一个比较栈
	Stack stack;
	//初始化栈
	StackInit(&stack);

	//定义两个指针分别指向入栈序列和出栈序列
	char*input = arr1;
	char*output = arr2;

	//将入栈序列的每一个元素进行比较
	while (*input != '\0') {

		//将入栈序列指针input所指向的元素入栈
		StackPush(&stack, *input);
		//再将刚入栈的元素取出来（为了进行比较）
		StackDataType temp = getTop(&stack);

		//如果这个元素和出栈序列指针output所指的元素相等，将该元素出栈
		while (temp == *output) {
			StackPop(&stack);
			//证明output当前所指的元素可以合法出栈，output++，比较下一个元素
			output++;
			//继续取栈顶元素与此时output所指的元素进行比较
			if (!StackIsEmpty(&stack)) {
				temp = getTop(&stack);
			}
		}
		//如果这个元素和出栈序列指针output所指的元素不相等，就将入栈序列的下一个元素入栈，再与output所指的元素进行比较
		input++;
	}
	//到这里，证明出栈序列的每一个元素都可以合法出栈
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

	printf("%s\n", IsValid(in, out1, strlen(in)) ? "合法" : "不合法");
	printf("%s\n", IsValid(in, out2, strlen(in)) ? "合法" : "不合法");
	printf("%s\n", IsValid(in, out3, strlen(in)) ? "合法" : "不合法");
	printf("%s\n", IsValid(in, out4, strlen(in)) ? "合法" : "不合法");
}
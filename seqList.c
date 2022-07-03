#include <stdio.h>
#define MaxSize 20
typedef int ElementType;

typedef struct seqList {
	ElementType elem[MaxSize];
	int length;	
} SeqList;

// 初始化顺序表
int Init_SeqList(SeqList &L) {
	// 对顺序表本身进行操作，因此需要引用
	L.length = 0;
	return 1;
}


// 顺序表中查找元素
int Locate_SeqList(SeqList &L, ElementType x) {
	int i = 0;
	while(i < L.length && L.elem[i] != x) {
		i++;	
	}
	if(i >= L.length) {
		printf("顺序表中不存在该元素!\n");
		return 0;
	}
	// 查找的是位序，所以找到列表下标后需要+1
	return i+1;
}

// 在第i个插入元素
int Insert_SeqList(SeqList &L, int i, ElementType x) {
	// 插入输入的是位序，从1开始
	int j;
	if(L.length >= MaxSize) {
		printf("顺序表已满，无法再插入!\n");
		return 0;
	}

	// 顺序表不允许存在空值
	if(i <= 0 || i > L.length + 1) {
		printf("插入位置不合法!\n");
		return 0;
	}

	for(j = L.length-1; j >= i-1; j--) {
		L.elem[j+1] = L.elem[j];
	}

	L.elem[i-1] = x;
	L.length += 1;
	return 1;
}

// 删除第i个元素
int Delete_SeqList(SeqList &L, int i) {
	// 删除输入的是位序，从1开始
	int j;
	// 如果删除的位置小于1或者大于顺序表的长度，则说明输入不合法
	if(i < 1 || i > L.length) {
		printf("删除位置不正确!\n");
		return 0;
	}
	for(j = i; j < L.length; j++) {
		L.elem[j-1] = L.elem[j];
	}
	L.length -= 1;
	return 1;
}

// 打印顺序表
void Display_SeqList(SeqList L) {
	int i;
	for(i = 0; i < L.length; i++) {
		printf("%d\n", L.elem[i]);
	}
}

int main() {
	SeqList L;
	int i;
	i = 1;
	Init_SeqList(L);
	printf("初始化, 建立顺序表如下：\n");
	Insert_SeqList(L, 1, 1);
	Insert_SeqList(L, 2, 2);
	Insert_SeqList(L, 3, 3);
	Insert_SeqList(L, 4, 4);
	Insert_SeqList(L, 5, 5);
	printf("原始的顺序表是:\n");
	Display_SeqList(L);
	printf("现在进行删除操作:\n");
	Delete_SeqList(L, 2);
	printf("删除2之后的顺序表是:\n");
	Display_SeqList(L);
	return 0;
}

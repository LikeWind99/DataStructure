#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
typedef int ElementType;

typedef struct SeqList {
	ElementType elem[MAXSIZE];
	int length;
} SeqList;

int InitSeqList(SeqList &L) {
	L.length = 0;
	return OK;
}

int InsertSeqList(SeqList &L, int i, ElementType data) {
	if(L.length >= MAXSIZE) {
		printf("The sequence list is full.\n");
		return ERROR;
	}
	if(L.length < 0 || i > L.length + 1) {
		printf("Invalid insert location.\n");
		return ERROR;
	}
	for(int j = L.length-1; j >= i-1; j--) {
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i-1] = data;
	L.length += 1;
	return OK;
}

int ModifySeqList(SeqList &L, int i, ElementType data, ElementType &value) {
	if(i < 1 || i > L.length) {
		printf("Invalid modification location.\n");
		return ERROR;
	}
	ElementType tmp = L.elem[i-1];
	L.elem[i-1] = data;
	value = tmp;
	return OK;
}

int DeleteSeqList(SeqList &L, int i) {
	if(i < 1 || i > L.length) {
		printf("Invalid delete location.\n");
		return ERROR;
	}
	for(int j = i; j < L.length; j++) {
		L.elem[j-1] = L.elem[j];
	}
	L.length -= 1;
	return OK;
}

int LocateSeqList(SeqList &L, ElementType x) {
	int i = 0;
	while(i < L.length && L.elem[i] != x) {
		i++;
	}
	if(i >= L.length) {
		printf("Not find element in sequence list\n");
		return ERROR;
	}
	return (i+1);
}

void DisplaySeqList(SeqList L) {
	for(int i = 0; i < L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int main() {
	SeqList seqList;
	InitSeqList(seqList);
	for(int i = 0; i < MAXSIZE / 2; i++) {
		InsertSeqList(seqList, 1, MAXSIZE-i);
	}
	printf("Original sequence list is:\n");
	DisplaySeqList(seqList);
	printf("\n");
	printf("Test delete function: ");
	printf("Try to delete 0th element\n");
	DeleteSeqList(seqList, 0);
	printf("Try to delete 5th element\n");
	DeleteSeqList(seqList, 5);
	printf("After delete 5th element: ");
	DisplaySeqList(seqList);
	printf("\n");
	printf("Test insert function: ");
	printf("Try to insert 7th element\n");
	InsertSeqList(seqList, 7, 520);
	printf("After insert 7th element: ");
	DisplaySeqList(seqList);
	printf("Try to insert 13th element\n");
	InsertSeqList(seqList, 13, 520);
	DisplaySeqList(seqList);
	printf("\n");
	printf("Test modify function: ");
	printf("Try to modify 8th element\n");
    ElementType data;
	ModifySeqList(seqList, 8, 521, data);
	printf("The original data of 8th is: %d\n", data);
	DisplaySeqList(seqList);
	printf("\n");
	printf("Test search function: ");
	int returnCode = LocateSeqList(seqList, 520);
	DisplaySeqList(seqList);
	printf("%d is the %dth element\n", 520, returnCode);
	return 0;
}

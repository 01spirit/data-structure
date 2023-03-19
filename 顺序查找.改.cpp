#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	int* data;
	int num;//当前线性表中元素个数 
	int length;
}List;

List* initList(int length){
	List* list=(List*)malloc(sizeof(List));
	list->length=length;
	list->data=(int*)malloc(sizeof(int)*length);
	list->data[0]=0; 
	list->num=1;
	return list;
} 

void listAdd(List* list,int data){
	list->data[list->num]=data;
	list->num=list->num+1;
}

void printList(List* list){
	for(int i=0;i<list->num;i++){
		printf("%d->",list->data[i]);
	}
	printf("NULL\n");
}

int search(List* list,int key){
	int i;
	list->data[0]=key;
	for(i=(list->num);list->data[i]!=key;i--){
		
	}
	return i;
}

int main(){
	List* list=initList(5);
	listAdd(list,10);
	listAdd(list,20);
	listAdd(list,30);
	listAdd(list,40);
	listAdd(list,50);
	printList(list);
	printf("%d\n",search(list,40));
	return 0;
}

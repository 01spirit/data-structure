#include<stdio.h>
#include<stdlib.h> 
typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* InitList(){
	Node* L = (Node*)malloc(sizeof(Node));
	L->data=0;
	L->next=L;
	return L;
}

//头插法 
void HeadInsert(Node* L,int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=L->next;
	L->next=node;
	L->data++;  
}

//尾插法
void TailInsert(Node* L,int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data=data;
	Node* n=L;
	while(n->next!=L){
		n=n->next;
	}
	node->next=L;
	n->next=node;
	L->data++;
} 
//输出链表
void printList(Node* L){
	Node* node=L->next;
	while(node!=L){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL\n");
} 

//删除
int Delete(Node* L,int data){
	Node* node = L->next;
	Node* preNode = L;
	while(node!=L){
		if(node->data==data){
			preNode->next=node->next;
			free(node);
			return 1;
		}
		preNode=node;
		node=node->next;
	}
	return 0;
} 
int main(){
	Node* L=InitList();
	HeadInsert(L,1);
	HeadInsert(L,2);
	HeadInsert(L,30);
	HeadInsert(L,4);
	HeadInsert(L,5);
	
	TailInsert(L,8);
	TailInsert(L,9);
	TailInsert(L,12);
	
	printList(L);
	printf("\n");
	
	Delete(L,30);
	printList(L);
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* pre;
	struct  Node* next;
}Node;

Node* InitList(){
	Node* L=(Node*)malloc(sizeof(Node));
	L->data=0;
	L->next=L;
	L->pre=L;
	return L;
}

//ͷ�巨
void HeadInsert(Node* L,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	if(L->data==0){//����Ϊ�� 
		node->pre=L;
		node->next=L->next;
		L->next=node;
		L->pre=node;
		L->data++;
	}
	
	else{
		node->next=L->next;
		node->pre=L;
		L->next->pre=node;
		L->next=node;
		L->data++;
	}
} 

//β�巨
void TailInsert(Node* L,int data){
	Node* node=L;
	while(node->next!=L){
		node=node->next;
	}
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->pre=node;
	n->next=L;
	L->pre=n;
	node->next=n;//L��ͷ��㣬node�Ǳ���������β���Ľڵ� 
	L->data++;
} 

//��ӡ����
void printList(Node* L){
	Node* node=L->next;
	while(node!=L){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL\n");
} 

//ɾ��
int Delete(Node* L,int data){
	Node*node=L->next;
	while(node!=L){
		if(node->data==data){
			node->next->pre=node->pre;
			node->pre->next=node->next;
			free(node);
			L->data--;
			return 1;
		}
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
	
	printList(L);
	
	TailInsert(L,6);
	TailInsert(L,10);
	
	printList(L);
	
	Delete(L,4);
	Delete(L,10);
	
	printList(L);
	
	return 0;
}

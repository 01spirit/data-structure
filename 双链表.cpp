#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

//��ʼ�� 
Node* InitList(){
	Node* L=(Node*)malloc(sizeof(Node));
    L->data=0;
	L->next=NULL;
	L->pre=NULL;
	return L;	
}

//ͷ�巨
void HeadInsert(Node* L,int data){
	Node*node=(Node*)malloc(sizeof(Node));
	node->data=data;
	
    if(L->data==0){//������ 
    	node->next=L->next;
    	node->pre=L;
    	L->next=node;
    	L->data++;
	}
	
	else{
		node->pre=L;
		node->next=L->next;
		L->next->pre=node;
		L->next=node;
		L->data++;
	}
	
} 

//β�巨
void TailInsert(Node* L,int data){
	Node* node=L;
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	while(node->next){
		node=node->next;
	}
	n->next=node->next;
	node->next=n;
	n->pre=node;
	L->data++;
}

//��ӡ����
void printList(Node* L){
	Node* node=L->next;
	while(node){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL\n");
} 

//ɾ��
int Delete(Node* L,int data){
	Node* node=L;
	while(node->next!=NULL){
		if(node->data==data){
			node->pre->next=node->next;
			node->next->pre=node->pre;
			free(node);
			return 1;
		}
		node=node->next;
	}
	
if(node!=NULL&&node->next==NULL&&node->data==data){
		node->pre->next=NULL;
		free(node);
		return 1;
	}//����������һ��Ԫ�ؽ��д��������ѭ�� û�취��������Ԫ�� 
	
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
	TailInsert(L,9);
	TailInsert(L,15);
	
	printList(L);
	
	Delete(L,30);
	Delete(L,15);
	
	printList(L);
	
	return 0;
}

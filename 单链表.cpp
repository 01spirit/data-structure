#include<stdio.h>
#include<stdlib.h>
//linklist
typedef struct Node{
	int data;
	struct Node* next;
}Node;//������������
Node* InitList(){
	Node* L=(Node*)malloc(sizeof(Node));
	L->data=0;
	L->next=NULL;
	return L;
}

//ͷ�巨
void HeadInsert(Node* L,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=L->next;
	L->next=node;
	L->data++;//��data���¼�������ж���Ԫ�أ�ÿ����һ��Ԫ�ؾ�Ҫ��������������� 
} 

//β�巨
void TailInsert(Node* L,int data){
	Node* node=L;
	for(int i=0;i<L->data;i++){
		node=node->next;
	}//�ҵ�����ĩβ 
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->next=NULL;
	node->next=n;
	L->data++;
} 

//��ӡ�ڵ� 
void printList(Node* L){
	Node* node=L->next;
	while(node){
		printf("node=%d\n",node->data);
		node=node->next;
	}
}

//ɾ��
int Delete(Node* L,int data){
	Node* node=L->next;
	Node* preNode=L;
	while(node){
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
	
    TailInsert(L,6);
	TailInsert(L,7);
	TailInsert(L,9); 
	printList(L);
	
	if(Delete(L,30)){
		printf("success\n");
		printList(L);
	}
	else{
		printf("defeat\n");
	}
	
	return 0;
}
 

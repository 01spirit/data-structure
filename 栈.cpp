#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

//��ʼ��
Node* InitStack(){
	Node* S=(Node*)malloc(sizeof(Node));
	S->data=0;
	S->next=NULL;
	return S;
} 

//�ж�ջ�� 
int isEmpty(Node* S){
	if(S->data==0||S->next==NULL){
		return 1;
	}
	else{
		return 0;
	}
} 

//��ȡջ��Ԫ��
int getTop(Node*S){
	if(isEmpty(S)){
		return -1;
	}
	else{
		return S->next->data;
	}
} 

//��ջ
void push(Node* S,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=S->next;
	S->next=node;
	S->data++;
} //����Ĵ����൱�ڲ��뵽����ͷ�� 

//��ջ
int pop(Node*S){
	if(isEmpty(S)){
		return -1;
	}
	else{
		Node*node=S->next;
		S->next=node->next;
		int data=node->data;
		free(node);
		return data;
	}
} 

//��ӡջ
void printStack(Node* S){
	Node* node=S->next;
	while(node){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL\n");
} 

int main(){
	Node* S=InitStack();
	push(S,1);
	push(S,2);
	push(S,30);
	push(S,4);
	
	printStack(S);
	
	pop(S);
	printf("\n%d\n",pop(S));
	printf("\n");
	printStack(S);
	
	return 0;
}

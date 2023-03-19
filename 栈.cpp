#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

//初始化
Node* InitStack(){
	Node* S=(Node*)malloc(sizeof(Node));
	S->data=0;
	S->next=NULL;
	return S;
} 

//判断栈空 
int isEmpty(Node* S){
	if(S->data==0||S->next==NULL){
		return 1;
	}
	else{
		return 0;
	}
} 

//获取栈顶元素
int getTop(Node*S){
	if(isEmpty(S)){
		return -1;
	}
	else{
		return S->next->data;
	}
} 

//入栈
void push(Node* S,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=S->next;
	S->next=node;
	S->data++;
} //这里的处理相当于插入到链表头部 

//出栈
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

//打印栈
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

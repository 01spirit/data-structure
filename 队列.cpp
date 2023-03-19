#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node; 

//初始化队列
Node* InitQueue(){
	Node* Q=(Node*)malloc(sizeof(Node));
	Q->data=0;
	Q->next=NULL;
	return Q;
} 

//入队
Node* enQueue(Node* Q,int data){
	Node* q=Q ;
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	
	for(int i=0;i<Q-> data;i++){
		q=q->next;
	}
	node->next=q->next;
	q->next=node;
	Q->data++;
} //这里的操作相当于插入到链表的尾部 

//判断为空 
int isEmpty(Node* Q){
	if(Q->data==0||Q->next==NULL){
		return 1;
	}
	else{
		return 0;
	}
} 

//出队
int deQueue(Node* Q){
	if(isEmpty(Q)){
		return -1;
	}
	else{
		Node* node=Q->next;
		int data=node->data;
		Q->next=node->next;
		free(node);
		return data;
	}
} 

//打印 
void printQueue(Node* Q){
	Node* node=Q->next;
	while(node){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL\n");
} 

int main(){
	Node* Q=InitQueue();
	enQueue(Q,1 );
	enQueue(Q,2);
	enQueue(Q,30);
	enQueue(Q,5);
	printQueue(Q);
	deQueue(Q);
	deQueue(Q);

	printQueue(Q);
	
	return 0;
} 

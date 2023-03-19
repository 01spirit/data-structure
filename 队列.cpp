#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node; 

//��ʼ������
Node* InitQueue(){
	Node* Q=(Node*)malloc(sizeof(Node));
	Q->data=0;
	Q->next=NULL;
	return Q;
} 

//���
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
} //����Ĳ����൱�ڲ��뵽�����β�� 

//�ж�Ϊ�� 
int isEmpty(Node* Q){
	if(Q->data==0||Q->next==NULL){
		return 1;
	}
	else{
		return 0;
	}
} 

//����
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

//��ӡ 
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

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

//初始化 
Node* InitList(){
	Node* L=(Node*)malloc(sizeof(Node));
    L->data=0;
	L->next=NULL;
	L->pre=NULL;
	return L;	
}

//头插法
void HeadInsert(Node* L,int data){
	Node*node=(Node*)malloc(sizeof(Node));
	node->data=data;
	
    if(L->data==0){//空链表 
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

//尾插法
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

//打印链表
void printList(Node* L){
	Node* node=L->next;
	while(node){
		printf("%d->",node->data);
		node=node->next;
	}
	printf("NULL\n");
} 

//删除
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
	}//对链表的最后一个元素进行处理，上面的循环 没办法处理最后的元素 
	
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

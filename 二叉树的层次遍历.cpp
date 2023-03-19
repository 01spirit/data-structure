#include<stdio.h>
#include<stdlib.h>
/*
    *将二叉树中元素存入队列中以实现层次便利
    *访问二叉树的元素即将该元素出队
    *元素出队时将其左右孩子入队
    *队列有先进先出的特点
    *上一层的节点遍历完后开始由左到右遍历入队的子节点
*/
typedef struct TreeNode{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode; 

typedef struct QueueNode{
	TreeNode* data;
	struct QueueNode* pre;
	struct QueueNode* next;
}QueueNode;

void creatTree(TreeNode** T,char* data,int* index){
	char ch;
	ch=data[*index];
	*index+=1;
	if(ch=='#'){
		*T=NULL;
	}
	else{
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=ch;
		creatTree(&((*T)->lchild),data,index);
		creatTree(&((*T)->rchild),data,index);
	}
}
 
void preOrder(TreeNode* T){
	if(T==NULL){
		return;
	}
	else{
		printf("%c ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

QueueNode* InitQueue(){
	QueueNode* Q=(QueueNode*)malloc(sizeof(QueueNode));
	Q->data=NULL;
	Q->next=Q;
	Q->pre=Q;
	return Q; 
}

void enQueue(TreeNode* data,QueueNode* Q){
	QueueNode* node=(QueueNode*)malloc(sizeof(QueueNode));
	node->data=data;
	node->pre=Q;
	node->next=Q;
	Q->pre->next=node;
	Q->pre=node; 
}

int isEmpty(QueueNode* Q){
	if(Q->next==Q){
		return 1;
	}
	else{
		return 0;
	}
}

QueueNode* deQueue(QueueNode* Q){
	if(isEmpty(Q)){
		return NULL;
	}
	else{ 
		QueueNode* node=Q->next;
		Q->next->next->pre=Q;
		Q->next=Q->next->next;
		return node;
	}
}

void levelTraverse(QueueNode* Q,TreeNode* T){
	enQueue(T,Q);
	while(!isEmpty(Q)){
		QueueNode* node=deQueue(Q);
		printf("%c ",node->data->data);
		if(node->data->lchild){
			enQueue(node->data->lchild,Q);
		}
		if(node->data->rchild){
			enQueue(node->data->rchild,Q);
		}
	}
}

int main(int argc,char* argv[]){
	TreeNode* T;
	int* index=0;
	QueueNode* Q=InitQueue();
	creatTree(&T,argv[1],index);
	preOrder(T);
	printf("\n");
	levelTraverse(Q,T);
	printf("\n");
	
	return 0;
} 

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
	int ltag;
	int rtag;
}TreeNode;

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
		(*T)->ltag=0;
		(*T)->rtag=0;
		creatTree(&((*T)->lchild),data,index);
		creatTree(&((*T)->rchild),data,index);
	}
}

//初始化
void inThreadTree(TreeNode* T,TreeNode** pre){
	if(T){
		inThreadTree(T->lchild,pre);
		if(T->lchild==NULL){
			T->ltag=1;
			T->lchild=*pre;
		}
		if(*pre!=NULL&&(*pre)->rchild==NULL){
			(*pre)->rtag=1;
			(*pre)->rchild=T;
		}
		inThreadTree(T->rchild,pre);
	}
} 

//遍历
TreeNode* getFirst(TreeNode* T){
	while(T->ltag==0){//左子树不为空，先向下遍历左子树 
		T=T->lchild;
	}
	return T;//直到找到左子树为空的节点，返回该节点 
} 

TreeNode* getNext(TreeNode* node){
	if(node->rtag==1){//右子树为空，返回右子树指向的节点 
		return node->rchild;
	}
	else{//右子树不为空，在右子树中遍历左子树 
		return getFirst(node->rchild);
	}
}

int main(int argc,char* argv[]){
	TreeNode* T;
	TreeNode* pre=NULL;
	int index=0;
	creatTree(&T,argv[1],&index);
	inThreadTree(T,&pre);
	pre->rtag=1;
	pre->rchild=NULL; 
	for(TreeNode* node=getFirst(T);node!=NULL;node=getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

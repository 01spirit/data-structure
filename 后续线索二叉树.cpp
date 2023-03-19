#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	char data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
	struct TreeNode* parent; 
	int ltag;
	int rtag;
}TreeNode;

void creatTree(TreeNode** T,char* data,int* index,TreeNode* parent){
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
		(*T)->parent=parent;
		creatTree(&((*T)->lchild),data,index,*T);
		creatTree(&((*T)->rchild),data,index,*T);
	}
}

//后序  
void postThreadTree(TreeNode* T,TreeNode** pre){
	if(T){
		postThreadTree(T->lchild,pre);
		postThreadTree(T->rchild,pre);
		if(T->lchild==NULL){
			T->ltag=1;
			T->lchild=*pre;
		}
		if(*pre!=NULL&&(*pre)->rchild==NULL){
			(*pre)->rtag=1;
			(*pre)->rchild=T;
		}
	}
} 

//遍历
TreeNode* getFirst(TreeNode* T){
	while(T->ltag==0){//遍历左子树，直到没有左子树 
		T=T->lchild;
	}
	if(T->rtag==0){//若最后一个左子树存在右子树，寻找右子树中的最后一个结点 
		return getFirst(T->rchild);
	}
	return T;//左子树为叶子节点，返回该节点 
} 

TreeNode* getNext(TreeNode* node){
	if(node->rtag==1){//node没有右孩子，而且已经线索化了，直接返回 
		return node->rchild;
	}
	else{//node有右孩子 
		if(node->parent==NULL){//node是根节点 ，没有后继 
			return NULL;
		}
		else if(node->parent->rchild==node){//node是右孩子，后继为双亲结点 
			return node->parent;
		}
		else{//node是左孩子 ，判断父亲结点的右子树是否为空，为空，next=parent；不为空，向下遍历 右子树 
			if(node->parent->rtag==0){//左子树不为空，向下遍历右子树 
			    return getFirst(node->parent->rchild);
			}
			else{
				return node->parent;
			}
		}
	}
}

int main(int argc,char* argv[]){
	TreeNode* T;
	TreeNode* pre=NULL;
	int index=0;
	creatTree(&T,argv[1],&index,NULL);
	postThreadTree(T,&pre);
	pre->rtag=1;
	pre->rchild=NULL; 
	for(TreeNode* node=getFirst(T);node!=NULL;node=getNext(node)){
		printf("%c ",node->data);
	}
	printf("\n");
	return 0;
}

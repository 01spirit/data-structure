 #include<stdio.h> 
 #include<stdlib.h>
 
 typedef struct TreeNode{
 	char data;
 	struct TreeNode* lchild;
 	struct TreeNode* rchild;
 }TreeNode;
 
 //创建二叉树
void creatTree(TreeNode** T,char* data,int* index ){
 	char ch;
 	ch=data[*index];
 	*index++;
 	if(ch=='#'){//空结点 
 		*T=NULL;
	}
	else{
		*T=(TreeNode*)malloc(sizeof(TreeNode));
	 	(*T)->data=ch;
	 	creatTree(&((*T)->lchild),data,index);
	 	creatTree(&((*T)->rchild),data,index);
	}
} 

//先序遍历
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

//中序遍历
void inOrder(TreeNode* T){
	if(T==NULL){
		return;
	}
	else{
		inOrder(T->lchild);
		printf("%c ",T->data);
		inOrder(T->rchild);
	}
}

//后序遍历
void postOrder(TreeNode* T){
	if(T==NULL){
		return;
	}
	else{
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ",T->data);
	}
}

int main(int argc,char*argv[]){
	TreeNode* T;
	int index=0;
	creatTree(&T,argv[1],&index);
	preOrder(T); 
	return 0;
}

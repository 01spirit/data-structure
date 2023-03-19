#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

//查找 
TreeNode* bstSearch(TreeNode* T,int data){
	if(T){//二叉树不为空 
		if(T->data==data){//找到对应关键字，返回结点 
			return T;
		}
		else if(data<T->data){//关键字比结点小 ，在左子树中查找 
			return bstSearch(T->lchild,data);
		}
		else{//关键字比结点大，在右子树中查找 
			return bstSearch(T->rchild,data);
		}
	}
	else{//二叉树为空 
		return NULL;
	}
}

//向二叉树中插入元素，用于创建平衡二叉树 
void bstInsert(TreeNode** T,int data){//因为要改变指针的值，要传入二级指针 
	if(*T==NULL){
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=data;
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
	} 
	else if(data==(*T)->data){
		return;//在二叉树中已存在，不插入 
	}
	else if(data<(*T)->data){//小于结点值，在左子树中查找合适位置 
		bstInsert(&(*T)->lchild,data);
	}
	else{//大于结点值，在右子树中查找 
		bstInsert(&(*T)->rchild,data);
	}
} 

//先序遍历，用于验证，创建的二叉排序树是否正确
void preOrder(TreeNode* T){
	if(T){//如果不写if，递归会在左子树为空时结束而不是继续遍历右子树 
		printf("%d ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
	
} 


int main(){
	TreeNode* T=NULL;
	int nums[8]={4,5,19,3,1,23,2,8};
	for(int i=0;i<8;i++){
		bstInsert(&T,nums[i]);
	}
	preOrder(T);
	printf("\n");
	
	
	
	return 0;
}

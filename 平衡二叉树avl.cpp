#include<stdio.h>
#include<stdlib.h>
//左右子树高度差不超过1，本质上和构建二叉排序树一致，在构建二叉排序树的过程中，如果发现树不符合特性，需进行调整
//调整：找到失衡树的根节点root，找到导致树失衡的结点node，判断node在root的哪一侧，判断node在root孩子的哪一侧
//RR：取中间节点，使他的父亲节点成为他的左孩子，如果他有左孩子的话，这个左孩子连接到父亲的右孩子上面
//LL:取中间节点，将他的父亲作为自己的右孩子，如果自己有右孩子，将右孩子连接到父亲的左孩子上 
/*LR：取最后一个节点，作为父节点，将他的父亲的父亲作为自己的右孩子，如果他有左孩子或右孩子，
      他原先的左孩子连接到父亲的右孩子上，他现在的右孩子连接到父亲的父亲的左孩子上
*/
/*RL；取最后一个节点作为父亲节点，将他原先的父亲作为自己的右孩子，将父亲的父亲作为自己的左孩子，如果自己有左孩子或右孩子的话，
      自己原先的左孩子连接到父亲的父亲的右孩子上面，原先的右孩子连接到父亲的左孩子上 
*/
//如果遇到多棵树不平衡，选择最小树
 
typedef struct TreeNode{
	int data;
	int height;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode; 

int getHeight(TreeNode* node){
	return node?node->height:0;
}

int max(int a,int b){
	return a>b?a:b;
} 

void rrRotation(TreeNode* node,TreeNode** root){//node为父亲节点，temp为node的右孩子，即中间节点，后续具体操作见开头 
	TreeNode* temp=node->rchild;
	node->rchild=temp->lchild;
	temp->lchild=node;
	node->height=max(getHeight(node->lchild),getHeight(node->rchild))+1;
	temp->height=max(getHeight(temp->lchild),getHeight(temp->rchild))+1;
	*root=temp;
}

void llRotation(TreeNode* node,TreeNode** root){
	TreeNode* temp=node->lchild;
	node->lchild=temp->rchild;
	temp->rchild=node;
	node->height=max(getHeight(node->lchild),getHeight(node->rchild))+1;
	temp->height=max(getHeight(temp->lchild),getHeight(temp->rchild))+1;
	*root=temp; 
} 



void avlInsert(TreeNode** T,int data){
	if(*T==NULL){
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=data;
		(*T)->height=0;
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
	}
	else if(data<(*T)->data){
		avlInsert(&(*T)->lchild,data);
		int lHeight=getHeight((*T)->lchild);
		int rHeight=getHeight((*T)->rchild);
		//判断高度差
		if(lHeight-rHeight==2){
			if(data<(*T)->lchild->data){//LL
				llRotation(*T,T);
			}
			else{//LR
				rrRotation((*T)->lchild,&(*T)->lchild);
				llRotation(*T,T);
			}
		} 
		
	}
	else if(data>(*T)->data){
		avlInsert(&(*T)->rchild,data);
		int lHeight=getHeight((*T)->lchild);
		int rHeight=getHeight((*T)->rchild);
		if(rHeight-lHeight==2){
			if(data>(*T)->rchild->data){//RR
				rrRotation(*T,T);
			}
			else{//RL
				llRotation((*T)->rchild,&(*T)->rchild);
				rrRotation(*T,T);
			}
		}
	
	}
	(*T)->height=max(getHeight((*T)->lchild),getHeight((*T)->rchild))+1;//在递归中增加树的高度，非常重要，需要理解 
}

void preOrder(TreeNode* T){
	if(T){
		printf("%d ",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

int main(){
	TreeNode* T=NULL;
	int nums[5]={1,2,3,4,5};
	for(int i=0;i<5;i++){
		avlInsert(&T,nums[i]);
	}
	preOrder(T);
	
	printf("\n");
	printf("%d",T->height);
	
	return 0;
}

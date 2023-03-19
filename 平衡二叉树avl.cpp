#include<stdio.h>
#include<stdlib.h>
//���������߶Ȳ����1�������Ϻ͹�������������һ�£��ڹ��������������Ĺ����У�������������������ԣ�����е���
//�������ҵ�ʧ�����ĸ��ڵ�root���ҵ�������ʧ��Ľ��node���ж�node��root����һ�࣬�ж�node��root���ӵ���һ��
//RR��ȡ�м�ڵ㣬ʹ���ĸ��׽ڵ��Ϊ�������ӣ�����������ӵĻ�������������ӵ����׵��Һ�������
//LL:ȡ�м�ڵ㣬�����ĸ�����Ϊ�Լ����Һ��ӣ�����Լ����Һ��ӣ����Һ������ӵ����׵������� 
/*LR��ȡ���һ���ڵ㣬��Ϊ���ڵ㣬�����ĸ��׵ĸ�����Ϊ�Լ����Һ��ӣ�����������ӻ��Һ��ӣ�
      ��ԭ�ȵ��������ӵ����׵��Һ����ϣ������ڵ��Һ������ӵ����׵ĸ��׵�������
*/
/*RL��ȡ���һ���ڵ���Ϊ���׽ڵ㣬����ԭ�ȵĸ�����Ϊ�Լ����Һ��ӣ������׵ĸ�����Ϊ�Լ������ӣ�����Լ������ӻ��Һ��ӵĻ���
      �Լ�ԭ�ȵ��������ӵ����׵ĸ��׵��Һ������棬ԭ�ȵ��Һ������ӵ����׵������� 
*/
//��������������ƽ�⣬ѡ����С��
 
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

void rrRotation(TreeNode* node,TreeNode** root){//nodeΪ���׽ڵ㣬tempΪnode���Һ��ӣ����м�ڵ㣬���������������ͷ 
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
		//�жϸ߶Ȳ�
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
	(*T)->height=max(getHeight((*T)->lchild),getHeight((*T)->rchild))+1;//�ڵݹ����������ĸ߶ȣ��ǳ���Ҫ����Ҫ��� 
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

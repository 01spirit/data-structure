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

//����  
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

//����
TreeNode* getFirst(TreeNode* T){
	while(T->ltag==0){//������������ֱ��û�������� 
		T=T->lchild;
	}
	if(T->rtag==0){//�����һ��������������������Ѱ���������е����һ����� 
		return getFirst(T->rchild);
	}
	return T;//������ΪҶ�ӽڵ㣬���ظýڵ� 
} 

TreeNode* getNext(TreeNode* node){
	if(node->rtag==1){//nodeû���Һ��ӣ������Ѿ��������ˣ�ֱ�ӷ��� 
		return node->rchild;
	}
	else{//node���Һ��� 
		if(node->parent==NULL){//node�Ǹ��ڵ� ��û�к�� 
			return NULL;
		}
		else if(node->parent->rchild==node){//node���Һ��ӣ����Ϊ˫�׽�� 
			return node->parent;
		}
		else{//node������ ���жϸ��׽����������Ƿ�Ϊ�գ�Ϊ�գ�next=parent����Ϊ�գ����±��� ������ 
			if(node->parent->rtag==0){//��������Ϊ�գ����±��������� 
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

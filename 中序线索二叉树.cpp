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

//��ʼ��
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

//����
TreeNode* getFirst(TreeNode* T){
	while(T->ltag==0){//��������Ϊ�գ������±��������� 
		T=T->lchild;
	}
	return T;//ֱ���ҵ�������Ϊ�յĽڵ㣬���ظýڵ� 
} 

TreeNode* getNext(TreeNode* node){
	if(node->rtag==1){//������Ϊ�գ�����������ָ��Ľڵ� 
		return node->rchild;
	}
	else{//��������Ϊ�գ����������б��������� 
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

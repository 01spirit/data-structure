#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

//���� 
TreeNode* bstSearch(TreeNode* T,int data){
	if(T){//��������Ϊ�� 
		if(T->data==data){//�ҵ���Ӧ�ؼ��֣����ؽ�� 
			return T;
		}
		else if(data<T->data){//�ؼ��ֱȽ��С �����������в��� 
			return bstSearch(T->lchild,data);
		}
		else{//�ؼ��ֱȽ������������в��� 
			return bstSearch(T->rchild,data);
		}
	}
	else{//������Ϊ�� 
		return NULL;
	}
}

//��������в���Ԫ�أ����ڴ���ƽ������� 
void bstInsert(TreeNode** T,int data){//��ΪҪ�ı�ָ���ֵ��Ҫ�������ָ�� 
	if(*T==NULL){
		*T=(TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data=data;
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
	} 
	else if(data==(*T)->data){
		return;//�ڶ��������Ѵ��ڣ������� 
	}
	else if(data<(*T)->data){//С�ڽ��ֵ�����������в��Һ���λ�� 
		bstInsert(&(*T)->lchild,data);
	}
	else{//���ڽ��ֵ�����������в��� 
		bstInsert(&(*T)->rchild,data);
	}
} 

//���������������֤�������Ķ����������Ƿ���ȷ
void preOrder(TreeNode* T){
	if(T){//�����дif���ݹ����������Ϊ��ʱ���������Ǽ������������� 
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

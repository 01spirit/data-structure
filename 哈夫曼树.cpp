//哈夫曼树所有叶子节点的带权路径长度最小，权值越大的结点路径越短 
/*生成方法：
    1.从结点列表中选出第一小和第二小的结点组成一棵树，父亲结点的权值=两节点权值之和
	2.将生成的新树再次放入节点列表中，重复第一步，直到结点中只剩下一个节点
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
	int weight;
	int parent;
	int lchild;
	int rchild;
}TreeNode;

typedef struct HFTree{
	TreeNode* data;
	int length;
}HFTree;

//初始化树，weight是一串权值，length是权值的数量 
HFTree* initTree(int* weight,int length){
	HFTree* T=(HFTree*)malloc(sizeof(HFTree));
	T->data=(TreeNode*)malloc(sizeof(TreeNode)*(2*length-1));//n个权值对应有2n-1个结点， 
	T->length=length;
	for(int i=0;i<length;i++){
		T->data[i].weight=weight[i];
		T->data[i].parent=0;
		T->data[i].lchild=-1;
		T->data[i].rchild=-1;
	}
	return T;
}

//选择两个最小的权值
int* selectMin(HFTree* T){
	int min=10000;
	int secondMin=10000;
	int minIndex;
	int secondIndex;
	for(int i=0;i<T->length;i++){
		if(T->data[i].parent==0){
			if(T->data[i].weight<min){
				min=T->data[i].weight;
				minIndex=i;
			}
		}
	}
	for(int i=0;i<T->length;i++){
		if(T->data[i].parent==0&&i!=minIndex){
			if(T->data[i].weight<secondMin){
				secondMin=T->data[i].weight;
				secondIndex=i;
			}
		}
	}
	int* res=(int*)malloc(sizeof(int)*2);
	res[0]=minIndex;
	res[1]=secondIndex;
	return res;
} 

//创建哈夫曼树
void creatHFTree(HFTree* T){
	int* res;
	int min;
	int secondMin;
	int length=T->length*2-1;
	for(int i=T->length;i<length;i++){
		res=selectMin(T);
		min=res[0];
		secondMin=res[1];
		T->data[i].weight=T->data[min].weight+T->data[secondMin].weight;
		T->data[i].lchild=min;
		T->data[i].rchild=secondMin;
		T->data[min].parent=i;
		T->data[secondMin].parent=i;
		T->length++;
	}
} 

//遍历
void preOrder(HFTree* T,int index){
	if(index!=-1){
		printf("%d ",T->data[index].weight);
		preOrder(T,T->data[index].lchild);
		preOrder(T,T->data[index].rchild);
	}
} 

int main(){
	int weight[4]={1,2,3,4};
	HFTree* T=initTree(weight,4);
	creatHFTree(T);
	preOrder(T,T->length-1);
	printf("\n");
//	printf("%d ",T->length);
	for(int i=0;i<T->length;i++){
		printf("%d ",T->data[i].weight);
	} 
/*	printf("%d ",res[0]);
	printf("%d ",res[1]);*/
	return 0;
} 

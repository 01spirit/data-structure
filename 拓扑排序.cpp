/*
 *有向无环图DAG
 *AOV图的节点表示任务，弧表示先后依赖关系
 *拓扑排序概念：将AOV中的顶点排成一个线性序列如果vi->vj有弧的话，那么vi必在vj前面
 *流程：1.找出没有前驱的点，输出他，剪掉以他为出发点的所有边
 *2.重复第一步，直到图中不存在没有前驱的点
*/
#include<stdio.h>
#include<stdlib.h>


typedef struct Graph{
	char* vexs;//顶点 
	int** arcs;//边
	int vexNum;//顶点数
	int arcNum;//边数 
}Graph;

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* initStack(){
	Node* stack=(Node*)malloc(sizeof(Node));
	stack->data=0;
	stack->next=NULL;
	return stack;
}

void push(Node* stack,int data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=stack->next;
	stack->next=node;
	stack->data++;
}

int isEmpty(Node* stack){
	if(stack->next==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int pop(Node*stack){
	if(!isEmpty(stack)){
		Node* node=stack->next;
		stack->next=node->next;
		return node->data;
	}
	else{
		return -1;
	}
}

int* findInDegrees(Graph* G){//入度 
	int* inDegrees=(int*)malloc(sizeof(int)*G->vexNum);
	for(int i=0;i<G->vexNum;i++){
		inDegrees[i]=0;
	}
	for(int i=0;i<G->vexNum;i++){
		for(int j=0;j<G->vexNum;j++){
			if(G->arcs[i][j]){
				inDegrees[j]=inDegrees[j]+1;
			}
		}
	}
	return inDegrees;
} 

void topologicalSort(Graph* G){
	int index=0;
	Node* stack=initStack();
	int* inDegrees=findInDegrees(G);
	int* top=(int*)malloc(sizeof(int)*G->vexNum);
	for(int i=0;i<G->vexNum;i++){//入度为零的点入栈 
		if(inDegrees[i]==0){
			push(stack,i);
		}
	}
	while(!isEmpty(stack)){
		int vex=pop(stack);
		top[index++]=vex;
		for(int i=0;i<G->vexNum;i++){
			if(G->arcs[vex][i]){
			inDegrees[i]=inDegrees[i]-1;
			if(inDegrees[i]==0){
				push(stack,i);
			}
			}
		}
	}
	for(int i=0;i<index;i++){
		printf("%c ",G->vexs[top[i]]);
	}
	printf("\n");
}

//初始化
Graph* initGraph(int vexNum){
	Graph* G=(Graph*)malloc(sizeof(Graph));
	G->vexs=(char*)malloc(sizeof(char)*vexNum);
	G->arcs=(int**)malloc(sizeof(int*)*vexNum);//使用的邻接矩阵，用二级指针
	for(int i=0;i<vexNum;i++){
		G->arcs[i]=(int*)malloc(sizeof(int)*vexNum);
	} 
	G->vexNum=vexNum;
	G->arcNum=0;
	return G;
} 

//创建图
void creatGraph(Graph* G,char* vexs,int* arcs){
	for(int i=0;i<G->vexNum;i++){
		G->vexs[i]=vexs[i];
		for(int j=0;j<G->vexNum;j++){
			G->arcs[i][j]=*(arcs+i*G->vexNum+j);
			if(G->arcs[i][j]!=0){
				G->arcNum++;
			}
		}
	}
	G->arcNum/=2;//无向图，边数减半 
} 

//图的遍历
 
void DFS(Graph* G,int* visited,int index){
	printf("%c\t",G->vexs[index]);
	visited[index]=1;
	for(int i=0;i<G->vexNum;i++){
		if(G->arcs[index][i]==1&&!visited[i]){///邻接矩阵为一且未被访问过，则对该节点进行遍历 
			DFS(G,visited,i);
		}
	}
}

int main(){
	Graph* G=initGraph(6);
	int* visited=(int*)malloc(sizeof(int)*G->vexNum);
	for(int i=0;i<G->vexNum;i++){
		visited[i]=0;
	}
	int arcs[6][6]={
	0,1,1,1,0,0,
	0,0,0,0,0,0,
	0,1,0,0,1,0,
	0,0,0,0,1,0,
	0,0,0,0,0,0,
	0,0,0,1,1,0
	};
	creatGraph(G,"123456",(int*)arcs);
	DFS(G,visited,0);
	printf("\n");
	topologicalSort(G);
	return 0;
} 

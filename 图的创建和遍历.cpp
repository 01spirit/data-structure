//DFS深度优先遍历（类似于树的先根遍历） 
/*    1.找一个节点访问
      2.找这个节点可以到达的节点去访问
	  3.重复第一步直到所有节点访问完毕
*/

//BFS广度优先遍历 （类似于树的按层次遍历） 
/*
      用循环队列实现 
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5 

typedef struct Graph{
	char* vexs;//顶点 
	int** arcs;//边
	int vexNum;//顶点数
	int arcNum;//边数 
}Graph;

typedef struct Queue{
	int front;
	int rear;
	int data[MAXSIZE];
}Queue;

Queue* initQueue(){
	Queue* Q=(Queue*)malloc(sizeof(Queue));
	Q->front=Q->rear=0;
	return Q;
}

//判断队满
int isFull(Queue* Q){
	if((Q->rear+1)%MAXSIZE==Q->front){
		return 1;
	}
	else{
		return 0;
	}
} 

//入队
int enQueue(Queue* Q,int data){
	if(isFull(Q)){//队满，进入失败 
		return 0;
	}
	else{
		Q->data[Q->rear]=data;
		Q->rear=(Q->rear+1)%MAXSIZE; 
		return 1;
	}
} 

//判断为空
int isEmpty(Queue* Q){
	if(Q->front==Q->rear){
		return 1;
	}
	else{
		return 0;
	}
} 

//出队
int deQueue(Queue* Q){
    if(isEmpty(Q)){
    	return -1;
	}	
	else{
		int data=Q->data[Q->front];
		Q->front=(Q->front+1)%MAXSIZE;
		return data; 
	}
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

void BFS(Graph* G,int* visited,int index){
	Queue* Q=initQueue();
	printf("%c\t",G->vexs[index]);
	visited[index]=1;
	enQueue(Q,index);
	while(!isEmpty(Q)){
		int i=deQueue(Q);
		for(int j=0;j<G->vexNum;j++){
			if(G->arcs[i][j]==1&&!visited[j]){
				printf("%c\t",G->vexs[j]);
				visited[j]=1;
				enQueue(Q,j);
			}
		}
	}

} 

int main(){
	Graph* G=initGraph(5);
	int* visited=(int*)malloc(sizeof(int)*G->vexNum);
	for(int i=0;i<G->vexNum;i++){
		visited[i]=0;
	}
	int arcs[5][5]={
	0,1,1,1,0,
	1,0,1,1,1,
	1,1,0,0,0,
	1,1,0,0,1,
	0,1,0,1,0
	};
	creatGraph(G,"ABCDE",(int*)arcs);
	DFS(G,visited,0);
	printf("\n");
	for(int i=0;i<G->vexNum;i++){
		visited[i]=0;
	}
	BFS(G,visited,0);
	printf("\n");
	return 0;
} 

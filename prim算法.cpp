//MST性质：(V,E)是一个连通图，假设U是V的非空子集（u，v）是一条最小权值的边，那么如果u属于U，v属于V-U，那么必然有（u，v）包含在最小生成树里 
//prim算法（找点法）：从集合中根据边的大小找点，根据最小边找点 

#include<stdio.h>
#include<stdlib.h>

/**
  *图顶点之前不通，邻接矩阵值为MAX
  *如果顶点是自己本身，那么值为0 
*/
#define MAX 32767 

typedef struct Graph{
	char* vexs;//顶点 
	int** arcs;//边
	int vexNum;//顶点数
	int arcNum;//边数 
}Graph;

typedef struct Edge{
	char vex;//记录U集合到最小边的起始节点
	int weight;//记录最小边 
}Edge;

/**
 *当edge.weight=0时，代表顶点加入到U集合中 
*/
Edge* initEdge(Graph* G,int index){
	Edge* edge=(Edge*)malloc(sizeof(Edge)*G->vexNum);
	for(int i=0;i<G->vexNum;i++){
		edge[i].vex=G->vexs[index];
		edge[i].weight=G->arcs[index][i];
	}
	return edge;
} 

int getMinEdge(Edge* edge,Graph* G){
	int index;
	int min=MAX;
	for(int i=0;i<G->vexNum;i++){
		if(edge[i].weight!=0&&min>edge[i].weight){
			min=edge[i].weight;
			index=i;
		}
	}
	return index;
} 

void prim(Graph* G,int index){
	int min;
	Edge* edge=initEdge(G,index);
	for(int i=0;i<G->vexNum-1;i++){
		min=getMinEdge(edge,G);
		printf("v%c->v%c,weight=%d\n",edge[min].vex,G->vexs[min],edge[min].weight);
		edge[min].weight=0;
		for(int j=0;j<G->vexNum;j++){
			if(G->arcs[min][j]<edge[j].weight){
				edge[j].weight=G->arcs[min][j];
				edge[j].vex=G->vexs[min];
			}
		}
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
			if(G->arcs[i][j]!=0&&G->arcs[i][j]!=MAX){
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
		if(G->arcs[index][i]>0&&G->arcs[index][i]!=MAX&&!visited[i]){///邻接矩阵为一且未被访问过，则对该节点进行遍历 
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
	0,6,1,5,MAX,MAX,
	6,0,5,MAX,3,MAX,
	1,5,0,5,6,4,
	5,MAX,5,0,MAX,2,
	MAX,3,6,MAX,0,6,
	MAX,MAX,4,2,6,0
	};
	creatGraph(G,"123456",(int*)arcs);
	DFS(G,visited,0);
	printf("\n");
	prim(G,0);
	return 0;
} 

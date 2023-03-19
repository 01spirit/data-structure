//MST���ʣ�(V,E)��һ����ͨͼ������U��V�ķǿ��Ӽ���u��v����һ����СȨֵ�ıߣ���ô���u����U��v����V-U����ô��Ȼ�У�u��v����������С�������� 
//prim�㷨���ҵ㷨�����Ӽ����и��ݱߵĴ�С�ҵ㣬������С���ҵ� 

#include<stdio.h>
#include<stdlib.h>

/**
  *ͼ����֮ǰ��ͨ���ڽӾ���ֵΪMAX
  *����������Լ�������ôֵΪ0 
*/
#define MAX 32767 

typedef struct Graph{
	char* vexs;//���� 
	int** arcs;//��
	int vexNum;//������
	int arcNum;//���� 
}Graph;

typedef struct Edge{
	char vex;//��¼U���ϵ���С�ߵ���ʼ�ڵ�
	int weight;//��¼��С�� 
}Edge;

/**
 *��edge.weight=0ʱ����������뵽U������ 
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

//��ʼ��
Graph* initGraph(int vexNum){
	Graph* G=(Graph*)malloc(sizeof(Graph));
	G->vexs=(char*)malloc(sizeof(char)*vexNum);
	G->arcs=(int**)malloc(sizeof(int*)*vexNum);//ʹ�õ��ڽӾ����ö���ָ��
	for(int i=0;i<vexNum;i++){
		G->arcs[i]=(int*)malloc(sizeof(int)*vexNum);
	} 
	G->vexNum=vexNum;
	G->arcNum=0;
	return G;
} 

//����ͼ
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
	G->arcNum/=2;//����ͼ���������� 
} 

//ͼ�ı���
void DFS(Graph* G,int* visited,int index){
	printf("%c\t",G->vexs[index]);
	visited[index]=1;
	for(int i=0;i<G->vexNum;i++){
		if(G->arcs[index][i]>0&&G->arcs[index][i]!=MAX&&!visited[i]){///�ڽӾ���Ϊһ��δ�����ʹ�����Ըýڵ���б��� 
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

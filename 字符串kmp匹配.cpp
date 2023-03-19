#include<stdio.h>
#include<stdlib.h>

typedef struct String{
	 char* data;
	 int len;
}String;

//初始化
String* InitString(){
	String* s=(String*)malloc(sizeof(String));
	s->data=NULL;
	s->len=0;
	return s;
} 

//字符串赋值
void StringAssign(String* s,char* data){
	if(s->data){
		free(s->data);
	}
	int len=0;
	char* temp=data;
	while(*temp){
		len++;
		temp++;
	}
	if(len==0){
		s->data=NULL;
		s->len=0;
	}
	else{
		temp=data;
		s->len=len;
		s->data=(char*)malloc(sizeof(char)*(len+1));
		for(int i=0;i<len;i++,temp++){
			s->data[i]=*temp;
		}
	}
} 

//打印
void printString(String* s){
	for(int i=0;i<s->len;i++){
		printf(i==0?"%c":"->%c",s->data[i]);
	}
	printf("\n");
} 

//next数组
int* getNext(String* s){
	int* next=(int*)malloc(sizeof(int)*s->len);
	int i=0;
	int j=-1;
	
	next[i]=j;
	while(i<s->len-1){
		if(j==-1||s->data[i]==s->data[j]){
			i++;
			j++;
			next[i]=j;
		}
		else{
			j=next[j];
		}
	}
	return next;
} 

void printNext(int* next,int len){
	for(int i=0;i<len;i++){
		printf(i==0?"%d":"->%d",next[i]+1);
	}
	printf("\n");
}

//匹配
void kmpMatch(String* master,String* sub,int* next){
	int i=0;
	int j=0;
	while(i<master->len&&j<sub->len){
		if(j==-1||master->data[i]==sub->data[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j==sub->len){
		printf("success\n");
	}
	else{
		printf("fail\n");
	}
} 

int main(){
	String* s=InitString();
	String* s1=InitString();
	StringAssign(s,"ababccabc");
	StringAssign(s1,"ca "); 
	printString(s); 
	printString(s1);
	int* next=getNext(s1);
	printNext(next,s1->len);
	kmpMatch(s,s1,next);
	return 0;
} 

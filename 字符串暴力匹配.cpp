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
	}//要重新开辟空间，防止野指针出现 
	int len=0;
	char* temp=data;
	while(*temp){
		len++;
		temp++;
	}
	if(len==0){
		s->data=NULL;
	}
	else{
		temp=data;//temp循环到了结尾，要让他重新指到头
		s->len=len;
		s->data=(char*)malloc(sizeof(char)*(len+1));//字符串结尾有'\0',长度为len+1 
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

//暴力匹配
void ForceMatch(String* master,String* sub){
	int i=0;//指向主串 
	int j=0;//指向子串 
	while(i<master->len&&j<sub->len){
		if(master->data[i]==sub->data[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(j==sub->len){
		printf("匹配成功\n"); 
	}
	else{
		printf("匹配不成功\n");
	}
}
 
int main(){
	String* s=InitString();
	String* s1=InitString();
	StringAssign(s,"Hello");
	StringAssign(s1,"ll");
	printString(s);
	printString(s1);
	ForceMatch(s,s1);
	 
	return 0;
}

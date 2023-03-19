#include<stdio.h>
#include<stdlib.h>

typedef struct String{
	char* data;
	int len;
}String;

//��ʼ��
String* InitString(){
	String* s=(String*)malloc(sizeof(String));
	s->data=NULL;
	s->len=0;
	return s;
} 

//�ַ�����ֵ
void StringAssign(String* s,char* data){
	if(s->data){
		free(s->data);
	}//Ҫ���¿��ٿռ䣬��ֹҰָ����� 
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
		temp=data;//tempѭ�����˽�β��Ҫ��������ָ��ͷ
		s->len=len;
		s->data=(char*)malloc(sizeof(char)*(len+1));//�ַ�����β��'\0',����Ϊlen+1 
		for(int i=0;i<len;i++,temp++){
			s->data[i]=*temp;
		} 
	}
} 

//��ӡ
void printString(String* s){
	for(int i=0;i<s->len;i++){
		printf(i==0?"%c":"->%c",s->data[i]);
	}
	printf("\n");
} 

//����ƥ��
void ForceMatch(String* master,String* sub){
	int i=0;//ָ������ 
	int j=0;//ָ���Ӵ� 
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
		printf("ƥ��ɹ�\n"); 
	}
	else{
		printf("ƥ�䲻�ɹ�\n");
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

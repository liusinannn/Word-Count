#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>  
int openFilt();//���ļ� 
int wordCount();//���㵥���� 
int charCount();//�����ַ��� 
int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[2],"r");//���ļ� 
	if(openFile(fp)==-1){
		printf("�ļ���ȡʧ�ܣ�");
		return 0;  
	}
	if(!strcmp(argv[1],"-c")){
		int CHARCOUNT = charCount(fp);
		printf("�ַ�����%d",CHARCOUNT); 
	}else if(!strcmp(argv[1],"-w")){
		int WORDCOUNT = wordCount(fp); 
		printf("��������%d",WORDCOUNT);
	}
	fclose(fp);//�ر��ļ�
	return 0;	 
}
int openFile(FILE *fp){ //���ļ��У�����-1��ʾδ�ɹ�
	if(!fp){
		return -1; 
	} 
}
int wordCount(FILE *fp){//���㵥����
	char c;
	int count=0; 
	c = fgetc(fp);//��ȡ�ļ��е�һ���ַ������ҹ��ָ����һ�� 
	while(c!=-1){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
			while((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){//�����ո�������������ѭ�� 
				c = fgetc(fp);
			}
			count++;
			c = fgetc(fp);
		}else{
			c = fgetc(fp);
		}
	}
	return count;
}
int charCount(FILE *fp){//�����ַ���
	char c;
	int count=0; 
	c = fgetc(fp);//��ȡ�ļ��е�һ���ַ������ҹ��ָ����һ�� 
	while(c!=-1){
		c = fgetc(fp);
		count++;
	}
	return count;
}

#include <stdio.h> 
#include <stdlib.h> 

 
#define BUF_SIZE 1024 

 
int main(){ 
	char buf[BUF_SIZE]; 
	FILE *in, *out; 
 	int nread; 
 	int count = 0; 
 
 	//in,out������ open�Ѵ�.
 	in = fopen("input2.txt", "r"); 
 	out = fopen("output2.txt", "w"); 
 
 	
	//�ҽ� ������ ���� �� �� �ڵ带 �����Ѵ�.
 	if(in != NULL && out != NULL) { 
 		while(!feof(in)){ 
 			nread = fread(buf, 1, BUF_SIZE, in); 
 			fwrite(buf, 1, nread, out);
			count++;
 			//1����Ʈ�� ����ɶ� ���� count�� �÷��� 1KB��  
 			//���簡 �Ǹ� *�� ������ش� 
 			if(count % 1024 == 0) printf("*"); 
 		}	 
 		fclose(in); 
 		fclose(out); 
 	} 
 	exit(0); 
 } 

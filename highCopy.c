#include <stdio.h> 
#include <stdlib.h> 

 
#define BUF_SIZE 1024 

 
int main(){ 
	char buf[BUF_SIZE]; 
	FILE *in, *out; 
 	int nread; 
 	int count = 0; 
 
 	//in,out파일을 open한다.
 	in = fopen("input2.txt", "r"); 
 	out = fopen("output2.txt", "w"); 
 
 	
	//소스 파일이 존재 할 때 코드를 진행한다.
 	if(in != NULL && out != NULL) { 
 		while(!feof(in)){ 
 			nread = fread(buf, 1, BUF_SIZE, in); 
 			fwrite(buf, 1, nread, out);
			count++;
 			//1바이트가 복사될때 마다 count를 올려서 1KB가  
 			//복사가 되면 *을 출력해준다 
 			if(count % 1024 == 0) printf("*"); 
 		}	 
 		fclose(in); 
 		fclose(out); 
 	} 
 	exit(0); 
 } 

#include <unistd.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdlib.h> 
#include <stdio.h> 
 
 
#define BUF_SIZE 1024 
 
 
int main(){ 
 	char block[BUF_SIZE]; 
 	int in, out; 
 	int nread; 
 	int count = 0; 
 	
	//input파일 이름 = input.txt
 	in = open("input.txt", O_RDONLY); 
	//output파일 이름 = ouput.txt
 	out = open("output.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR); 
 
	printf("file copy를 시작합니다.\n") 	

 	while((nread = read(in,block,BUF_SIZE)) > 0){ 
 		write(out,block,nread);	
		count++; 
 		//파일을 복사하는 과정에서 .을 출력해주기 위해서 
 		//1KB마다 .이출력되게 1바이트가 복사될때 마다 count를 증가시킨다. 
 		if(count % 1024 == 0) 
			printf(".");	 
 	} 
 	exit(0);	 
 } 

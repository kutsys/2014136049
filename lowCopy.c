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
 	
	//input���� �̸� = input.txt
 	in = open("input.txt", O_RDONLY); 
	//output���� �̸� = ouput.txt
 	out = open("output.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR); 
 
	printf("file copy�� �����մϴ�.\n") 	

 	while((nread = read(in,block,BUF_SIZE)) > 0){ 
 		write(out,block,nread);	
		count++; 
 		//������ �����ϴ� �������� .�� ������ֱ� ���ؼ� 
 		//1KB���� .����µǰ� 1����Ʈ�� ����ɶ� ���� count�� ������Ų��. 
 		if(count % 1024 == 0) 
			printf(".");	 
 	} 
 	exit(0);	 
 } 

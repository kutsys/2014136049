//선행처리 지시자
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>   //dirent구조체 위한 헤더파일
#include<string.h>
#include<sys/stat.h>  // 정보를 담고 있는 structstat(sys/stat.h)
#include<stdlib.h>

 
void printdir(char *dir,int depth)
{
     DIR *dp;  //구조체 DIR의 포인터 변수
     struct dirent *entry; //구조체 dirent(디렉토리 엔트리)포인터 변수
     struct stat statbuf; //구조체 stat버퍼 변수
 
 
     // 문자열 dir로 디렉토리 열기
     if((dp=opendir(dir)) == NULL)
     {
  fprintf(stderr,"cannot open directory : %s \n ",dir);
  return;
     }
     chdir(dir); //문자열 dir에 저장되어 있는 디렉토리로 이동
 
 
     // dp에 저장된 디렉토리 엔트리를 읽어들여 entry에 저장, 저장된 값이 참인 동안 실행
     while((entry = readdir(dp)) !=NULL) 
     {
  // entry에 저장된 디렉토리명을 상태 버퍼에 저장
  lstat(entry->d_name,&statbuf);
  // 상태버퍼의 모드 값을 검사했는데, 디렉토리이면
  if(S_ISDIR(statbuf.st_mode))
  {
      if(strcmp(".",entry->d_name) == 0 ||   //문자열이 '.' 또는 '..'이면
       strcmp("..",entry->d_name) ==0) continue; //다음 entry읽이들이기
 
 
      printf("%*s%s/\n",depth,"",entry->d_name); //디렉토리 depth와 디렉토리명을 출력
      
      // 디렉토리명으로 재귀호출
      printdir(entry->d_name,depth+4);
  } 
  // 앞에가 .으로 시작한다면 출력하지 않는다.
  else if(strncmp(".",entry->d_name,1))
  { 
      printf("%*s%s/\n",depth,"",entry->d_name);
  }
  else
  {
  
  }
     }
     chdir(".."); //이전 디렉토리로 이동
     closedir(dp); //dp에 열려있는 디렉토리 닫기
 }
 
 
 int main()
 {
     printf("Directory scan of /home : \n");
     printdir("/home",0); //디렉토리 출력 함수 호출
     printf("done.\n");
     exit(0);
 } 

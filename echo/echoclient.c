#include "csapp.h"

int main(int argc, char **argv){
  // 선언
  int clientfd;
  char *host, *port, buf[MAXLINE];
  rio_t rio;

  if(argc !=3){
    fprintf(stderr, "usage: %s <host> ./>\n", argv[0]);
    exit(0);
  }
  // 프로그램 실행시 입력받는 인자 [프로그램명, host, port]
  host = argv[1];
  port = argv[2];

  clientfd = Open_clientfd(host, port); // Open_clientfd 함수를 이용해서 소켓을 clientㅇfd(file description)로 만듦
  Rio_readinitb(&rio, clientfd); // rio의 주소값을 clientfd에 연결
  
  // buf 에서 MAXLINE 크기 만큼 읽어와서 (NULL이 아니면)
  while (Fgets(buf, MAXLINE, stdin) != NULL){ 
    Rio_writen(clientfd, buf, strlen(buf)); // 연결된 주소 clientfd에 buf내의 값을 복사 (buf 길이 만큼)
    Rio_readlineb(&rio, buf, MAXLINE); // rio에 있는 값을 MAXLINE만큼 buf에 복사
    Fputs(buf, stdout); // 표준 출력 stream에 buf를 넣음
  }
  Close(clientfd); // 메모리 누수를 막기 위해서 clientfd를 닫음
  exit(0); // 함수 밖으로 나감
}
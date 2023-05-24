#include "csapp.h"

void echo(int connfd);

int main(int argc, char **argv){
  // 선언
  int listenfd, connfd;
  socklen_t clientlen;
  struct sockaddr_storage clientaddr; // 어떤 주소에도 충분한 공간
  char client_hostname[MAXLINE], client_port[MAXLINE];

  // 프로그램 실행시 입력받은 인자 [프로그램명, port]  
  if(argc !=2){
    fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
    exit(0);
  }

  // open_listenfd 함수를 사용해서 server 소켓을 listenfd로 오픈하여 대기함
  listenfd = Open_listenfd(argv[1]);
  // EOF가 들어오기 전까지 무한루프
  while (1){ 
    clientlen = sizeof(struct sockaddr_storage); // clientlen는 sockaddr_storage 구조체의 크기
    connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen); // listenfd가 clinentfd를 만나면 accept 실행. 새로운 식별자를 connfd에 return
    Getnameinfo((SA *)&clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0); // clientaddr와 clientlen을 이용해 client_hostname, client_port를 만들어냄
    printf("Connected to (%s %s)\n", client_hostname, client_port); // 연결되면 hostnme port 출력
    echo(connfd); // echo 함수에 connfd 를 넣어서 echo 함수 돌림 --> 여기서 buf에 connfd에 복사함
    Close(connfd); // 그리고 닫음
  }
  exit(0);
}
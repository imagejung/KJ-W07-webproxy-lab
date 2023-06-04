# KJ-W07-malloc-lab

##1./echo
- echo 서버 구현(tiny 서버와 독립적) 
- make 파일 통해 서버/클라이언트 두개 실행
- 클라이언트 : 입력한 내용 서버에 전달 후 클라이언트에 다시 출력
- 서버 : 전달받은 내용 byte크기 출력

##2./tiny
- tiny 서버 구현 
- tiny 파일 실행으로 서버 실행 및 브라우저 통해 접속
- 한 개의 HTTP Transaction 처리 함수
- 동영상 게시, add 함수 추가 과제 구현

##3.proxy.c 
- tiny 서버에 proxy 서버 추가
- 서버 실행 후 브라우저로 접속시 프록시 통해 접속



------
원본 




####################################################################
# CS:APP Proxy Lab
#
# Student Source Files
####################################################################

This directory contains the files you will need for the CS:APP Proxy
Lab.

proxy.c
csapp.h
csapp.c
    These are starter files.  csapp.c and csapp.h are described in
    your textbook. 

    You may make any changes you like to these files.  And you may
    create and handin any additional files you like.

    Please use `port-for-user.pl' or 'free-port.sh' to generate
    unique ports for your proxy or tiny server. 

Makefile
    This is the makefile that builds the proxy program.  Type "make"
    to build your solution, or "make clean" followed by "make" for a
    fresh build. 

    Type "make handin" to create the tarfile that you will be handing
    in. You can modify it any way you like. Your instructor will use your
    Makefile to build your proxy from source.

port-for-user.pl
    Generates a random port for a particular user
    usage: ./port-for-user.pl <userID>

free-port.sh
    Handy script that identifies an unused TCP port that you can use
    for your proxy or tiny. 
    usage: ./free-port.sh

driver.sh
    The autograder for Basic, Concurrency, and Cache.        
    usage: ./driver.sh

nop-server.py
     helper for the autograder.         

tiny
    Tiny Web server from the CS:APP text 


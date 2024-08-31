/*
============================================================================
Name : 21.c
Author : Gnanendhar Reddy
Description : Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2024
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

int main(){
	printf("The parent process pid is :%d\n",getpid());
	int f=fork();
	if(f==0){
		printf("We are in the child process wit pid:%d\n",getpid());
	}
	else if(f>0){
		printf("We are in the parent process with Child pid: %d and parent pid :%d\n",f,getppid());
	}
	else{
		printf("We are in the parent process but child was not created\n");
	}
	return 0;
}
/*
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ cc 21.c
gnanendhar-reddy@gnanendhar-reddy-HP-EliteBook-830-G7-Notebook-PC:~/SS/temp$ ./a.out
The parent process pid is :7556
We are in the parent process with Child pid: 7557 and parent pid :3274
We are in the child process wit pid:7557
*/

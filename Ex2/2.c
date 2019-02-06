#include<stdio.h>
#include<unistd.h>
void main(){
  printf("Before fork\n");
  fork();
  printf("Hello world\n");
}

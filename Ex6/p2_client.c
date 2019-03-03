#include <sys/ipc.h>
#define NULL 0
#include <sys/shm.h>
#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<stdio_ext.h>
// parent writing a char in shared memory and child reads it and prints it.
int main(){
  int pid;
  char *a,*b,c;
  int id,n,i;
  // you can create a shared memory between parent and child here or you can //create inside them separately.
  id=shmget(111,50,00666);
  sleep(3);
  //id=shmget(111,50,0);
  b=shmat(id,NULL,0);
  b[0] = toupper(b[0]);
  printf("\nchild %s\n",b);
  shmdt(b);
  shmctl(id, IPC_RMID,NULL);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct memory{
  int block;
  int notfree;
  char f[50];
};
typedef struct memory Memory;
Memory disc[100];
int memsize, blocksize, nb;
struct element{
  int block;
  int size;
  char f[50];
  struct element *next;
};
typedef struct element Element;
Element *table = NULL;
void initialise(){
  for(int i = 0; i < nb; i++){
    disc[i].block = i;
    disc[i].notfree = 0;
    strcpy(disc[i].f, "---");
  }
}
void insertfile(char f[], int size, int block){
  Element *newnode = (Element*)malloc(sizeof(Element));
  newnode->next = NULL;
  newnode->block = block;
  newnode->size = size;
  strcpy(newnode->f, f);
  if(table == NULL)
    table = newnode;
  else{
    newnode->next = table;
    table = newnode;
  }
}
void display(){
  Element *temp = table;
  printf("File\tBlock\tSize\n");
  while(temp!=NULL){
    printf("%s\t%d\t%d\n",temp->f,temp->block,temp->size);
    temp = temp->next;
  }
}
int checkfree(int size){
  for(int i = 0; i < nb; ){
    if(disc[i].notfree == 0){
      int j = i;
      while(disc[j].notfree == 0 && j < nb){
	if(j-i+1 == size)
	  return i;
	j++;
      }
      i += (j+1);
    }
    else i++;
  }
  return -1;
}
int check(int ind, int size){
  if(disc[ind].notfree == 0){
    for(int i = ind; i < ind+size && i < nb; i++)
      if(disc[i].notfree == 1)
	return 0;
  }
  else
    return 0;
  if(ind + size - 1 < nb)
    return 1;
  else
    return 0;
}
int allocate(int size, char name[]){
  int flag = 0;
  int b = size/blocksize;
  if(size*1.0/blocksize != b)
    b++;
  size = b;
  if(checkfree(size) >= 0){
    while(1){
      int ind = random()%nb;
      if(check(ind,size) == 1){
	flag = 1;
	int i = ind;
	do{
	  disc[i].notfree = 1;
	  strcpy(disc[i].f,name);
	  i++;
	}while(i < b+ind);
	insertfile(name,b,ind);
	break;
      }
    }
  }
  else
    printf("Not enough memory available!\n");
  return (flag == 0) ? 0 : 1;
}
int main(){
  int nf, size, block;
  char f[50];
  printf("Enter size of memory in KB: ");
  scanf("%d", &memsize);
  printf("Enter size of block in KB: ");
  scanf("%d", &blocksize);
  nb = memsize/blocksize;
  initialise();
  printf("Enter no. of files: ");
  scanf("%d", &nf);
  for(int i = 0; i < nf; i++){
    printf("Enter the file name: ");
    scanf("%s",f);
    printf("Enter the size of the file: ");
    scanf("%d",&size);
    allocate(size, f);
  }
  display();
  return 0;
}

#include<stdio.h>
void swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
void sort(int n, int pid[], int at[], int bt[]){ 
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(at[j]<at[i]){
	swap(&at[j],&at[i]);
	swap(&pid[j],&pid[i]);
	swap(&bt[j],&bt[i]);
      }
}
void start_finish_time(int n, int pid[], int at[], int bt[], int st[], int ft[]){
  st[0]=at[0];
  ft[0]=st[0]+bt[0];
  for(int i=1;i<n;i++){
    if(at[i]>ft[i-1])
      st[i]=at[i];
    else
      st[i]=ft[i-1];
    ft[i]=st[i]+bt[i];
  }
}
void wait_tat_time(int n, int at[], int st[], int ft[], int wt[], int tat[]){
  for(int i=0;i<n;i++){
    wt[i]=st[i]-at[i];
    tat[i]=ft[i]-at[i];
  }
}
void print(int n, int pid[], int at[], int bt[], int st[], int ft[], int wt[], int tat[]){
  printf("ID\tAT\tBT\tST\tFT\tWT\tTAT\n");
  for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],st[i],ft[i],wt[i],tat[i]);
  }
}
void main(){
  int n;
  scanf("%d",&n);
  int pid[n],at[n],bt[n],st[n],ft[n],wt[n],tat[n];
  for(int i=0;i<n;i++){
    pid[i]=i+1;
    scanf("%d%d",&at[i],&bt[i]);
  }
  sort(n,pid,at,bt);
  start_finish_time(n,pid,at,bt,st,ft);
  wait_tat_time(n,at,st,ft,wt,tat);
  print(n,pid,at,bt,st,ft,wt,tat);
}

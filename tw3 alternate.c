#include<stdio.h>
struct node
{
 unsigned dist[10];
 unsigned to[10];
}rt[10];
int main()
{
 int cost[10][10], nodes, flag;
 printf("\nEnter the number of nodes : ");
 scanf("%d",&nodes);
 printf("\nEnter the cost matrix :\n");
 for(int i=0;i<nodes;i++)
 for(int j=0;j<nodes;j++)
 {
 scanf("%d",&cost[i][j]); 
 rt[i].dist[j]=cost[i][j];
 rt[i].to[j]=j;
 }
 do
 {
 flag = 0;
 for(int i=0;i<nodes;i++)
 for(int j=0;j<nodes;j++)
 for(int k=0;k<nodes;k++)
 if(rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j])
 {
 rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
 rt[i].to[j] = k;
 flag = 1;
 }
 }while(flag!=0);
 for(int i=0;i<nodes;i++)
 {
 printf("\n\nFor router %d:\n",i+1);
 for(int j=0;j<nodes;j++)
 printf("\t\nNode %d via %d Distance %d ",j+1,rt[i].to[j]+1,rt[i].dist[j]);
 }
 printf("\n\n");
}

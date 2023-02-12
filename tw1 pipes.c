#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int fd[2],n;
char buffer[100];
pid_t p;
pipe(fd);
p=fork();
if(p>0){
printf("Parent having pid %d\n",getpid());
printf("My childs pid %d\n",p);
printf("Passing value to child\n");
write(fd[1],"Hello IPC from NP lab\n",22);
}
else{
printf("child having pid %d\n",getpid());
printf("My parents pid %d\n",getppid());
n=read(fd[0],buffer ,100);
printf("Child received data\n");
write(1,buffer,n);
}
  }

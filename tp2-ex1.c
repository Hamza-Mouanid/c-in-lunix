#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    pid_t pid1, pid2;
    char message[30];
    pipe(fd);
    if(pipe(fd)==-1){
        printf("erreur\n");
        exit(1);
    }

    //la creation de premier prossuse 
    pid1=fork();
    if(pid1==-1){
        printf("erreur\n");
        exit(0);
    }else if(pid1==0){
        //lecture
        close(fd[1]);
        read(fd[0],message,30);
        printf("le message recu : %s",message);
        exit(0);
    }

    //la creation de dexieme prossuse 
    pid2 = fork();
    if(pid2==-1){
        printf("erreur \n ");
        exit(0);
    }else if(pid2==0){
        //ecrutir
        close(fd[0]);
        sprintf(message ,"bonjour \n");
        write(fd[1], message , 30);
        exit(0);
    }
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
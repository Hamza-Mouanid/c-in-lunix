#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	pid_t p1 = fork();
	if(p1 == -1){
		printf("erreur \n");
	}
	if(p1==0){
		printf("pid de le fils %d \n", getpid() );
	}else if(p1>0){
		printf("pid de le pere %d \n" , getppid() );
	}
	return 0;
}

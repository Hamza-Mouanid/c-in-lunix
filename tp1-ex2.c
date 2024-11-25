#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
	pid_t p1 = fork() ;
	if(p1==0){
		int i;
		printf("le fils :\n");
		for(i=0;i<10;i++){
			printf(" %d \n ", i+1 );
		}
	}else if(p1>0){
		int j;
		printf("le pere : \n");
		for(j=10;j<20;j++){
			printf(" %d \n ", j+1);
		}
	}else{
		printf("erreur");
	}
	return 0;
}

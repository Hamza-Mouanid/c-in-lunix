#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t root_pid;
    printf("je suis prossuse 1 \n");

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Processus enfant 2
        printf("  je suis le prossuse 2\n");
        exit(0);  // Le processus enfant se termine
    }
    wait(NULL);  // Attendre que le processus 2 se termine

    pid_t pid3 = fork();
    if (pid3 == 0) {
        // Processus enfant 3
        printf("  je suis le prossuse 3 \n");
        exit(0);  // Le processus enfant se termine
    }
    wait(NULL);  // Attendre que le processus 3 se termine

    pid_t pid4 = fork();
    if (pid4 == 0) {
        // Processus enfant 4
        printf("  je suis le prossuse 4\n");

        // Création des processus pour les nœuds 5 et 6 (enfants du processus 4)
        pid_t pid5 = fork();
        if (pid5 == 0) {
            // Processus enfant 5
            printf("	je suis le prossuse 5\n");
            exit(0);  // Le processus enfant se termine
        }
        wait(NULL);  // Attendre que le processus 5 se termine

        pid_t pid6 = fork();
        if (pid6 == 0) {
            // Processus enfant 6
            printf("	je suis le prossuse 6\n");
            exit(0);  // Le processus enfant se termine
        }
        wait(NULL);  // Attendre que le processus 6 se termine

        exit(0);  // Le processus 4 se termine après avoir créé ses enfants
    }

    // Attendre que le processus 4 (et ses enfants) se termine
    wait(NULL);

    return 0;
}

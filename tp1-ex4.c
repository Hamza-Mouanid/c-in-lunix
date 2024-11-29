#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int i, j;

    // Boucle pour créer 10 processus fils
    for (i = 0; i < 10; i++) {
        pid = fork();  // Création du processus fils
        if (pid < 0) {
            // Si la création du processus a échoué
            perror("fork failed");
            exit(1);
        }
        if (pid == 0) {
            // Si on est dans le processus fils
            for (j = 0; j < 10; j++) {
                printf("Processus %d: %d\n", i, j);
            }
            exit(0);  // Le processus fils se termine après avoir affiché 10 fois son numéro
        }
    }

    // Attendre que tous les processus fils se terminent
    for (i = 0; i < 10; i++) {
        wait(NULL);
    }

    return 0;
}

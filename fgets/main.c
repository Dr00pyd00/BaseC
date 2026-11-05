
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF         10

int main(void) {

    printf("hello\n");

    // je prend un petit buffer pour bien illustrer 
    char buf[MAX_BUF];

    printf("Entre une input: ");

    // fgets lis 10 -1 car il reserve le dernier char pour \0;
    
    if (  fgets(buf, sizeof(buf), stdin) == NULL ) {
        fprintf(stderr, "Error first fgets\n");
        exit(1);
    }
    // fgets garde le \n du clavier
    printf("buf => %s\n", buf);
    // on le retire 
    buf[ strcspn(buf, "\n") ] = '\0';  // TODO: il se passe quoi si ya pas de \n ?
    printf("buf apres nettoyage du \\n => %s\n", buf);
        
    // SI l'input depasse, fgets cut et met \0 a la fin:
    //      input:  'salut salut salut'
    //          prend les 9 premier char et reserve le dernier pour \0

    // PROBLEM: si l'input est trop longue alors fgets lis la taille du buffer, 
    // mais ducoup le reste de l'input reste en attente

    if ( strlen(buf) == MAX_BUF -1 ) {
        printf("ca a depasser\n");
    } else {
        printf("ca a PAS depasser\n");
    }

    return 0;
}

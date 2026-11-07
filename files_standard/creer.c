
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define NEWF_NAME   "fileUn"

int main(void) {

    FILE *f;

    // creer un file 
    // le 'x' est pour : si jamais le file existe deja ca plante pour pas ecraser

    f = fopen(NEWF_NAME, "wx");
    if ( f == NULL ) {
        if ( errno == EEXIST ) {
            fprintf(stderr, "file already exist...\n");
        } else {
            perror("fopen fail");
        }
        return EXIT_FAILURE;
            }

    // ici le file est creer et le ptr f est dispo pour faire des trucs

    fprintf(f, "premiere ligne de mon file\n");
    printf("premiere ligne ecrite avec fprintf\n");

    const char *phrase = "salut de la part de fputc\n";
    int sPhrase = strlen(phrase);
    int i;
    for ( i = 0; i < sPhrase; i++ ) {
        fputc( *(phrase + i), f);   
    }
    printf("fputc fini!\n");

    const char *phrase2 = "ici c'est avec fwrite !!!\n";
    
    size_t totalSend = fwrite(phrase2, sizeof(char), strlen(phrase2), f);
    if ( totalSend < strlen(phrase2) ) {
        printf("error pas tout envoyer par fwrite!\n");
    }



    fclose(f);


    return 0;
}

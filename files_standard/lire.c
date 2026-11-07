
#include <stdio.h> 
#include <stdlib.h>

#define FILENAME    "fileUn"

void goNextLine(FILE *f) {
    char c;
    while( (c = getchar()) != EOF && c != '\n' )
        ;
    fseek(f,1,SEEK_CUR);
}


int main(void) {

    FILE *f = fopen(FILENAME, "r");
    if ( f == NULL ) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    
    // lire les lignes:

    char buffer[200];
    while ( fgets(buffer, sizeof(buffer), f) ) 
        printf("%s", buffer);


    rewind(f);
    // avec fread :
    size_t re = fread((void*)buffer, sizeof(char), sizeof(buffer),f );
    printf("re de fread = %zu\n", re);
    if ( re == 0 ) {
        printf("rien a lire avec fread...\n");
        return EXIT_FAILURE;
    }
    printf("apres fread\n");
    printf("%s", buffer);


    // GERER LE buffer

    long pos = ftell(f);
    printf("ftell(f) = %ld\n", pos);


    




    return 0;
}

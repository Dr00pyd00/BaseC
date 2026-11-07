
#include <stdio.h>
#include <stdlib.h>

#define FILENAME    "fileUn"

void goNextLine(FILE *f) {
    char c;
    while( (c = fgetc(f)) != EOF && c != '\n' )
        ;
}


int main (void) {
    
    FILE *f = fopen(FILENAME, "r");
    if ( f == NULL ) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    printf("file open\n");

    long pos = ftell(f);
    printf("pos = %ld\n", pos);

    goNextLine(f);
    goNextLine(f);
    //
    // char buf[100];
    // fgets(buf, 100,f);
    // printf("%s", buf);
    //
    rewind(f);
    int rfs = fseek(f,-10L,SEEK_CUR);
    if ( rfs == -1) {
        perror("fs");
    }
    char c;
    while ( (c = fgetc(f)) != EOF && c != '\n')
        printf("%c", c);
    printf("\n");
    
    return 0;
}



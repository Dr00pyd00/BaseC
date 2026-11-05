/*
   Une fonction qui sert a lire une input et faire des checks !! 

*/

#include <stdio.h>
#include <string.h>

#define LOK         0
#define LNOTHING    1
#define LTOOLONG    2

int readLine(char buf[], int bufSize) {
    if ( fgets(buf, bufSize, stdin) == NULL ) {
        // veut dire rien a lire ou erreur tres rare 
        return LNOTHING;
    }

    size_t len = strcspn(buf, "\n");
    if ( buf[len] == '\n' ) {
        // il y a bien un \n donc la ligne est complete
        buf[len] = '\0';
        return LOK;
    } else {
        // la ligne a ete trop longue et le fgets a pas atteint de \n
        // il faut vider le buffer stdin 
        int c;
        while ( (c = getchar()) != '\n' && c != EOF ) 
            ;
        return LTOOLONG;
    }
}


int main(void) {

    char buf[10];

    printf("tape un truc: ");
    int rc = readLine(buf, sizeof(buf));

    if ( rc == LOK ) {
        printf("LOK input => %s\n", buf);
    }
    else if ( rc == LNOTHING ) {
        printf("Rien n'a ete ecrit... => %s\n", buf);
    }
    else if ( rc == LTOOLONG ) {
        printf("Too long input => %s\n", buf);
    }

    


    return 0;
}

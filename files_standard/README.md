
# Files Standard : fopen fclose f...

On manipule tout avec `FILE` qui est une struct opaque.

## Creer 

```C 

FILE *f = fopen("filename", "wx");
if ( f == NULL ) {
    if (errno == EEXIST ) {
        // le file existe deja
    } else {
        perror("fopen"); //autre erreur
    }
}
fclose(f);
```

## Ecrire dedans: 

>Il y a 3 methodes.

###  fprintf 

Rapide efficace:
```C
fprintf(f, "premiere ligne de mon fichier\n");
```
### fputc 

Char par char:
```C 
const *phrase = "Une ligne du fichier\n";
int sPhrase = strlen(phrase);
int i;
for ( i = 0; i < sPhrase; i++ ) 
    fputc( *(phrase + i), f);
```

### fwrite

```C
const char *phrase2 = "ici c'est avec fwrite !!!\n";

size_t totalSend = fwrite(phrase2, sizeof(char), strlen(phrase2), f);
if ( totalSend < strlen(phrase2) ) {
    printf("error pas tout envoyer par fwrite!\n");
}
```

--- 

## Lire 

### fgets 

```C
char buf[200];
while ( fgets(buf, sizeof(buf), f) )
    printf("%s",buf);
```

### fread 

```C
    size_t re = fread(buf, sizeof(char), sizeof(buf),f );
    if ( re == 0 ) {
        printf("rien a lire avec fread...\n");
        return EXIT_FAILURE;
    }
    printf("%s", buf);
```


# Gerer le ptr de file: 

Quand on lit ou ecrit le `ptr` avance et reste a sa position.

```C
long pos = ftell(f);        // où en est-on ? (en octets depuis le début)
fseek(f, 0, SEEK_SET);      // aller à une position
rewind(f);                  // revenir au début

```
- `SEEK_SET` = debut du file 
- `SEEK_CUR` = depuis position actuelle 
- `SEEK_END` = fin


## Le FD du file reel

```C
int fd = fileno(f);
```


# INFOS:

On utilise une `struct stat`.

```C
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

#define FN      "fileUn"

int main(void) {
    
    FILE *f = fopen(FN, "r");
    if ( f == NULL ) {
        perror("fopen");
        return 1;
    } 

    int fd = fileno(f);
    printf("fd de %s = %d\n", FN, fd);

    struct stat st;
    if ( fstat(fd, &st) == -1 ) {
        perror("fstat");
        return 1;
    }

    printf("inode numner = %llu\n", (unsigned long long)st.st_ino);

    printf("time last access = %s\n", ctime(&st.st_atim.tv_sec));


    fclose(f);

    return 0;
}
```












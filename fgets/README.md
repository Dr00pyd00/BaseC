
# la fonction fgets

```C 
#include <stdio.h>

char *fgets(int size;
                char s[size], int size, FILE stream
                );
```

Returns:
    - `Success`: le text lui meme
    - `Fail`: NULL 
    - `EOF` : NULL aussi

---

Ca lis TOUT jusqu'au premier `\n` ou `EOF`, le reste reste dans le buffer stdin il faudra le gerer.
   
ATTENTION:  buf[10] --> fgets va reserver le dernier char pour `\0` donc l'input sera de 9 max!

---
#### Traitement de fin ( \n ) :
Pour avoir un buf propre autant virer le `\n` qui lui est pris en compte par `fgets`.  
```C
buf[ strcspn( buf, "\n")] = '\0';
```
ATTENTION: on peut checker si l'input a ete tronque car => le \n est remplacer par \0 MAIS,
si jamais le premier \0 est a la toute fin  ca veut dire notre traitement n'as pas eut d'effet,
donc que le seul \0 est celui de la toute fin: AUCUN `\n` n'as ete remplacer. 
=> ca veut dire que ca a ete tronque.


### Traitement propre:
```C
size_t len = strcspn(buf, "\n"); // index du premier \n
// SI pas de \n , strcspn va chercher le \0 donc il renvoie la longueur de la chaine.

if ( buf[len] == '\n' ) {
    // ca veut dire que la ligne est complete et on retire le saut a la ligne 
    buf[len] = '\0';
}
else {
    // chaine couper car pas de saut final: VIDER le buffer STDIN
    int c;
    while ( (c=getchar()) != '\n' && c != EOF) 
        ; // deroule sans rien faire
}
```
Ducoup ici on check si `\n` existe ce qui est signe d'une fin normal, si pas trouver on considere 
que le buffer est trop long donc on le vide pour les prochains appels.



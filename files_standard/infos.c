
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

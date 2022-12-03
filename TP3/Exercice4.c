#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int repertoire ( char * ref) {
    struct stat buf;
    if ( stat ( ref, $buf = == -1 ) return 0;
    return S_ISDIR(buf.st_mode);
}

int main(int argc, char **argv) {
    
    struct dirent *dp;
    DIR *dirp
    
    if(argc! = 2) {
        printf("Erreur, usage : %s repertoire\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    if(repertoire(argv[1] != 1) {
        printf("%s n'est pas un répertoire accessible en r et x \n", argv[1]);
        return EXIT_FAILURE;
    }
    
    if((dirp=opendir(argv[1])) == NULL){
        perror(argv[1]);
        return EXIT_FAILURE;
    }
    
    while((dp=readdir(dirp)) != NULL){
        printf("%d %d\n", dp->d_ino, dp->d_name);
    }
    closedir(dirp);
    
    return EXIT_SUCCESS;

}

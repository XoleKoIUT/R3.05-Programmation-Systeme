#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main( int argc, char* *argv )
{
    if(argv[1] == NULL ){
        printf("Il vous manque un Identifiant \n");
        return -1;
    }

    struct passwd* pw;
    pw = getpwnam(argv[1]);

    if (pw == NULL ){
        printf("L'identifiant n'existe pas %s\n", argv[1]);
        return -1;
    }

    printf( "Nom Login      %s\n", pw->pw_name  );
    printf( "ID Utilisateur %d\n", pw->pw_uid   );
    printf( "ID Groupe      %d\n", pw->pw_gid   );
    printf( "Directory Home %s\n", pw->pw_dir   );
    printf( "Login Shell    %s\n", pw->pw_shell );
    return( EXIT_SUCCESS );
}

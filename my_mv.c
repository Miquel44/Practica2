#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#define S_IRWXU 1000
void main(){
    char nom_fitxer[20], nom_fitxer2[20],fitxer[100000],dir[20]; // Declarem les variables on anira el nom del fitxer i el contingut del fitxer respectivament.
    printf("Escriu el nom del fitxer:\n");
    scanf("%s", nom_fitxer); // Llegim el nom del fitxer donat per teclat.
    printf("Escriu el nou nom del fitxer:\n");
    scanf("%s", nom_fitxer2); // Llegim el nom del fitxer donat per teclat.
    printf("Escriu la nova direccio:\n");
    scanf("%s", dir);
    int fd = open(nom_fitxer, O_RDONLY); // Obrim el fitxer.
    int desc = open(strcat(dir,nom_fitxer2), O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

    if (fd==-1){ // Si fd = -1 vol dir que hi ha agut un error i per tant que el fitxer no existeix.
        printf("Fitxer no trobat\n");
    }
    else{ // Si fd != -1 vol dir que no hi ha cap error i per tant que el fitxer existeix.
        ssize_t n = read(fd,fitxer,100000); // Llegim el fitxer i emmagatzem el contingut a fitxer

        write(desc, fitxer, n);
        close(fd);
        unlink(nom_fitxer); 
    }
    
    if (desc != -1){
        close(desc); // Tanquem la direccio
    }

}

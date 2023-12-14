// Importem les llibreries necessaries
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void main(){
    char nom_fitxer[20], fitxer[100000]; // Declarem les variables on anira el nom del fitxer i el contingut del fitxer respectivament.
    printf("Escriu el nom del fitxer:\n");
    scanf("%s", nom_fitxer); // Llegim el nom del fitxer donat per teclat.
    int fd = open(nom_fitxer, O_RDONLY); // Obrim el fitxer.
    if (fd==-1){ // Si fd = -1 vol dir que hi ha agut un error i per tant que el fitxer no existeix.
        printf("Fitxer no trobat\n");
    }
    else{ // Si fd != -1 vol dir que no hi ha cap error i per tant que el fitxer existeix.
        ssize_t n = read(fd,fitxer,100000); // Llegim el fitxer i emmagatzem el contingut a fitxer
        int lineCount = 0;
        for (int i = 0; i < n && lineCount < 10; i++) {
		printf("%c", fitxer[i]);
		if (fitxer[i] == '\n') {
		    lineCount++;
		  
		}
	}
    }
    close(fd); // Tanquem el fitxer.
}





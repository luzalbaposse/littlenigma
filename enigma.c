#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Este ejemplo corresponde a un programa que implementa una maquina little enigma de 5 discos.
// Su objetivo es que lo utilicen de ejemplo y realizar pruebas.
// Los invitamos a investigar el funcionamiento de la funcion atoi y el uso de los parametros argc y argv en main.

int main(int argc, char *argv[]) {

    // Mensaje de ayuda

    if (argc != 8) {
        printf("Modo de uso:\n\n");
        printf("\tEncriptar:\n");
        printf("\t\t./enigma.out E <password> <mensaje>\n\n");
        printf("\tDesencriptar:\n");
        printf("\t\t./enigma.out D <password> <codigo>\n\n");
        printf("\tObs:\n");
        printf("\t\t- Solo se soportan mensajes y codigos en mayusculas.\n");
        printf("\t\t- La password son 5 numeros de 0 al 25 separados por espacios.\n\n");
        printf("\tEjemplos:\n");
        printf("\t\t./enigma.out E 3 5 9 1 13 TDDOSESLAMEJORNOTENGODUDASTAMPOCOPRUEBAS\n");
        printf("\t\t./enigma.out D 3 5 9 1 13 MVTADZODWBDEETZBJAGGJCPFLRAHCUTBNMJQXDMG\n\n");
        return 0;
    }

    // Lectura de parametros

    int password[5];
    for (int i=0;i<5;i++)
        password[i] = atoi(argv[i+2]);

    char* text = argv[7];
    char* command = argv[1];
    char* result = 0;

    // Create and configure little enigma machine

    char* alphabetPermutation[5];
    alphabetPermutation[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    alphabetPermutation[2] = "JVIUBHTCDYAKEQZPOSGXNRMWFL";
    alphabetPermutation[3] = "QYHOGNECVPUZTFDJAXWMKISRBL";
    alphabetPermutation[4] = "QWERTZUIOASDFGHJKPYXCVBNML";

    struct littleEnigma* le = littleEnigmaNew(alphabetPermutation, 5);
    littleEnigmaSet(le, password);

    // Run command and print results

    if(command[0]=='E') {
        result = littleEnigmaEncrypt(le, text);
    }

    if(command[0]=='D') {
        result = littleEnigmaDecrypt(le, text);
    }

    if(result) {
        printf("%s\n",result);
        free(result);
    }

    // Delete little enigma machine
    
    littleEnigmaDelete(le);

    return 0;
}

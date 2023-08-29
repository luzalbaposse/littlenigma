#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "utils.c"

int main(){
   // strLen test
    char* strvacio = "";
    char* str1caracter = "a";
    char* strtodo = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789!#$&/()=?¡¿";
    printf("strLen\n");
    printf("String vacio: %d\n", strLen(strvacio));
    printf("String de un caracter: %d\n", strLen(str1caracter));
    printf("String de todos los caracteres: %d\n", strLen(strtodo));
    printf("\n");

    // strDup test
    printf("strDup\n");
    printf("String vacio: %s\n", strDup(strvacio));
    printf("String de un caracter: %s\n", strDup(str1caracter));
    printf("String de todos los caracteres: %s\n", strDup(strtodo));
    printf("\n");

    // makeWheelFromString test
    printf("makeWheelFromString\n");
    printf("Generar una estructura wheel con un alfabeto de 1 caracter: %s\n", makeWheelFromString(str1caracter)->alphabet);
    printf("Generar una estructura wheel con un alfabeto de 10 caracteres: %s\n", makeWheelFromString("ABCDEFGHIJ")->alphabet);
    printf("Generar una estructura wheel con un alfabeto de 26 caracteres: %s\n", makeWheelFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ")->alphabet);

    // rotateWheel test
    printf("rotateWheel\n");
    //Rotate wheel de 26 caracteres 1 vez
    printf("Rotate wheel de 26 caracteres 1 vez\n");
    struct wheel* w1 = makeWheelFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    rotateWheel(w1, 1);
    wheelPrint(w1);
    printf("Rotate wheel de 26 caracteres 26 posiciones\n");
    //Rotate wheel de 26 caracteres 26 posiciones
    struct wheel* w2 = makeWheelFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    rotateWheel(w2, 26);
    wheelPrint(w2);

    //Rotate wheel de 5 caracteres 26 posiciones
    printf("Rotate wheel de 5 caracteres 26 posiciones\n");
    struct wheel* w3 = makeWheelFromString("ABCDE");
    rotateWheel(w3, 26);
    wheelPrint(w3);

    //Rotate wheel de 1 caracter 26 posiciones
    printf("Rotate wheel de 1 caracter 26 posiciones\n");
    struct wheel* w4 = makeWheelFromString("a");
    rotateWheel(w4, 26);
    wheelPrint(w4);

   // littleEnigmaEncrypt y littleEnigma Decrypt test
    printf("littleEnigmaEncrypt y littleEnigma Decrypt\n");
    struct wheel* w5 = makeWheelFromString("CIFRARYDECIFRAR");
    char* alphabetPermutation[2];
    alphabetPermutation[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    struct littleEnigma* le = littleEnigmaNew(alphabetPermutation, 2);
    char* encrypted= littleEnigmaEncrypt(le, w5);
    printf("Texto cifrado: %s\n", encrypted);
    char* decrypted= littleEnigmaDecrypt(le, w5);
    printf("Texto decifrado: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    }

    }
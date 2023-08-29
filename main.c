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
     // strDup test
    printf("strDup\n");
    char* str1 = strDup(strvacio);
    printf("String vacio: %s\n", str1);
    free(str1);
    
    char* str2 = strDup(str1caracter);
    printf("String de un caracter: %s\n", str2);
    free(str2);
    
    char* str3 = strDup(strtodo);
    printf("String de todos los caracteres: %s\n", str3);
    free(str3);

    // makeWheelFromString test
    printf("makeWheelFromString\n");
    struct wheel* w1 = makeWheelFromString(str1caracter);
    printf("Generar una estructura wheel con un alfabeto de 1 caracter: %s\n", w1->alphabet);
    struct wheel* w2 = makeWheelFromString("ABCDEFGHIJ");
    printf("Generar una estructura wheel con un alfabeto de 10 caracteres: %s\n", w2->alphabet);
    struct wheel* w3 = makeWheelFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    printf("Generar una estructura wheel con un alfabeto de 26 caracteres: %s\n", w3->alphabet);
    
    // rotateWheel test
    printf("rotateWheel\n");
    //Rotate wheel de 26 caracteres 1 vez
    printf("Rotate wheel de 26 caracteres 1 vez\n");
    struct wheel* w4 = makeWheelFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    rotateWheel(w4, 1);
    wheelPrint(w4);
    printf("Rotate wheel de 26 caracteres 26 posiciones\n");
    //Rotate wheel de 26 caracteres 26 posiciones
    struct wheel* w5 = makeWheelFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    rotateWheel(w5, 26);
    wheelPrint(w5);

    //Rotate wheel de 5 caracteres 26 posiciones
    printf("Rotate wheel de 5 caracteres 26 posiciones\n");
    struct wheel* w6 = makeWheelFromString("ABCDE");
    rotateWheel(w6, 26);
    wheelPrint(w6);

    //Rotate wheel de 1 caracter 26 posiciones
    printf("Rotate wheel de 1 caracter 26 posiciones\n");
    struct wheel* w7 = makeWheelFromString("a");
    rotateWheel(w7, 26);
    wheelPrint(w7);

    // littleEnigma
    printf("littleEnigmaDecrypt y Encrypt\n");
    char* alphabetPermutation[2];
    alphabetPermutation[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    struct littleEnigma* le = littleEnigmaNew(alphabetPermutation, 2);
    littleEnigmaPrint(le);
    printf("\n\n");

    int password[2] = { 3, 5 };
    littleEnigmaSet(le, password);
    littleEnigmaPrint(le);
    printf("\n\n");

    char* text = "TEXT";
    char* code = littleEnigmaEncrypt(le, text);
    littleEnigmaPrint(le);
    printf("%s -> %s\n\n", text, code);

    littleEnigmaSet(le, password);
    littleEnigmaPrint(le);
    printf("\n\n");

    char* decode = littleEnigmaDecrypt(le, code);
    littleEnigmaPrint(le);
    printf("%s -> %s -> %s\n\n", text, code, decode);

    if(code) free(code);
    if(decode) free(decode);

    littleEnigmaDelete(le);

    // Liberar la memoria asignada a 'w1', 'w2' y 'w3'
    wheelDelete(w1);
    wheelDelete(w2);
    wheelDelete(w3);
    wheelDelete(w4);
    wheelDelete(w5);
    wheelDelete(w6);
    wheelDelete(w7);

    return 0;
}

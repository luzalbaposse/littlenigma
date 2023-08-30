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
      // Configuración del conjunto de rotores y la máquina Enigma
    char* rotorAlphabets[3];
    rotorAlphabets[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    rotorAlphabets[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    rotorAlphabets[2] = "QYHOGNECVPUZTFDJAXWMKISRBL";

    struct littleEnigma* le = littleEnigmaNew(rotorAlphabets, 3);

    // Caso 1: Encriptar y desencriptar un mensaje de 0 caracteres
    int password1[3] = { 0, 0, 0 };
    littleEnigmaSet(le, password1);
    char* text1 = "";
    char* code1 = littleEnigmaEncrypt(le, text1);
    char* decode1 = littleEnigmaDecrypt(le, code1);

    printf("Caso 1:\n");
    printf("Mensaje original: %s\n", text1);
    printf("Mensaje encriptado: %s\n", code1);
    printf("Mensaje desencriptado: %s\n\n", decode1);

    if (code1) free(code1);
    if (decode1) free(decode1);

    // Caso 2: Encriptar y desencriptar un mensaje de 35 caracteres iguales con una máquina de un solo disco
    int password2[3] = { 1, 2, 0 }; // Usar los rotores 1 y 2, rotor 3 en posición 0
    littleEnigmaSet(le, password2);
    char* text2 = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";
    char* code2 = littleEnigmaEncrypt(le, text2);
    char* decode2 = littleEnigmaDecrypt(le, code2);

    printf("Caso 2:\n");
    printf("Mensaje original: %s\n", text2);
    printf("Mensaje encriptado: %s\n", code2);
    printf("Mensaje desencriptado: %s\n\n", decode2);

    if (code2) free(code2);
    if (decode2) free(decode2);

    // Caso 3: Encriptar y desencriptar un mensaje de 10 caracteres con una máquina de tres discos
    int password3[3] = { 2, 1, 0 }; // Usar los rotores 2, 1 y 0
    littleEnigmaSet(le, password3);
    char* text3 = "ALANTURING";
    char* code3 = littleEnigmaEncrypt(le, text3);
    char* decode3 = littleEnigmaDecrypt(le, code3);

    printf("Caso 3:\n");
    printf("Mensaje original: %s\n", text3);
    printf("Mensaje encriptado: %s\n", code3);
    printf("Mensaje desencriptado: %s\n\n", decode3);

    if (code3) free(code3);
    if (decode3) free(decode3);

    // Caso 4: Encriptar y desencriptar un mensaje de 10 caracteres con una máquina de cinco discos
    int password4[3] = { 0, 2, 1 }; // Usar los rotores 0, 2 y 1
    littleEnigmaSet(le, password4);
    char* text4 = "NIELSBOHR";
    char* code4 = littleEnigmaEncrypt(le, text4);
    char* decode4 = littleEnigmaDecrypt(le, code4);

    printf("Caso 4:\n");
    printf("Mensaje original: %s\n", text4);
    printf("Mensaje encriptado: %s\n", code4);
    printf("Mensaje desencriptado: %s\n\n", decode4);

    if (code4) free(code4);
    if (decode4) free(decode4);

    // Caso 5: Encriptar y desencriptar un mensaje de 10 caracteres con una máquina de ocho discos
    int password5[3] = { 1, 0, 2 }; // Usar los rotores 1, 0 y 2
    littleEnigmaSet(le, password5);
    char* text5 = "MARIECURIE";
    char* code5 = littleEnigmaEncrypt(le, text5);
    char* decode5 = littleEnigmaDecrypt(le, code5);

    printf("Caso 5:\n");
    printf("Mensaje original: %s\n", text5);
    printf("Mensaje encriptado: %s\n", code5);
    printf("Mensaje desencriptado: %s\n\n", decode5);

    if (code5) free(code5);
    if (decode5) free(decode5);

    // Liberar la memoria asignada a 'le'
    littleEnigmaDelete(le);
   
    // Liberar la memoria asignada a 'w1', 'w2' 'w3' etc
    wheelDelete(w1);
    wheelDelete(w2);
    wheelDelete(w3);
    wheelDelete(w4);
    wheelDelete(w5);
    wheelDelete(w6);

    return 0;
}

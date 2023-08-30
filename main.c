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
    char* alphabetPermutation1[2];
    char* alphabetPermutation2[1];
    char* alphabetPermutation3[3];
    char* alphabetPermutation4[5];
    char* alphabetPermutation5[8];
    alphabetPermutation1[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    alphabetPermutation1[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    alphabetPermutation2[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    
    for (int i = 0; i < 3; i++){
    	alphabetPermutation3[i] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    }
    
    for (int i = 0; i < 5; i++){
    	alphabetPermutation4[i] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    }
    
    for (int i = 0; i < 8; i++){
    	alphabetPermutation5[i] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    }
    struct littleEnigma* le1 = littleEnigmaNew(alphabetPermutation1, 2);
    struct littleEnigma* le2 = littleEnigmaNew(alphabetPermutation2, 1);
    struct littleEnigma* le3 = littleEnigmaNew(alphabetPermutation3, 3);
    struct littleEnigma* le4 = littleEnigmaNew(alphabetPermutation4, 5);
    struct littleEnigma* le5 = littleEnigmaNew(alphabetPermutation5, 8);
    printf("\n");

    int password1[2] = { 3, 5 };
    int password2[1] = { 0 };
    int password3[3] = { 3, 5, 6 };
    int password4[5] = { 3, 5, 6, 7, 8 };
    int password5[8] = { 3, 5, 6, 7, 8, 9, 10, 11 };
    
    littleEnigmaSet(le1, password1);
    littleEnigmaSet(le2, password2);
    littleEnigmaSet(le3, password3);
    littleEnigmaSet(le4, password4);
    littleEnigmaSet(le5, password5);
   

    printf("littleEnigmaEncrypt() \n");
    char* text1 = "";
    char* text2 = "MURCIELAGOMURCIELAGOMURCIELAGOMURCI";
    char* text3 = "MURCIELAGO";
    char* text4 = "AGUAFUERTE";
    char* text5 = "MARIECURIE";
    char* code1 = littleEnigmaEncrypt(le1, text1);
    char* code2 = littleEnigmaEncrypt(le2, text2);
    char* code3 = littleEnigmaEncrypt(le3, text3);
    char* code4 = littleEnigmaEncrypt(le4, text4);
    char* code5 = littleEnigmaEncrypt(le5, text5);
    printf("%s -> %s\n\n", text1, code1);
    printf("%s -> %s\n\n", text2, code2);
    printf("%s -> %s\n\n", text3, code3);
    printf("%s -> %s\n\n", text4, code4);
    printf("%s -> %s\n\n", text5, code5);

    littleEnigmaSet(le1, password1);
    littleEnigmaSet(le2, password2);
    littleEnigmaSet(le3, password3);
    littleEnigmaSet(le4, password4);
    littleEnigmaSet(le5, password5);


    printf("littleEnigmaDecrypt()\n");
    char* decode1 = littleEnigmaDecrypt(le1, code1);
    char* decode2 = littleEnigmaDecrypt(le2, code2);
    char* decode3 = littleEnigmaDecrypt(le3, code3);
    char* decode4 = littleEnigmaDecrypt(le4, code4);
    char* decode5 = littleEnigmaDecrypt(le5, code5);
    printf("%s -> %s -> %s\n\n", text1, code1, decode1);
    printf("%s -> %s -> %s\n\n", text2, code2, decode2);
    printf("%s -> %s -> %s\n\n", text3, code3, decode3);
    printf("%s -> %s -> %s\n\n", text4, code4, decode4);
    printf("%s -> %s -> %s\n\n", text5, code5, decode5);
  
    littleEnigmaDelete(le1);
    littleEnigmaDelete(le2);
    littleEnigmaDelete(le3);
    littleEnigmaDelete(le4);
    littleEnigmaDelete(le5);
    
    free(code1);
    free(code2);
    free(code3);
    free(code4);
    free(code5);
    free(decode1);
    free(decode2);
    free(decode3);
    free(decode4);
    free(decode5);
    
    // Liberar la memoria 
    wheelDelete(w1);
    wheelDelete(w2);
    wheelDelete(w3);
    wheelDelete(w4);
    wheelDelete(w5);
    wheelDelete(w6);
    wheelDelete(w7);

    printf("Tests finalizados\n");

}

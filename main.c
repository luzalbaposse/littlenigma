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
    // char* alphabetPermutation[2];
    // alphabetPermutation[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    // alphabetPermutation[1] = "NTZPSFBOKMWRCJDIVLAEYUXHGQ";
    // struct littleEnigma* le = littleEnigmaNew(alphabetPermutation, 2);
    // littleEnigmaPrint(le);
    // printf("\n\n");

    // int password[2] = { 3, 5 };
    // littleEnigmaSet(le, password);
    // littleEnigmaPrint(le);
    // printf("\n\n");

    // char* text = "TEXT";
    // char* code = littleEnigmaEncrypt(le, text);
    // littleEnigmaPrint(le);
    // printf("%s -> %s\n\n", text, code);

    // littleEnigmaSet(le, password);
    // littleEnigmaPrint(le);
    // printf("\n\n");

    // char* decode = littleEnigmaDecrypt(le, code);
    // littleEnigmaPrint(le);
    // printf("%s -> %s -> %s\n\n", text, code, decode);

    // if(code) free(code);
    // if(decode) free(decode);

    // littleEnigmaDelete(le);

//Encriptar y desncriptar un mensaje de 0 caracteres
    char* alphabetPermutation[1];
    alphabetPermutation[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      
   
    struct littleEnigma* le = littleEnigmaNew(alphabetPermutation, 5);
    int password[3] = { 0 };
    littleEnigmaSet(le, password);

    char* text = " ";
    char* code = littleEnigmaEncrypt(le, text);

    printf("Encriptar y desncriptar un mensaje de 0 caracteres:");
    littleEnigmaPrint(le);
    printf("Encripta un mensaje de 0 caracteres: %s -> %s\n\n", text, code);
    
    littleEnigmaSet(le, password);
    
    char* decode = littleEnigmaDecrypt(le, code);
    littleEnigmaPrint(le);
    printf("Desencripta el codigo: %s -> %s \n\n", text, decode);


    if(code) free(code);
    if(decode) free(decode);
    littleEnigmaDelete(le);
   


  //Encriptar y desncriptar un mensaje de 35 caracteres iguales con un solo disco. 
  char* alphabetPermutation2[1];
      alphabetPermutation2[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
   

    struct littleEnigma* le2 = littleEnigmaNew(alphabetPermutation2, 5);
    int password2[1] = { 0 };
    littleEnigmaSet(le2, password2);

    char* text2 = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";
    char* code2 = littleEnigmaEncrypt(le2, text2);

    printf("Encriptar y desncriptar un mensaje de 35 caracteres iguales con una maquina de un solo disco:");
    littleEnigmaPrint(le2);
    printf("Encripta un mensaje de 35 caracteres con una maquina de un solo disco: %s -> %s\n\n", text2, code2);
    
    littleEnigmaSet(le2, password2);
    
    char* decode2 = littleEnigmaDecrypt(le2, code2);
    littleEnigmaPrint(le2);
    printf("Desencripta el codigo con una maquina de un solo disco: %s -> %s\n\n", text2, decode2);


    if(code2) free(code2);
    if(decode2) free(decode2);
    littleEnigmaDelete(le2);
   




  //Encriptar y desncriptar un mensaje de 10 caracteres con un 3 discos. 
    char* alphabetPermutation3[3];
      alphabetPermutation3[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation3[1] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation3[2] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
    

    struct littleEnigma* le3 = littleEnigmaNew(alphabetPermutation3, 3);
    int password3[3] = { 0, 0, 0 };
    littleEnigmaSet(le3, password3);

    char* text3 = "ALANTURING";
    char* code3 = littleEnigmaEncrypt(le3, text3);

    printf("Encriptar y desncriptar un mensaje de 10 caracteres con una maquina de un 3 discos:");
    littleEnigmaPrint(le3);
    printf("Encripta un mensaje de 10 caracteres con una maquina de un 3 discos: %s -> %s\n\n", text3, code3);
    
    littleEnigmaSet(le3, password3);
    
    char* decode3 = littleEnigmaDecrypt(le3, code3);
    littleEnigmaPrint(le3);
    printf("Desencripta el codigo con una maquina de 3 discos %s -> %s\n\n", text3, decode3);


    if(code3) free(code3);
    if(decode3) free(decode3);
    littleEnigmaDelete(le3);
   

//Encriptar y desencriptar un mensaje de 10 caracteres con un 5 discos. 
char* alphabetPermutation4[5];
      alphabetPermutation4[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation4[1] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation4[2] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation4[3] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation4[4] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";

    

    struct littleEnigma* le4 = littleEnigmaNew(alphabetPermutation4, 5);
    int password4[5] = { 0, 0, 0, 0, 0 };
    littleEnigmaSet(le4, password4);

    char* text4 = "NIELSBOHR";
    char* code4 = littleEnigmaEncrypt(le4, text4);

    printf("Encriptar y desncriptar un mensaje de 10 caracteres con una maquina de un 5 discos:");
    littleEnigmaPrint(le4);
    printf("Encripta un mensaje de 10 caracteres con una maquina de un 5 discos: %s -> %s\n\n", text4, code4);
    
    littleEnigmaSet(le4, password4);
    
    char* decode4 = littleEnigmaDecrypt(le4, code4);
    littleEnigmaPrint(le4);
    printf("Desencripta el codigo con una maquina de 5 discos %s -> %s\n\n", text4, decode4);


    if(code4) free(code4);
    if(decode4) free(decode4);
    littleEnigmaDelete(le4);
   


   //Encriptar y desncriptar un mensaje de 10 caracteres con un 8 discos. 
      char* alphabetPermutation5[8];
      alphabetPermutation5[0] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation5[1] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation5[2] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation5[3] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation5[4] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation5[5] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation5[6] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";
      alphabetPermutation5[7] = "JGDQOXUSCAMIFRVTPNEWKBLZYH";


    struct littleEnigma* le5 = littleEnigmaNew(alphabetPermutation5, 8);
    int password5[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    littleEnigmaSet(le5, password5);

    char* text5 = "MARIECURIE";
    char* code5 = littleEnigmaEncrypt(le5, text5);

    printf("Encriptar y desncriptar un mensaje de 10 caracteres con una maquina de un 8 discos:");
    littleEnigmaPrint(le5);
    printf("Encripta un mensaje de 10 caracteres con una maquina de un 5 discos: %s -> %s\n\n", text5, code5);
    
    littleEnigmaSet(le5, password5);
    
    char* decode5 = littleEnigmaDecrypt(le5, code5);
    littleEnigmaPrint(le5);
    printf("Desencripta el codigo con una maquina de 5 discos %s -> %s\n\n", text5, decode5);


    if(code5) free(code5);
    if(decode5) free(decode5);
    littleEnigmaDelete(le5);
    // Liberar la memoria asignada a 'w1', 'w2' y 'w3'
    wheelDelete(w1);
    wheelDelete(w2);
    wheelDelete(w3);
    wheelDelete(w4);
    wheelDelete(w5);
    wheelDelete(w6);

    return 0;
}

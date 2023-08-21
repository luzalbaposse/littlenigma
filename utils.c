#include "utils.h"
#include <stdio.h>

int strLen(char* src) {
/*
Requiere: src es un puntero a un arreglo de caracteres terminado en '\0'.
Devuelve: la cantidad de caracteres en src sin contar el '\0'.
*/
    int i;
    while(src[i] != '\0'){
        i++;
    }
    return i;
}

char* strDup(char* src) {
    /*
    Requiere: src es un puntero a un arreglo de caracteres terminado en '\0'.
    Devuelve: un puntero a un arreglo de caracteres con el mismo contenido que src.
    */
    int i = 0;
    char* aux = (char*)malloc(sizeof(char) * (strLen(src)+1)); 
    while (src[i] != '\0'){        
        aux[i] = src[i];
        i++;
    }
    // le agrego el caracter nulo
    aux[i] = '\0';
    return aux;
}

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count){

    return 0;
}

void littleEnigmaSet(struct littleEnigma* le, int* password) {

    // COMPLETAR
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){

    // COMPLETAR

    return 0;
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {

    // COMPLETAR

    return 0;
}

void littleEnigmaDelete(struct littleEnigma* le) {

    // COMPLETAR

}

void littleEnigmaPrint(struct littleEnigma* le) {
    for(int i=0; i<le->wheelsCount; i++) {
        wheelPrint(le->wheels[i]);
        printf("\n");
    }
}

struct wheel* makeWheelFromString(char* alphabetPermutation) {
    int tamano = len(alphabetPermutation);
    struct wheel* rueda = (struct wheel*)malloc(sizeof(struct wheel*));
    struct letter* letras = (struct letter*)malloc(sizeof(struct letter*));
    wheel->first = letras;
    for(int i = 0;i<tamano;i++){
        letras->letter = alphabetPermutation[i];
        letras->position = i;
        letras->next = (struct letter*)malloc(sizeof(struct letter*))
        letras = letras->next;
    }
    return wheel;
}

void setWheel(struct wheel* w, int position) {
    struct letter* current = w->first;
    while(current->position != position) {
        current = current->next;
    }
    w->first = current;   
}

void rotateWheel(struct wheel* w, int steps) {
  /*COMPLETAR*/
}

void rotateWheels(struct wheel** wheels, int wheelsCount) {
     /*COMPLETAR*/
}

void wheelDelete(struct wheel* w) {
   /*COMPLETAR*/
}

void wheelPrint(struct wheel* w) {
    printf("%s", w->alphabet);
    struct letter* current = w->first;
    int i = 0;
    while(i<w->count) {
        printf("(%c-%i)", current->letter, current->position);
        current = current->next;
        i++;
    }
}

int letterToIndex(char letter) {
    if('A' <= letter && letter <= 'Z') return letter-'A';
    return 0;
}

char indexToletter(int index) {
    if(0 <= index && index <= 25) return index+'A';
    return 0;
}

char encryptWheel(struct wheel* w, char letter) {
    int index =  letterToIndex(letter);
    struct letter* current = w->first;
    int i = 0;
    while(i<index) {
        current = current->next;
        i++;
    }
    return current->letter;
}

char decryptWheel(struct wheel* w, char letter) {
    struct letter* current = w->first;
    int i = 0;
    while(current->letter != letter) {
        current = current->next;
        i++;
    }
    return indexToletter(i);
}

char encryptOneLetter(struct littleEnigma* le, char letter) {

    // COMPLETAR

    return 0;
}

char decryptOneLetter(struct littleEnigma* le, char letter) {

    // COMPLETAR

    return 0;
}

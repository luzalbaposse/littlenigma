#ifndef _UTILS_HH_
#define _UTILS_HH_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// Structs

struct littleEnigma {
    struct wheel** wheels; // Doble puntero, 
    int wheelsCount; // Dice cuántas wheels hay, o sea que es el tamaño del array e involucra que las letras a encriptar van a pasar por esta cantidad de wheels
};

struct wheel { // Es una lista circular es decir que el último elemento apunta al primero.
    struct letter* first; // son los nodos de la lista circular con 3 campos
    char* alphabet; // guarda una copia de la permutación del alfabeto
    int count; // cantidad de letras de este alfabeto
};

struct letter {
    char letter; // guarda la letra
    int  position; // es la posición para indicar la posicion de la letra dentro de la permutación
    struct letter* next; // siguiente letra
};

// Little Enigma

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count);
void littleEnigmaSet(struct littleEnigma* le, int* positions);
char* littleEnigmaEncrypt(struct littleEnigma* le, char* text);
char* littleEnigmaDecrypt(struct littleEnigma* le, char* code);
void littleEnigmaDelete(struct littleEnigma* le);
void littleEnigmaPrint(struct littleEnigma* le);

// Alphabet Wheels

struct wheel* makeWheelFromString(char* alphabetPermutation);
void setWheel(struct wheel* w, int position);
void rotateWheel(struct wheel* w, int steps);
void rotateWheels(struct wheel** w, int count);
void wheelDelete(struct wheel* w);
void wheelPrint(struct wheel* w);

// Auxiliary

int letterToIndex(char letter);
char indexToletter(int index);
char encryptWheel(struct wheel* w, char letter);
char decryptWheel(struct wheel* w, char letter);
char encryptOneLetter(struct littleEnigma* le, char letter);
char decryptOneLetter(struct littleEnigma* le, char letter);

// Strings

int strLen(char* src);
char* strDup(char* src);

#endif

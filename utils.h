#ifndef _UTILS_HH_
#define _UTILS_HH_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// Structs

struct littleEnigma {
    struct wheel** wheels;
    int wheelsCount;
};

struct wheel {
    struct letter* first;
    char* alphabet;
    int count;
};

struct letter {
    char letter;
    int  position;
    struct letter* next;
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

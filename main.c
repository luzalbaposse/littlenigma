#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
int main(){
    /*
    test
    */

    // strLen
    char* stringVacio = "";
    char* stringUnCaracter = "A";
    char* stringTodosCaracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("strLen\n");
    printf("1. String vacio: %i\n", strLen(stringVacio));
    printf("2. String de un car´acter: %i\n", strLen(stringUnCaracter));
    printf("3. String que incluya todos los caracteres validos distintos de cero: %i\n", strLen(stringTodosCaracteres));

    // strDup
    printf("strDup\n");
    printf("1. String vacio: %s\n", strDup(stringVacio));
    printf("2. String de un caracter: %s\n", strDup(stringUnCaracter));
    printf("3. String que incluya todos los caracteres validos distintos de cero: %s\n", strDup(stringTodosCaracteres));

    // makeWheelFromString
    printf("makeWheelFromString\n");
    char* alphabet1 = "A";
    char* alphabet2 = "ABCDEFGHIJ";
    char* alphabet3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* alphabet4 = "ABCDE";
    struct wheel* w4 = makeWheelFromString(alphabet4);
    struct wheel* w1 = makeWheelFromString(alphabet1);
    struct wheel* w2 = makeWheelFromString(alphabet2);
    struct wheel* w3 = makeWheelFromString(alphabet3);
    printf("1. Generar una estructura wheel con un alfabeto de 1 caracter: ");
    wheelPrint(w1);
    printf("\n");
    printf("2. Generar una estructura wheel con un alfabeto de 10 caracteres: ");
    wheelPrint(w2);
    printf("\n");
    printf("3. Generar una estructura wheel con un alfabeto de 26 caracteres: ");
    wheelPrint(w3);
    printf("\n");
    printf("4. Generar una estructura wheel con un alfabeto de 5 caracteres: ");
    wheelPrint(w4);

    // rotateWheel
    printf("rotateWheel\n");
    printf("1. Rotar una estrucutura wheel de 26 caracteres una posicion: ");
    rotateWheel(w3, 1);
    wheelPrint(w3);
    printf("\n");
    printf("2. Rotar una estrucutura wheel de 26 caracteres 26 posiciones: ");
    rotateWheel(w3, 26);
    wheelPrint(w3);
    printf("\n");
    printf("3. Rotar una estrucutura wheel de 5 caracteres 26 posiciones: ");
    rotateWheel(w4, 26);
    wheelPrint(w4);
    printf("\n");
    printf("4. Rotar una estrucutura wheel de 1 caracteres 26 posiciones: ");
    rotateWheel(w1, 26);
    wheelPrint(w1);
    printf("\n");
}

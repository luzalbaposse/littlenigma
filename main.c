#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
int main(){
    /*
    se enumera un conjunto m´ınimo de casos de test que deben implementar dentro
del archivo main:
strLen
1. String vac´ıo.
2. String de un car´acter.
3. String que incluya todos los caracteres v´alidos distintos de cero.
strDup
1. String vac´ıo.
2. String de un car´acter.
3. String que incluya todos los caracteres v´alidos distintos de cero.
makeWheelFromString
1. Generar una estructura wheel con un alfabeto de 1 caracter.
2. Generar una estructura wheel con un alfabeto de 10 caracteres.
3. Generar una estructura wheel con un alfabeto de 26 caracteres.
rotateWheel
1. Rotar una estrucutura wheel de 26 caracteres una posici´on.
2. Rotar una estrucutura wheel de 26 caracteres 26 posiciones.
3. Rotar una estrucutura wheel de 5 caracteres 26 posiciones.
4. Rotar una estrucutura wheel de 1 caracteres 26 posiciones.
littleEnigmaEncrypt y littleEnigmaDecrypt
1. Encriptar y desencriptar un mensaje de 0 caracteres.
2. Encriptar y desencriptar un mensaje de 35 caracteres iguales con una m´aquina de un solo
disco.
3. Encriptar y desencriptar un mensaje de 10 caracteres con una m´aquina de tres discos.
4. Encriptar y desencriptar un mensaje de 10 caracteres con una m´aquina de cinco discos.
5. Encriptar y desencriptar un mensaje de 10 caracteres con una m´aquina de ocho discos.
    */

    // strLen
    char* stringVacio = "";
    char* stringUnCaracter = "A";
    char* stringTodosCaracteres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("strLen\n");
    printf("1. String vacıo: %i\n", strLen(stringVacio));
    printf("2. String de un caracter: %i\n", strLen(stringUnCaracter));
    printf("3. String que incluya todos los caracteres validos distintos de cero: %i\n", strLen(stringTodosCaracteres));

    // strDup
    printf("strDup\n");
    printf("1. String vacıo: %s\n", strDup(stringVacio));
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

    // littleEnigmaEncrypt y littleEnigmaDecrypt
    printf("littleEnigmaEncrypt y littleEnigmaDecrypt\n");
    char* message1 = "";
    char* message2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char* message3 = "ABCDEFGHIJ";
    char* message4 = "ABCDEFGHIJ";
    char* message5 = "ABCDEFGHIJ";

    char* alphabetPermutation1[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", NULL};
    char* alphabetPermutation2[] = {"ABCDEFGHIJ", "BCDEFGHIJA", "CDEFGHIJAB", "DEFGHIJABC", "EFGHIJABCD", "FGHIJABCDE", "GHIJABCDEF", "HIJABCDEFG", "IJABCDEFGH", "JABCDEFGHI", NULL};
    char* alphabetPermutation3[] = {"ABCDEFGHIJ", "BCDEFGHIJA", "CDEFGHIJAB", "DEFGHIJABC", "EFGHIJABCD", "FGHIJABCDE", "GHIJABCDEF", "HIJABCDEFG", "IJABCDEFGH", "JABCDEFGHI", NULL};
    char* alphabetPermutation4[] = {"ABCDEFGHIJ", "BCDEFGHIJA", "CDEFGHIJAB", "DEFGHIJABC", "EFGHIJABCD", "FGHIJABCDE", "GHIJABCDEF", "HIJABCDEFG", "IJABCDEFGH", "JABCDEFGHI", NULL};
    char* alphabetPermutation5[] = {"ABCDEFGHIJ", "BCDEFGHIJA", "CDEFGHIJAB", "DEFGHIJABC", "EFGHIJABCD", "FGHIJABCDE", "GHIJABCDEF", "HIJABCDEFG", "IJABCDEFGH", "JABCDEFGHI", NULL};
    struct littleEnigma* le1 = littleEnigmaNew(alphabetPermutation1, 1);
    struct littleEnigma* le2 = littleEnigmaNew(alphabetPermutation2, 10);
    struct littleEnigma* le3 = littleEnigmaNew(alphabetPermutation3, 10);
    struct littleEnigma* le4 = littleEnigmaNew(alphabetPermutation4, 10);
    struct littleEnigma* le5 = littleEnigmaNew(alphabetPermutation5, 10);

    printf("1. Encriptar y desencriptar un mensaje de 0 caracteres: ");
    printf("Encriptado: %s\n", littleEnigmaEncrypt(le1, message1));
    printf("Desencriptado: %s\n", littleEnigmaDecrypt(le1, message1));
    printf("2. Encriptar y desencriptar un mensaje de 35 caracteres iguales con una maquina de un solo disco: ");
    printf("Encriptado: %s\n", littleEnigmaEncrypt(le2, message2));
    printf("Desencriptado: %s\n", littleEnigmaDecrypt(le2, message2));
    printf("3. Encriptar y desencriptar un mensaje de 10 caracteres con una maquina de tres discos: ");
    printf("Encriptado: %s\n", littleEnigmaEncrypt(le3, message3));
    printf("Desencriptado: %s\n", littleEnigmaDecrypt(le3, message3));
    printf("4. Encriptar y desencriptar un mensaje de 10 caracteres con una maquina de cinco discos: ");
    printf("Encriptado: %s\n", littleEnigmaEncrypt(le4, message4));
    printf("Desencriptado: %s\n", littleEnigmaDecrypt(le4, message4));
    printf("5. Encriptar y desencriptar un mensaje de 10 caracteres con una maquina de ocho discos: ");
    printf("Encriptado: %s\n", littleEnigmaEncrypt(le5, message5));
    printf("Desencriptado: %s\n", littleEnigmaDecrypt(le5, message5));
    printf("\n");

    printf("Eso es todo :D ");
}

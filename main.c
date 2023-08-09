#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main() {

    // COMPLETAR

    // A Continuacion dejamos algunos ejemplos de como
    // llama a las funciones pedidas. Este codigo debe
    // ser borrado / modificado.

    // strLen
    int len = strLen("hola");
    printf("strDup(\"hola\") -> \"%i\"\n", len);
    printf("\n");

    // strDup
    char* dup = strDup("hola");
    printf("strDup(\"hola\") -> \"%s\"\n", dup);
    free(dup);
    printf("\n");

    // wheel
    struct wheel* w = makeWheelFromString("QWERTYUIOPASDFGHJKLMNBVCXZ");
    wheelPrint(w);
    printf("\n");

    setWheel(w, 5);
    wheelPrint(w);
    printf("\n");

    rotateWheel(w, 100);
    wheelPrint(w);
    printf("\n");

    wheelDelete(w);
    printf("\n\n");

    // littleEnigma
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

    return 0;
}

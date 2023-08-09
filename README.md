# Trabajo Práctico 1: Little Enigma - Programación en C

**Tecnología Digital II**

## Introducción

En este trabajo práctico, exploraremos la implementación de una simplificación de la Máquina Enigma, una famosa máquina de cifrado utilizada en la Segunda Guerra Mundial. A través de una serie de ejercicios, implementaremos funciones que simulan el funcionamiento de esta máquina y sus componentes.

## Funciones sobre Strings

### Función `strLen`

Esta función calcula la longitud de una cadena de caracteres pasada como parámetro.

### Función `strDup`

Duplica una cadena de caracteres, creando una nueva copia en memoria. El resultado es un puntero a la copia duplicada.

## Funciones sobre Tipo de Datos `wheel`

### Función `letterToIndex`

Convierte un carácter en un índice entre 0 y 25 (representando las letras del alfabeto).

### Función `indexToletter`

Convierte un índice en un carácter correspondiente.

### Función `setWheel`

Gira una estructura de disco (`wheel`) a la posición especificada.

### Función `wheelPrint`

Imprime en pantalla una estructura de disco (`wheel`).

### Función `makeWheelFromString`

Crea una estructura de disco (`wheel`) a partir de una permutación del alfabeto.

### Función `rotateWheel`

Gira una estructura de disco (`wheel`) una cantidad específica de pasos.

### Función `rotateWheels`

Gira un arreglo de discos (`wheel`) de manera secuencial.

### Función `wheelDelete`

Libera la memoria ocupada por una estructura de disco (`wheel`).

## Funciones sobre Tipo de Datos `littleEnigma`

### Función `littleEnigmaNew`

Crea una nueva máquina Enigma (`littleEnigma`) con una configuración de discos dada.

### Función `littleEnigmaSet`

Configura las posiciones iniciales de los discos de una máquina Enigma (`littleEnigma`).

### Función `littleEnigmaEncrypt`

Cifra un mensaje utilizando una máquina Enigma (`littleEnigma`) y devuelve el resultado.

### Función `littleEnigmaDecrypt`

Descifra un mensaje cifrado utilizando una máquina Enigma (`littleEnigma`) y devuelve el mensaje original.

### Función `littleEnigmaDelete`

Libera la memoria ocupada por una máquina Enigma (`littleEnigma`) y sus componentes.

### Función `encryptOneLetter`

Cifra un carácter utilizando una máquina Enigma (`littleEnigma`) y actualiza las posiciones de los discos.

### Función `decryptOneLetter`

Descifra un carácter cifrado utilizando una máquina Enigma (`littleEnigma`) y actualiza las posiciones de los discos.

## Casos de Test

A continuación, se detallan algunos casos de test que deberán implementarse en el archivo `main.c` para probar las funciones desarrolladas.

1. Pruebas sobre `strLen` y `strDup` para diferentes tipos de cadenas.
2. Generación y manipulación de estructuras `wheel`.
3. Cifrado y descifrado de mensajes utilizando una máquina Enigma.
4. Configuración y rotación de discos en una máquina Enigma.

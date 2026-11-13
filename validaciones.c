#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

double leerDouble(const char *mensaje) {
    double valor;
    char buffer[100];
    int valido = 0;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            char *endptr;
            valor = strtod(buffer, &endptr);
            
            if (endptr != buffer && (*endptr == '\n' || *endptr == '\0')) {
                valido = 1;
            } else {
                printf("[Error] Entrada invalida. Por favor, ingrese un numero valido.\n");
            }
        } else {
            printf("[Error] No se pudo leer la entrada.\n");
        }
    } while (!valido);

    return valor;
}

double leerDoublePositivo(const char *mensaje, double minimo) {
    double valor;
    do {
        valor = leerDouble(mensaje);
        if (valor < minimo) {
            printf("[Error] El valor debe ser mayor o igual a %.2lf.\n", minimo);
        }
    } while (valor < minimo);
    return valor;
}
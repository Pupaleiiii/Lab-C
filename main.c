#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

int main() {
    NaveOrion orion;
    int opcion;
    double DT, Fg, Ag, Ki, Kf, x, DL, DiL, Ui, Uf, WPorUnidadDeMasa;

    // Arreglo unidimensional para cumplir con el requisito técnico obligatorio de la cátedra
    double historialResultados[10];
    int totalHistorial = 0;

    // Llamamos a la función pasando el puntero de la estructura (&)
    configurarNave(&orion);

    // Ciclo del menú interactivo (Experiencia de usuario solicitada por cátedra)
    do {
        printf("\n==================================================\n");
        printf("      SIMULADOR ARTEMIS: INYECCION TRANSLUNAR     \n");
        printf("==================================================\n");
        printf("1. Analisis de inercia y fuerza gravitatoria (1ra Ley)\n");
        printf("2. Calcular energia cinetica inicial (K1)\n");
        printf("3. Calcular trabajo externo al punto de equilibrio\n");
        printf("4. Ver analisis energetico del viaje (Tierra vs Luna)\n");
        printf("5. Ver historial de calculos guardados (Arreglo)\n");
        printf("0. Salir del simulador\n");
        printf("==================================================\n");
        
        opcion = leerEntero("Seleccione una opcion: ");

        printf("\n--------------------------------------------------\n");

        switch (opcion) {
            case 1:
                Fg = fuerzaGravitatoria(orion.masa, orion.alturaOrbital);
                Ag = aceleracionGravitatoria(orion.masa, orion.alturaOrbital);
                printf("[RESULTADO] Analisis de Inercia y Gravedad:\n");
                printf("-> La orion continua moviendose por inercia pero la gravedad terrestre sigue actuando sobre ella y modifica su movimiento.\n");
                printf("-> Intensidad de la fuerza gravitatoria que actua sobre la nave es: %.2lf N\n", Fg);
                printf("-> La intensidad de la aceleracion gravitatoria que actua sobre la nave es: %.2lf m/s^2\n", Ag);
                
                // Guardamos el resultado en el arreglo si hay espacio
                if (totalHistorial < 10) {
                    historialResultados[totalHistorial] = Fg;
                    totalHistorial++;
                }
                break;

            case 2:
                Ki = energiaCinetica(orion.masa, orion.velocidadInicial);
                printf("[RESULTADO] Energia Cinetica Inicial:\n");
                printf("-> La energia cinetica inicial al iniciar su viaje translunar es: %.2lf J\n", Ki);
                
                if (totalHistorial < 10) {
                    historialResultados[totalHistorial] = Ki;
                    totalHistorial++;
                }
                break;

            case 3:
                Kf = 0;
                Ki = energiaCinetica(orion.masa, orion.velocidadInicial);
                x = posicionEquilibrio(D);
                DL = D - x;
                DT = RT + orion.alturaOrbital;
                DiL = D - DT;
                Ui = UgTotal(orion.masa, DT, DiL);
                Uf = UgTotal(orion.masa, x, DL);
                WPorUnidadDeMasa = Wext(Ki, Kf, Ui, Uf) / orion.masa;
                
                printf("[RESULTADO] Trabajo Externo:\n");
                printf("-> Distancia a la posicion de equilibrio: %.2lf m\n", x);
                printf("-> Trabajo externo por unidad de masa: %.2lf J/kg\n", WPorUnidadDeMasa);
                
                if (totalHistorial < 10) {
                    historialResultados[totalHistorial] = WPorUnidadDeMasa;
                    totalHistorial++;
                }
                break;

            case 4:
                printf("[RESULTADO] Analisis Energetico:\n");
                printf("-> La Tierra posee un campo gravitatorio mas intenso que la Luna.\n");
                printf("-> Por lo tanto, abandonar el campo gravitatorio terrestre requiere un mayor aporte energetico.\n");
                printf("-> En el retorno hacia la Tierra se puede aprovechar la atraccion gravitatoria lunar y ahorrar mucho combustible.\n");
                break;

            case 5:
                printf("[RESULTADO] Historial de calculos almacenados en el Arreglo:\n");
                if (totalHistorial == 0) {
                    printf("-> Todavia no se registro ningun calculo en la sesion.\n");
                } else {
                    for (int i = 0; i < totalHistorial; i++) {
                        printf("   [%d] Valor guardado: %.2lf\n", i + 1, historialResultados[i]);
                    }
                }
                break;

            case 0:
                printf("Apagando sistemas del simulador Artemis... ¡Hasta luego!\n");
                break;

            default:
                printf("[Error] Opcion no valida. Por favor, elija una opcion del menu.\n");
                break;
        }
        printf("--------------------------------------------------\n");

    } while (opcion != 0);

    return 0;
}
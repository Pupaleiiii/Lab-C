#include <stdio.h>
#include "artemis.h"

int main() {
    
    double x, m, h, Fg, Ag, Vi, DT, DL, DiL, Ki, Kf, Ui, Uf, WPorUnidadDeMasa;
    
    printf("Masa de Orion (kg): ");
    scanf("%lf", &m);

    printf("Altura orbital (m): ");
    scanf("%lf", &h);

    printf("Velocidad inicial (m/s): ");
    scanf("%lf", &Vi);

    if (m <= 0 || h < 0 || Vi < 0) {
        printf("Error: datos de entrada invalidos.\n");
        return 1;
    }

    //A: 1º Ley de Newton

    DT = RT + h;
    
    Fg = (G*MT*m)/(DT*DT);

    Ag = Fg/m;

    printf("La orion continua moviendose por inercia pero la gravedad terrestre sigue actuando sobre ella y modifica su movimiento. \n");
    
    printf("El intensidad de la fuerza gravitatoria que actua sobre la nave es: %.2lf N\n", Fg);
    
    printf("La intensidad de la aceleracion gravitatoria que actua sobre la nave es: %.2lf m/s^2\n", Ag);

    //B: Energia cinética

    Ki = energiaCinetica(m, Vi);

    printf("La energia cinetica inicial al iniciar su viaje translunar es: %.2lf J\n", Ki);
    
    //C: Trabajo externo
    
    Kf = 0;

    x = posicionEquilibrio(D);

    DL = D - x;

    DiL = D - DT;

    Ui = UgTotal(m, DT, DiL);

    Uf = UgTotal(m, x, DL);

    WPorUnidadDeMasa = Wext(Ki, Kf, Ui, Uf)/m;
    
    printf("distancia a la posicion de equilibrio: %.2lf m\n", x);

    printf("Trabajo externo por unidad de masa: %.2lf J/kg\n", WPorUnidadDeMasa);

    //D: Energía

    printf("La Tierra posee un campo gravitatorio mas intenso que la Luna.\n");

    printf("Por lo tanto, abandonar el campo gravitatorio terrestre requiere un mayor aporte energetico.\n");

    printf("En el retorno hacia la Tierra se puede aprovechar la atraccion gravitatoria lunar y ahorrar mucho combustible.\n");

    return 0;

}




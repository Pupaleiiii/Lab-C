#include <stdio.h>
#include <math.h>
#include "artemis.h"
#include "validaciones.h"

void configurarNave(NaveOrion *nave) {
    printf("==================================================\n");
    printf("        CONFIGURACION DE LA MISION ARTEMIS        \n");
    printf("==================================================\n");
    
    nave->masa = leerDoublePositivo("Ingrese la masa de Orion en kg (> 0): ", 0.0001);
    nave->alturaOrbital = leerDoublePositivo("Ingrese la altura orbital en m (>= 0): ", 0.0);
    nave->velocidadInicial = leerDoublePositivo("Ingrese la velocidad inicial en m/s (>= 0): ", 0.0);
    
    printf("\n[Configuracion guardada exitosamente en el sistema!]\n\n");
}

double fuerzaGravitatoria(double m, double h) {
    double DT = RT + h;
    return (G * MT * m) / (DT * DT);
}

double aceleracionGravitatoria(double m, double h) {
    double Fg = fuerzaGravitatoria(m, h);
    return Fg / m;
}

double energiaCinetica(double m, double v) {
    return (m*v*v)/2;
}

double posicionEquilibrio(double d) {
    return d/(1+sqrt(ML/MT));
}

double UgTotal(double m, double r1, double r2) {
    double UT, UL;
    UT = -(G*MT*m)/r1;
    UL = -(G*ML*m)/r2;
    return UT + UL;
}

double Wext(double Ki, double Kf, double Ui, double Uf) {
    return Kf - Ki + Uf - Ui;
}
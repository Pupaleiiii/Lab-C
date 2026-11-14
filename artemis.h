#ifndef ARTEMIS_H
#define ARTEMIS_H

//Constantes físicas
#define G 6.67430e-11 // Constante de gravitación universal
#define MT 5.972e24 //Masa de la Tierra (kg)
#define ML 7.348e22 //Masa de la Luna (kg)
#define RT 6371000.0 //Radio de la Tierra (m)
#define D 384000000.0 //Distancia Tierra-Luna (m)

typedef struct {
    double masa;
    double alturaOrbital;
    double velocidadInicial;
} NaveOrion;

void configurarNave(NaveOrion *nave);
double fuerzaGravitatoria(double m, double h);
double aceleracionGravitatoria(double m, double h);

double energiaCinetica(double m, double v);
double posicionEquilibrio(double d);
double UgTotal(double m, double r1, double r2);
double Wext(double Ki, double Kf, double Ui, double Uf);

#endif
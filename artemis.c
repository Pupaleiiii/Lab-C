#include <math.h>
#include "artemis.h"

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
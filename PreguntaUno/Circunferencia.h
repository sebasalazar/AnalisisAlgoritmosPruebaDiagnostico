#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iostream>


#define LARGO 3

class Circunferencia {
public:
    Circunferencia();
    Circunferencia(std::string orig);
    Circunferencia(const Circunferencia& orig);
    virtual ~Circunferencia();
    double GetX() const;
    void SetX(double x);
    double GetY() const;
    void SetY(double y);
    double GetR() const;
    void SetR(double r);
    bool seIntersecta(Circunferencia circulo);
    bool esValido() const;
private:
    double x;
    double y;
    double r;
};

#endif /* CIRCUNFERENCIA_H */


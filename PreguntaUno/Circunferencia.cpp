#include "Circunferencia.h"

Circunferencia::Circunferencia() {
    this->x = 0.0;
    this->y = 0.0;
    this->r = 0.0;
}

Circunferencia::Circunferencia(std::string orig) {
    try {
        // [2,3,4]
        this->x = 0.0;
        this->y = 0.0;
        this->r = 0.0;

        std::string linea(orig.c_str());
        if (!linea.empty()) {
            /**
             * 
             * Eliminar caracteres innecesarios del enunciado
             */
            linea.erase(std::remove(linea.begin(), linea.end(), '['), linea.end());
            // 2,3,4]
            linea.erase(std::remove(linea.begin(), linea.end(), ']'), linea.end());
            // 2,3,4

            // Obtenemos un token
            std::replace(linea.begin(), linea.end(), ',', ' ');
            // 2 3 4

            std::vector<std::string> arreglo;
            std::stringstream ss(linea);
            std::string temp;

            while (ss >> temp) {
                arreglo.push_back(temp);
            }

            this->x = atof(arreglo[0].c_str());
            this->y = atof(arreglo[1].c_str());
            this->r = atof(arreglo[2].c_str());
        }


    } catch (...) {
        this->x = 0.0;
        this->y = 0.0;
        this->r = 0.0;
    }
}

Circunferencia::Circunferencia(const Circunferencia& orig) {
    if (orig.esValido()) {
        this->x = orig.GetX();
        this->y = orig.GetY();
        this->r = orig.GetR();
    } else {
        this->x = 0.0;
        this->y = 0.0;
        this->r = 0.0;
    }
}

Circunferencia::~Circunferencia() {
}

double Circunferencia::GetX() const {
    return x;
}

void Circunferencia::SetX(double x) {
    this->x = x;
}

double Circunferencia::GetY() const {
    return y;
}

void Circunferencia::SetY(double y) {
    this->y = y;
}

double Circunferencia::GetR() const {
    return r;
}

void Circunferencia::SetR(double r) {
    this->r = r;
}

bool Circunferencia::seIntersecta(Circunferencia circulo) {
    bool ok = false;
    try {

        if (this->esValido() && circulo.esValido()) {
            double dx, dy, d;

            /**
             * 
             * dx y dy son las distancias verticales y horizontales entre los centros de los circulos.
             */
            dx = (double) (circulo.GetX() - this->GetX());
            dy = (double) (circulo.GetY() - this->GetY());

            /**
             * La distancia en linea recta
             */
            d = sqrt((dy * dy) + (dx * dx));

            /**
             * Comprobación de solvencia
             */
            if (d > (this->GetR() + circulo.GetR())) {
                ok = false;
            } else if (d < fabs(this->GetR() - circulo.GetR())) {
                ok = false;
            } else {
                ok = true;
            }
        }

    } catch (...) {
        ok = false;
    }
    return ok;
}

bool Circunferencia::esValido() const {
    return (r > 0.0);
}
#include <iostream>
#include <vector>
using namespace std;

// Componente
class Figura {
public:
    int x , y;
    virtual void dibujar() = 0;
};

// Hoja
class Circulo : public Figura {
public:
    void dibujar() override {
        cout << "Dibujando un circulo en el punto: " << "(" << x << " , " << y << ")" << endl;
    }
};

// Hoja
class Rectangulo : public Figura {
public:
    void dibujar() override {
        cout << "Dibujando un rectangulo en el punto: " << "(" << x << " , " << y << ")" << endl;
    }
};

// Composite
class Pantalla : public Figura {
private:
    vector<Figura*> figuras;

public:
    int width, length;
    void agregarFigura(Figura* figura) {
        figuras.push_back(figura);
    }

    void dibujar() override {
        cout << "Dibujando una ventana de " << "ancho: " << width << " y " << "largo: " << length << endl;
        for (Figura* figura : figuras) {
            figura->dibujar();
        }
    }
};

int main() {

    Circulo c1;
    c1.x = 54;
    c1.y = 76;

    Rectangulo r1;
    r1.x = 45;
    r1.y = 65;

    Pantalla grupo;
    grupo.length = 400;
    grupo.width = 200;

    grupo.agregarFigura(& c1);
    grupo.agregarFigura(& r1);

    grupo.dibujar();

    return 0;
}
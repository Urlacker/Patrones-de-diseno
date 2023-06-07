#include <iostream>

using namespace std;
// Interfaz existente
class InterfazExistente {
public:
    virtual void metodoExistente() const {
        cout << "Método existente" << std::endl;
    }
};

// Interfaz objetivo
class InterfazObjetivo {
public:
    virtual void metodoObjetivo() const = 0;
};

// Adaptador
class Adaptador : public InterfazObjetivo {
private:
    InterfazExistente* objetoExistente;
    

public:
    Adaptador(InterfazExistente* objeto) : objetoExistente(objeto) {}

    void metodoObjetivo() const override {
        cout << "Llamando al método objetivo" << std::endl;
        objetoExistente->metodoExistente();
    }
};

// Cliente
void Cliente(InterfazObjetivo* objetivo) {
    objetivo->metodoObjetivo();
}

int main() {
    InterfazExistente* objetoExistente = new InterfazExistente();
    InterfazObjetivo* adaptador = new Adaptador(objetoExistente);

    Cliente(adaptador);

    delete adaptador;
    delete objetoExistente;

    return 0;
}

/*En este ejemplo, tenemos una interfaz existente llamada InterfazExistente, que define un método
 metodoExistente(). Luego, tenemos la interfaz objetivo InterfazObjetivo, que define un método 
 metodoObjetivo(). El adaptador Adaptador implementa la interfaz objetivo y utiliza el objeto de la 
 interfaz existente para adaptar sus métodos. El cliente Cliente utiliza el adaptador para llamar al 
 método objetivo.
*/
#include <iostream>

// Implementador: Clase base para la implementación de gráficos
class GraphicsRenderer {
public:
    virtual void render() = 0;
};

// Implementación concreta de gráficos: DirectX
class DirectXRenderer : public GraphicsRenderer {
public:
    void render() override {
        std::cout << "Renderizando con DirectX." << std::endl;
    }
};

// Implementación concreta de gráficos: OpenGL
class OpenGLRenderer : public GraphicsRenderer {
public:
    void render() override {
        std::cout << "Renderizando con OpenGL." << std::endl;
    }
};

// Abstracción: Clase base para las entidades del juego
class GameObject {
protected:
    GraphicsRenderer* renderer;

public:
    virtual void draw() = 0;
    void setRenderer(GraphicsRenderer* renderer) {
        this->renderer = renderer;
    }
};

// Entidad concreta: Jugador
class Player : public GameObject {
public:
    void draw() override {
        std::cout << "Dibujando jugador " << std::endl;
        renderer->render();
    }
};

int main() {
    // Crear objeto de implementación
    GraphicsRenderer* renderer = new DirectXRenderer();

    // Crear objeto de entidad del juego
    GameObject* player = new Player();
    player->setRenderer(renderer);

    // Dibujar la entidad
    player->draw();

    // Liberar memoria
    delete renderer;
    delete player;

    return 0;
}

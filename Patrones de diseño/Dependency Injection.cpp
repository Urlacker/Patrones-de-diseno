#include <iostream>
#include <fstream>

// Clase que depende del logger
class UserManager {
private:
    Logger& logger;

public:
    UserManager(Logger& logger) : logger(logger) {}

    void createUser(const std::string& username) {
        // Lógica para crear un nuevo usuario
        logger.log("Se creó un nuevo usuario: " + username);
    }
};
// Interfaz del logger
class Logger {
public:
    virtual void log(const std::string& message) = 0;
};

// Implementación concreta del logger
class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "Inicio de sesion: " << message << std::endl;
        // Lógica de registro en la consola
    }
};

// Implementación alternativa del logger para registrar en un archivo
class FileLogger : public Logger {
private:
    std::ofstream file;

public:
    FileLogger(const std::string& filename) {
        file.open(filename);
    }

    void log(const std::string& message) override {
        file << "Inicio de sesion " << message << std::endl;
        // Lógica de registro en un archivo
    }
};

int main() {
    // Utilizando la implementación de ConsoleLogger
    ConsoleLogger consoleLogger;
    UserManager userManager1(consoleLogger);

    userManager1.createUser("Juan");

    // Si se desea cambiar a la implementación de FileLogger sin modificar el código de UserManager,
    // se puede crear una nueva instancia de UserManager utilizando la implementación de FileLogger.

    FileLogger fileLogger("registro.txt");
    UserManager userManager2(fileLogger);

    userManager2.createUser("Pablo");

    return 0;
}

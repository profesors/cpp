#include <string>
#include "Persona.h"

using namespace std;

Persona::Persona(const char* nombre, int edad){	
	this->nombre = std::string(nombre);
	this->edad = edad;
}

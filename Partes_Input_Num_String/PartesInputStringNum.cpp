#include <iostream>
#include <string>
//#include <limits>

bool filtrado(std::string);
bool buscaSPZ(std::string tira);

int main() {

	std::string ok{};
	std::string cadena{};
	do{
		std::cout << "\t Entre cadena convertible a numerica : ";
		std::getline(std::cin, cadena, '\n');
		unsigned short cs = cadena.size();
		std::cout << "\n\n\t la cadena recibida es : " << cadena << \
			" que ahora veremos si pasa los filtros." << std::endl;
		std::string plural = cs > 1 ? "es" : "";
		std::cout << "\t La cadena tiene " << cs << " caracter" << plural << "\n";
		ok = filtrado(cadena) ? "" : "NO";
		std::cout << "\t y " << ok << " ha pasado el filtrado" << std::endl;
	} while (ok == "NO");
	std::cout << " Pulsar s o S para salir del programa ";
	do {
		std::cin >> ok;
	} while (!(ok == "s" || ok == "S"));
	

	return 19671111;

}

bool filtrado(std::string chain) {
	// de entrada va a devolver true si es una cadena con algun caracter
	if (chain.empty()) {
		// std::cout << "\n\t La cadena introducida no tiene ningun signo ni punto ni digito" << std::endl;
		return false;
	}

	else  if (buscaSPZ(chain))
		return true;
	
	else
		return false;
}


bool buscaSPZ(std::string tira){
	unsigned short sidt = (unsigned short)tira.size();

	unsigned short* mitiraS = new unsigned short[sidt];
	unsigned short* mitiraP = new unsigned short[sidt];
	unsigned short* mitiraZ = new unsigned short[sidt];
	
	bool mas = false;
	bool menos = false;
	bool signo = false;
	bool punto = false;
	bool zero = false;
	bool mal = false;

	for (unsigned short i = 0; i < sidt; i++) {
		mitiraS[i] = 0xFFFF;
		mitiraP[i] = 0xFFFF;
		mitiraZ[i] = 0xFFFF;
	}

	for (unsigned short i = 0; i < sidt; i++)
	{
		if (tira[i] == '+'){ 
			mitiraS[i] = i;
			mas = true;
			signo = true;
			continue;
		}
			
		if (tira[i] == '-') {
			mitiraS[i] = i;
			menos = true;
			signo = true;
			continue;
		}
			
		if (tira[i] == '.') {
			mitiraP[i] = i;
			punto = true;
			continue;
		}
			
		if (tira[i] == '0') {
			mitiraZ[i] = i;
			zero = true;
			continue;
		}
		
		if (tira[i] <= '9' && tira[i] >= 0)
			continue;
		else {
			mal = true;
			break;
		}
			
	}

	/*
	for (unsigned short i = 0; i < sidt; i++) {
		std::cout.width(8);
		std::cout << "\n mitira[";
		std::cout.width(2); 
		std::cout.fill('0');
		std::cout << i << "]";
		std::cout.fill(' ');
		std::cout.width(8); 
		std::cout << mitiraS[i];
		std::cout.width(8); 
		std::cout << mitiraP[i];
		std::cout.width(8);
		std::cout << mitiraZ[i] ;
		std::cout.width(3);
		std::cout << tira[i];
	}
	*/
	if (mas + menos > 1)  // hay mas de un signo
		mal = true;

	if (signo == 1 && mitiraS[0] != 0) // el signo debe ser el primer elemento   posicion 0
		mal = true;

	unsigned short cuentapuntos = 0;
	for (unsigned short i = 0; i < sidt; i++) {
		if (mitiraP[i] != 0xFFFF)
			cuentapuntos++;
	}
	if (cuentapuntos > 1)	// solo puede haber un punto decimal
		mal = true;

	if (mitiraZ[0] == 0 && mitiraP[1] != 1)		// si empieza por 0 debe seguir el punto decimal
		mal = true;		// este seria un corregible eliminando el 0 excesivo en posicion 0
	if (signo == 1 && mitiraZ[1] == 1 && mitiraP[2] != 2)	// si empieza por signo y sigue con 0 pero no sigue punto 
		mal = true;		// este seria un corregible eliminando el 0 excesivo en posicion 1
	
	/*
	std::cout << "\n\n\tmas = " << mas \
		<< "    menos = " << menos \
		<< "    signo = " << signo \
		<< "    punto = " << punto \
		<< "    zero = " << zero \
		<< "    mal = " << mal \
		<< std::endl;
	*/
	delete[]mitiraS;
	delete[]mitiraP;
	delete[]mitiraZ;

	return !(mal);
	}
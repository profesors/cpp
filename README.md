# cpp

This is just a set of test to learn programming C++

# Arrays de punteros como parámetros de una función
	Carga* v[SIZE];		// Array de punteros
	getE(*v, SIZE);		// Llamada a la función pasando el puntero al primer elemento
 
	// Se usa el vector como si fuera local
	double CampoElectrico::getE(... Carga v[], int size){
		for (int i=0; i<size; i++){
			cout<<v[i].carga<<endl;
		}
	}

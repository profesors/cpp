#include <CampoElectrico.h>
#include <iostream>

using namespace std;
using namespace CampoElectrico;

const int NCARGAS = 3;

int main(){
	//std::unique_ptr<Carga> q1(new Carga(0,4,1e-9));
	Carga* q[NCARGAS];

	q[0] = new Carga(0,4,1);
	q[1] = new Carga(3,0,2);
	q[2] = new Carga(0,0,3);

	getE(2, 2, *q, NCARGAS);

	return 0;
}

#include <CampoElectrico.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

#include <boost/algorithm/string.hpp>

using namespace std;
using namespace CampoElectrico;

const int NCARGAS = 3;


int main(){
	//std::unique_ptr<Carga> q1(new Carga(0,4,1e-9));

	ifstream fCargas;
	fCargas.open("cargas.txt", ifstream::in);

	int i = 0;
	string sLine;
	CampoElectrico::Vector2d E={0, 0};
	while(getline(fCargas, sLine)){
		vector<string> arrLine;
	    split(arrLine, sLine, boost::is_any_of(" "));	// [0] carga.x	[1]	carga.y	[2] carga.q
		CampoElectrico::Vector2d E_i = getE(0, 0, stof(arrLine[0]), stof(arrLine[1]), stol(arrLine[2]));
		E.x += E_i.x;
		E.y += E_i.y;
	}

	fCargas.close();

	cout<<E.x<<"i "<<E.y<<"j "<<endl;

	return 0;
}

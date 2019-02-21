#include <CampoElectrico.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
using namespace CampoElectrico;

int main(){
	ifstream fCargas("cargas.txt");
	CampoElectrico::Vector2d E={0, 0};
	float x,y;
	double q;
	while(fCargas>>x>>y>>q){
		CampoElectrico::Vector2d E_i = getE(0, 0, x, y, q);
		E.x += E_i.x;
		E.y += E_i.y;
	}
	fCargas.close();
	cout<<E.x<<"i "<<E.y<<"j "<<endl;
	return 0;
}

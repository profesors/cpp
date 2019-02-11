#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

bool esPrimo(int);
int cotaSuperior=100;
 

int main(void){
	ofstream fPrimes;
	fPrimes.open("primos.txt");
	cout<<"Cota superior: ";
	cin>>cotaSuperior;

	int percent = 0;
	for (int n=1; n<=cotaSuperior; n++){
		if (esPrimo(n)){
			//cout<<setw(2)<<(int)(n*100.0/cotaSuperior)<<"% "<<n<<endl;
			int percentTmp = (int)(n*100.0/cotaSuperior);
			if (percentTmp!=percent){
				percent = percentTmp;
				cout<<setw(2)<<percent<<"%"<<endl;
			}
			fPrimes<<n<<endl;
		}
	}
	fPrimes.close();
	return 0;
}

bool esPrimo(int n){
	switch(n){
		case 1:	return true;	break;
		case 2: return true;	break;
		case 3: return true;	break;
		default:
			if (n%2==0)	{	// Es un número par
				return false;
			} else {		// Es un número impar
				for (int i=3; i*i<=n; i+=2){
					if (n%i==0){	// Es primo pq es divisible entre i
						return false;
						break;
					}
				}
			}
	}
	return true;
}

#include <iostream>

using namespace std;

const int MAX = 3;

struct Vector{
	int sz;
	double* elem;
};

void vector_init(Vector& v, int s){
	v.sz = s;
	v.elem = new double[s];
}

int main(void) {
	Vector v;
	vector_init(v, MAX);
	cout<<v.sz<<endl;
	
	for (int i=0; i<MAX; i++){
		cin>>v.elem[i];
	}
	
	for( int i=0; i<MAX; i++){
		cout<<v.elem[i];
	}
	cout<<endl;
    return(0);
}

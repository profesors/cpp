#ifndef _LOAD_TOOL
#define _LOAD_TOOL

#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// Solo si el carácter es un separador devuelve true
bool inline is_a_separator(char const c)
{
    switch (c) {
        case ' ':
            return true;
        case '\t':
            return true;
        default:
            return false;
    }
    return false;
}

bool inline is_a_comment(char const *c){
	char const *c2 = c;
	cout<<(c==c2)<<endl;
	return true;
}

// Devuelve un vector de strings, donde cada elemento es una palabra de la línea
vector<string> split_line(string const sLine)
{
    vector<string> vLine;
    int i{0};
    while (i < sLine.size()) {
        string sWord;
        while (is_a_separator(sLine[i])) // Salta espacios al principio de línea
            ++i;

		if (sLine[i]=='#'){	// Lo que queda de línea es un comentario. Termina bucle y función
			break;
		} else {			// Lo que queda de línea es una palabra
			while (i < sLine.size() && !is_a_separator(sLine[i])) {
				sWord += sLine[i++];
			}
			vLine.push_back(sWord);
		}
    }
    return vLine;
}

// Devuelve la estructura vector<vector<string>> sin líneas en blanco
vector<vector<string>> remove_null(vector<vector<string>> vLines){
	// @TODO implementar la eliminación de líneas en blanco
}

// Vector de vector<string>, cada item es un vector que contiene items que son
// a su vez palabras
vector<vector<string>> split_file(string const file_name)
{
    ifstream finput(file_name);
    vector<vector<string>> vLines; // Vector de vector<string>
    string sLine;
    while (getline(finput, sLine)) { vLines.push_back(split_line(sLine)); }	
    return vLines;
}
#endif

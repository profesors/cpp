#include "load_tool.cc"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace load_tool;

int main()
{
    vector<vector<string>> vLines = split_file("datos.txt");
    for (vector<string> vLine : vLines) {
        for (string sWord : vLine) { cout << sWord << " "; }
        // cout << endl;
    }
}

#include <iostream>
#include <string>
#include <fstream>
#include "hello.h"
using namespace std;



int main(int argc, char** argv){
		ifstream file(argv[1]);
		string str;
		cout << "start reading " << argv[1] << endl;
		getline(file,str);
		while( file.good() ){
				cout << "\t" << str << endl;
				getline(file,str);
		}
		cout << "end reading" << endl;
		//abort();
		return 0;
}



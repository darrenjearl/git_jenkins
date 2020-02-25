#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
using namespace std;

int main(int argc, char** argv){
		cout << "hello world" << endl;
		if( argc == 2 && strcmp( argv[1], "fail" ) == 0 ){
				assert(0);
		}
		return 0;
}

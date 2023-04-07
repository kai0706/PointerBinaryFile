#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	const float pi = 3.141592;
	char header[12];
	int* n;
	n = (int*)header;
	*n = 500;
	float* f;
	f = (float*)(header + 4);
	*f = 1000;
	short* a;
	a = (short*)(header + 8);
	*a = 1000;
	short* p;
	p = (short*)(header + 10);
	*p = 12;
	short* data1;
	data1 = new short[*n];
	short* data2;
	data2 = new short[*n];

	float dt = 1. / f[0] / 20.0;
	for (int i = 0; i < n[0]; i++) {
		data1[i] = (short)(a[0] * sin(2.0 * pi * f[0] * i * dt));
	}
	ofstream xx("a.dat", ios::binary | ios::out);
	if (!xx) return 666;
	xx.write(header, 12 * sizeof(char));
	xx.write((char*)data1, n[0] * sizeof(short));
	xx.close();

	*f = 700;
	for (int i = 0; i < n[0]; i++) {
		data2[i] = (short)(a[0] * sin(2.0 * pi * f[0] * i * dt));
	}

	ofstream yy("b.dat", ios::binary | ios::out);
	if (!yy) return 666;
	yy.write(header, 12 * sizeof(char));
	yy.write((char*)data2, n[0] * sizeof(short));
	yy.close();


	
	ofstream zz("c.txt");
	if (!zz) return 666;
	for (int i = 0; i < n[0]; i++) {
		zz << i * dt << " " << data1[i] << " "<<data2[i]<<endl;
	}
	zz.close();


	ifstream ww("a.dat", ios::binary | ios::in);
	if (!zz) return 666;
	ww.read((char*)header, 12 * sizeof(char));
	ww.close();

}

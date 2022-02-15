#include <iostream>
#include <fstream>
#include <math.h>

double f(double x){
	return exp(-x*x);
}

int main(){
	std::ofstream *File;

	File = new std::ofstream[2];

	File[0].open("Data/DerivadaCentral.txt",std::ofstream::trunc );


	std::cout << File << std::endl;
	
	double Func[4000];
	
	double X =0;

	double h = 1.0/100.0;

	int ind =0;

	for(int i = -2000; i < 2000; i++){
		
		ind = i+2000;

		X = i/100.0;
		Func[ind] = f(X);

	}
	
	for(int i = -1999; i < 1999;i++){
		X = i/100.0;
		ind = i+2000;


		File[0] << X << " " << (Func[ind+1]-Func[ind-1])/(2*h) << std::endl;
	}



	File[0].close();

	return 0;
}

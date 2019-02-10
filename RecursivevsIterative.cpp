#include <iostream> 
#include <fstream> 
#include <chrono>
#include <algorithm> 

using namespace std;
using namespace std::chrono;

double iterativePower(double base, int exponent);
double recursivePower(double base, int exponent);

int main(int argc, char* argv[]) {
	

	std::ofstream myfile;
	myfile.open("example.csv");
	myfile << "n,Iterative,Recursive" << endl;
	for (int i = 0; i < 4310; i++) {
		auto start = high_resolution_clock::now();
		iterativePower(3.14159265359, i);
		auto stop = high_resolution_clock::now();

		auto duration = duration_cast<nanoseconds>(stop - start);

		auto start1 = high_resolution_clock::now();
		recursivePower(3.14159265359, i);
		auto stop1 = high_resolution_clock::now();

		auto duration1 = duration_cast<nanoseconds>(stop1 - start1);

		myfile << i << "," << duration.count() <<","<< duration1.count() << endl;
		

	}

	

		



	return 0;

}




double iterativePower(double base, int exponent) {
	double retVal = 1.0;
	if (exponent < 0) {
		return 1.0 / iterativePower(base, -exponent);
	}
	else {
		for (int i = 0; i<exponent; i++)
			retVal *= base;
	}
	return retVal;
}

double recursivePower(double base, int exponent) {
	if (exponent < 0) {
		return 1.0 / recursivePower(base, -exponent);
	}
	else if (exponent == 0) {
		return 1.0;
	}
	else {
		return base * recursivePower(base, exponent - 1);
	}
}
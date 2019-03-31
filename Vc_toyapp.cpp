// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<chrono>
#include<vector>
#include<Vc/global.h>
#include<Vc/array>
#include<Vc/support.h>
#include<Vc/vector.h>

int main()
{
	std::vector<Vc::float_v> a(10000000, 3.2);
	std::vector<Vc::float_v> b(10000000, 2.8);
	std::vector<Vc::float_v> c;
	auto begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < a.size(); i++) {
		c.push_back(a[i] + b[i]);
	}
	auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<std::endl; 

	std::vector<float> e(10000000, 3.2);
	std::vector<float> f(10000000, 2.8);
	std::vector<float> g;

	auto begin_ = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 1; i++) {
		g.push_back(e[i] + f[i]);
	}
	auto end_ = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end_ - begin_).count() << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

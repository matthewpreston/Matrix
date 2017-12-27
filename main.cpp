#include <iostream>
#include <fstream>
#include <exception>
#include "matrix.hpp"

int main(int argc, char *argv[]){
	std::ifstream sourcefile;			//reads matrix
	std::ofstream outputfile;			//prints matrix

	switch (argc){
	case 2:
		sourcefile.open(argv[1], std::ios::in);
		outputfile.open("output.txt", std::ios::out);
		break;
	case 3:
		sourcefile.open(argv[1], std::ios::in);
		outputfile.open(argv[2], std::ios::out);
		break;
	default:
		std::cerr << "Usage MatrixTest.exe input.txt [output.txt]\n";
		return 1;
	};

	if (sourcefile.fail()){
		std::cerr << "Cannot open: " << argv[1] << std::endl;
		return 1;
	}

	if (outputfile.fail()){
		std::cerr << "Cannot open: ";
		std::cerr << (argc == 3) ? argv[2] : "output.txt";
		std::cerr << std::endl;
		return 1;
	}

	try{
		Matrix m(sourcefile), n = m;
		m.PrintMatrix(outputfile);
		n.RREF();
		n.PrintMatrix(outputfile, "Row Reduced:");
		m.PrintFourSubsets(outputfile);
	}catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}catch (...){
		std::cerr << "Unknown exception occurred\n";
	}

	sourcefile.close();
	outputfile.close();
	return 0;
}
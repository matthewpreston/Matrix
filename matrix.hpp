#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "fraction.hpp"

typedef std::vector<Fraction> VectorType;
typedef std::vector<VectorType> MatrixType;
typedef std::list<VectorType> BasisType;

struct FourSubsets {
	enum {Null, Row, Col, LeftNull};
	static const char *titles[4];
	BasisType Space[4];
};

class Matrix {
public:
	Matrix();
	//Constructor accepting vector of vectors to represent matrix
	Matrix(MatrixType m);
	//Initialization constructor accepting an array of an array of Fractions
	Matrix(Fraction **f, size_t rows, size_t cols);
	//Initialization constructor that reads matrix from file
	Matrix(std::istream &is, const bool header=false);
	//Destructor that does nothing
	~Matrix();
	
	//Mutator Methods--------------------------------------------------------------
	//Pops a vector off the right side (returns empty vector if empty)
	const VectorType PopRightVector();
	//Pushes a vector onto the right side (returns false if improper row size)
	const bool PushRightVector(const VectorType &v);
	//Pops a vector off the bottom side (returns empty vector if empty)
	const VectorType PopBottomVector();
	//Pushes a vector onto the right side (returns false if improper row size)
	const bool PushBottomVector(const VectorType &v);
	//Pushes a matrix onto the right side (returns false if improper row size)
	const bool PushRightMatrix(const Matrix &m);
	const bool PushRightMatrix(const MatrixType &m);
	//Gauss-Jordan elimination aka row reduced echelon form, returns reduced matrix
	const MatrixType RREF();
	//Transposes matrix
	const MatrixType Transpose();
	
	//Accessor Methods-------------------------------------------------------------
	//Returns the number of rows in the matrix
	const unsigned int GetRowNumber() const;
	//Returns the number of cols in the matrix
	const unsigned int GetColNumber() const;
	//Returns a list of pivot columns
	const std::list<unsigned int> GetPivotCols() const;
	//Returns matrix
	const MatrixType GetMatrix() const;
	//Returns matrix from (r1, c1) to (r2, c2) if params are in range
	//i.e. 1 <= r1 < r2 <= rows , 1 <= c1 < c2 <= cols
	const MatrixType GetMatrix(unsigned int r1, unsigned int c1,
							   unsigned int r2, unsigned int c2) const;
	//Returns null space in a list
	const BasisType GetNullSpace() const;
	//Returns row space in a list
	const BasisType GetRowSpace() const;
	//Returns column space in a list
	const BasisType GetColumnSpace() const;
	//Returns left null space in a list
	const BasisType GetLeftNullSpace() const;
	//Returns four subsets in an array of lists
	const FourSubsets GetFourSubsets() const;
	
	//Output Methods---------------------------------------------------------------
	//Prints matrix to file (default is stdout)
	void PrintMatrix(std::ostream &os=std::cout, const char *title="") const;
	//Prints null space to file (default is stdout)
	void PrintNullSpace(std::ostream &os=std::cout,
		const char *title=FourSubsets::titles[FourSubsets::Null]) const;
	//Prints row space to file (default is stdout)
	void PrintRowSpace(std::ostream &os=std::cout,
		const char *title=FourSubsets::titles[FourSubsets::Row]) const;
	//Prints column space to file (default is stdout)
	void PrintColumnSpace(std::ostream &os=std::cout,
		const char *title=FourSubsets::titles[FourSubsets::Col]) const;
	//Prints left null space to file (default is stdout)
	void PrintLeftNullSpace(std::ostream &os=std::cout,
		const char *title=FourSubsets::titles[FourSubsets::LeftNull]) const;
	//Prints four subsets to file (default is stdout)
	void PrintFourSubsets(std::ostream &os=std::cout,
		const char **titles=FourSubsets::titles) const;
	
	//Mathematical operators-------------------------------------------------------
	const VectorType operator [] (unsigned int row) const;

protected:
	//Swaps rows a and b
	void row_swap(unsigned int a, unsigned int b);
	//Creates a leading one at col and scales the rest of the entries of that row
	void create_leading_one(unsigned int row, unsigned int col);
	//Creates a pivot column at col, while keeping the leading one at row
	void create_pivot_col(unsigned int row, unsigned int col);
	//Finds pivot columns from a row reduced matrix
	const std::list<unsigned int> find_pivot_cols(const MatrixType &m) const;
	//Instantiates null space
	const BasisType find_null_space(const MatrixType &m,
									const unsigned int v_size) const;
	const BasisType find_row_space(const MatrixType &m,
								   const unsigned int v_size) const;
	const FourSubsets find_four_subsets() const;
	//Prints a basis to file (default is stdout)
	void print_basis(const BasisType b, std::ostream &os,
					 const char *title) const;
					 
private:
	MatrixType matrix;
};

//Useful Functions-------------------------------------------------------------
//Creates a zero vector of size n
const VectorType CreateZeroVector(const unsigned int n);
//Creates an identity matrix of size n
const MatrixType CreateIdentityMatrix(const unsigned int n);

#endif
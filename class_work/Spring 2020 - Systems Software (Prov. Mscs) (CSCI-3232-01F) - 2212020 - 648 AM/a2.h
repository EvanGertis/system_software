//Note: this program needs three files: main2.cpp, a2.cpp, a2.h
class matrix {
	int p;//default access is private
	int q;//p and q are dimensions of matrices
	int **A;//matrix of p by q
	int **B;//matrix of q by p
	int **AB;//matrix of p by p (=A*B)
	int **BA;//matrix of q by q (=B*A)
	void printMatrix(int **m, int a, int b);
public:
	matrix(int a, int b);//constructor
	void generateMatrix();
	void computeProducts();
	void printallmatrices();
	~matrix();//destructor
};
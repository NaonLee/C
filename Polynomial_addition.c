#inclue <studio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {
	int degree;					//Degree of polynomial
	float coef[MAX_DEGREE];		//Coefficient of polynomial
}polynomial;

polynomial addPoly(polynomial A, polynomial B) {

	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {				
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index];
			A_degree--;
		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;			//return a result
}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++)
		printf("%3.0fx^%d", P.coef[i], degree--);
	printf("\n");
}

void main() {
	polynomial A = { 5, {4,3,5,4,1,1} };					//declare polynomial
	polynomial B = { 2, {3,3,2} };

	polynomial C = addPoly(A, B);

	printf("\n A(x) = ");
	printPoly(A);
	printf("\n B(x) = ");
	printPoly(A);
	printf("\n A(x) + B(x) = C(x) = ");
	printPoly(C);

	getchar();
}
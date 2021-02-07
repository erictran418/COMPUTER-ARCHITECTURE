/*
 *
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the
 * weight of different features.
 *
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)
 *
 * weight(w) = pseudoInv(X) * Y
 * 			where	X = Input data matrix
 * 					Y = Target vector
 *
 */

#include<stdio.h>
#include<stdlib.h>

#include <string.h>
#include <ctype.h>

// all methods declarations
double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat, int row, int col);
double** inverseMatrix(double **matA, int dimension);

void freeMatrix(double **matA, int row) {

for(int i = 0; i < row; i++) {
	free(matA[i]);
}
free(matA);
}


// main method starts here
int main(int argc, char** argv){

	//train
	FILE *fp1;
	  fp1 = fopen(argv[1], "r");

	//test
	FILE *fp2;
		fp2 = fopen(argv[2], "r");

		//Gets the sizes of the matrix and values of rows and collumns
		char buffer1[900];
		char buffer2[900];
		int c1 = 0;
		int c2 = 0;
		int r1 = 0;
		int r2 = 0;
		char ch = ',';

		fseek(fp1, 0L, SEEK_END);
		rewind(fp1);
		fgets(buffer1, sizeof(buffer1),fp1);
		if(strlen(buffer1) < 10) {
			while(strlen(buffer1) < 10) {
				fgets(buffer1, sizeof(buffer1), fp1);
			}
		}
		for(int t = 0; t<strlen(buffer1); t++) {
			if(buffer1[t] == ch) {
				c1++;
			}
		}
		rewind(fp1);


		fseek(fp2, 0L, SEEK_END);
		rewind(fp2);
		fgets(buffer2, sizeof(buffer2),fp2);
		if(strlen(buffer2) < 10) {
			while(strlen(buffer2) < 10) {
				fgets(buffer2, sizeof(buffer2), fp2);
			}
		}
		for(int t = 0; t<strlen(buffer2); t++) {
			if(buffer2[t] == ch) {
				c2++;
			}
		}
		rewind(fp2);



char buff_1[900];
while(fgets(buff_1, sizeof(buff_1),fp1)) {
if(strlen(buff_1) > 10) {
	r1++;
}
}


char buff_2[900];
while(fgets(buff_2, sizeof(buff_2),fp2)) {
if(strlen(buff_2) > 10) {
	r2++;
}
}

rewind(fp1);
rewind(fp2);
//
c1 = c1+1;
c2 = c2+2;

double **train = malloc(sizeof(double)*r1);

for(int i = 0; i < r1; i++) {
	train[i] = malloc(sizeof(double)*c1);
}

double **test = malloc(sizeof(double)*r2);
for(int i = 0; i < r2; i++) {
	test[i] = malloc(sizeof(double)*c2);
}



for(int i = 0; i < r1; i++) {
	train[i][0] = 1;
}

for(int i = 0; i < r2; i++) {
	test[i][0] = 1;
}


char work[500] = "";

int tr1 = 0;
int tc1 = 1;

double **yprice = malloc(sizeof(double)*r1);
for(int i = 0; i <r1; i++) {
	yprice[i] = malloc(r1*sizeof(double));
}


while(fgets(buff_1, sizeof(buff_1),fp1)) {

if(strlen(buff_1) > 10) {
	tc1 = 1;

	for(int i = 0; i < strlen(buff_1); i++) {

		if(isdigit(buff_1[i]) || buff_1[i] == '.') {
			strncat(work, &buff_1[i] , 1);

		}
		if(buff_1[i] == ',') {
			train[tr1][tc1] = atof(work);;
			tc1++;
			strcpy(work, "");
		}
	}
	yprice[tr1][0] = atof(work);;
	strcpy(work, "");
	tr1++;
}
}

char work2[500] = "";

int tr2 = 0;
int tc2 = 1;

while(fgets(buff_2, sizeof(buff_2),fp2)) {

if(strlen(buff_2) > 10) {
	tc2 = 1;

	for(int i = 0; i < strlen(buff_2); i++) {

		if(isdigit(buff_2[i]) || buff_2[i] == '.') {
			strncat(work2, &buff_2[i] , 1);
		}
		if(buff_2[i] == ',') {
			test[tr2][tc2] = atof(work2);;
			tc2++;
			strcpy(work2, "");
		}
	}
	test[tr2][tc2] = atof(work2);
	tr2++;
	strcpy(work2, "");
}

}



fclose(fp1);
fclose(fp2);
/*

for(int i = 0; i < r1; i++) {

	for(int j = 0; j < c1; j++) {
		printf("%lf\t", train[i][j]);
	}
	printf("\n");
}
*/
/*
printf("\n");

for(int i = 0; i < r2; i++) {

	for(int j = 0; j < c2; j++) {
		printf("%lf\t", test[i][j]);
	}
	printf("\n");
}
*/
/*
printf("\n");

printf("r1:%d  c1:%d\n", r1, c1);
printf("r2:%d  c2:%d\n", r2, c2);
printf("yr: %d\n", yr);
*/
int Trow = c1;
int Tcol = r1;
int yr = r1;
int ycol = 1;

double **trainTranspose = transposeMatrix(train, r1, c1);
double **tranXtrain = multiplyMatrix(trainTranspose, train, Trow, Tcol, r1, c1);
/*
printf("\n");
for (int i = 0; i < Trow; i++) {
	for(int j = 0; j <c1; j++) {
		printf("%lf\t", tranXtrain[i][j]);
	}
	printf("\n");
}
printf("\n");
*/
int txtRow = Trow;
double **tranXy = multiplyMatrix(trainTranspose, yprice, Trow, Tcol, yr, ycol);
double **productinverse = inverseMatrix(tranXtrain,Trow);
double **weightresult = multiplyMatrix(productinverse, tranXy, Trow, Trow, Trow, ycol);
double **finalproduct = multiplyMatrix(test, weightresult, r2, c2, Trow, ycol);


/*
printf("\n");
for(int i = 0; i < r2; i++) {
	printf("%lf\n",finalproduct[i][0]);
}


printf("\n");
for(int i = 0; i < Trow; i++) {
	printf("%lf\n",weightresult[i][0]);
}

for(int i = 0; i < yr; i++) {
	printf("%lf\n", yprice[i][0]);
}


printf("\n");

for(int i = 0; i<Trow; i++) {
	for(int j = 0; j < Trow; j++) {
		printf("%lf\t", productinverse[i][j]);
	}
	printf("\n");
}

printf("\n");

for(int i = 0; i < c1; i++) {
	for(int j = 0; j < r1; j++) {
		printf("%lf\t", trainTranspose[i][j]);
	}
	printf("\n");
}
printf("This is tranXy\n");

for(int i = 0; i< 5; i++) {
	printf("%lf\n", tranXy[i][0]);
}


printf("\n");

printf("r1:%d  c1:%d\n", r1, c1);
printf("Trow:%d  Tcol:%d\n", Trow, Tcol);
printf("yr:%d ycol:%d \n", yr, ycol);
printf("txtRow:%d  txtCol:%d\n", txtRow, txtCol);
*/
for(int i = 0; i < r2; i++) {
	printf("%0.0lf\n",finalproduct[i][0]);
}


freeMatrix(train, r1);
freeMatrix(test, r2);
freeMatrix(trainTranspose, Trow);
freeMatrix(tranXtrain, txtRow);
freeMatrix(yprice, yr);
freeMatrix(tranXy, Trow);
freeMatrix(productinverse, Trow);
freeMatrix(weightresult, Trow);
freeMatrix(finalproduct, r2);


	return 0;
}

double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2)
{
    double** result=malloc(r1*sizeof(double*));
		for(int i = 0; i<r1; i++) {
			result[i] = malloc(c2*sizeof(double*));
		}

    // your code goes here
		int rowcount = 0;
		double sum = 0;

		if(c2 == 1) {
			while(rowcount < r1) {
				sum = 0;
					for(int j = 0; j < r2; j++) {
						sum += matA[rowcount][j]*matB[j][0];
				}
				result[rowcount][0] = sum;
				rowcount++;
			}
			return result;
		}

		while(rowcount < r1){
		for(int i = 0; i < c2; i++) {
			sum = 0;
			for(int j = 0; j < c1; j++) {
				sum += matA[rowcount][j]*matB[j][i];
			}
			result[rowcount][i] = sum;
		}
		rowcount++;
	}



    return result;
}


double** transposeMatrix(double** mat, int row, int col)
{

	double** matTran=malloc(col*sizeof(double*));

    // your code goes here
		for(int i = 0; i < col; i++) {
			matTran[i] = malloc(row*sizeof(double));
		}

		int collumncount= 0;
		while(collumncount < col) {
			for(int i= 0; i < row; i++) {
				matTran[collumncount][i] =  mat[i][collumncount];
			}

			collumncount++;
		}
    return matTran;
}


double** inverseMatrix(double **matA, int dimension)
{

    double** matI=malloc(dimension*sizeof(double*));
		for(int i = 0; i < dimension; i++) {
			matI[i] = malloc(dimension*sizeof(double*));
		}

    // your code goes here

		for(int i= 0; i<dimension; i++) {
			for(int j = 0; j<dimension; j++) {
				matI[i][j] = 0;
			}
		}
		int versework = 0;
		while(versework < dimension) {
			matI[versework][versework] = 1;
			versework++;
		}

		for(int p = 0; p<dimension;p++) {
			double f = matA[p][p];

			for(int x =0; x<dimension; x++) {
				matA[p][x] = matA[p][x]/f;
				matI[p][x] = matI[p][x]/f;


			}
			for(int i = p+1; i<dimension; i++) {
				double z = matA[i][p];

				for(int x = 0; x<dimension; x++) {
					matA[i][x] = matA[i][x] - (matA[p][x]*z);
					matI[i][x] = matI[i][x] - (matI[p][x]*z);
				}

			}
		}

		for(int p = dimension-1; p>=0; p--) {
			for(int i = p-1; i>=0;i--) {
				double f = matA[i][p];
				for(int x = 0; x<dimension; x++) {
					matA[i][x] = matA[i][x] - (matA[p][x]*f);
					matI[i][x] = matI[i][x] - (matI[p][x]*f);
				}


			}
		}




	return matI;

}

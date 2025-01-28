#include <stdio.h>
#include <math.h>

int main() {
	system("chcp 1253");//to support Greek charachters
	
	int a, b;//Declaration of integer variables
	
	/*
		Selection of integers by the user
	*/
	printf("\nChoose the first integer: ");
	scanf("%d", &a);
	printf("\nChoose the second integer: ");
	scanf("%d", &b);
	
	
	printf("\nα)");
	printf("\n\tsum: %d+%d=%d", a, b, a+b);//sum
	printf("\n\tsub: %d-%d=%d", a, b, a-b);//sub
	printf("\n\tproduct %d*%d=%d", a, b, a*b);//product
	printf("\n\tquotient: %d/%d=%d and modulo %d", a, b, a/b, a%b);//quotient and modulo
	
	
	printf("\n\nβ)");
	printf("\n\tReal numbers quotient: %d/%d=%f", a, b, (float) a/b);//real quotient
	
	
	printf("\n\n)");
	printf("\n\tThe square of a: %d^2=%d", a, a*a);//square of the first integer
	printf("\n\tThe root of %d is %f", b, sqrt((double)b));//square of the second integer
	
	return 0;
}

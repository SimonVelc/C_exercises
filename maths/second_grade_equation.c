#include <stdio.h>
#include <math.h>

int main() {
	
	system("chcp 1253");
	
	float root1, root2, D, a, b, c;//Declaration of Root, Discriminant and variables a, b and c
	
	printf("\nChoose the a: ");
	scanf("%f", &a);
	printf("\nChoose the b: ");
	scanf("%f", &b);
	printf("\nChoose the c: ");
	scanf("%f", &c);
	
	
	if(a==0 && b==0){
		printf("\nNo such function is defined");
	} 
	else if(a==0){
		printf("\n%fx + %f = 0<=> \nx=%f", b, c, (-c)/b);
	}
	else{
		D=b*b-4*a*c;
		printf("\n\nΔ=%f^2 - 4*%f*%f<=> \nΔ=%f\n\n", b, a, c, D);
		
		if(D>0) {
			printf("\nΔ>0");
			root1=(-b+sqrt(D))/a;
			root2=(-b-sqrt(D))/a;
			printf("\nWe have root x1=%f and root x2=%f", root1, root2);
		}
		else if(D==0) {
			printf("\nΔ=0");
			root1=-b/a;
			printf("\nWe have a unique root x=%f", root1);
		}
		else {
			printf("\nΔ<0");
			printf("\nThe equation has no roots");
		}
	}	
	
	return 0;
}

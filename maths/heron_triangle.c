#include <stdio.h>

int main() {
	
	system("chcp 1253");
	
	int a, b, c;
	
	printf("\nChoose the first side of the triangle: ");
	scanf("%d", &a);
	printf("\nChoose the second side of the triangle: ");
	scanf("%d", &b);
	printf("\nChoose the third side of the triangle: ");
	scanf("%d", &c);
	
	float s= (float)(a+b+c)/2;
	
	//Heron formula
	printf("\n\nWe have triangle area: %sq.m.", sqrt((double)s*(s-a)*(s-b)*(s-c)));
}

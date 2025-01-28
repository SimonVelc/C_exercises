#include <stdio.h>

#define p 3.14

int main() {
	system("chcp 1253");
	
	float side=3.0;
	
	/*
		CUBE
	*/
	
	printf("\n\nA cube with side %fm has, \nArea: %sq.m. \nVolume: %sq.m.", side, 6*side*side, side*side*side);
	
	/*
		Sphere
	*/
	
	printf("\n\nA sphere with radius %fμ has, \nArea: %fsq.m. \nVolume: %fc.m.", side, 4*p*side*side,  4/3*p*side*side*side);
	
	return 0;
}

#include <stdio.h>

int main() {
	int N, even, i=0, cnt=0;//N is the number of integer scales we want to insert, even is the even we insert, j is the iteration structure, cnt is the counter of the numbers we will insert
	int sum_of_mod3=0, cnt_for_mod3=0;//the sum of the numbers of multiples of 3, counter for the number of numbers multiplied by 3

	int product_of_mod4=1;//initialize the product for numbers multiplied by 4
	int product_of_negatives=1;//initialization of the product for negative numbers
	
	system("chcp 1253");
	
	printf("Choose number of integers: ");
	scanf("%d", &N);
	
	printf("\n\nFor repetition structure do while\n==========================\n\n");
	
	
	do{
		printf("%d even number: ",i+1);
		scanf("%d", &even);
		
		cnt++;//increases each time we enter a number
		
		//condition that terminates while if we do not enter an even number
		if(!(even%2==0)){
			break;
		}
		//condition for the calculation of the average of the poles of 3
		if(even%2==0 && even%3==0){
			sum_of_mod3+=even;
			cnt_for_mod3++;
		}
		//condition for calculating the product of the poles of 4
		if(even%2==0 && even%4==0){
			product_of_mod4*=even;
		}
		//condition for calculating the product of negative numbers
		if(even%2==0 && even<0){
			product_of_negatives*=even;
		}
		
		i++;
	}while(i<N);
	
	//Print Results
	printf("\n\n%d numbers were given.", cnt);
	
	if(cnt_for_mod3>0)
		printf("\n\nAverage of multiples of 3: %f", (float) sum_of_mod3/cnt_for_mod3);
	
	if(product_of_mod4>1)
		printf("\n\nProduct of multiples of 4: %d", product_of_mod4);
		
	if(product_of_negatives!=1)
		printf("\n\nProduct of negative numbers: %d", product_of_negatives);	
		
		
	return 0;
	
}

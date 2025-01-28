#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592
#define break_point 0.00006

void menu();
float sin_fun(float degree);
float cos_fun(float degree);
float power_fun(int base, int power);
int combinations(int N, int K);
float average(int N);

int main() {
	system("chcp 1253");
	
	menu();
	

	return 0;
}

void menu(){
	int choice;//for switch
	float angle;// for the angles
	int base, power;//for power calculation
	int N, K;//to calculate combinations
	int lastN;//for 5th case
	do
	{
	 system("cls");
	 printf("Menu\n\n");
	 printf("1. Semitone calculation\n");
	 printf("2. Cosine calculation\n");
	 printf("3. Power calculation\n");
	 printf("4. Calculation of the number of combinations of N elements per K\n");
	 printf("5. Introduce N integers and calculate their average.\n");
	 printf("0. Exit\n");
	 printf("\nSelect mode: ");
	 scanf("%d",&choice);
	 //getchar();
	   
	 switch (choice)
	 {
	    case 1:
	    	system("cls");
	    	printf("\nChoose how many degrees you want your angle: ");
			scanf("%f", &angle);//enter degrees
			printf("\nsin(%f)=%f\n\n", angle, sin_fun(angle)); 
			system("pause");
	      	break;
		case 2: 
			system("cls");
			printf("Choose how many degrees you want your angle: \n");
			scanf("%f", &angle);//enter degrees
	  		printf("\ncos(%f)=%f\n\n", angle, cos_fun(angle));
	  		system("pause");
	        break;
	    case 3:		 
	    	system("cls");
	    	printf("\nChoose base: ");
			scanf("%d", &base);
			printf("\nChoose an exhibitor: ");
			scanf("%d", &power);
	    	printf("\n%d ^ %d = %.f\n\n", base, power, power_fun(base, power));
	    	system("pause");
	        break;
	    case 4:
	    	printf("\nSelection of N elements: ");
			scanf("%d", &N);
			printf("\nChoice of number K: ");
			scanf("%d", &K);
			printf("\n %d! / (%d-%d)!%d! = %d combinations\n\n", N, N, K, K, combinations(N, K));
	    	system("pause");
	    	break;  
		case 5:
			printf("\nΔιάλεξε αριθμό ακεραίων: ");
			scanf("%d", &lastN);
			printf("\nAverage: %.2f\n", average(lastN));
				
			system("pause");
			break;                 
	 } 
	  
	} while (choice!=0);
}

float sin_fun(float degree){
	
	float rad;
	float sin, prevSin;
	float breaker, iSin=1.0;
			
	rad = degree * (PI / 180);//degrees to rad conversion
	
	
	while(rad<0.0 || rad>2.0*PI){
		printf("\nYour number is not accepted.Choose an angle in rad: \n");
		scanf("%f", &rad);
	}
	
	sin=rad;
	
	do{
		prevSin = sin;
		
		//printf("\nsin(%f)=(%f^%.f)/%.f!", rad, rad, iSin, iSin);
		sin+=((rad*PI)*(rad*PI))/iSin;
		
		//printf("\nsin=%f", sin);
		
		breaker=sin-prevSin;
		//printf("\nbreaker: %f\n", breaker);
		iSin+=2.0;
	}while(breaker>break_point);
	
	//printf("\nsin=%f\n\n", sin);
	
	return sin; 
	
}

float cos_fun(float degree){
	float rad;
	float  cos, prevCos;
	float breaker, iCos=2.0;
	
	
	
	rad = degree * (PI / 180);//degrees to rad conversion
	
	
	
	while(rad<0.0 || rad>2.0*PI){
		printf("\nYour number is not accepted.Choose an angle in rad: \n");
		scanf("%f", &rad);
	}
	
	cos=1 + (rad * rad)/iCos;
	//printf("cos(%f)=1+(%f^%.1f)/!", rad, rad, iCos, iCos);
	
	do{
		prevCos = cos;
		
		cos+=((rad*PI)*(rad*PI))/iCos;
		//printf("\ncos(%f)=(%f^%.f)/%.f!", rad, rad, iCos, iCos);
		
		//printf("\ncos=%f", cos);
		
		breaker=cos-prevCos;
		//printf("\nbreaker: %f\n", breaker);
		iCos+=2.0;
	}while(breaker>break_point);
	
	//printf("\ncos=%f\n\n", cos);
	
	return cos;

}

float power_fun(int base, int power){
	
	if(power==0){
		return 1.0;
	}
	
	int i;
	float result;
	
	result=base;
			
	for(i=1; i<power; i++){
		result*=base;
	}
	
	return (float)result;

}

int combinations(int N, int K){
	int i, cntN=1, cntK=1, cntN_K=1;
	
	
	for(i=1; i<=N; i++){
		cntN*=i;
	}
	for(i=1; i<=N-K; i++){
		cntN_K*=i;
	}
	for(i=1; i<=K; i++){
		cntK*=i;
	}
	
	return cntN/((cntN_K)*cntK);
}
float average(int N){
	int sum=0, input, i;
	float avg;
	
	FILE *fp = fopen("sample.txt", "w");
	
	for(i=0; i<N; i++){
		printf("\nChoose the %do number: ", i+1);
		scanf("%d", &input);
		sum+=input;
		
		fprintf(fp, "%d\n", input);//to pass the integers to txt
	}
	fclose(fp);
	
	avg = (float)sum/N;// for the average
	
	return avg;
}


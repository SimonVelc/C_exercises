#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getRows(FILE *fp_pointer);
char **allocate(int size, FILE *fp_pointer);
void getWords(FILE *fp_pointer, char **text, int size);
void calcLetterFreq(char **text, int size, int *letterFreq);
void sort(int *pointOfFreq, char *pointOfAb, int size);
void print_int(int x);

int main(int argc, char *argv[]){
	FILE *fp;
	char c;//to read from txt
	char ch='A';//to initialize the alphabet table
	int line_cnt;
	int i, j;
	char *alphabet;//alphabet table
	char **dic;//table string
	int *freq;//table for the frequency of occurrence of letters
	int ab=26;//Latin alphabet
	int top=5;
	//incorrect number of parameters
	if (argc != 2) {
        printf("Invalid number of parameters", argv[0]);
        exit(1);
    }
    
    //open txt for reading
    fp = fopen(argv[1], "r");
	if(fp==NULL){
		printf("Cannot read input file");
		exit(0);
	}

	line_cnt = getRows(fp);//we find how many lines we will need to bind
	
	//printf("\ngrammes: %d", line_cnt);
	
	/*
		allocate memory for rows and columns
	*/
	dic = allocate(line_cnt, fp);
	
	getWords(fp, dic, line_cnt);
	
	/*
	//dictionary table
	for (i = 0; i < line_cnt; i++) {
        fscanf(fp, "%s", dic[i]);
        printf("\nWord %d: %s", i + 1, dic[i]);
    }
	*/
	/*
		allocate memory and initializing the table for the letter appearances
	*/
	freq = (int *)malloc(ab*sizeof(int));
	if(!freq){
		printf("Memory Problem");
		exit(0);
	}
	
	for(i=0; i<ab; i++){
		freq[i]=0;
	}
	/*
		allocate memory and initializing the table with the characters of the alphabet
	*/
	alphabet = (char *)malloc(ab*sizeof(char));
	if(!alphabet){
		printf("Memory Problem");
		exit(0);
	}
	
	for(i=0; i<ab; i++){
		alphabet[i]=ch;
		//printf("\n%c", alphabet[i]);
		ch++;
	}
	
	calcLetterFreq(dic, line_cnt, freq);
	/*
	for(i=0; i<ab; i++){
		printf("\n%c:%d", alphabet[i], freq[i]);
	}
	*/
	//printf("\n\nSORT\n\n");
	sort(freq, alphabet, ab);
	
	/*
		Print the letters with frequency
	*/
	for(i=0; i<top; i++){
		printf("%c:", alphabet[i]);
		print_int(freq[i]);
		printf("\n");
	}
	/*
		Combinations of letters per 2
	*/
	for(i=0; i<top; i++){
		for(j=i+1; j<top; j++){
			printf("%c%c\n", alphabet[i], alphabet[j]);
		}
	}
	
	fclose(fp);
	
	for(i=0; i<line_cnt; i++){
		free(dic[i]);
	}
	free(dic);
	free(freq);
	free(alphabet);
	return 0;
}

int getRows(FILE *fp_pointer){
	
	int cnt=0;
	char c;
	while((c=fgetc(fp_pointer))!=EOF){
		//printf("%c", c);
		
		/*
			check for the character to be uppercase Latin
		*/
		if((c!='\n') && (c<'A' || c>'Z')){
				printf("Invalid Data in Line ");
				print_int(cnt + 1);
				exit(0);		
		}
		
		if(c=='\n'){
			cnt++;		
		}
		
	}
	
	rewind(fp_pointer);//return the cursor to the beginning of the file
	
	return cnt;
}
char **allocate(int size, FILE *fp_pointer){
	char **p;
	char c;
	int i;
	int cnt=0;
	
	p = (char **)malloc(size*(sizeof(char *)));

	for(i=0; i<size; i++){
		cnt=0;
		while((c=fgetc(fp_pointer))!=EOF && c!='\n'){
			cnt++;		
		}
		p[i]=(char *)malloc((cnt+1)*sizeof(char));
			if(!p[i]){
				printf("Memory Problem");
				exit(0);
			}
		//printf("\nAdded %d cols", cnt+1);		
	}
	
	rewind(fp_pointer);
	
	return p;
}
void getWords(FILE *fp_pointer, char **text, int size) {
	int i;
    for (i = 0; i < size; i++) {
        fscanf(fp_pointer, "%s", text[i]);
        //printf("\nWord %d: %s", i + 1, dic[i]);
    }
    
    rewind(fp_pointer);
}
void calcLetterFreq(char **text, int size, int *letterFreq){
	int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; text[i][j] != '\0'; j++) {
            letterFreq[text[i][j] - 'A']++;
            // printf("\n%c:%d", text[i][j], letterFreq[text[i][j] - 'A']);
        }
    }
}
void sort(int *pointOfFreq, char *pointOfAb, int size) {
    int tmp;
    char tmpChar;
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (pointOfFreq[i] < pointOfFreq[j]) {
                tmp = pointOfFreq[i];
                pointOfFreq[i] = pointOfFreq[j];
                pointOfFreq[j] = tmp;

                tmpChar = pointOfAb[i];
                pointOfAb[i] = pointOfAb[j];
                pointOfAb[j] = tmpChar;
            }
        }
    }
}
void print_int(int x){
	if(x<10){
		printf("000000%d", x);
	}
	else if(x>9 && x<100){
		printf("00000%d", x);
	}
	else if(x>99 && x<1000){
		printf("0000%d", x);
	}
	else if(x>999 && x<10000){
		printf("000%d", x);
	}
	else if(x>9999 && x<100000){
		printf("00%d", x);
	}
	else if(x>99999 && x<1000000){
		printf("0%d", x);
	}
	else{
		printf("%d", x);
	}
}

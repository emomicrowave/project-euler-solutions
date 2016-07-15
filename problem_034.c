// Digit factorials
// --------------------------------------
// https://projecteuler.net/problem=34  |
// --------------------------------------
// Solution by Emil Milanov

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LIMIT 1500000	// how many numbers to iterate through
#define LIMIT_SIZE 8	// how many digits does the max number have
#define ENABLE_DEBUG 0	// set to 1 to display information for every number

int fak(int n);
int* digits(int n);
int arraylen(int *arr);
int digits_factorial(int *arr, int number_len);
int len_number(int n);



int main(){
    printf("Program start\n");
	int endsum = 0;
    clock_t begin = clock();

    for (int i = 1; i < LIMIT; i++){
        if(ENABLE_DEBUG){printf("------\nLooping number: %d --||--", i);}
		
        if (i == digits_factorial(digits(i), len_number(i))){
            printf("%d is equal the sum of the factorial of its digits! \n", i);
            endsum += i;
        }
    }

	printf("\n---------\n End sum: %d \n ---------\n", endsum);

    clock_t end = clock();
    double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Time spent: %f ms\n", time_spent);

    return EXIT_SUCCESS;}

// fak(n) = n! = n*n-1*n-2* ... * 2*1
int fak(int n){
    
    if (n < 0){
        fprintf(stderr, "Error, argument less than zero. \n");
        return EXIT_FAILURE;
    }
    else if (n==0){return 1;}
    else{
        int result = 1;

        while (n >= 1){
            result = result*n;
            n--;
        }

        return result;
    }
}

// return an array of single digits of a number
int* digits(int n){

    static int digits[LIMIT_SIZE - 1];
	int counter = 0;
	int digit;

    // get the single digits
    while (n > 0){
        digit = n % 10;
        digits[counter] = digit;

        if(ENABLE_DEBUG){printf("%d=%d, ", counter, digit);}

        counter ++;
        n = div(n,10).quot;
	}

    return digits;
}

// get a pointer of int array and calculate the factorial of its digits
int digits_factorial(int* arr, int number_len){

    int result = 0;

    for (int i = 0; i < number_len; i++){
        result += fak(*(arr+i));
    }

    if(ENABLE_DEBUG){printf(" factorial of digits = %d\n", result);}

    return result;
}

// get the number of digits of an int
int len_number(int n){
	int proof; 

	// start with 10^LIMIT_SIZE and divide by 10 each iteration
	// to find how big the number is
	for(int i = LIMIT_SIZE; i >= 0; i--){
		proof = (int) pow(10, (double) i);

		if (n % proof != n){
		    if (ENABLE_DEBUG){printf("Number length: %d, proof: %d;", i, proof);}
            return i+1;
		}		

	}
	fprintf(stderr, "Unable to calculate length of %d. Aborting...\n", n);
	return EXIT_FAILURE;
}

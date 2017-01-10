#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "ArrayTools.h"


void printInt(int array[], int size);
void printdouble(double array[], int size);

//Main prototypes
double arrayAverage(double array[], int arraySize);
double arrayVariance(double array[], int arraySize);

int main(void){
	double* dataArray;
	int* dataArrayInt;
	
	int* size = (int*)malloc(sizeof(int));

	node_t* head = getNums();

	printf("Printing list...\n\n");
	printNums(head);

	printf("Converting list to array...");
	dataArray = listToArr(head, size);
	printf("Done\n\n");

	printf("Printing double array...\n");
	printdouble(dataArray, *size);

	printf("Converting double array to ints...");
	dataArrayInt = arrDoubleToInt(dataArray, *size);
	printf("Done\n\n");

	printf("Printing int array...\n");
	printInt(dataArrayInt, *size);


	double average = arrayAverage(dataArray, *size);
	printf("Average is %f\n", average);
	double variance = arrayVariance(dataArray, *size);
	printf("Variance is %f\n", variance);
	system("PAUSE");
	return 0;
}

void printInt(int array[], int size){
	printf("{ ");
	for (int i = 0; i < size; i++){
		printf("%d, ", array[i]);
	}
	printf("}\n");
}
void printdouble(double array[], int size){
	printf("{ ");
	for (int i = 0; i < size; i++){
		printf("%.2f, ", array[i]);
	}
	printf("}\n");
}


double arrayAverage(double array[], int arraySize){
	double total = 0;
	for (int i = 0; i < arraySize; i++){
		total += array[i];
	}
	return (total / arraySize);
}

double arrayVariance(double array[], int arraySize){
	double average = arrayAverage(array, arraySize);
	double total = 0;
	for (int i = 0; i < arraySize; i++){
		total += (array[i] - average)*(array[i] - average);
	}
	return (total / (arraySize - 1));

}

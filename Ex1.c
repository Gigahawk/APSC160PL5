#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Linked List stuff
typedef struct node{
	double data;
	struct node* next;
}node_t;

node_t* getNums();
void printNums(node_t* head);
double* listToArr(node_t* head, int* size);

//Main prototypes
double arrayAverage(double array[], int arraySize);
double arrayVariance(double array[], int arraySize);

int main(void){
	double* dataArray = (double*)malloc(sizeof(double));
	int* size = (int*)malloc(sizeof(int));
	node_t* head = getNums();
	printNums(head);
	dataArray = listToArr(head, size);
	double average = arrayAverage(dataArray, *size);
	printf("Average is %f\n", average);
	double variance = arrayVariance(dataArray, *size);
	printf("Variance is %f\n", variance);
	system("PAUSE");
	return 0;
}

node_t* getNums(void){
	double d;
	node_t* head = NULL;
	node_t* temp = NULL;
	do{
		printf("Please enter a number to add to the list: ");
		scanf("%lf", &d);
		if (head == NULL){
			head = (node_t*)malloc(sizeof(node_t));
			head->data = d;
			head->next = NULL;
			temp = head;
		}
		else{
			temp->next = (node_t*)malloc(sizeof(node_t));
			temp = temp->next;
			temp->data = d;
			temp->next = NULL;
		}
		
		fputc(EOF, stdin);
		printf("Press Enter to continue or Ctrl+Z and Enter to end.\n");
	}while(fgetc(stdin) != EOF);
	return head;
}

void printNums(node_t* head){
	printf("Printing Numbers...\n");
	while (head != NULL){
		printf("%f\n", head->data);
		head = head->next;
	}
	return;
}

double* listToArr(node_t* head, int* size){
	double* output;
	node_t* root = head; //list needs to be traversed twice, so the head pointer is cloned
	int count = 0;
	*size = 0;
	
	//Ideally you would only traverse the list once, but I can't think of a better way of getting the size to initialize the array
	while (head != NULL){
		(*size)++;
		head = head->next;
	}
	
	//Create array after getting its size
	output = (double*)malloc(*size * sizeof(double));
	
	//traverse list and put values into array
	while (root != NULL && count < *size){
		output[count] = root->data;
		root = root->next;
		count++;
	}
	return output;
}

double arrayAverage(double array[], int arraySize){
	double total = 0;
	for(int i = 0; i < arraySize; i++){
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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayTools.h"

int isZero(char* input){
	int i = 0;
	int check = 0;
	do{
		if ((!isdigit(input[i])) && input[i] != '.' && input[i] != '-'){
			if (input[i] != '\n')
				check = 1;
			break;
		}
		i++;
	} while (input[i] != NULL);
	return check;
}

node_t* getNums(void){
	double d;
	char* input = (char*)malloc(100 * sizeof(char));
	node_t* head = NULL;
	node_t* temp = NULL;

	printf("Please enter a number to add to the list or Ctrl+Z to end: ");
	while (fgets(input, 100, stdin) != NULL){

		if (isZero(input) != 0){
			printf("I didn't understand that input, please try again: ");
			continue;
		}
		d = atof(input);
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

		//fputc(EOF, stdin);
		//printf("Press Enter to continue or Ctrl+Z and Enter to end.\n");
		printf("Please enter a number to add to the list or Ctrl+Z to end: ");
	}
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

int* listToArrInt(node_t* head, int* size){
	int* output;
	node_t* root = head; //list needs to be traversed twice, so the head pointer is cloned
	int count = 0;
	*size = 0;

	//Ideally you would only traverse the list once, but I can't think of a better way of getting the size to initialize the array
	while (head != NULL){
		(*size)++;
		head = head->next;
	}

	//Create array after getting its size
	output = (int*)malloc(*size * sizeof(double));

	//traverse list and put values into array
	while (root != NULL && count < *size){
		output[count] = (int)(root->data);
		root = root->next;
		count++;
	}
	return output;
}

int* arrDoubleToInt(double array[], int size){
	int* arr = (int*)malloc(size*sizeof(int));
	while (size > 0){
		size--;
		arr[size] = (int)array[size];
	}
	return arr;
}

double* arrIntToDouble(int array[], int size){
	double* arr = (double*)malloc(size*sizeof(double));
	while (size > 0){
		size--;
		arr[size] = (double)array[size];
	}
	return arr;
}

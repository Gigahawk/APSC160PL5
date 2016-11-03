#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H

//New data type containing a double and a pointer
typedef struct node{
	double data;
	struct node* next;
}node_t;

/*
 * Repeatedly asks user to input numbers, non-number entries will be rejected
 * A linked list is generated in the order of the input.
 * NOTE: By default each input is limited to 100 characters
 */
node_t* getNums(void);

/*
 * Takes the first pointer for a linked list and prints out the data at each node 
 */
void printNums(node_t* head);

/*
 * Purpose:		Takes the first pointer for a linked list and converts every node to an entry in an array
 *				of size equal to the number of entries. 
 * Parameters:	The first pointer to a linked list, a pointer to store the size of the generated array
 * Returns:		An array of doubles
 */
double* listToArr(node_t* head, int* size);
//Does the same thing, but casts all values to int and returns an array of ints
int* listToArrInt(node_t* head, int* size);

//converts arrays to different types
int* arrDoubleToInt(double array[], int size);
double* arrIntToDouble(int array[], int size);

#endif //ARRAYTOOLS_H

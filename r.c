/*
* File: rotate.c
* Author: Suhani Surana
* Purpose: This program rotates N numbers in a vector
* by some number
*/

#include <stdio.h>
#include <stdlib.h>

/* rotateArray -- This places the elements in the correct position
* in a new array after the number of moves specified by the user
*/
void rotateArray(int *A, int *B, int size, int moves) {
    moves = moves % size;
    if (moves < 0) {
        moves += size; 
    }

    for (int i = 0; i < size; i++) {
        B[i] = A[(i - moves + size) % size];
    }
}

int main() {
    int size;
    int retval = scanf("%d", &size);

    if (retval != 1 || size <= 0) {
        fprintf(stderr, "Error: The first integer value is not positive or cannot be read.\n");
        return 1;
    }

    int *A = calloc(size, sizeof(int));
    if (A == NULL) {
        fprintf(stderr, "Error: Out of Memory\n");
        return 1;
    }

    int flag = 0;
    for (int i = 0; i < size; i++) {
        int number;
        retval = scanf("%d", &number);

        if (retval != 1) 
        {
            fprintf(stderr, "Error: Invalid integer literal or fewer integers available than specified.\n");
            return(1);
            
        } 
        else 
        {
            A[i] = number;
        }
    }
    if (!flag) {
        int move;
        retval = scanf("%d", &move);
        if (retval != 1) {
            fprintf(stderr, "Error: Invalid integer literal for moves.\n");
            return 1;
        }

       
        int *B = calloc(size, sizeof(int));
        if (B == NULL) {
            fprintf(stderr, "Error: Out of Memory\n");
            return 1;
        }

        rotateArray(A, B, size, move);

        for (int i = 0; i < size; i++) {
            A[i] = B[i];
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");

       
        
    }

    return 0;
}

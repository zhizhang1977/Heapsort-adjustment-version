#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void HeapAdjust(int* arr, int n)  //Adjust an array of length n to a small top heap
{
       int loc = 0;  //Used to locate child nodes
       int temp = 0;
       int i = n / 2 -1;

       if(n % 2 == 0) {   //Judge whether the last non-leaf node has only left children             
              loc = n - 1;  //The variable loc points to the left child node of the last non-leaf node
              if(arr[loc] < arr[i]) { //If the left child node is less than the value of the parent node, exchange the child node and the parent node
                            temp = arr[loc];
                            arr[loc] = arr[i];
                            arr[i] = temp;
               }  


               
              for(i = n / 2 - 2; i >= 0; i--) { //Adjust from the penultimate non-leaf node to the root node
                     loc = 2 * i + 1;  //The variable loc points to the left child node
                     if(arr[loc] > arr[loc+1]) {
                            loc++;  //The variable loc is the position of the minimum child node
                     }
              
                     if(arr[loc] < arr[i]) { //If the minimum child node is less than the value of the parent node, exchange the child node and the parent node
                            temp = arr[loc];
                            arr[loc] = arr[i];
                            arr[i] = temp;
                     }
              }           
       }
       else{
              for(i = n / 2 - 1; i >= 0; i--) { //Adjust from the last non-leaf node to the root node
                     loc = 2 * i + 1;  //The variable loc points to the left child node
              

                     if(arr[loc] > arr[loc+1]) {
                            loc++;  //The variable loc is the position of the minimum child node
                     }

                     if(arr[loc] < arr[i]) { //If the minimum child node is less than the value of the parent node, exchange the child node and the parent node
                            temp = arr[loc];
                            arr[loc] = arr[i];
                            arr[i] = temp;
                     }
              }
       
       }
}

void HeapSort_Adj(int* arr, int len)  //Sort the array arr with length n in the adjusted ascending heapsort
{
       for(int i = len; i > 1; i--) {  //Adjust the reciprocal sequence (len: 2) elements into small top heap	
               HeapAdjust(arr + len - i, i);
       }
}

int main()
{
       int n = 10;
       int arr[10] = {};

       srand((unsigned)time(NULL));

       for(int i = 0; i < n; i++)
              arr[i] = rand() % 1000;  //Using 10 random numbers to construct the sequence to be sorted
       
       printf("Before sorting: ");


       for(int i = 0; i < n; i++) {
              printf("%d ", arr[i]);
       }

       printf("\n");
   

       HeapSort_Adj(arr, n);  //Adjust version heap sorting


       printf("After sorting: ");


       for(int i = 0; i < n; i++) {
             printf("%d ", arr[i]);
       }

       return 0;
}
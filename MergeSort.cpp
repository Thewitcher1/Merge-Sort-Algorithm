//#include <stdio.h>
#include<iostream>
using namespace std;

void mergeIt(int arr[], int l, int m, int r) {
    int i,j,k;
    int leftArraySize = m - l +1, rightArraySize = r - m;
    int Left[leftArraySize], Right[rightArraySize];

    for(i=0; i<leftArraySize; i++) Left[i] = arr[l+i];
    for(j=0; j<rightArraySize; j++) Right[j]= arr[m+1+j];
    i=j=0; k=l;

    while(i< leftArraySize && j< rightArraySize) {

        if (Left[i]<=Right[j]){arr[k] = Left[i]; i++;}
        else                  {arr[k] = Right[j]; j++;}
        k++;
    }
    while(i<leftArraySize){arr[k] = Left[i]; i++; k++;}
    while(j<rightArraySize){arr[k] = Right[j]; j++; k++;}

}

void breakIt(int arr[], int l, int r) {
    if(l==r) 
       return;
    int m = l+(r-l)/2;
    breakIt(arr,l,m);
    breakIt(arr, m+1,r);
    mergeIt(arr,l,m,r);
}

void mergesort(int arr[], int l, int r) {
    breakIt(arr,l,r);
}

int main() {

    int Arr[]= {10, 9, 8, 7 ,6 ,5 ,4 ,3 ,2 ,1};
    int n = sizeof(Arr)/sizeof(Arr[0]);
    mergesort(Arr,0,n-1);
    for(int i=0; i<n;++i){
        cout << Arr[i] << " ";
    }
      
        return 0;

}
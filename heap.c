#include<stdio.h>
void heapify(int heap[], int size , int current){
    int largest=current;
    int leftchild=2*current+1;
    int rightchild=2*current+2;
    if(leftchild<size){
        if(heap[leftchild]>heap[largest]){
            largest=leftchild;
        }
    }
    if(rightchild<size){
        if(heap[rightchild]>heap[largest]){
            largest=rightchild;
        }
    }
    if(largest!=current){
        int temp=heap[current];
        heap[current]=heap[largest];
        heap[largest]=temp;

        heapify(heap, size, largest);
    }
}
void heapsort(int heap[], int size){
    for(int parent=size/2-1; parent>=0; parent--){
        heapify(heap, size, parent);
    }
    for(int le= size-1; le>0; le--){
        int temp=heap[0];
        heap[0]=heap[le];
        heap[le]= temp;

        heapify(heap,le, 0);
    }
}
int main(){
    int size;
    int heap[100];
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter numbers: ");
    for(int i=0; i<size; i++){
        scanf("%d", &heap[i]);
    }
    heapsort(heap, size);
    printf("Numbers in ascending Order: ");
    for(int i=0; i<size; i++){
        printf("%d\n", heap[i]);
    }
    return 0;
}
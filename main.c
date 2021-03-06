#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAXSIZE 100000

void Swap(int *a,int *b)
{
    int Temp = *a;
    *a=*b;
    *b=Temp;
}
void Flip(int array[],int size)
{
    int i,Temp;
    for(i=0; i<=size/2; i++)
    {
        Swap(&array[i],&array[size-1-i]);
    }
}
void PrintArray(int array[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t\t",array[i]);
    }
    printf("\n");
}
double BubbleSort(int array[],int size)
{
    clock_t start,end;
    start=clock();

    int i,j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(array[j]>array[j+1])
            {
                Swap(&array[j],&array[j+1]);
            }
        }
    }
    end=clock();
    double funcTime=  ((double) (end-start))/CLOCKS_PER_SEC;
    return funcTime;
}
double SelectionSort(int array[],int size)
{
    clock_t start,end;
    start=clock();

    int min_index,i,j;
    for(i=0; i<size; i++)
    {
        min_index=i;
        if(i==size-1)
            break;
        else
        {
            for(j=i+1; j<size; j++)
            {
                if(array[min_index]>array[j])
                {
                    min_index=j;
                }
            }
            Swap(&array[i],&array[min_index]);
        }
    }
    end=clock();
    double funcTime=  ((double) (end-start))/CLOCKS_PER_SEC;
    return funcTime;
}
int left(int node)
{
    int child;
    if(node==0)
        child=1;
    else if(node>0)
        child= (2*node)+1;
    return child;
}
int right(int node)
{
    int child = (2*node)+2;
    return child;
}
void MaxHeapify(int array[],int node,int size)
{
    int currentElement=array[node];
    int leftChildNode=left(node);
    int leftChild = array[leftChildNode];
    int rightChildNode=right(node);
    int rightChild = array[rightChildNode];
    int largerNode;
    if(leftChildNode<=size-1 && leftChild>currentElement)
        largerNode=leftChildNode;
    else
        largerNode=node;
    if(rightChildNode<=size-1 && rightChild>array[largerNode])
        largerNode=rightChildNode;
    if(largerNode!=node)
    {
        Swap(&array[largerNode],&array[node]);
        MaxHeapify(array,largerNode,size);
    }
}
void BuildMaxHeap(int unsorted[],int size)
{
    int i;
    for(i=(size-1)/2; i>=0; i--)
    {
        MaxHeapify(unsorted,i,size);
    }
}
double HeapSort(int array[],int size)
{
    clock_t start,end;
    start=clock();

    int m=size;
    int Temp[size];
    int i;
    BuildMaxHeap(array,size);
    for(i=0; i<=m; i++)
    {
        Temp[i]=array[0];
        Swap(&array[0],&array[size-1]);
        size=size-1;
        MaxHeapify(array,0,size);
    }
    for(i=0; i<m; i++)
    {
        array[i]=Temp[i];
    }
    end=clock();
    double funcTime=  ((double) (end-start))/CLOCKS_PER_SEC;
    return funcTime;
}
void merge(int arr[],int start,int end,int mid)
{
    int n1 = mid-start + 1;
    int n2 = end-mid;
    int arr1[n1];
    int arr2[n2];
    for(int i=0; i<n1; i++)
        arr1[i] = arr[start+i];
    for(int j=0; j<n2; j++)
        arr2[j] = arr[mid+1+j];
    int i=0;
    int j=0;
    int k =start;
    while (i<n1 && j<n2)
    {
        if (arr1[i] <= arr2[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr2[j++];
    }
    while (i<n1)
        arr[k++] = arr1[i++];
    while (j < n2)
        arr[k++] = arr2[j++];

}
double MergeSort(int array[],int start,int end)
{
    clock_t run,finish;
    run=clock();

    if (start<end)
    {
        int m = (start+end)/2;  //index of middle element

        MergeSort(array,start,m);
        MergeSort(array,m+1,end);

        merge(array,start,end,m);
    }
    finish=clock();
    double funcTime= ((double) (finish-run)/CLOCKS_PER_SEC);
    return funcTime;
}
int partitioning(int arr[],int start,int end)
{
    int    pivot=arr[end];
    int    pIndex=start;
    for(int i=start; i<end; i++)
    {
        if(arr[i]<pivot)
        {
            Swap(&arr[i],&arr[pIndex]);
            pIndex++;
        }

    }
    Swap(&arr[end],&arr[pIndex]);
    return pIndex;
}
double quickSort(int arr[], int start, int end)
{
    clock_t run,finish;
    run=clock();

    if(start<end)
    {
        int pIndex=partitioning(arr,start,end);
        quickSort(arr,start,pIndex-1);
        quickSort(arr,pIndex+1,end);
    }
    finish=clock();
    double funcTime= ((double) (finish-run))/CLOCKS_PER_SEC;
    return funcTime;
}
double insertionSort(int arr[],int n)
{
    clock_t start,end;
    start=clock();

    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    end=clock();
    double funcTime= ((double) (end-start))/CLOCKS_PER_SEC;
    return funcTime;
}
void generateTest(int arrayOfSizes[],int n)
{
    double bubbleTime,selectionTime,insertionTime,heapTime,quickTime,mergeTime;
    int size,element,i,j;
    for(i=0;i<n;i++)
    {
        size=arrayOfSizes[i];
        int Test[size];
        int copy[size];
        for(j=0;j<size;j++)
        {
            element=rand();
            Test[j]=element;
            copy[j]=Test[j];
        }
        bubbleTime=BubbleSort(Test,size);
        for(j=0;j<size;j++)
            Test[j]=copy[j];
        selectionTime=SelectionSort(Test,size);
        for(j=0;j<size;j++)
            Test[j]=copy[j];
        insertionTime=insertionSort(Test,size);
        for(j=0;j<size;j++)
            Test[j]=copy[j];
        heapTime=HeapSort(Test,size);
        for(j=0;j<size;j++)
            Test[j]=copy[j];
        quickTime=quickSort(Test,0,size-1);
        for(j=0;j<size;j++)
            Test[j]=copy[j];
        mergeTime=MergeSort(Test,0,size-1);
        printf("Array #%d/%d\n-------------\n",i+1,n);
        printf("Bubble Time=%lf\n",bubbleTime);
        printf("Selection Time=%lf\n",selectionTime);
        printf("Insertion Time=%lf\n",insertionTime);
        printf("Heap Time=%lf\n",heapTime);
        printf("Quick Time=%lf\n",quickTime);
        printf("Merge Time=%lf\n",mergeTime);
        printf("\n\n");
    }
}
int main()
{
    int array[MAXSIZE];
    int sizes[]= {10,100,1000,10000,100000};
    generateTest(sizes,5);
}

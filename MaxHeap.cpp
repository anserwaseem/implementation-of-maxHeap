/**
 * C++ template class maxHeap with following features;
 * O(logN)  insert
 * O(logN)  deletion
 * O(N)     Heapify
 * O(NlogN) Heap-Sort
 * 
 * @param T the type of data stored in the Heap.
 * @warning T 'string' datatype isn't compatible.
 */

#include<iostream>
using namespace std;

template<class T>
class maxHeap
{
    int size;
    int index;
    T *arr;
public:
    //Paramterized Constructor
    maxHeap(int s)
    {
        size=s;
        index=0;
        arr=new T[size];

        for(int i=0;i<size;i++)
            arr[i]=-1;
    }

    /**
     * Inserts an element in heap.
     * @param el means element which'll be entered in heap.
     */
    void Insert(T el)
    {
        if (index == size) 
        { 
            cout<<"maxHeap is full. Cannot enter "<<el<<endl;
            return; 
        }
        index++; 
        int i = index - 1; 
        arr[i] = el; 
        while (i != 0 && arr[(i-1)/2] < arr[i]) 
        { 
            T swapping = arr[(i-1)/2]; 
            arr[(i-1)/2] = arr[i]; 
            arr[i] = swapping;
            i = (i-1)/2; 
        }
    }

    /**
     * Deletes an element in heap.
     * @param el means element which'll be deleted in heap.
     */
    void Delete(T el)
    {
        arr[0] = el;
        for (int i=0;arr[(i-1)/2]<arr[i];i=(i-1)/2) 
        { 
            T swapping = arr[(i-1)/2]; 
            arr[(i-1)/2] = arr[i]; 
            arr[i] = swapping;
        }
    }

    /**
     * Builds heap via comparisons recursively.
     * @param arr means element which'll be deleted in heap.
     * @param size means size of the array.
     * @param i means index on which heapify property is to be applied.
     */
    void maxHeapify(T *arr, int size, int i) 
    { 
        int largest = i;
        int l = 2*i + 1; //left
        int r = 2*i + 2; //right

        if (l < size && arr[l] > arr[largest]) 
            largest = l;
        if (r < size && arr[r] > arr[largest]) 
            largest = r; 
        if (largest != i) 
        { 
            swap(arr[i], arr[largest]);
            T swapping = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swapping;
            maxHeapify(arr, size, largest); 
        } 
    }

    /**
     * Sorts heap.
     * @param arr means element which has to be sorted in heap.
     * @param size means size of the array.
     * @relatesalso maxHeapify
     */
    void maxHeapSort(T *arr, int n) 
    { 
        for (int i=(n/2)-1;i>=0;i--) 
            maxHeapify(arr, n, i); 
        for (int i=n-1;i>0;i--) 
        { 
            T swapping = arr[i]; 
            arr[i] = arr[0]; 
            arr[0] = swapping;
            maxHeapify(arr, i, 0); 
        } 
    }

    // Prints all elements in heap.
    void print()
    {
        for(int i=0;i<size && arr[i]!=-1;i++)
            cout<<arr[i]<<"\t";
        cout<<endl;
    }

    //Destructor
    ~maxHeap()
    {
        arr=nullptr;
        delete arr;
    }
};

int main()
{
    maxHeap<int>* maxHeapINT=new maxHeap<int>(10);
    maxHeapINT->Insert(93);
    maxHeapINT->Insert(89);
    maxHeapINT->Insert(81);
    maxHeapINT->Insert(77);
    maxHeapINT->Insert(70);
    maxHeapINT->Insert(65);
    maxHeapINT->Insert(59);
    maxHeapINT->Insert(53);
    maxHeapINT->Insert(48);
    maxHeapINT->Insert(44);
    maxHeapINT->Insert(36);
    maxHeapINT->Insert(27);
    maxHeapINT->Insert(20);
    maxHeapINT->print();

    maxHeap<char>* maxHeapCHAR=new maxHeap<char>(10);
    maxHeapCHAR->Insert('q');
    maxHeapCHAR->Insert('w');
    maxHeapCHAR->Insert('e');
    maxHeapCHAR->Insert('r');
    maxHeapCHAR->print();
    
    return 0;
}
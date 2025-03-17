#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <limits>


void Max_Heapify(vector<int> &arr, int root){

    int l = 2 * root;
    int r = 2 * root + 1;
    int max = root;
    int heap_size = arr.size();

    if(l < heap_size && arr[l] > arr[root] ){ 
        int max = l;
    }

    if(r < heap_size && arr[r] > max ){ 
        int max = r;
    }

    if(arr[max] != arr[root]){
        swap(arr[max], arr[root]);
    }

}

int Extract_Max(vector<int> &arr){
    /*
     * @brief function extract the maximumm value from the heap 
     * @param arr refer to the heap. If it is a random array we shoul convert it into a heap by using BUILD_HEAP function
     * @retrun int of the maximum value
     * 
     * @complexity O(log n)
    */

    int max = arr[0]; //getting the maximum value of the heap
    int heap_size = arr.size(); //taking the size of the heap
    
    arr[0] = arr[heap_size-1]; //swap the maximum and the last element of the heap
    arr.pop_back(); //delete the maximum element

    Max_Heapify(arr,0); //heapify the rest of the heap

    return max;

}

void Increse_Key(vector<int> &arr, int i, int key){
    /* 
     * @brief increse an element to given key and change it location until the heap property is reinstated
     * @parm  arr refers to the array which contains the heap
     * @i reference to the element's index that has to be changed
     * @key refer to the value which we have to update
     * 
     * @complexity O(log n)
     */
    
    if( arr[i] > key){
        cout << "Error: the key  is less than the value of the index";
    }
    arr[i] = key; //change the value 

    while(i > 0 && arr[i] > arr[i/2]){ //while i is not the root and the parent of i is smaller than the i
        swap(arr[i], arr[i/2]);        //swap the element i with its parent
        i = i / 2;                     // set i to be its parent index

    }

}

void Heap_Insert(vector<int> &arr, int key){
    /*
     * @brief insert a key to the heap(max priority queue)
     * @param arr refer to the array
     * @param key refer to the value that has to be inseted
     * @return void modified array
     * 
     * @complexity O(log n)
    */

    int negative_infinity = numeric_limits<int>::min(); 
    arr.push_back(negative_infinity); //add a final element as the negative infinity
    int heap_size = arr.size(); //take the changed array size

    Increse_Key(arr, heap_size - 1, key ); //increase the negative infinity to the value which have to be inserted.

}
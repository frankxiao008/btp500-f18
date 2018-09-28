int binarySearch(int key, int array[], int size){
    int rc=-1;
    int low=0;
    int high=size-1;
    int mid;
    while(low<=high && rc==-1){
        mid=(low+high)/2;
        if(key < arr[mid])
            high=mid-1;
        else if(key > arr[mid] )
            low=mid+1;
        else
            rc=mid;
    }/*while*/
    return rc;
}



/*recursive version1*/
int binarySearch(int key, int array[], int size){
    int rc;
    int low = 0;
    int high = size-1;
    if(size == 0){
        rc=-1;
    }
    else{
        mid = size/2;
        if(key==array[mid]){
            rc=mid;
        }
        else if(key < array[mid]){
            rc =binarySearch(key,array+mid+1, size/2-1 );
        }
        else{
            rc= mid+ binarySearch(key,array,mid-1);
        }
    }
}

/*recursive version 2, work done in another function, initial
call made with expected function prototype*/
int binarySearch(int key, int array[], int size){
    return binarySearch(key,array,0,size-1);
}
int binarySearch(int key, int array[],int low, int high){
    int rc=-1;
    if(low <= high){
        if(array[mid] == key){
            rc=mid;
        }
        else if(key < array[mid]){
            rc=binarySearch(key,array,low,mid-1);
        }
        else{
            rc=binarySearch(key,array,mid+1,high);            
        }
    }
    return rc;
}












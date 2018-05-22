int merge(int a[], int start, int mid, int end){

    int i,j,k;
    int temp[end-start+1];
    
    i = start; j = mid+1; k =0;

    while(i <= mid && j <= end){
        if(a[i]< a[j]){
            temp[k++]= a[i++];
        }
        else {
            temp[k++]  = a[j++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++]; 
    }
    while(j <= end){
        temp[k++] = a[j++]; 
    }
    for(i=0; i<k; i++){
        a[i+start] = temp[i];
    }
}
int mergeSort(int a[], int start, int end ){

    int mid  = (start + end)/2;
    if(start<end){
        //sort the left part
        mergeSort(a, start, mid);
        //sort right part
        mergeSort(a, mid+1, end);
        
        //merge them together
        merge(a, start, mid, end);
    }
}
int main(){
    int a[] = {2,3,4,1,8,7,6,9};
    int size = sizeof(a)/sizeof(a[0]);
    
    mergeSort(a, 0, size-1);
    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
}

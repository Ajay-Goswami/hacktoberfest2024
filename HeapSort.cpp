//heap sort
#include<iostream>
using namespace std;

void heapify(int a[], int n, int i){
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && a[l]<a[smallest]){
        smallest = l;
    }
    if(r<n && a[r]<a[smallest]){
        smallest = r;
    }
    if(smallest!=i){
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        heapify(a,n,smallest);
    }
}

void buildheap(int arr[], int n){
        for(int i=n/2-1; i>=0; i--){
            heapify(arr,n,i);
        }
    }

void heapSort(int a[], int n){
    for(int i=n; i>1; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a,i-1,0);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    buildheap(a,n);
    heapSort(a,n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

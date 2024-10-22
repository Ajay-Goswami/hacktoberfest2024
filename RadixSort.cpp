//radix sort

#include<iostream>
using namespace std;

int getMax(int a[], int n){
    int max=0;
    for(int i=0; i<n; i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void countSort (int a[], int n , int pos){
    int count[10]={0};
    for(int i=0; i<n; i++){
        count[(a[i]/pos)%10]++;
    }
    for(int i=1; i<10; i++){
        count[i]+=count[i-1];
    }
    int temp[n];
    for(int i=n-1; i>=0; i--){
        temp[count[(a[i]/pos)%10]-1]=a[i];
        count[(a[i]/pos)%10]--;
    }
    for(int i=0; i<n; i++){
        a[i]=temp[i];
    }
}

void radixSort(int a[], int n){
    int max =getMax(a, n);
    for(int pos=1; max/pos>0; pos*=10){
        countSort(a, n, pos);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    radixSort(a,n);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}

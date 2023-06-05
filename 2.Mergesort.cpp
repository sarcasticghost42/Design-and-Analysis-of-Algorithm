#include<iostream>
#include<ctime>
#include<fstream>

using namespace std;

void merge(int a[],int low,int mid,int high){
    int i,j,k,b[20];
    i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(a[i]<=a[j])
           b[k++]=a[i++];
        else
           b[k++]=a[j++];
    }
    while(i<=mid)  b[k++]=a[i++];
    while(j<=high) b[k++]=a[j++];
       for(k=low;k<=high;k++)
            a[k]=b[k];
}
void mergesort(int a[],int low,int high){
    int mid;
    if(low>=high)
      return;
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}

int main(){
int n, a[1000],i,j;

cout<<"Enter the No. of Elements :";
cin>>n;
cout<<"The Random numbers are :"; 
for(i=0;i<n;i++){
    a[i]=rand()%100;
    cout<<a[i]<<" ";
}

clock_t start=clock();
mergesort(a,0,n);
clock_t end=clock();

cout<<"\nSorted Elements are :";
for(i=0;i<n;i++)
   cout<<a[i]<<" ";
double time=(double) (end-start)/CLOCKS_PER_SEC;
cout<<"\nTime taken is :"<<time;

for(i=1000;i<=10000;i+500){
        n=i;
        int a[n];
        for(j=0;j<n;j++)
           a[j]=rand()%1000;
        clock_t start=clock();
        mergesort(a,0,n);
        clock_t end=clock();
        double t=(double) (end-start)/CLOCKS_PER_SEC;
        ofstream file;
        file.open("mergesort.txt", ofstream :: app);
        file<<n<<"\t"<<t<<"\n";
        file.close();
    }
}


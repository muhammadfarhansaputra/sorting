#include<iostream>
using namespace std;
int data1[100], data2[100];
int n;
void merge(int,int,int);
void tukar_data_selection(int a,int b) {
	int t;
	t= data1[b];
	data1[b]=data1[a];
	data1[a]=t;
}

void  SelectionSort() {
	int awal, i, j;
	for ( i=1;i<=n-1;i++) {
		awal=i;
		for( j=i+1;j<=n;j++) {
			if(data1[j]<data1[awal]) {
				awal=j;
			}
		}
		if (awal != i)  tukar_data_selection(awal,i);
	}
}



void BubbleSort(){
	int awal,i,j;
		for ( i=1;i<n;i++) {
		for( j=n-1;j>=i;j--) {
			if(data1[j]<data1[j-1]) {
				awal=data1[j-1];
				data1[j-1]=data1[j];
				data1[j]=awal;
			}
		} 
    }
}

void merge_sort(int low,int high){
   int mid;
   if(low<high){
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low,int mid,int high){
    int h,i,j,k;
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high)) {
        if(data1[h]<=data1[j]) {
           data2[i]=data1[h]; h++;
        }
        else{
            data2[i]=data1[j]; j++;
        } i++;
    }
    if(h>mid) {
        for(k=j;k<=high;k++){
             data2[i]=data1[k]; i++;
        }
    }
    else {
  for(k=h;k<=mid;k++) {
         data2[i]=data1[k]; i++;
        }
    }
    for(k=low;k<=high;k++)
    data1[k]=data2[k];
}
int main(){
	cout<<"PROGRAM SELECTION SORT";
	cout<<"\nmasukan berapa banyak data = ";cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"masukan data ke "<<i<<"= ";cin>>data1[i];
		data2[i]=data1[i];
		}
		SelectionSort();
		cout<<"\ndata setelah di sort : ";
		for(int i=1;i<=n;i++){
			cout<<" "<<data1[i];
		}
		
		cout<<"\n\n\nPROGRAM BUBBLE SORT";
		cout<<"\nmasukan berapa banyak data = ";cin>>n;
		for(int i=0;i<n;i++){
			cout<<"masukan data ke "<<i+1<<"= "; cin>>data1[i];
        data2[i]=data1[i];
		}
		BubbleSort();
		
		cout<<"\ndata setelah di sort : ";
		for(int i=0;i<n;i++){
			cout<<" "<<data1[i];
		}
		
		
		cout<<"\n\n\nPROGRAM MERGE SORT : ";
		cout<<"\nmasukan berapa banyak data = ";cin>>n;
		for(int i=1;i<=n;i++){
			cout<<"masukan data ke "<<i<<"= ";cin>>data1[i];
			data2[i]=data1[i];
		}
		merge_sort(1,n);
		cout<<"\ndata setelah di sort : ";
		for(int i=1;i<=n;i++){
             cout<<data1[i]<<" ";
        }
}


//muhammad farhan saputra-1717051009

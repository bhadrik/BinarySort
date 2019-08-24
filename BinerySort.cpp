//RAW CODE

#include<iostream>
#define n 5
using namespace std;
//int n=5;
int globalArray[5];
short ptr=0;
void my_sort(int*, short, short);

int main()
{
	int arr[n]={50,83,95,14,63};
	/*int num,ii=0;
	int *arr=(int*)malloc(0);
	cout<<"Enter numbers u want to sort"<<endl<<"Enter -1 if complete"<<endl;
	while(num!=-1){
		cin>>num;
		realloc(arr,sizeof(int));
		arr[ii]=num;
		ii++;
	}
	n=ii;
	*/
	for(short i=6;i>=0;i--){
		my_sort(arr,i,n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(globalArray[i]==arr[j])
					arr[j] = 0;
			}
		}
	}
	for(short i=0;i<n;i++)
		cout<<globalArray[i]<<" ";
	return 0;
}

void my_sort(int *arr,short bitNo, short length){
	int *subarray = (int*)malloc(0);
	short newLength = 0;
	bool gone=0;

	cout<<"length :"<<length<<endl;
	cout<<"bitNo :"<<bitNo<<endl;

	if(bitNo == 0){
		cout<<"bitNo == 0\n";
		return;
	}

	if(length == 1 ){
			globalArray[ptr]=arr[0];
			ptr++;
			cout<<"leng == 1\n";
			return ;
	}
	if(length==2){
		globalArray[ptr]=arr[1]>arr[0]?arr[1]:arr[0];
		ptr++;
		globalArray[ptr]=arr[1]>arr[0]?arr[0]:arr[1];
		ptr++;
	}
	else{
		for(int i=0;i<length;i++){
			if((arr[i] >> bitNo) & 1){
				realloc(subarray,sizeof(int));
				subarray[newLength] = arr[i];
				newLength++;
				cout<<"Yes"<<endl;
				gone=1;
			}
		}
	}
	cout<<subarray[0]<<" + "<<subarray[1]<<endl;
	cout<<"BEF:";
	for(short i=0;i<n;i++)
		cout<<globalArray[i]<<" ";
	cout<<endl;
	if(length>2){
		if(!gone)
			my_sort(arr,bitNo-1,length);
		else
			my_sort(subarray,bitNo-1,newLength);
	}

	cout<<"AFT:";
	for(short i=0;i<n;i++)
		cout<<globalArray[i]<<" ";
	cout<<endl;
}

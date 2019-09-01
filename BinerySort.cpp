//RAW CODE

#include<iostream>
#define n 5
using namespace std;
int globalArray[5];
short ptr=0;
void binerySort(int*, short, short);

int main()
{
	int arr[n]={50,83,95,14,63};
	
	for(short i=6;i>=0;i--){
		binerySort(arr,i,n);
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

void binerySort(int *arr,short bitNo, short length){
	int *subarray = (int*)malloc(0);
	short newLength = 0;
	bool gone=0;

	if(bitNo == 0){
		return;
	}

	if(length == 1 ){
		globalArray[ptr]=arr[0];
		ptr++;
		return;
	}
	
	if(length == 2){
		globalArray[ptr]=arr[1]>arr[0]?arr[1]:arr[0];
		ptr++;
		globalArray[ptr]=arr[1]>arr[0]?arr[0]:arr[1];
		ptr++;
	}
	else{
		for(int i=0;i<length;i++){
			if((arr[i] >> bitNo) & 1){
				subarray = (int*)realloc(subarray,sizeof(int));
				subarray[newLength] = arr[i];
				newLength++;
				gone=1;
			}
		}
	}
	if(length>2){
		if(!gone)
			binerySort(arr,bitNo-1,length);
		else
			binerySort(subarray,bitNo-1,newLength);
	}
}

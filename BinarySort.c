#include <stdio.h>
#define N 10

//i1 <-> i2 position swap in "data" array
void swap(int* data, int i1, int i2) {
	if (i1 == i2) return;
	int temp = data[i1];
	data[i1] = data[i2];
	data[i2] = temp;
}

//Print the content of given array
void displayData(int *data) {
	int i = 0;
	printf("%d",data[0]);
	for (i = 1; i < N; i++)
		printf(", %d", data[i]);
	printf("\n");
}

//Perform binery sort
void binarySort(int* data, int bitNo, int* lowerBound, int* upperBound) {

	//Start form given bit number in "bitNo" and goes into a loop until it becomes 0
	if (bitNo == 0) return;

	int l_backup = *lowerBound, u_backup = *upperBound, i;

	if (*upperBound - *lowerBound == 0) return;

	//Scaning all the numbers between location "lowerBound" to "upperBound"
	for (i = l_backup; i <= *upperBound; i++) {
		//If found bit == 1 swap with "lowerBound";
		if ((data[i] >> bitNo) & 1) {
			swap(data, i, *lowerBound);
			*lowerBound += 1;
		}
	}
	int hold = *lowerBound;
	if (*lowerBound == l_backup)
		hold = *upperBound;
	else
		hold = *lowerBound - 1;

	//Again calling for divided subarry, and now for (bitNo - 1)th bit
	binarySort(data, (bitNo - 1), &l_backup, &hold);
	binarySort(data, (bitNo - 1), lowerBound, upperBound);
}

int main() {
	int data[N] = { 70, 80, 30, 60, 50, 90, 20, 40, 90, 15 };
	int lowerBound = 0, upperBound = N - 1, bitNo = 6;

	displayData(data);

	/*
	* BitNo is most importent thing in this algorithm because it affect the performace most.
	* Here I have choosen 6 as bitNo because there is not a single bit 1 after 6th bit in any number.
	* 
	*                   <- bitNo
	*     10 9 8 7 6 5 4 3 2 1 0
	* 70:  0 0 0 0 1 0 0 0 1 1 0
	* 80:  0 0 0 0 1 0 1 0 0 0 0
	* 30:  0 0 0 0 0 0 1 1 1 1 0
	* 60:  0 0 0 0 0 1 1 1 1 0 0
	* 50:  0 0 0 0 0 1 1 0 0 1 0 
	* 90:  0 0 0 0 1 0 1 1 0 1 0
	* 20:  0 0 0 0 0 0 1 0 1 0 0
	* 40:  0 0 0 0 0 1 0 1 0 0 0
	* 90:  0 0 0 0 1 0 1 1 0 1 0
	* 15:  0 0 0 0 0 0 0 1 1 1 1
	* 
	* So either you have to determine bitNo from your input data manuly or can
	* choose maximum number of bits in your data type like int(4byte)-> 32bit.
	*/
	binarySort(data, bitNo, &lowerBound, &upperBound);

	displayData(data);

	return 0;
}

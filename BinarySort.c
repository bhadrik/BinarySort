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
void displayData(int* data) {
	int i = 0;
	printf("%d", data[0]);
	for (i = 1; i < N; i++)
		printf(", %d", data[i]);
	printf("\n");
}

//Perform binery sort
void binarySort(int* data, int bitNo, int* lowerBound, int* upperBound) {

	//Start form given bit number in "bitNo"
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
	int lowerBound = 0, upperBound = N - 1;

	displayData(data);

	binarySort(data, 6, &lowerBound, &upperBound);

	displayData(data);

	return 0;
}
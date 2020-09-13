#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int N = 10;

//i1 <-> i2 position swap in "data" array
void swap(int* data, int i1, int i2) {
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
void binarySort(int* data, int bitNo, int lowerBound, int upperBound) {

	//Start form given bit number in "bitNo" and goes into a loop until it becomes 0
	if (bitNo == 0) return;

	int l_backup = lowerBound, u_backup = upperBound, i;

	if (upperBound - lowerBound == 0) return;

	//Scaning all the numbers between location "lowerBound" to "upperBound"
	for (i = l_backup; i <= upperBound; i++) {
		if ((data[i] >> bitNo) & 1) {
			if (i != upperBound) {
				swap(data, i, upperBound);
				i--;
			}
			upperBound--;
		}
	}

	int hold = upperBound;

	if (upperBound == u_backup)
		hold = lowerBound;
	else
		hold = upperBound + 1;

	//Again calling for divided subarry, and now for (bitNo - 1)th bit
	binarySort(data, (bitNo - 1), hold, u_backup);
	binarySort(data, (bitNo - 1), lowerBound, upperBound);
}

int main(int argc, char* args[]) {
	if (argc == 3)
		N = atoi(args[1]);
	else
		printf("Check given argument!\n");

	clock_t startTime, endTime;
	double time;
	int data[N];
	int lowerBound = 0, upperBound = N - 1, bitNo = sizeof(data[0]) * 4;
	int i = 0;

	FILE* fptr;
		
	if (argc == 3 || argc == 0)
		fptr = fopen(args[2], "r");
	else
		printf("Check given argument!\n");

	if (fptr == NULL) { printf("File not found!!\n"); exit(1); }

	while (fscanf(fptr, "%d", &data[i]) == 1) { i++; }

	startTime = clock();
	//printf("Start: %f\n", (float)startTime);

	//First binarySort call
	binarySort(data, bitNo-1, lowerBound, upperBound);

	endTime = clock();
	fclose(fptr);

	//printf("End: %f\n", (float)endTime);

	time = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

	char name[20]="Sorted ";

	strcat(name, args[2]);

	fptr = fopen(name, "w");

	for (i = 0; i < N; i++)
		fprintf(fptr, "%d ", data[i]);

	fclose(fptr);

	free(data);

	printf("%s file generated in %.3fs", name, time);

	return 0;
}

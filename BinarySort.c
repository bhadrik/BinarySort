#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int N = 10;

//i1 <-> i2 position swap in "data" array
void swap(int* data, int i1, int i2) {
	int temp = data[i1];
	data[i1] = data[i2];
	data[i2] = temp;
}

//Print the content of given array for debugging
void displayData(int* data) {
	int i = 0;

	printf("%d", data[0]);

	for (i = 1; i < N; i++)
		printf(", %d", data[i]);

	printf("\n");
}

int findBitNo(int* data){
	int tempBit = 31;
	int i = 0;

	while(true){
		i=0;
		while(i<N){
			if((data[i] >> tempBit) & 1){
				// printf("bitNo: %d data[%d]=%d\n",tempBit,i,data[i]);
				return ++tempBit;
			}
			i++;
		}
		tempBit--;
	}

    return ++tempBit;
}

//Perform binery sort
void binarySort(int* data, int bitNo, int lowerBound, int upperBound) {

	//Start form given bit number in "bitNo" and goes into a loop until it becomes 0
	if (bitNo < 0) return;

	int l_backup = lowerBound, u_backup = upperBound, i;

	if (upperBound - lowerBound == 0) return;

    // int p = 10;
	//Scaning all the numbers between location "lowerBound" to "upperBound"
    // while(p){
    // printf("At: %d (%d, %d)\n",bitNo,l_backup+1,upperBound+1);
	for (i = l_backup; i <= upperBound; i++) {
		if ((data[i] >> bitNo) & 1) {
			if (i != upperBound) {
                // printf("[%d <= %d] -> ",i, upperBound);
				swap(data, i, upperBound);
				i--;
			}
            // else printf("Equal: ");
			upperBound--;
		}
        // else printf("[%d :N %d] -> ",i, upperBound);
        // displayData(data);
	}
    // p--;
    // }

	int hold = upperBound;

	if (upperBound == u_backup)
		hold = lowerBound;
	else
		hold = upperBound + 1;

	//Again calling for divided subarry, and now for (bitNo - 1)th bit
    // printf("->\n");
	binarySort(data, (bitNo - 1), hold, u_backup);
    // printf("<-\n");
    // printf("->\n");
	binarySort(data, (bitNo - 1), lowerBound, upperBound);
    // printf("<-\n");
}

int main(int argc, char* args[]) {
	if (argc == 3)
		N = atoi(args[1]);
	else
		printf("Check given argument!\n");

	clock_t startTime, endTime;
	double time;
	int data[N];
	int lowerBound = 0, upperBound = N - 1, bitNo = _INTEGRAL_MAX_BITS/2;
	int i = 0;

	FILE* fptr = NULL;
		
	//READ file data
	if (argc == 3)
		fptr = fopen(args[2], "r");
	else
		printf("Check given argument!\n");

	if (fptr == NULL) { printf("File not found!!\n"); exit(1); }

	while (fscanf(fptr, "%d", &data[i]) == 1) { i++; }

	startTime = clock();

    bitNo = findBitNo(data);
	printf("Found: %d\n", bitNo);
	
	//Perform BinarySort
	binarySort(data, bitNo-1, lowerBound, upperBound);

	endTime = clock();

	time = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

	fclose(fptr);


	//WRITE data into file
	char name[20]="Sorted_";

	strcat(name, args[2]);

	fptr = fopen(name, "w");

	for (i = 0; i < N; i++)
		fprintf(fptr, "%d ", data[i]);

	fclose(fptr);

	free(data);

	printf("%s file generated in %.3fs", name, time);

	return 0;
}
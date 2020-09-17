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

	int l_backup = lowerBound, u_backup = upperBound, i;
    bool letsGo = false;

loopAgain:
	//Scaning all the numbers between location "lowerBound" to "upperBound"
	for (i = l_backup; i <= upperBound; i++) {
		if ((data[i] >> bitNo) & 1) {
            letsGo = true;
			if (i != upperBound) {
				swap(data, i, upperBound);
				i--;
			}
			upperBound--;
		}
	}

    if(!letsGo && bitNo > 0){
        bitNo--;
        goto loopAgain;
    }

	int hold = upperBound;

	if (upperBound == u_backup)
		hold = lowerBound;
	else
		hold = upperBound + 1;

	//Again calling for divided subarry, and now for (bitNo - 1)th bit
    if(bitNo > 0 && (hold != u_backup || lowerBound != upperBound)){
    	binarySort(data, (bitNo - 1), hold, u_backup);
	    binarySort(data, (bitNo - 1), lowerBound, upperBound);        
    }
}

int main(int argc, char* args[]) {

	long startTime, endTime, time;
	int lowerBound = 0, upperBound = 0, bitNo = _INTEGRAL_MAX_BITS/2, i = 0;
    int* data = NULL;
	FILE* fptr = NULL;
    int size; char fileName[20];

    if(argc == 3){
		size = atoi(args[1]);
		strcpy(fileName, args[2]);
	}
	else{
		size = 10000;
		strcpy(fileName, "Data.txt");
		printf("Default size:%d File name:%s!\n",size, fileName);
	}

	N = size;
	data = (int*)malloc(sizeof(int)*N);
	upperBound = N -1;

		
	//READ from file to an array -----------------
	fptr = fopen(fileName, "r");

	if (fptr == NULL) { printf("File not found!!\n"); exit(1); }

	while (fscanf(fptr, "%d", &data[i]) == 1) { i++; }

	fclose(fptr);
	//----------------------------------------


	startTime = clock();

    // bitNo = findBitNo(data);  //Exteranal function to optimize bitNo
    binarySort(data, bitNo-1, lowerBound, upperBound);

	endTime = clock();

    //WRITE data into file -------------------
	char name[20]="Sorted_";

	strcat(name, fileName);

	fptr = fopen(name, "w");

	for (i = 0; i < N; i++)
		fprintf(fptr, "%d ", data[i]);

	fclose(fptr);
	//---------------------------------------

	free(data);

    time = (endTime - startTime) / CLOCKS_PER_SEC;

	printf("%s file generated in %.3fs", name, time);

	return 0;
}
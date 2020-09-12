#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N atoi(args[1])

int main(int argc, char* args[])
{

    int lower = 645646, upper = 2147483647;

    srand(time(0));

    FILE* fptr;

    if (argc == 3)
        fptr = fopen(args[2], "w");
    else printf("Not proper argument!\n");

    int i;
    if (fptr == NULL) {
        printf("ERROR, couldn't allocate space");
        exit(1);
    }

    for (i = 0; i < N; i++) {
        //int val = (rand() % (upper - lower + 1)) + lower;
        int val = rand() % upper;
        if (val < 40000 && rand() % 1) {
            val = rand() % upper;
        }

        fprintf(fptr, "%d ", val);
    }

    fclose(fptr);
    printf("Random data has been genreated");
    return 0;
}
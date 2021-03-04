#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N atoi(args[1])

int main(int argc, char* args[])
{
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

    printf("Going to generat\n");

    for (i = 0; i < N; i++) {
        //it will generate value between the range 0 - RAND_MAX [32767]. Unfortunatly RAND_MAX is constant.
        unsigned int val = rand() * rand() ;
        fprintf(fptr, "%u ", val);
    }

    fclose(fptr);
    printf("Random data has been genreated\n");
    return 0;
}

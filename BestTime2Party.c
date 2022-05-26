#include <stdio.h>


void merge(int metalBands[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = metalBands[l + i];
    for (j = 0; j < n2; j++)
        R[j] = metalBands[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            metalBands[k] = L[i];
            i++;
        }
        else {
            metalBands[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        metalBands[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        metalBands[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int metalBands[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(metalBands, l, m);
        mergeSort(metalBands, m + 1, r);

        merge(metalBands, l, m, r);
    }
}

int main()
{
    int comeMetalBands[23] =  { 20, 22, 19, 18, 19, 19, 21, 20, 20, 19, 20, 22, 18, 18, 23, 22, 19, 21, 20, 22, 19, 18, 20};
    int leaveMetalBands[23] = { 23 ,24 ,20 ,22 ,21 ,20 ,23 ,22 ,21 ,21 ,22 ,24 ,23 ,21 ,24 , 24 ,24 ,22 ,23 ,24 ,23 ,20, 21};

    int arr_csize = sizeof(comeMetalBands) / sizeof(comeMetalBands[0]);
    int arr_msize = sizeof(leaveMetalBands) / sizeof(leaveMetalBands[0]);


    //call mergeSort for leaveMetalBands
    mergeSort(leaveMetalBands, 0, arr_msize - 1);

    //call mergeSort for comeMetalBands
    mergeSort(comeMetalBands, 0, arr_csize - 1);

    //initialize variables with 0
    int i = 0, j =0, count = 0, max = 0, position = 0;

    /*compare comeMetalBands with leaveMetalBands and I find if stathis is times so count become +1
     * For first repetition
     *
     * For example if the smallest leaveMetalBands is bigger than
     * smallest comeMetalBands so I have to move count +1 i++ because this means stathis is in this band and he can take his selfie.
     *
     *  If the smallest leaveMetalBands is smaller than smallest comeMetalBands
     *  I have to move count -1 and j++ because this means stathis is in not in the time and he lost the band .
     *
     * If the smallest leaveMetalBands is the same with comeMetalBands
     * I don't have to do anything but to move (i and j)++  because this means stathis is not going to see anything again because
     * band " start-end" at the same time so if you don't lose anything you don't have to count -- or count ++ .
     *
     * */
    while (i < 23){
        if ( comeMetalBands[i] > leaveMetalBands[j]){
            j++;
            count--;
        }else if ( comeMetalBands[i] == leaveMetalBands[j]){
            i++;
            j++;
        }else{
            i++;
            count++;
        }
        if (max < count){
            max = count;
            position = comeMetalBands[i-1];//save the position ( It is -1 because i goes +1 but max was in the penultimate position the max)
        }

    }
    printf("-----------------------------------------------------------\n");
    printf("Stathis has to come at: %d:00 o'clock if he want to see the most bands\nSpecifically he is going to see: %d bands", position, max);
    printf("\n-----------------------------------------------------------");


    return 0;
}
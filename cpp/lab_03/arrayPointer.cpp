#include <iostream>

using namespace std;

/* func. prototypes */
void prompt_usr(int &num_elements);
void populate_arr1(short *arr1, int arr1_size);
int populate_arr2(short *arr1, short *arr2, int arr1_size);
void print_arr(short *arr, int size);
void dealloc_mem(short *arr1, short *arr2);

/* this func. will prompt the user to enter the number of elements,
    then read/write the specified value into the address loc. */
void prompt_usr(int &num_elements) {
    cout << "please enter the number of elements: ";
    cin >> num_elements;
}

/* this func. will populate the contents of arr1 of {@code Integer} arr1_size
    where each elem. corresponds to the index pos. */
void populate_arr1(short *arr1, int arr1_size) {
    int i = 0;
    while(i < arr1_size) {
        *(arr1 + i) = i;
        i++;
    }
}

/* this func. will populate the contents of arr2
    where each elem. corresponds to the odd index pos. of arr1 of {@code Integer} arr1_size */
int populate_arr2(short *arr1, short *arr2, int arr1_size) {
    int i = 0;
    int j = 0;
    while(i < arr1_size) {
        if(i % 2 != 0) { /* check whether satisfies the def. of oddness */
            *(arr2 + j) = *(arr1 + i);
            j++;
        }
        i++;
    }
    return j; /* return the size of arr2 */
}

/* this func. will print the contents of arr of {@code Integer} size */
void print_arr(short *arr, int size) {
    int i = 0;
    while(i < size) {
        cout << *(arr + i) << " ";
        i++;
    }
    cout << endl;
}

/* this func. will deallocate memory */
void dealloc_mem(short *array1, short *array2) {
    delete[] array1;
    delete[] array2;
}

/* this is the main func. */
int main(int argc, char *argv[]) {
    int NUMBER_ELEMENTS;

    /* func. call to obtain the number of elements */
    prompt_usr(NUMBER_ELEMENTS);

    short *array1 = new short[NUMBER_ELEMENTS];
    if(array1 == nullptr) {
        cout << "error: memory allocation failed" << endl;
        exit(-1); /* exit with an error status */
    }

    /* func. call to populate the contents of array1 */
    populate_arr1(array1, NUMBER_ELEMENTS);

    short *array2 = new short[(NUMBER_ELEMENTS + 1) / 2];
    if(array2 == nullptr) {
        cout << "error: memory allocation failed" << endl;
        delete[] array1;
        exit(-1); /* exit with an error status */
    }

    /* func. call to populate the contents of array2 */
    int arr2_size = populate_arr2(array1, array2, NUMBER_ELEMENTS);

    cout << "array1: ";
    /* func. call to print the contents of array1 */
    print_arr(array1, NUMBER_ELEMENTS);

    cout << "array2: ";
    /* func. call to print the contents of array2 */
    print_arr(array2, arr2_size);

    /* func. call to deallocate memory */
    dealloc_mem(array1, array2);

    return EXIT_SUCCESS;
}

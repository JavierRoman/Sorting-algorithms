/**
 * This function swaps two elements in a list
 * 
 * Input: i, j: Indexes of the elements to swap
 *        list: The listh where the swapping will be performed
 */
void swap(int i, int j, int *list);

/**
 * This function sorts a list of numbers using selection-sort algorithm
 * 
 * Input: list: The list of numbers
 *         len: The length of the list
 */
void selection(int *list, int len);

/**
 * This function sorts a list of numbers using insertion-sort algorithm
 * 
 * Input: list: The list of numbers
 *         len: The length of the list
 */
void insertion(int *list, int len);

/**
 * This function sorts a list of numbers using bubble-sort algorithm
 * 
 * Input: list: The list of numbers
 *         len: The length of the list
 */
void bubble(int *list, int len);

/**
 * This function sorts a list of numbers using quicksort algorithm
 * 
 * Input: list: The list of numbers
 *         len: The length of the list
 */
void quicksort(int *list, int len);

/**
 * This function sorts a list of numbers using mergesort algorithm
 * 
 * Input: list: The list of numbers
 *         len: The length of the list
 */
void mergesort(int *list, int len);
/**
 * This function prints a list.
 * 
 * Input: list: The list to be printed
 *         len: The length of the list
 */
void printList(int *list, int len);

/**
 * This function clones an array. The retrieved array 
 * must be freed by the user.
 * 
 * Input: list: The list to be printed
 *         len: The length of the list
 */
int *copyList(int *list, int len);

/**
 * Ask for the parameters needed to create a list 
 * and returns a pointer to it.
 * 
 * Output: The list and the length as a parameter
 */
int *introduceList(int *len);

/**
 * Retrieves a portion of a certain list alloating
 * memory for it.n 
 * 
 * Input: ini: The index where the sublist begins.
 *        len: The lenght of the sublist.
 *       list: The list from where the sublist will be extracted.
 * 
 * Output: This function retrieves the sublist: This sublist must be
 *         freed after its use.
 * */
int *getSubList(int ini, int len, int *list);

/**
 * This function copies the content of a list to another list.
 * 
 * Input: dst: The list where the content will be copied.
 *        src: The list from where the content will be copied.
 *        len: The lenght of both lists.
 */
void copyListContent(int *dst, int *src, int len);
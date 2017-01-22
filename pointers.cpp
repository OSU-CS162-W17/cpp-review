#include <iostream>

int main(int argc, char** argv) {

  /*
   * Here, we're creating a new integer variable n along with an integer
   * pointer n_ptr, which points to the address of n.  Look at the output
   * of the cout statements below.  You'll see that &n and n_ptr are both
   * memory addresses (they print as 0x... values) and that those memory
   * addresses are equal to each other.  That means that those two values
   * represent the same location in memory.
   *
   * Also, you can see that the value of n and the value of *n_ptr are both
   * 16 when printed.  Accessing this value with the statement *n_ptr is
   * called "dereferencing" a pointer to access the value stored in the memory
   * address it represents.
   *
   * Note that n is a statically allocated integer, i.e. it lives on the call
   * stack.
   */
  int n = 16;
  int* n_ptr = &n;

  std::cout << "n: " << n << std::endl;
  std::cout << "&n: " << &n << std::endl;
  std::cout << "n_ptr: " << n_ptr << std::endl;
  std::cout << "*n_ptr: " << *n_ptr << std::endl;
  std::cout << std::endl;

  /*
   * Here, we are creating a dynamically allocated integer (i.e. a single
   * integer value that lives on the heap), and we're using the dereference
   * operator (*) to assign the value 8 to that memory address.
   *
   * In the cout statements below, note that we are printing both dyn_ptr and
   * &dyn_ptr, that those values are both memory addresses, and that they are
   * *different* memory addresses.  The important thing to note here is that
   * the value of dyn_ptr (i.e. the memory address to which it points) is
   * different than its own address (i.e. the place in memory where dyn_ptr
   * itself is stored).  In particular, dyn_ptr itself is stored on the call
   * stack, but it points to a location in the heap.
   *
   * Also (importantly), note that we're freeing the memory we allocated for
   * dyn_ptr as soon as we're done with it using the delete operation.
   */
  int* dyn_ptr = new int;
  *dyn_ptr = 8;
  std::cout << "dyn_ptr: " << dyn_ptr << std::endl;
  std::cout << "&dyn_ptr: " << &dyn_ptr << std::endl;
  std::cout << "*dyn_ptr: " << *dyn_ptr << std::endl;
  std::cout << std::endl;
  delete dyn_ptr;

  /*
   * Here, we're declaring a reference variable that also points to the
   * memory address of n.  Because this is a reference variable instead of a
   * pointer, it works a little differently than a pointer.  For example, we
   * can't update the address to which the reference points.  When we say
   * "n_ref = m" below, it actually updates the value of the reference (and
   * hence the value of the original variable), as you can see when we print
   * out n again below.
   */
  int& n_ref = n;
  int m = 10;
  std::cout << "n_ref: " << n_ref << std::endl;
  n_ref = m;
  std::cout << "n: " << n << std::endl;
  std::cout << std::endl;

  /*
   * Here, we're creating a 1D static array (i.e. an array allocated on the
   * call stack) with a variable size (i.e. with size n, which is a variable),
   * and we're filling it and printing its values using a for loop.
   */
  int static_array[n];
  for (int i = 0; i < n; i++) {
    static_array[i] = i;
    std::cout << "static_array[" << i << "]: " << static_array[i] << std::endl;
  }
  std::cout << std::endl;

  /*
   * Here, we're allocating a static 2D array (a matrix) and filling and
   * printing its values with a nested for loop.
   */
  int static_matrix[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      static_matrix[i][j] = i * j;
      std::cout << "static_matrix[" << i << "][" << j << "]: "
        << static_matrix[i][j] << std::endl;
    }
  }
  std::cout << std::endl;

  /*
   * Here, we're creating a 1D dynamic array (i.e. an array allocated on the
   * heap) and filling it and printing its values using a for loop.  Note that
   * we're freeing the array's memory with delete[] as soon as we're done with
   * it.
   */
  n = 4;
  int* dynamic_array = new int[n];
  for (int i = 0; i < n; i++) {
    dynamic_array[i] = i;
    std::cout << "dynamic_array[" << i << "]: " << dynamic_array[i]
      << std::endl;
  }
  std::cout << std::endl;
  delete[] dynamic_array;

  /*
   * Here, we're allocating a 2D dynamic array (i.e. one allocated on the
   * heap).  Note that the allocation here happens in 2 steps.  First we
   * allocate an array of integer pointers.  Then, for each of those pointers
   * we allocate an array of integers.  In other words, the 2D array is
   * actually an array of 1D arrays, where each of the 1D arrays represents a
   * row in the 2D array.
   */
  m = 3;
  int** dynamic_matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    dynamic_matrix[i] = new int[m];
  }

  /*
   * Here, we fill and print the values of the dynamic 2D array in a nested
   * for loop.
   */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        dynamic_matrix[i][j] = i * j;
        std::cout << "dynamic_matrix[" << i << "][" << j << "]: "
          << dynamic_matrix[i][j] << std::endl;
    }
  }
  std::cout << std::endl;

  /*
   * Here, we're freeing all of the memory allocated to our dynamic 2D array.
   * First, we must free each of the 1D rows we allocated above, and only
   * after this is done can we free the array of pointers we initially
   * allocated.  We're basically reversing the work we did to allocate the
   * array.
   */
  for (int i = 0; i < n; i++) {
    delete[] dynamic_matrix[i];
  }
  delete[] dynamic_matrix;

}

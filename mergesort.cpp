#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

// Implements a mergesort with 1 vector as an input
// Uses only 2 vectors, passing the data back and forth each iteration
template <class Comparable>
void mergesort( vector<Comparable> &a ) {

  int size = a.size( );
  vector<Comparable> b( size );  // this is only one temporary array.
  int merge_itr = 0;

  for ( ; merge_itr < log2(size); merge_itr++) {  //iterates for log(n) times
    int nItems = pow(2, merge_itr);
//    cout << "nItems = " << nItems << endl;
    if (merge_itr % 2 == 0) {
//        cout << "merge a to b" << endl;
        int index = 0;
        while (index < size) {
            int first1 = index;
            int last1 = first1 + nItems - 1;
            int first2 = last1 + 1;
            int last2 = first2 + nItems - 1;
            if (nItems * 2 >= size || last2 >= size) { // handles when size != n^2
                last2 = size - 1;
            }
            for ( ; (first1 <= last1) && (first2 <= last2); index++) {  // sort elements of nItems length
                if (a[first1] < a[first2]) {
                    b[index] = a[first1];
                    ++first1;
                }
                else {
                    b[index] = a[first2];
                    ++first2;
                }
            }
            for ( ; first1 <= last1; first1++, index++)
                b[index] = a[first1];
            for ( ; first2 <= last2; first2++, index++)
                b[index] = a[first2];
            }
/*        for ( int i = 0; i < size; i++ )
            cout << "a" << "[" << i << "] = " << a[i] << endl;
        cout << "-----------------" << endl;
        for ( int i = 0; i < size; i++ )
            cout << "b" << "[" << i << "] = " << b[i] << endl; */
    }
    else if (merge_itr % 2 == 1) { // repeat the "if" section with a and b swapped
//    cout << "merge b to a" << endl;
        int index = 0;
        while (index < size){
            int first1 = index;
            int last1 = first1 + nItems - 1;
            int first2 = last1 + 1;
            int last2 = first2 + nItems - 1;
            if (nItems * 2 >= size || last2 >= size) { // handles when size != n^2
                last2 = size - 1;
            }
            for ( ; (first1 <= last1) && (first2 <= last2); index++) {
                if (b[first1] < b[first2]) {
                    a[index] = b[first1];
                    first1++;
                }
                else {
                    a[index] = b[first2];
                    first2++;
                }
            }
            for ( ; first1 <= last1; first1++, index++)
                a[index] = b[first1];
            for ( ; first2 <= last2; first2++, index++)
                a[index] = b[first2];
        }
/*            for ( int i = 0; i < size; i++ )
                cout << "a" << "[" << i << "] = " << a[i] << endl;
            cout << "-----------------" << endl;
            for ( int i = 0; i < size; i++ )
                cout << "b" << "[" << i << "] = " << b[i] << endl; */
    }
  }
  if (merge_itr % 2 == 1) {
//    cout << "switched arrays at end" << endl;
    for ( int index = 0; index < size; index ++) {
        a[index] = b[index];
    }
  }
}

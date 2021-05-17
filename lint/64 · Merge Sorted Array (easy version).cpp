class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int ct1 = n-1, ct2 = m-1;
        for(int i = n+m-1 ; i > -1; i--){
            if(ct1 == -1) {
                A[i] = A[ct2--];
            } else if (ct2 == -1) {
                A[i] = B[ct1--];
            } else if(A[ct2] > B[ct1]) {
                A[i] = A[ct2--];
            } else {
                A[i] = B[ct1--];
            }
        }
    }
};

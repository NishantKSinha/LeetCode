class Solution {
public:
    void nextPermutation(vector<int>&A) {
      int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int pivot = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            pivot = i;
            break;
        }
    }

    // If break point does not exist:
    if (pivot == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return;
    }

    // Step 2: Find the next greater element == next greater will not always last indx of array ==e.g = [2,3,1]
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > pivot; i--) {
        if (A[i] > A[pivot]) {
            swap(A[i], A[pivot]);
            break;
        }
    }

    // Step 3: reverse the right half:
   // reverse(A.begin() + ind + 1, A.end());
   int i = pivot + 1 , j = n-1;
   while(i <= j){
     swap(A[i++],A[j--]);
   }
        
    }
};
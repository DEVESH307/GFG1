//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
// class Solution{
// public:	
// 	/* if x is present in arr[] then returns the count
// 		of occurrences of x, otherwise returns 0. */
// 	int count(int arr[], int n, int x) {
// 	    // code here
// 	    int ans = 0;
// 	    for(int i = 0; i < n; i++){
// 	        if(arr[i] == x){
// 	            ans++;
// 	        }
// 	    }
// 	    return ans;
// 	}
// };
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int firstOccurance(int arr[], int n, int x){
        int first = -1;
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high){
            mid = low+(high-low)/2;
            if(arr[mid] == x){
                first = mid;
                high = mid-1;
            }
            else if(arr[mid] < x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return first;
    }
    int lastOccurance(int arr[], int n, int x){
        int last = -1;
        int low = 0;
        int high = n-1;
        int mid;
        while(low <= high){
            mid = low+(high-low)/2;
            if(arr[mid] == x){
                last = mid;
                low = mid+1;
            }
            else if(arr[mid] < x){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return last;   
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int _first = firstOccurance(arr, n, x);
        int _last = lastOccurance(arr, n, x);
        
        if(_first == -1 || _last == -1) return 0;
        else return (_last - _first + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
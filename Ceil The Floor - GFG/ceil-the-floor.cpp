//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int lowerBound(int arr[], int n, int x){
    // Your code here
    int ans = -1;
    int mid;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x){
    // Your code here
    int ans = -1;
    int mid;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            ans = arr[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr, arr+n);
    int _floor = lowerBound(arr, n, x);
    int _ceil = upperBound(arr, n, x);
    return {_floor, _ceil};
}
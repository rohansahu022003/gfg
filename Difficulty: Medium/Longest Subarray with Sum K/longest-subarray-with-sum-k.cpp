//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int sum=0;
        int maxlen=0;
        map<int, int>presummap;
        for(int i=0; i<arr.size();i++){
            sum+=arr[i];
            if(presummap.find(sum)==presummap.end()){
                presummap[sum]=i;
            }
            if(sum==k){
                maxlen=i+1;
            }
            int rem=sum-k;
            if(presummap.find(rem)!=presummap.end()){
                int len=i-presummap[rem];
                maxlen=max(maxlen, len);
            }
            
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
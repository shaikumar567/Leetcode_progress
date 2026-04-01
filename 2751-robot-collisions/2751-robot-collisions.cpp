class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<vector<int>> arr(n, vector<int>(4));

        for(int i = 0; i < n; i++) {
            arr[i][0] = positions[i];
            arr[i][1] = healths[i];
            arr[i][2] = directions[i]; // store as char (int)
            arr[i][3] = i; // original index
        }

        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        stack<int> st;

        for(int i = 0; i < n; i++) {
            int currDir = arr[i][2];

            if(currDir == 'R') {
                st.push(i);
            } else {
                while(!st.empty() && arr[i][1] > 0) {
                    int top = st.top();

                    if(arr[top][2] == 'L') break;

                    if(arr[top][1] > arr[i][1]) {
                        arr[top][1] -= 1;
                        arr[i][1] = 0;
                        break;
                    }
                    else if(arr[top][1] < arr[i][1]) {
                        arr[i][1] -= 1;
                        arr[top][1] = 0;
                        st.pop();
                    }
                    else {
                        arr[i][1] = 0;
                        arr[top][1] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }

        vector<int> res(n, -1);

        for(int i = 0; i < n; i++) {
            if(arr[i][1] > 0) {
                int idx = arr[i][3];
                res[idx] = arr[i][1];
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(res[i] != -1) {
                ans.push_back(res[i]);
            }
        }

        return ans;
    }
};
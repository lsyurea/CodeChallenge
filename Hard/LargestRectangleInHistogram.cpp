class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // store the indexes
        vector<int> stk;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            res = max(res, heights[i]);
            int last_pop = -1;
            while(!stk.empty() && heights[i] <= heights[stk.back()]) {
                int val = stk.back();
                last_pop = val;
                stk.pop_back();
                // need to update value everytime we pop
                if (!stk.empty()) res = max(res, heights[val] * (i - stk.back() - 1));
            }

            if (stk.empty()) {
                res = max(res, heights[i] * (i + 1));
                if (last_pop != -1) res = max(res, heights[last_pop] * i);
            }
            else {
                res = max(res, heights[i] 
                * (i - stk.back()));
                if (last_pop != -1)res = max(res, heights[i] * (i - last_pop + 1));
            }
            
            stk.push_back(i);
            // cout << res << '\n';
            // cout << "Here is the stack: ";
            // for (int j = 0; j < stk.size(); j++) cout << stk[j] << ' ';
            // cout << '\n';

        }
        // remaining stk not accounted for
        if (!stk.empty()) res = max(res, heights[stk[0]] * (int)heights.size());

        for (int i = 1; i < stk.size(); i++) {
            res = max(res, heights[stk[i]] * (stk[stk.size() - 1] - stk[i - 1]));
        }

        return res;
    }
};
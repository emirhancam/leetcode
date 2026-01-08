class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> result(n, 0); //Başlangıçta tüm elemanları 0 ile başlattık.
        stack<int> st; // Indexleri tutacak olan stack.

        for (int i=0; i<n; i++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return result;
    }
};

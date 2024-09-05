class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string prevStr = countAndSay(n-1);
        string temp = "";
        int i = 0 ;
        int j = 0 ;
        int m = prevStr.size();
        while(i < m and j < m)
        {
            char c = prevStr[i];
            while(i<m and prevStr[i] == c)
            {
                i++;
            }
            int cnt = i-j;
            temp.push_back('0' + cnt);
            temp.push_back(c);
            // i++;
            j=i;
        }
        cout<<temp<<" ";
        return temp;
    }
};
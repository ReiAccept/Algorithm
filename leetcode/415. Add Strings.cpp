class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()>num2.size()) {
            swap(num1,num2);
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans;
        bool flag=false;
        for(int i=0;i<num1.size();i++) {
            int x=flag+num1[i]-'0'+ num2[i]-'0';
            ans+=to_string(x%10);
            flag=(x>9);
        }
        for(int i=num1.size();i<num2.size();i++) {
            int x=flag+num2[i]-'0';
            ans+=to_string(x%10);
            flag=(x>9);
        }
        if(flag) {
            ans+='1';
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

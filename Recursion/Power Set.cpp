// TC : O(2^n) && SC : O(N)
class Solution{
	public:
	void solve(int i, string& curr, vector<string>& res, string s)
	{
	    if(i >= s.size())
	      return;
	      
	     curr.push_back(s[i]);
	     solve(i + 1, curr, res, s);

	     res.push_back(curr);
	     
	     curr.pop_back();
	     solve(i + 1, curr, res, s);
	}
	vector<string> AllPossibleStrings(string s){
	   vector<string> res;
	   string curr = "";
	   solve(0, curr, res, s);
	   sort(res.begin(), res.end());
	   return res;
	}
};

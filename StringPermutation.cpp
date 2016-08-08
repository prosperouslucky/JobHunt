#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> permute(string t)
{
	vector<string> ret;
	if(t.size() == 0)
	{
		return ret;
	}
	else if(t.size() == 1)
	{
		ret.push_back(t);
		return ret;
	}
	else
	{
		char a = t[0];
		// Trying permuations of remaining substring
		vector<string> p = permute(t.substr(1));
		vector<string>::iterator iter;
		for(iter = p.begin(); iter != p.end(); iter++)
		{
			string tmp = *iter;
			//Inserting extracted char in every possible position of all permutations
			for(unsigned i = 0; i <= tmp.size(); i++)
			{
				ret.push_back(tmp.substr(0, i) + a + tmp.substr(i)); 
			}
		}
		return ret;
	}
}

int main()
{
	string t;
	cin >> t;
	vector<string> ret = permute(t);
	
	vector<string>::iterator iter;
	for(iter = ret.begin(); iter != ret.end(); iter++)
	{
		cout << *iter << endl;
	}
	
    return 0;
}

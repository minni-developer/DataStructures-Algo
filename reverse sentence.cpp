#include <iostream>
#include <stack>
using namespace std;
void reverseStack(string s)
{
	stack<string>st;
	for(int i=0;i<s.length();i++)	
	{
		string word=" ";
		while(s[i]!=' ' && i<s.length())
		{
			word+=s[i];
			i++;
		}
		s.push_back(s);
	
	}
	while(!s.empty())
	{
		cout<<st.top();
		cout<<st.pop_str();
	}   cout<<"\n";
	
}

int main()
{
	string s="i am manahil";
	reverseStack(s);
	
}

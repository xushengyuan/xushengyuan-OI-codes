#include <bits/stdc++.h>
using namespace std;
string key,text;
int main()
{
	//freopen("in.txt","r",stdin);
	cin >>key>>text;
	for(int i=0;i<text.length();i++)
	{
		int key_p=i%key.length();
		char ans;
		if(islower(text[i]))
		{
			ans=26+text[i]-'a'-tolower(key[key_p])+'a';
			ans=ans%26+'a';
		}
		else
		{
			ans=26+text[i]-'A'-tolower(key[key_p])+'a';
			ans=ans%26+'A';
		}
		cout <<ans;
	}
	return 0;
}

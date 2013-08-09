#include<iostream>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	int test_cases;
	string str,word;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		int size=0,count=0,max=0;
		getline(cin,str);
		if(str=="")
		{
			test_cases++;
			continue;
		}
		istringstream iss(str, istringstream::in);
		while(iss>>word)
		{
			if(word.length()==size) 
				count++;
			else
			{
				size=word.length();
				count=1;
			}
			if(count>max) 
				max=count;
		}
		printf("%d\n",max);
	}
	return 0;
}

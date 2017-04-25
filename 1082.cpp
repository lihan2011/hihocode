#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	while(getline(cin,str)){
		for (int i = 0; i < str.length(); ++i)
		{
			string temp = str.substr(i,9);
			std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
			if(temp=="marshtomp"){
				str.replace(i,9,"fjxmlhx");
			}
		}
		cout << str<<endl;
	}
	return 0;
}
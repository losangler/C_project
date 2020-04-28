#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[90];
	gets(str);
	int len = strlen(str), r = 0, h = 0;
	char ans[90][90];
	//strlen会忽略最后一个\0的长度
	for(int i = 0; i <= len; i++)
	{
		if(str[i] != ' ')
		{
			ans[r][h++] = str[i];
		}else{
			ans[r][h] = '\0';
			r++;
			h = 0;
		}
	}

	for(int i = r; i >= 0; i--)
	{
		cout << ans[i];
		if(i > 0)
			cout << " ";
	}

	cin.get();

    return 0;
}

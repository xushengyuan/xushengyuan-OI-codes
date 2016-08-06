#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[20];
    int len,i,n;
    scanf("%s",s);
    len=strlen(s);
    if(s[0]=='-')
    {
    	printf("-");
	}
	i=len-1;
	while(s[i]=='0')
		i--;
    for(i=i;i>=0;i--)
    {
    	if(isdigit(s[i]))
    		printf("%c",s[i]);
	}
    return 0;
}

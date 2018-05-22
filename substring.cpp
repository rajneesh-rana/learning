#include <stdio.h>
#include <string.h>

int main()
{
 char str[20]="love";
 char s[20][20];
 int l=strlen(str);
 int cnt=0;
 int i=0,j=0,k=0,m;
 for(i=0;i<l;i++)
 {
	 for(j=0;j<l-i;j++){
		for(m=0,k=i;k<(l-j);k++,m++)
			s[cnt][m]=str[k];
			s[cnt][m]='\0';
		cnt++;
	}
 }
 for(i=0;i<cnt;i++)
  printf("%d %s\n",i,s[i]);
	return 0;
}



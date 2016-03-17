#include <stdio.h>
int main(){
	char s[2056]="\0";
	int i=0;
	gets(s);
	for(i=0;i<2056;i++){
		if(s[i]=='\0')	break;
		if('a'<=s[i]&&s[i]<='z'){
			s[i]='A'+(s[i]-'a');
		}
	}
	puts(s);
	return 0;
}

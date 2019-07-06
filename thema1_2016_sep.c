#include <stdio.h>
int parentheses = 0;
char c;

int scanner() {
	//printf("%c", c);
	if (c == '-' || c == '+') {
		c = getchar();
		if (c >= '0' && c <= '9') {
			do {
				c = getchar();
			} while (c >= '0' && c <= '9');
			return scanner();
		} else if (c == '(') {
			parentheses++;
			c = getchar();
			return scanner();
		}  else {
			return -1;
		}
	} else if (c == ')') {
		parentheses--;
		c = getchar();
		return scanner();
	} else if (c == '.') {
		if (parentheses == 0) return 1;
		else return -1;
	} else {
		return -1;
	}
}

int main() {
	c = getchar();
	if (scanner() == 1) printf("OK\n");
	else printf("NOT OK\n");
	
	return 0;
}

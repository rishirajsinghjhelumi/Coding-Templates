#include <stdio.h>

int main() {
	int cur, ma, T, prev, con;
	char c;
	scanf("%d", &T);
	while(T--){
		scanf(" ");
		cur = 0;
		ma = 0;
		prev = -1;
		con = 0;
		while (c = getchar ()) {
			if (! isalpha (c)) {
				if (prev == cur && ++con> ma) ma = con;
				else if (prev != cur) {
					prev = cur;
					con = 1;
				}
				cur = 0;
				if (c != ' ') {
					break;
				}
			}
			else {
				cur++;
			}
		}
		printf ("%d\n", ma);
	}
	return 0;
}

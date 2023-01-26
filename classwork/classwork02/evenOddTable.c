#include <stdio.h>
#include <string.h>

int main() {
	for(int i = -10; i <= 10; i++) {
		printf("%d\t\t%d\t\t%s\n", i, i*i, i % 2 == 0 ? "EVEN" : "ODD");
	}
}
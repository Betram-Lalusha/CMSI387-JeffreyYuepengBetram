#include <stdio.h>
#include <string.h>

#define START -10
#define END 10
#define TOTAL (END - START + 1)
#define ODDS (TOTAL/2 + (TOTAL % 2)*(END % 2))
#define EVENS (TOTAL - ODDS)
//Note: above will be wrong if END < 0 and odd or if START > END + 1.
//Square the END % 2 term to fix the former

int main() {
	for(int i = START; i <= END; i++) {
		printf("%d\t\t%d\t\t%s\n", i, i*i, i % 2 == 0 ? "EVEN" : "ODD");
	}
	printf("# odd numbers = %d\n# even numbers = %d", ODDS, EVENS);
}
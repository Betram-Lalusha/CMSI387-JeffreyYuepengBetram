#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int fish[25] = {-9999, -9999, -9999, -9999, -9999,
					-9999, -9999, -9999, -9999, -9999,
					-9999, -9999, -9999, -9999, -9999,
					-9999, -9999, -9999, -9999, -9999,
					-9999, -9999, -9999, -9999, -9999 }; //known unused value
	printf("Enter up to 25 numbers. Enter -9999 to exit.\n");
	
	int i;
	
	for (i = 0; i < 25; i++) {
		char buffer[256];
		gets(buffer);
		if(!strcmp(buffer, "-9999")) { break; } //strcmp == 0 on positive match, 0 == false in C
		fish[i] = atoi(buffer);
	}
	
	int sum = 0;
	int count = 0;
	
	for (i = 0; fish[i] != -9999 && i < 25; i++) {
		sum += fish[i];
		count++;
	}
	
	char longStr[256] = "";
	char buffer[16];
	
	for (i = 0; fish[i] != -9999 && i < 25 ; i++) {
		strcat(longStr, itoa(fish[i], buffer, 10));
	}
	
	int sevenCount = 0;
	for (i = 0; i < strlen(longStr)/*longStr[i] != '\0' is technically better*/; i++) {
		if (longStr[i] == '7') { sevenCount++; }
	}
	
	printf( "Numbers sum to %d and average to about %.2f\n", sum, (double)sum/count );
	printf( "I can shove them into the string %s that contains %d 7s", longStr, sevenCount );
	
}
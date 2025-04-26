#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	
	FILE* arq = fopen("10000000.txt", "w");
	
	for (int i = 0; i < 10000000 - 1;  i++)
		fprintf(arq, "%d,", (rand() % 10000 + 1));
		
	fprintf(arq, "%d", (rand() % 10000 + 1));
	
	fclose(arq);
	
	return 0;
}

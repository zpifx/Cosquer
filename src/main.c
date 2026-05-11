#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_READ		4096

char *ReadFile(const char *fpath) {
	FILE *fptr;
	long size;
	char *buffer;

	fptr = fopen(fpath, "r");
	if (!fptr) {
		perror("fopen");
		exit(1);
	}

	fseek(fptr, 0, SEEK_END);
	size = ftell(fptr);
	rewind(fptr);

	buffer = malloc(size + 1);
	fread(buffer, 1, size, fptr);
	buffer[size] = '\0';
	fclose(fptr);

	return buffer;
}


int main(int argc, char *argv[]) {
	char *fileData;
	
	if (argc < 2) {
		printf("Too few arguments!\n");
		exit(1);
	}
	
	fileData = ReadFile(argv[1]);
	
	printf("%s", fileData);

	return 0;
}

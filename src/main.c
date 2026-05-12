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

int GetLine(char *largeBuffer, int lineNumber, char *StrBuffer) {
	int nlCount = 0;
	int charNum = 0;
	int lineStart = 0;

	char chrBuffer = 1;
	int lineLen = 0;
	char *subst;

	while (nlCount < lineNumber) {
		if (largeBuffer[charNum] == '\n' ) nlCount++;
		else if (largeBuffer[charNum] == '\0') return 1;
		charNum++;
	}

	lineStart = charNum;

	while (chrBuffer != '\n') {
		chrBuffer = largeBuffer[charNum];
		charNum++;
		lineLen++;
	}

	subst = largeBuffer + lineStart;
	snprintf(StrBuffer, lineLen, subst);
	StrBuffer[lineLen] = '\0';

	return 0;
}

int main(int argc, char *argv[]) {
	char *fileData;
	char curLine[256];
	int i = 0;
	int ret = 0;

	if (argc < 2) {
		printf("Too few arguments!\n");
		exit(1);
	}
	
	fileData = ReadFile(argv[1]);
	
	/* printf("%s", fileData); */

	while (ret == 0) {
		ret = GetLine(fileData, i, curLine);
		printf("%s\n", curLine);
		i++;
	}

	return 0;
}

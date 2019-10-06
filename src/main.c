#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int timeStart; // timer for translation time

struct bitVariable {
	char* name;
	int type; // 0 - memory, 1 - system, 2 - step
	int local; // 0 - local
};

// FIX ME
//struct bitVariable* bitVariables[20]; // array of bit variables, 20 max for the moment. index says which pin is it

void mapBitVariable(char* VarName, int type, int local){
	// here we have to check available addresses of bit variable
	printf("Mapping %s to %%%c%d\n", VarName, 0, 0);
	// here we should map it to some global map, so later it will be written to ladder code, and map list
}

void finish(int i){
	printf("Stop! Operation took: %d seconds\n", (int)time(NULL)-timeStart);
	exit(i);
}

int main(int argc, char* argv[]) {
	printf("LDC Code translator\n");
	if(argc < 2){
		printf("Usage: ldc <file_input>\n\n");
		exit(1);
	}

	printf("Filename: %s\n", argv[1]);
	timeStart = (int)time(NULL);
	printf("Timer start at: %d\n", timeStart);
	
	// Open file
	FILE *codeFile = fopen(argv[1], "r");
	if(codeFile == NULL){
		printf("Error! File does not exist!\n");
		finish(1);
	}

	// Start reading the code, line by line
	// (there was an idea to read from ; to ;, but im too lazy)
	char* codeLine = NULL;
	size_t len = 0;
	ssize_t read;

	char* buffPointer = NULL;

	// Read loop
	while((read = getline(&codeLine, &len, codeFile)) != -1){
		// Ignore comments
		// (Literally put \0 in "/" place)
		buffPointer = strchr(codeLine, '/');
		if(buffPointer != NULL)
			codeLine[buffPointer-codeLine] = '\0';
		
		// Map variables
		// Bit
		buffPointer = strstr(codeLine, "bit");
		if(buffPointer != NULL){
			// Check for type of bit // TODO FINISH ME PLEASE
			char* bitLocation = buffPointer;
			if(strncmp(codeLine, "memory", 6) == 0){
			}else if(strncmp(codeLine, "system", 6) == 0){
			}else if(strncmp(codeLine, "step", 4) == 0){
			}else finish(2);
		}

		printf("%s", codeLine);
	}

	finish(0);
}

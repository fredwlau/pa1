#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv){
	
	
	if (argc < 2){
		
		printf("error \n");
		exit(0); 
		
	}
	int i = 0;
	
	char * output = (char *) malloc(sizeof(char)*(argc));
	
	for (i = 0; i < argc-1; i++){
		
		output[i] = argv[i+1][strlen(argv[i+1])-1];
		
	}
	
	output[argc-1] = '\0';
	printf("%s\n", output);
	return 0;
}
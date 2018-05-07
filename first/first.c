#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv){
	if (argc!=2){
		printf("error \n");
		exit (0);
	
	}
	
	int value=atoi(argv[1]);
	if (value<2){
		printf("no \n");
		exit (0);
	}
	if (value==2||value==3){
		printf("yes \n");
		exit (0);
	
	}
	
	else{
		int i;
		for (i=2;i<value;i++){
			if (value%i==0){
				printf("no \n");
				exit (0);
				}
				
		}	
		
		printf("yes\n");
		
	}
	
		
	return 0;
	
	
}
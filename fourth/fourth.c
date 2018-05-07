#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv){
	if (argc!=2){
		printf("error \n");
		exit (0);
	
	}
	
	FILE *fp;
	fp=fopen(argv[1], "r");
	if (fp==NULL){
		printf ("error \n");
		exit (0);
	
	}
	else{
		int ** resultmatrix;
		int row=0, column=0;
		int i, j;
		
		
		fscanf(fp, "%d\t%d", &row, &column);
		
		resultmatrix=(int**)malloc(sizeof(int*)*row);
		
		for (i=0; i<row; i++){
			resultmatrix[i]=(int*)malloc(sizeof(int)* column);
		
		}
		
		for (i=0; i<row; i++){
			for (j=0; j<column; j++){
				fscanf(fp, "%d", &resultmatrix[i][j]);
			
			}
		}
		
		for (i=0; i<row; i++){
			for (j=0; j<column; j++){
				int sum=0;
				fscanf(fp, "%d", &sum);
				resultmatrix[i][j]=resultmatrix[i][j]+sum;
			
			}
		
		}
		
		for (i=0; i<row; i++){
			for (j=0; j<column; j++){
				printf ("%d\t", resultmatrix[i][j]);
			
			}
			printf("\n");
		
		}	
	
	
	}
	fclose (fp);
	return 0;
}
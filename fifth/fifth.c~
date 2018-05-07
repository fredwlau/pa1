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
		int **matrix1, **matrix2, **resultmatrix;
		int row1=0, column1=0, row2=0, column2=0, val=0, i, j, k;
		
		fscanf(fp, "%d\t%d", &row1, &column1);
		matrix1=(int**)malloc(sizeof(int*)*row1);
		
		for (i=0; i<row1; i++){
			matrix1[i]=(int*)malloc(sizeof(int)*column1);
		
		}
		for(i=0; i<row1; i++){
			for(j=0; j<column1; j++){
				fscanf(fp, "%d", &matrix1[i][j]);
			
			}
		}
		
		fscanf(fp, "%d\t%d", &row2, &column2);
		
		if (column1!=row2){
			printf("error \n");
			exit(0);
		
		}
		matrix2=(int**)malloc(sizeof(int*)*row2);
		
		for (i=0; i<row2; i++){
			matrix2[i]=(int*)malloc(sizeof(int)*column2);
		
		}
		
		for (i=0; i<row2; i++){
			for (j=0; j<column2; j++){
				fscanf(fp, "%d", &matrix2[i][j]);
			
			}
		
		}
		
		resultmatrix=(int**)malloc(sizeof(int*)*row1);
		
		for (i=0; i<row1; i++){
			resultmatrix[i]=(int*)malloc(sizeof(int)*column2);
		
		}
		
		for(i=0; i<row1; i++){
			for (j=0; j<column2; j++){
				for(k=0; k<row2; k++){
					val=val+matrix1[i][k]*matrix2[k][j];
				
				}
				
				resultmatrix[i][j]=val;
				val=0;
			
			}
		
		}
		
		for (i=0; i<row1; i++){
			for (j=0; j<column2; j++){
				printf("%d\t", resultmatrix[i][j]);
			
			}
			printf("\n");
		
		}
		
		
		
		}
	return 0;	
	
	}
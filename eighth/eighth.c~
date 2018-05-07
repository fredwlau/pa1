#include <stdio.h>
#include <stdlib.h>

struct btnode{
	int data;
	int height;
	struct btnode* leftchild;
	struct btnode* rightchild;

};

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
		
		char choice = 'a';
		int value = 0;
		int heightcounter=0;
		
		struct btnode *root=NULL;
		
		while (fscanf(fp, "%c\t%d\r", &choice, &value)!=EOF){
			
			if (choice !='i'&& choice!='s'){
				printf("error \n");
				continue;
			
			}
			else{
				if (choice=='i'){
					
					if(root==NULL){
						struct btnode *temp;
						temp=(struct btnode*)malloc(sizeof(struct btnode));
						temp->data=value;
						temp->height=1;
						temp->leftchild=(struct btnode*)malloc(sizeof(struct btnode));
						temp->rightchild=(struct btnode*)malloc(sizeof(struct btnode));

						root=temp;
						heightcounter=root->height;
						
						printf("inserted %d\n", temp->height);
						
						continue;
					}
					else {
						struct btnode *temp2=(struct btnode*)malloc(sizeof(struct btnode));
						temp2=root;
						int duplicate=0;
						heightcounter=root->height;
						while(temp2->leftchild!=NULL||temp2->rightchild!=NULL){
							
							if(value==temp2->data){
								printf("duplicate \n");
								duplicate=1;
								break;
							
							}
							else if(value<temp2->data){
								
								temp2=temp2->leftchild;
								heightcounter++;
								
							
							}
							else if (value>temp2->data){
								
								temp2=temp2->rightchild;
								heightcounter++;
							
							}
						
						}
						
						if(duplicate==0){
							temp2->data=value;
							temp2->height=heightcounter;
							temp2->leftchild=(struct btnode*)malloc(sizeof(struct btnode));
							temp2->rightchild=(struct btnode*)malloc(sizeof(struct btnode));
							printf("inserted %d\n", temp2->height);
						
						continue;}
					}	
				
				}
				else{
					
					if (root==NULL){
						
						printf("absent \n");
						continue;
					
					}
					else{
						
						struct btnode *temp=(struct btnode*)malloc(sizeof(struct btnode));
						temp=root;
						heightcounter=root->height;
						int present=0;
						while(temp->leftchild!=NULL||temp->rightchild!=NULL){
							if(value==temp->data){
								printf("present %d\n", heightcounter);
								present=1;
								break;
							
							}
							else if(value<temp->data){
								heightcounter++;
								temp=temp->leftchild;
								continue;
								
							}
							else if(value>temp->data){
								heightcounter++;
								temp=temp->rightchild;	
								continue;
							}
				
				
						}
				
						if (present==0){
							printf("absent \n");
						
						}
			
					}
				}
	
			}
			
		}
	}
	fclose(fp);
return 0;
}
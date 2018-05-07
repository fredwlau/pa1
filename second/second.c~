#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;

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
	
	else {
		char choice='a';
		int value=0;
		struct node *root=NULL, *temp=NULL, *current=NULL, *previous=NULL;
		
		while (fscanf(fp, "%c\t%d\r", &choice, &value)!=EOF){
			
			if (choice !='d'&& choice!='i'){
				printf("error \n");
				exit(0);
			
			}
			
			if (root==NULL){
				if(choice=='d'){
					continue;
				}
				else {
					temp=(struct node*) malloc(sizeof(struct node));
					temp->data=value;
					temp->next=NULL;
					root=temp;
					temp=temp->next;
				
				}
			
			
			}
			else {
				if (choice=='d') {
					current = root;
				
					while (current!=NULL){
						
						if (current->data==value){
							if (current==root){
								root=root->next;
								free(current);
								break;
							
							}
						
						else{
							previous->next=current->next;
							free(current);
							break;
						}
						
						}
						previous=current;
						current=current->next;
					
				}
			}	
				else{
					current=root;
				
					if (value<current->data){
						current=(struct node*)malloc(sizeof(struct node));
						current->data=value;
						current->next=root;
						root=current;
					
					
					}
					else {
						while(value>=current->data){
							if(value==current->data){
								break;
							
							}
							previous=current;
							current=current->next;
							
							if (current==NULL||value<current->data){
								temp=(struct node*)malloc(sizeof(struct node));
								temp->data=value;
								previous->next=temp;
								temp->next=current;
								break;
							
							}
						}
					}
				}
			}
		}
		fclose(fp);
		while(root!=NULL){
	
			printf("%d", root->data);
			root=root->next;
			
			if(root!=NULL){
			printf("\t");
		}
			}
	}
	

	
return 0;

}



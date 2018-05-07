#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;

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
		int value = 0, i;
		
		struct node *hashtable[10000];
		
		for (i=0; i<10000; i++){
			hashtable[i]=NULL;
		
		}
		
		while (fscanf(fp, "%c\t%d\r", &choice, &value)!=EOF){
			
			if (choice !='i'&& choice!='s'){
				printf("error \n");
				continue;
			
			}
			else{
				if (choice=='i'){
					
					if(hashtable[abs(value)%10000]==NULL){
						struct node *temp;
						temp=(struct node*)malloc(sizeof(struct node));
						temp->data=value;
						temp->next=NULL;

						hashtable[abs(value)%10000]=temp;
						
						printf("inserted \n");
						continue;
					}
					else {
						struct node *temp4=(struct node*)malloc(sizeof(struct node));
						temp4=hashtable[abs(value)%10000];
						while(temp4!=NULL){
							if (value==temp4->data){
								
								printf("duplicate \n");
								
								break;
							
							}
							else if (temp4->next==NULL){
								struct node *temp2=(struct node*)malloc(sizeof(struct node));
								temp2->data=value;
								temp2->next=NULL;
								temp4->next=temp2;
								printf("inserted \n");
								break;								
							
							}
						temp4=temp4->next;
						
						}
						
					
					}
					
				
				
				}
				else{
					
					if (hashtable[abs(value)%10000]==NULL){
						
						printf("absent \n");
						continue;
					
					}
					else{
						
						struct node *temp3=(struct node*)malloc(sizeof(struct node));
						temp3=hashtable[abs(value)%10000];
						
						
						while (temp3!=NULL){
							
							if (value==temp3->data){
								
								printf ("present \n");
								break;
							
							}
							else{
								temp3=temp3->next;
								if (temp3==NULL){
									printf ("absent \n");
								
								}
								
							
							}
						
						}
						
						
					
					}
				
				
				}
				
			
			
			}
		}
	
	}
	fclose(fp);
	return 0;
}
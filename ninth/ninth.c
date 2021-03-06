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
			
			if (choice !='i'&& choice!='s'&& choice!='d'){
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
				else if(choice=='s'){
					
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
				
				else if(choice=='d'){
					
					if(root==NULL){
						printf("fail \n");
						break;
					}
					
					else{
						struct btnode* current=(struct btnode*)malloc(sizeof(struct btnode));
						struct btnode* previous=(struct btnode*)malloc(sizeof(struct btnode));
						current=root;
						int deleted=0;
						
						//first check to see if root is the only node and it contains data to be deleted
						
						if(current->leftchild->leftchild==NULL&&current->rightchild->rightchild==NULL){
							if (value==current->data){
								root=NULL;
								printf("success \n");
								deleted=1;
								continue;
							}
							else {
								printf("fail \n");
								continue;
							}	
						}
						//then check to see if root contains data to be deleted and if it has a right or left subtree or both
						if (value==current->data){
							if(current->leftchild->leftchild!=NULL||current->rightchild->rightchild!=NULL){
								
								if(current->rightchild->rightchild==NULL){
									current->data=current->leftchild->data;
									current->leftchild=current->leftchild->leftchild;
									deleted=1;
									printf("success \n");
									continue;
								
								}
							//marker
								//root node is the node to be deleted and it has only a right subtree or two subtrees
							else if(current->leftchild->leftchild==NULL){
								struct btnode*succ=(struct btnode*)malloc(sizeof(struct btnode));
								succ=current->rightchild;
								//this checks to see if successor has a left child
								if(succ->leftchild->leftchild==NULL){
									//if we get here we know that successor has no left child and no right child ie it is a leaf node
									if(succ->rightchild->rightchild==NULL){
										current->data=succ->data;
										current->rightchild=succ->rightchild;
										deleted=1;
										printf("success \n");
										continue;
												
									}
									//if we get here we know that successor has no left child but DOES have a right subtree
									else if(succ->rightchild->rightchild!=NULL){
										current->data=succ->data;
										current->rightchild=succ->rightchild;
										deleted=1;
										printf("success \n");
										continue;
										}		
									}			
								}
							
								//if we get here we know successor has two subtrees
							else {	
								struct btnode* succ=(struct btnode*)malloc(sizeof(struct btnode));
								succ=current->rightchild;
								while(succ->leftchild->leftchild!=NULL){
									previous=succ;
									succ=succ->leftchild;
											
								}
								//if we get here we know we have successor which is the leftmost node of the right subtree
								if (succ->leftchild->leftchild==NULL){
									//succ has right subtree
									if(succ->rightchild->rightchild!=NULL){
										current->data=succ->data;
										previous->leftchild=succ->rightchild;
										deleted=1;
										printf("success \n");
										continue;
												
									}
									//succ is leaf node
									else if(succ->rightchild->rightchild==NULL){
										current->data=succ->data;
										previous->leftchild=(struct btnode*)malloc(sizeof(struct btnode));
										deleted=1;
										printf("success \n");
										continue;
											
									}		
								}	
							}	
						}
					}			
				
						
					
					else{
							//shit hits the fan
							
							//if we get to this point, we know the root is not the one to be deleted and root has at least one subtree or it can have two
						while (current->leftchild->leftchild!=NULL||current->rightchild->rightchild!=NULL){
								
								
							if (value<current->data){
								previous=current;
								current=current->leftchild;
									
									if(value!=current->data){
										continue;
									
									}
									if(value==current->data){
										if (current->leftchild->leftchild==NULL&&current->rightchild->rightchild==NULL){
											if(previous->rightchild==current){
												previous->rightchild=(struct btnode*)malloc(sizeof(struct btnode));
												deleted=1;
												printf("succcess \n");
												break;
											}
											else{
												previous->leftchild=(struct btnode*)malloc(sizeof(struct btnode));
												deleted=1;
												printf("succcess \n");
												break;
											}
										}
										//if we get to this point we know that the node to be deleted has at least one subtree, we now determine whether it is a left or a right or both
										else if(current->rightchild->rightchild==NULL){
											if(previous->rightchild==current){
												previous->rightchild=current->leftchild;
												deleted=1;
												printf("succcess \n");
												break;
											}
											else if(previous->leftchild==current){
												previous->leftchild=current->leftchild;
												deleted=1;
												printf("succcess \n");
												break;
											}
											
										
										}
										//if we get to this point we know that the node to be deleted has a RIGHT subtree OR two subtrees
										else{
											struct btnode*succ=(struct btnode*)malloc(sizeof(struct btnode));
											succ=current->rightchild;
											if(succ->leftchild->leftchild==NULL){
												//succ is a leaf node
												if(succ->rightchild->rightchild==NULL){
													current->data=succ->data;
													current->rightchild=succ->rightchild;
													deleted=1;
													printf("success \n");
													break;
												
												}
												//succ has a right subtree
												else if(succ->rightchild->rightchild!=NULL){
													current->data=succ->data;
													current->rightchild=succ->rightchild;
													deleted=1;
													printf("success \n");
													break;
												
												}
											
											
											}
											while(succ->leftchild->leftchild!=NULL){
												previous=succ;
												succ=succ->leftchild;
											
											}
											if (succ->leftchild->leftchild==NULL){
												if(succ->rightchild->rightchild!=NULL){
													current->data=succ->data;
													previous->leftchild=succ->rightchild;
													deleted=1;
													printf("success \n");
													break;
												
												}
												else if(succ->rightchild->rightchild==NULL){
													current->data=succ->data;
													previous->leftchild=(struct btnode*)malloc(sizeof(struct btnode));
													deleted=1;
													printf("success \n");
													break;
												
												}
											
											}
											
										
										
										}
											
										
										}
									
									}
								
								if (value>current->data){
									previous=current;
									current=current->rightchild;
									if (value!=current->data){
										continue;
									
									}
									else if (value==current->data){
										//node to be deleted is a leaf node
										if (current->leftchild->leftchild==NULL&&current->rightchild->rightchild==NULL){
											//node to be deleted is a right child of parent
											if(previous->rightchild==current){
												previous->rightchild=(struct btnode*)malloc(sizeof(struct btnode));
												deleted=1;
												printf("succcess \n");
												break;
											}
											//node to be deleted is a left child of parent
											else{
												previous->leftchild=(struct btnode*)malloc(sizeof(struct btnode));
												deleted=1;
												printf("succcess \n");
												break;
											}
										}
										//if we get to this point we know that the node to be deleted has at least one subtree, we now determine whether it is a left or a right or both
										else if(current->rightchild->rightchild==NULL){
											//we know that the node to be deleted has a left subtree and that the node is a right child of parent
											if(previous->rightchild==current){
												previous->rightchild=current->leftchild;
												deleted=1;
												printf("succcess \n");
												break;
											}
											//we know that the node to be deleted is a left child of parent
											else if(previous->leftchild==current){
												previous->leftchild=current->leftchild;
												deleted=1;
												printf("succcess \n");
												break;
											}
											
										
										}
										//if we get to this point we know that the node to be deleted has a RIGHT subtree OR two subtrees
										else{
											struct btnode*succ=(struct btnode*)malloc(sizeof(struct btnode));
											succ=current->rightchild;
											//successor has no left children
											if(succ->leftchild->leftchild==NULL){
												//successor is a leaf node
												if(succ->rightchild->rightchild==NULL){
													current->data=succ->data;
													current->rightchild=succ->rightchild;
													deleted=1;
													printf("success \n");
													break;
												
												}
												//successor has no left children but has a right subtree
												else if(succ->rightchild->rightchild!=NULL){
													current->data=succ->data;
													current->rightchild=succ->rightchild;
													deleted=1;
													printf("success \n");
													break;
												
												}
											
											
											}
											//successor has a left subtree
											while(succ->leftchild->leftchild!=NULL){
												previous=succ;
												succ=succ->leftchild;
											
											}
											//double checks to make sure we found successor
											if (succ->leftchild->leftchild==NULL){
												//we found the left most value of the right subtree ie successor, this checks to see if the left most node has any right children
												if(succ->rightchild->rightchild!=NULL){
													current->data=succ->data;
													previous->leftchild=succ->rightchild;
													deleted=1;
													printf("success \n");
													break;
												
												}
												//successor has no right subtree
												else if(succ->rightchild->rightchild==NULL){
													current->data=succ->data;
													previous->leftchild=(struct btnode*)malloc(sizeof(struct btnode));
													deleted=1;
													printf("success \n");
													break;
												
												}
											
											}
											
										
										
										}
											
										
										
									
									}
									
									
									}
								}
								if(deleted==0){
							printf("fail \n");
						
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
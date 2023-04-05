/*
File Name		: DinamicNonBinaryTree.cpp
Description		: 
Author			: Garly Nugraha & Nazwa Fitriyani Zahra
Editor			: 
Created at		: 13/04/2022
Updated at		: 18/05/2022
*/

/* ========== Header File ========== */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "DinamicNonBinaryTree.h"
#include "Welcome.h"
/* ======= End of Header File ====== */

void Create(DataTree *Tree) {
	(*Tree).Root = NULL;
}

bool IsEmpty(DataTree Tree) {
	return Tree.Root == NULL;
}

TNBTree* Allocation(InfoType Name, bool Gender, int Age) {
	TNBTree *NewNode = (TNBTree*)malloc(sizeof(TNBTree));
	
	strcpy(Name(NewNode), Name);
	FirstSon(NewNode) = NULL;
	NextBrother(NewNode) = NULL;
	Parent(NewNode) = NULL;
	Pair(NewNode) = NULL;
	Gender(NewNode) = Gender;
	Status(NewNode) = false;
	Age(NewNode) = Age;
	
	return NewNode;
}

TNBTree* Search(DataTree Tree, InfoType Name) {
	TNBTree *Node = Tree.Root;
	
	while(Node != NULL) {
		if(strcmp(Name(Node), Name) == 0) {
			return Node;
		}
		
		if(FirstSon(Node) != NULL) {
			Node = FirstSon(Node);
		} else {
			if(NextBrother(Node) != NULL) {
				Node = NextBrother(Node);
			} else {
				while(NextBrother(Node) == NULL && Node != Tree.Root) {
					Node = Parent(Node);
				}
				
				Node = NextBrother(Node);
			}
		}
	}
	
	return NULL;
}

void Insert(DataTree *Tree) {
	TNBTree *NewNode, *Temp;
	InfoType Name, Parent;
	char JenisKelamin;
	bool Gender;
	int Age;
	
	if(IsEmpty(*Tree)) {
		fflush(stdin);
		printf("Name	: ");
		gets(Name);
		
		do {
			printf("Age (Minimum King Age 60 Years)	: ");
			scanf("%d", &Age);
			fflush(stdin);
		}while(Age <= 59);
		
		Gender = true;
		
		NewNode = Allocation(Name, Gender, Age);
		(*Tree).Root = NewNode;
		
		printf("\n\n");
		printf("Node Becomes Root Because Tree is Empty...!!! \n");
		printf("Press Any Key to continue . . .");
		getche();
		 		
		system("cls");
	} else {
		fflush(stdin);
		printf("Name	: ");
		gets(Name);
		
		do {
			fflush(stdin);
			printf("Gender (M/F)	: ");
			JenisKelamin = toupper(getche());
		}while(JenisKelamin != 'M' && JenisKelamin != 'F');
		
		printf("\n");
		printf("Age	(Minimum age gap of 20 years with parents) : ");
		scanf("%d", &Age);
		fflush(stdin);
		
		NewNode = Allocation(Name, JenisKelamin == 'M', Age);
		
		do{
			fflush(stdin);
			printf("Parent	: ");
			gets(Parent);
		}while(Search(*Tree, Parent) == NULL);
		
		Temp = Search(*Tree, Parent);
		
		if(Temp->Pair != NULL) {
			if((Temp->Age - 20) > NewNode->Age) {
				Parent(NewNode) = Temp;
				
				if(FirstSon(Temp) == NULL) {
					FirstSon(Temp) = NewNode;
					
					printf("\n\n");
					printf("Node with name %s successfully added with parent %s \n", Name, Parent);					
					printf("Press Any Key to continue . . .");
			 		getche();
			 		
			 		system("cls");
				} else {
					if(Temp->FirstSon->Age >= NewNode->Age) {
						Temp = FirstSon(Temp);
						
						while(NextBrother(Temp) != NULL) {
							Temp = NextBrother(Temp);
						}
						
						NextBrother(Temp) = NewNode;
						
						printf("\n\n");
						printf("Node with name %s successfully added with parent %s \n", Name, Parent);
						printf("Press Any Key to continue . . .");
		 				getche();
		 		
		 				system("cls");
					} else {
						printf("\n\n");
						printf("ERROR : The age of the next child must not be more than the age of the previous child...!!! \n");
						printf("Press Any Key to continue . . .");
				 		getche();
				 		
				 		system("cls");
					}
				}
			} else {
				printf("\n\n");
				printf("ERROR : The distance between age and child is at least 20 years...!!! \n");
				printf("Press Any Key to continue . . .");
		 		getche();
		 		
		 		system("cls");
			}
		} else {
			printf("\n\n");
			printf("ERROR : Can't have children because they don't have a partner...!!! \n");
			printf("Press Any Key to continue . . .");
		 	getche();
		 	system("cls");
		}
	}
}

void InsertWife(DataTree *Tree) {
	TNBTree *newNode, *Temp;
	InfoType Name, Husband;
	char JenisKelamin;
	bool Gender;
	int Usia;

	if (!IsEmpty(*Tree)) {
		fflush(stdin);	
		printf("Name	: ");
		gets(Name);
		
		fflush(stdin);
	   	printf("Age (The age of the Wife must be the same as the age of the Husband)	: ");
	    scanf("%d", &Usia);
	    
        JenisKelamin = 'L';
        
        newNode = Allocation(Name, JenisKelamin == 'F', Usia);
        
        printf("\n");
        printf("A husband can only have one wife.\n");
        
        fflush(stdin);
        printf("Wife of : ");
        gets(Husband);
        
        if(Search(*Tree, Husband) == NULL) {
        	printf("Husband not found, maybe he doesn't love you\n");
        	system("pause");
        	system("cls");
			free(newNode);
		} else {
			Temp = Search(*Tree,Husband);
			
			if(Age(Temp) != Age(newNode)) {
            	printf("The age between couples should be the same.\n");
            	system("cls");
				free(newNode);
        	} else {
       			if (Gender(Temp) == false) {
           			printf("This government rejects lesbians");
            		system("cls");
					free(newNode);
       			} else if (Pair(Temp) != NULL) {
	            	printf("Sorry he already has a wife");
	            	system("cls");
					free(newNode);
				} else {
		            Pair(Temp) = newNode;
		            Status(Temp) = true;
		            
		            printf("\n\n");
		            printf("Yey... Wishing the both of you all the love and happiness in the world and congratulations on your marriage\n");
		            system("pause");
					system("cls");
        		}
        	}	
		}
	}   
}
    
void InsertHusband(DataTree *Tree) {
	TNBTree *newNode, *Temp;
	InfoType Name, Pair;
	char JenisKelamin;
	bool Gender;
	int Usia;
	
	if(!IsEmpty(*Tree)) {
		fflush(stdin);
		printf("Name : ");
		gets(Name);
		
		fflush(stdin);
		printf("Age (The age of the Husband must be the same as the age of the Wife) : ");
		scanf("%d", &Usia);
		
		JenisKelamin = 'M';
		newNode = Allocation(Name, JenisKelamin == 'M', Usia);
		
		printf("\n");
		printf("A wife can only have one husband.");
		
		printf("\n");
		
		fflush(stdin);
		printf("Husband of : ");
		gets(Pair);
		
		if(Search(*Tree, Pair) == NULL) {
			printf("Wife not found, maybe he doesn't love you");
        	system("cls");
					free(newNode);
		} else {
			Temp = Search(*Tree, Pair);
		
			if(Age(Temp) != Age(newNode)) {
				printf("The age of the couple should be the same");
				system("cls");
				free(newNode);
			} else {
				if(Gender(Temp) == true) {
					printf("Sorry this kingdom rejects gays");
					system("cls");
					free(newNode);
				} else if(Pair(Temp) != NULL) {
					printf("Sorry she already has a husband");
					free(newNode);
				} else {
					Pair(Temp) = newNode;
					Status(Temp) = true;
					
					printf("\n\n");
					printf("Yey... Wishing the both of you all the love and happiness in the world and congratulations on your marriage\n");
					system("pause");
					system("cls");
				}
			}
		}
	}
}

void Print(TNBTreeAddress TreeAddress, char tab[]) {
	char Temp[255];
	strcpy(Temp, tab);
	strcat(Temp, "-");
		if(TreeAddress != NULL) {
			if(Status(TreeAddress) == true) {
				printf("%s %s (%s)\n", tab, Name(TreeAddress), Name(Pair(TreeAddress)));
				Print(FirstSon(TreeAddress), Temp);
				Print(NextBrother(TreeAddress), tab);
			} else {
				printf("%s %s \n", tab, Name(TreeAddress));
				Print(FirstSon(TreeAddress), Temp);
				Print(NextBrother(TreeAddress), tab);
			}	
	}	    
}

void CountChildren(DataTree Tree){
	InfoType Parent;
	int Count;
	
	printf("Parent : ");
	scanf("%s", Parent);
	
	Count = ControlCountChildren(Tree, Parent);
	printf("%s Has %d child", Parent, Count);
	
	printf("\n");
}

int ControlCountChildren(DataTree Tree, InfoType Parent) {
	TNBTree *Temp;
	
	int Count = 0;
	
	if(!IsEmpty(Tree)) {
		Temp = Search(Tree, Parent);
		if(FirstSon(Temp) != NULL) {
			Count = Count + 1;
			Temp = FirstSon(Temp);
		} else {
			return 0;
		}
		
		while(NextBrother(Temp) != NULL) {
			Temp = NextBrother(Temp);
			Count = Count + 1;
		}
		
		return Count;
	}
	return 0;
}

int Depth(TNBTree *Root) {
	int Level = -1;
	
	if(Root != NULL) {
		if(Level <= Depth(FirstSon(Root))) {
			Level = Depth(FirstSon(Root));
		}
		
		Level = Level + 1;
		
		if(Level <= Depth(NextBrother(Root))) {
			Level = Depth(NextBrother(Root));
		}
	}
	
	return Level;
}

int CountGenerations(DataTree Tree) {
	if(IsEmpty(Tree)) {
		printf("This king has no generation.");
	} else {
		Depth((Tree).Root);
	}
}

void Delete(DataTree *Tree) {
	TNBTree *NodeSearch, *temp, *temp1;
	InfoType NameDel, ExRaja;
	
	FILE *fp;
	
	fflush(stdin);
	printf("Anggota Keluarga Kerajaan yang meninggal :");
	gets(NameDel);
	NodeSearch = Search(*Tree, NameDel);
	
	if(NodeSearch == Root(Tree)){
		//Jika Tidak punya anak
		if (FirstSon(Root(Tree)) == NULL){
			//Jika Tidak punya saudara
				if(NextBrother(Root(Tree)) == NULL){
					if(NextBrother(Parent(Root(Tree))) == NULL){
						fp = fopen("Assets/ExportKing.txt", "a");
						strcpy(ExRaja, Name(NodeSearch));
						fwrite(&ExRaja, sizeof(ExRaja),1,fp);
						fclose(fp);
						
						printf("\n");
						printf("Raja %s telah meninggal, karena tidak ada keturunan maka kerajaan runtuh", Name(Root(Tree)));
						Root(Tree) = NULL;
//						free(NodeSearch);						
					}
					else{
						//Paman Raja Yang Naik
						if(Gender(NextBrother(Parent(Root(Tree)))) == true){
							temp = NextBrother(Parent(Root(Tree)));
							
							fp = fopen("Assets/ExportKing.txt", "a");
							strcpy(ExRaja, Name(NodeSearch));
							fwrite(&ExRaja, sizeof(ExRaja),1,fp);
							fclose(fp);
							printf("Selamat %s diangkat sebagai raja baru", Name(temp));
							Root(Tree) = temp;
//							free(NodeSearch);
						}
						else{
							fp = fopen("Assets/ExportKing.txt", "a");
							strcpy(ExRaja, Name(NodeSearch));
							fwrite(&ExRaja, sizeof(ExRaja),1,fp);
							fclose(fp);
								
							printf("\n");
							printf("Karena tidak ada calon raja yang memenuhi kriteria maka kerajaan runtuh");
							Root(Tree) = NULL;
//							free(NodeSearch);								
							}
						}
				}
				else{
					//Saudara Raja Naik
					if(Gender(NextBrother(Root(Tree))) == true){
						temp = NextBrother(Root(Tree));
						fp = fopen("Assets/ExportKing.txt", "a");
						strcpy(ExRaja, Name(NodeSearch));
						fwrite(&ExRaja, sizeof(ExRaja),1,fp);
						fclose(fp);
						printf("\n");
						printf("Selamat %s diangkat sebagai raja baru", Name(temp));
						Root(Tree) = temp;
//						free(NodeSearch);
					}
					else{
						fp = fopen("Assets/ExportKing.txt", "a");
						strcpy(ExRaja, Name(NodeSearch));
						fwrite(&ExRaja, sizeof(ExRaja),1,fp);
						fclose(fp);
									
						printf("\n");
						printf("Karena tidak ada calon raja yang memenuhi kriteria maka kerajaan runtuh");
						Root(Tree) = NULL;
//						free(NodeSearch);						
					}
				}
			}
			else {
			temp = Tree->Root->FirstSon;
			
			if(NextBrother(temp) == NULL){
				if(Gender(temp) == true){
					fp = fopen("Assets/ExportKing.txt", "a");
					strcpy(ExRaja, Name(NodeSearch));
					fwrite(&ExRaja, sizeof(ExRaja),1,fp);
					fclose(fp);
					
					printf("\n");
					printf("Selamat %s diangkat sebagai raja baru", Name(temp));
					Root(Tree) = temp;
//					free(NodeSearch);
				} else {
					if(FirstSon(temp) != NULL){
						if(Gender(FirstSon(temp)) == true){
							fp = fopen("Assets/ExportKing.txt", "a");
							strcpy(ExRaja, Name(NodeSearch));
							fwrite(&ExRaja, sizeof(ExRaja),1,fp);
							fclose(fp);
									
							Root(Tree) = FirstSon(temp);
							printf("\n");
							printf("Selamat %s diangkat sebagai raja baru", Name(FirstSon(temp)));
//							free(NodeSearch);
						} else {
							if(NextBrother(FirstSon(temp)) != NULL){
								if(Gender(NextBrother(FirstSon(temp))) == true){
									fp = fopen("Assets/ExportKing.txt", "a");
									strcpy(ExRaja, Name(NodeSearch));
									fwrite(&ExRaja, sizeof(ExRaja),1,fp);
									fclose(fp);
									
									Root(Tree) = NextBrother(FirstSon(temp));
									printf("\n");
									printf("Selamat %s diangkat sebagai raja baru", Name(NextBrother(FirstSon(temp))));
//									free(NodeSearch);
								} else {
									fp = fopen("Assets/ExportKing.txt", "a");
									strcpy(ExRaja, Name(NodeSearch));
									fwrite(&ExRaja, sizeof(ExRaja),1,fp);
									fclose(fp);
									
									printf("\n");
									printf("Karena tidak ada keturunan laki laki maka, kerajaan runtuh");
									Root(Tree) = NULL;
//									free(NodeSearch);
								}
							} else {
									fp = fopen("Assets/ExportKing.txt", "a");
									strcpy(ExRaja, Name(NodeSearch));
									fwrite(&ExRaja, sizeof(ExRaja),1,fp);
									fclose(fp);
									
									printf("\n");
									printf("Karena tidak ada keturunan laki laki maka, kerajaan runtuh");
									Root(Tree) = NULL;
//									free(NodeSearch);
							}
						}
					} else {
						fp = fopen("Assets/ExportKing.txt", "a");
						strcpy(ExRaja, Name(NodeSearch));
						fwrite(&ExRaja, sizeof(ExRaja),1,fp);
						fclose(fp);
						
						printf("\n");
						printf("Karena tidak ada keturunan laki laki maka, kerajaan runtuh");
						Root(Tree) = NULL;
//						free(NodeSearch);
					}
				}
			}else {
				if(Gender(temp) == true){
					fp = fopen("Assets/ExportKing.txt", "a");
					strcpy(ExRaja, Name(NodeSearch));
					fwrite(&ExRaja, sizeof(ExRaja),1,fp);
					fclose(fp);
					
					Root(Tree) = temp;
					printf("\n");
					printf("Selamat %s diangkat sebagai raja baru", Name(temp));
//					free(NodeSearch);
				} else {
					if(FirstSon(temp) == NULL){
						while((Gender(temp) == false) || (NextBrother(temp) != NULL)) {
						temp = NextBrother(temp);
						
							if(Gender(temp) == true){
								fp = fopen("Assets/ExportKing.txt", "a");
								strcpy(ExRaja, Name(NodeSearch));
								fwrite(&ExRaja, sizeof(ExRaja),1,fp);
								fclose(fp);
								Root(Tree) = temp;
								printf("\n");
								printf("Selamat %s diangkat sebagai raja baru", Name(temp));						
	//							free(NodeSearch);
							} else {
								fp = fopen("Assets/ExportKing.txt", "a");
								strcpy(ExRaja, Name(NodeSearch));
								fwrite(&ExRaja, sizeof(ExRaja),1,fp);
								fclose(fp);
								
								Root(Tree) = NULL;
								printf("\n");
								printf("Karena tidak ada calon raja yang memenuhi kriteria maka kerajaan runtuh");
	//							free(NodeSearch);
							}
						}
					}
					else{
						if(Gender(FirstSon(temp)) == true){
							fp = fopen("Assets/ExportKing.txt", "a");
							strcpy(ExRaja, Name(NodeSearch));
							fwrite(&ExRaja, sizeof(ExRaja),1,fp);
							fclose(fp);
							Root(Tree) = FirstSon(temp);
							printf("Selamat %s diangkat sebagai raja baru", Name(FirstSon(temp)));
						}
						else{
							while((Gender(FirstSon(temp)) == false) || (NextBrother(FirstSon(temp)) != NULL)) {
							temp = NextBrother(FirstSon(temp));
							
								if(Gender(temp) == true){
									fp = fopen("Assets/ExportKing.txt", "a");
									strcpy(ExRaja, Name(NodeSearch));
									fwrite(&ExRaja, sizeof(ExRaja),1,fp);
									fclose(fp);
									Root(Tree) = temp;
									printf("\n");
									printf("Selamat %s diangkat sebagai raja baru", Name(temp));						
		//							free(NodeSearch);
								} else {
									fp = fopen("Assets/ExportKing.txt", "a");
									strcpy(ExRaja, Name(NodeSearch));
									fwrite(&ExRaja, sizeof(ExRaja),1,fp);
									fclose(fp);
									
									Root(Tree) = NULL;
									printf("\n");
									printf("Karena tidak ada calon raja yang memenuhi kriteria maka kerajaan runtuh");
		//							free(NodeSearch);
								}
							}
						}
					}
				}
			}	
		}	
	}
	//Bukan Raja yang meninggal
	else{
		if(NodeSearch == FirstSon(Root(Tree))){
			if(FirstSon(NodeSearch) == NULL){
				if(NextBrother(NodeSearch) == NULL){
						FirstSon(Root(Tree)) = NULL;
	//					free(NodeSearch);
				}
				else{
					temp = NextBrother(NodeSearch);
					FirstSon(Root(Tree)) = temp;
					printf("Selamat %s ditunjuk sebagai calon raja berikutnya", FirstSon(Root(Tree)));
	//				free(NodeSearch);
				}	
			}				
			else{
				temp = FirstSon(NodeSearch);
				FirstSon(Root(Tree)) = temp;
				printf("Selamat %s ditunjuk sebagai calon raja berikutnya", FirstSon(Root(Tree)));
	//			free(NodeSearch);
			}				
	}else {
			if(NextBrother(NodeSearch) != NULL){
				temp = FirstSon(Parent(NodeSearch));
				temp1 = NextBrother(NodeSearch);
				
				while(NextBrother(temp)!= NodeSearch){
					temp = NextBrother(temp);
				}
				
				NextBrother(NodeSearch) = NULL;
				NextBrother(temp) = temp1;
//				free(NodeSearch);
			} else{
				temp = FirstSon(Parent(NodeSearch));
				
				while(NextBrother(temp)!= NodeSearch){
					temp = NextBrother(temp);
				}
				
				NextBrother(temp) = NULL;
//				free(NodeSearch);
			}
		}
	}	
	
	system("pause");
	system("cls");
}

void ExportKing(){
    char oke[20];
    int i = 1;

    FILE *fp;
	fp = fopen("Assets/ExportKing.txt", "r");

	while(fread(&oke, sizeof(oke), 1, fp)){
        printf("%d. %s\n", i,oke);
        i++;
	}
	
	fclose(fp);
}

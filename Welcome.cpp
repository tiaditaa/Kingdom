/*
File Name		: Welcome.cpp
Description		: 
Author			: Garly Nugraha & Nazwa Fitriyani Zahra
Editor			: 
Created at		: 02/04/2022
Updated at		: 17/05/2022
*/

/* ========== Header File ========== */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "TimeDate.h"
#include "DinamicNonBinaryTree.h"
/* ======= End of Header File ====== */

int Welcome() {
	time_t t;
	char Menu;
	struct tm now;
	DataTree Tree;
	Tree.Root = NULL;
	char str[]="";
	
	t = time(NULL);
	now = *localtime(&t);
	
	for(;;) {
		printf("Date : %s, %s %d, %d", DAY[now.tm_wday], MONTH[now.tm_mon], now.tm_mday, now.tm_year + 1900);
		printf("\n\n");
		
		printf("%c", 201);
		for(int i = 0; i <=40; i++){
			printf("%c", 205);
		}
		printf("%c", 187);
		
		printf("\n");
		printf("%c %-7c WELCOME TO GALUH EMPIRE %-7c %c", 186, 32, 32, 186);
		printf("\n");
		
		printf("%c", 204);
		for(int i = 0; i <=40; i++){
			printf("%c", 205);
		}
		printf("%c", 185);
		
		printf("\n");
		
		printf("%c 1. Insert the King and His Descendants  %c\n", 186, 186);
		printf("%c 2. Insert Wife                          %c\n", 186, 186);
		printf("%c 3. Insert Husband                       %c\n", 186, 186);
		printf("%c 4. Print the Royal Family Genealogy     %c\n", 186, 186);
		printf("%c 5. Count Children                       %c\n", 186, 186);
		printf("%c 6. Count the Generation of the Kingdom  %c\n", 186, 186);
		printf("%c 7. Kill the King and His Descendants    %c\n", 186, 186);
		printf("%c 8. Print King History                   %c\n", 186, 186);
		
		printf("%c", 204);
		for(int i = 0; i <=40; i++){
			printf("%c", 205);
		}
		printf("%c", 185);
		
		printf("\n");
		printf("%c %-1c Copyright 2022 - Develop by GNANFZ %-2c %c", 186, 32, 32, 186);
		printf("\n");
		
		printf("%c", 200);
		for(int i = 0; i <=40; i++){
			printf("%c", 205);
		}
		printf("%c", 188);
		
		printf("\n\n");
	    
	    printf("Select Menu : ");
		scanf("%d", &Menu);
		system("cls");
		
		switch(Menu){
			case 1 : 
				Insert(&Tree);
				break;
			case 2 : 
				InsertWife(&Tree);
				break;
			case 3 : 
				InsertHusband(&Tree);
				break;
			case 4 :
				if(Tree.Root->Status == true){
					printf("%s (%s) \n",Tree.Root->Name, Tree.Root->Pair->Name);
					Print(Tree.Root->FirstSon,str);
					system("pause");
					system("cls");
					break;
				}
				else{
					printf("%s \n",Tree.Root->Name);
					Print(Tree.Root->FirstSon,str);
				break;
				}
			case 5 :
				CountChildren(Tree);
				break;
			case 6 :
				printf("Jumlah Genrasi %d", 1 + CountGenerations(Tree));
				printf("\n");
				break;
			case 7 :
				Delete(&Tree); 
				break;
			case 8 :
				ExportKing();
				break;
			default:
		 		printf("ERROR : Sorry I don't know the answer to this one!!!\n");
		 		printf("Press Any Key to continue . . .");fflush(stdin);
		 		getche();
		 		
		 		system("cls");
		 		
		 		/* Call Modul Welcome */
				Welcome();
				break;
		}
	}
}


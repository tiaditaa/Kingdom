/*
File Name		: main.cpp
Description		: 
Author			: Garly Nugraha & Nazwa Fitriyani Zahra
Editor			: 
Created at		: 02/04/2022
Updated at		: 14/04/2022
*/

/* ========== Header File ========== */
#include <stdio.h>
#include "Welcome.h"
#include "DinamicNonBinaryTree.h"
/* ======= End of Header File ====== */

int main() {
	DataTree Tree;
	Create(&Tree);
	Tree.Root = NULL;
	
	/* Call Modul Welcome */
    Welcome();

    return 0;
}


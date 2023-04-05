/*
File Name		: DinamicNonBinaryTree.h
Description		: 
Author			: Garly Nugraha & Nazwa Fitriyani Zahra
Editor			: 
Created at		: 13/04/2022
Updated at		: 18/05/2022
*/

#ifndef DinamicNonBinaryTree_H
#define DinamicNonBinaryTree_H

#define Name(P) (P)->Name
#define FirstSon(P) (P)->FirstSon
#define NextBrother(P) (P)->NextBrother
#define Parent(P) (P)->Parent
#define Age(P) (P)->Age
#define Status(P) (P)->Status
#define Gender(P) (P)->Gender
#define Pair(P) (P)->Pair
#define Root(P)	(P)->Root

typedef char InfoType[20];
typedef struct TNBTree *TNBTreeAddress;
typedef struct TNBTree{
	InfoType Name;
	int Age;
	bool Status;
	bool Gender;
	TNBTree *FirstSon, *NextBrother, *Parent, *Pair;
} NBTree;

typedef struct{
	TNBTree *Root;
}DataTree;

void Create(DataTree *Tree); // Create an empty tree
bool IsEmpty(DataTree Tree); // Check if the tree is empty or not
TNBTree* Allocation(InfoType Name, bool Gender, int Age); // Allocate a new node in the tree
TNBTree* Search(DataTree Tree, InfoType Name); // Searching for nodes in the tree
void Insert(DataTree *Tree); // Create a new node in the tree
void InsertWife(DataTree *Tree);
void InsertHusband(DataTree *Tree);
void Print(TNBTreeAddress TreeAddress, char Name[]); 
void CountChildren(DataTree Tree);
int ControlCountChildren(DataTree Tree, InfoType Parent);
int Depth(TNBTree *Root);
int CountGenerations(DataTree Tree);
void Delete(DataTree *Tree); 
\
void ExportKing();
#endif


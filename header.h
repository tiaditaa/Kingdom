#ifndef header_H
#define header_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <windows.h>
#include <time.h>

// Tree => nbAddr
// info => nama
#define nama(P) (P)->nama
#define fs(P) (P)->fs
#define nb(P) (P)->nb
#define parent(P) (P)->parent
#define jenis_kelamin(P) (P)->jenis_kelamin
#define usia(P) (P)->usia
<<<<<<< HEAD
#define status(P) (P)->status
#define pasangan(P) (P)->pasangan
#define Gender(P) (P)->Gender
#define namapasangan(P) (P)->namapasangan
=======
#define pair(P) (P)->pair
#define Status(P) (P)->Status
#define Gender(P) (P)->Gender

>>>>>>> 969b1817954e64e4c59027ed9c878db2689916e5

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef char nbType[50];
typedef struct TNBTree *nbAddr;
typedef struct TNBTree{
	nbType nama;
	char jenis_kelamin;
	char name;
	int usia;
	nbAddr fs;
	nbAddr nb;
<<<<<<< HEAD
	nbAddr parent; 
	TNBTree *pasangan, *namapasangan;
	bool Gender;
	bool status;
}NBTree;
	
=======
	nbAddr parent;
	//nbAddr pair;
	//bool Status;
	//bool Gender;
}nbTreeNode;

>>>>>>> 969b1817954e64e4c59027ed9c878db2689916e5
struct TreeSilsilah{
//	nbAddr *root;
	nbAddr root;
};

typedef struct{
	TNBTree *Root;
}DataTree;


#endif

#include "header.h"
#include "Body.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_LENGTH 1000


TNBTree* Search(nbAddr tr, nbType nama) {
	TNBTree *Node = tr;
	
	while(Node != NULL) {
		if(strcmp(nama(Node), nama) == 0) {
			return Node;
		}
		
		if(fs(Node) != NULL) {
			Node = fs(Node);
		} else {
			if(nb(Node) != NULL) {
				Node = nb(Node);
			} else {
				while(nb(Node) == NULL && Node != tr) {
					Node = parent(Node);
				}
				
				Node = nb(Node);
			}
		}
	}
	
	return NULL;
}

void printSilsilah(nbAddr tr, char tab[])
{
	int i = 1;
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (tr != NULL)
	{
//		// root node jangan di tampilkan
//		if (strcmp(nama(tr), "root") != 0)
//		{
			if(status(tr) !=NULL)
			{
				printf("\t %s%s (%s) \n", tab, nama(tr), nama(pasangan(tr)));
				printSilsilah(tr->fs, tempTab);
				printSilsilah(tr->nb, tab);
				
			} else 
			{ printf("\t %s%s \n", tab, tr->nama); 
					printSilsilah(tr->fs, tempTab);
				printSilsilah(tr->nb, tab);	
			}
			
//	} else (strcmp(nama(tr), "history") !=0);
//		{ printf("\t %s%s \n", tab, tr->nama); 
//					printSilsilah(tr->fs, tempTab);
//				printSilsilah(tr->nb, tab);	
//			
//		}
		}

}

//}

TNBTree *SearchNode(TreeSilsilah tree, nbType nama)
{
	TNBTree *Node = tree.root;
	
	while(Node != NULL) {
		if(strcmp(nama(Node), nama) == 0) {
			return Node;
		}
		
		if(fs(Node) != NULL) {
			Node = fs(Node);
		} else {
			if(nb(Node) != NULL) {
				Node = nb(Node);
			} else {
				while(nb(Node) == NULL && Node != tree.root) {
					Node = parent(Node);
				}
				
				Node = nb(Node);
			}
		}
	}
	
	return NULL;
}

// Delete Raja and Upgrade
//void nbDelete2(nbAddr *pDel, TreeSilsilah *pTree){
//	nbAddr pCur;
//	pCur = *pDel;
//
//	if (pCur == pTree->root && pCur->fs==NULL){
//		pTree->root=NULL;
//		return;
//	}
//
//	while(pCur->fs != NULL)
//		pCur=pCur->fs;
//
//	while (pCur!=*pDel){
//		nbUpgrade(&pCur);
//		if (pCur->parent!=NULL)
//			pCur->nb=pCur->parent->nb;
//		else
//			pCur->nb=NULL;
//		pCur=pCur->parent;
//	}
//
//	if (pCur->parent!=NULL)
//		pCur->parent->fs=pCur->fs;
//	if (pCur->fs!=NULL)
//		pCur->fs->parent=pCur->parent;
//	if (pCur->parent==NULL)
//		pTree->root=pCur;
//	
//}

//void nbDelete2(nbAddr *node, TreeSilsilah *tree) {
//    if (*node == NULL) {
//        return;
//    }
//
//    nbAddr parent = (*node)->parent;
//    nbAddr child = (*node)->fs;
//
//    if (parent != NULL) {
//        if (parent->fs == *node) {
//            parent->fs = child;
//        } else {
//            nbAddr prevSibling = parent->fs;
//            while (prevSibling != NULL && prevSibling->nb != *node) {
//                prevSibling = prevSibling->nb;
//            }
//            if (prevSibling != NULL) {
//                prevSibling->nb = child;
//            }
//        }
//    } else {
//        tree->root = child;
//        if (child != NULL) {
//            child->parent = NULL;
//        }
//    }
//
//    // Update parent for the children of the deleted node
//    nbAddr currChild = child;
//    while (currChild != NULL) {
//        currChild->parent = parent;
//        currChild = currChild->nb;
//    }
//
//    free(*node);
//    *node = NULL;
//}

void nbDelete2(nbAddr *node, TreeSilsilah *tree) {
    if (*node == NULL) {
        return;
    }

    nbAddr parent = (*node)->parent;
    nbAddr child = (*node)->fs;

    if (parent != NULL) {
        if (parent->fs == *node) {
            parent->fs = child;
        } else {
            nbAddr prevSibling = parent->fs;
            while (prevSibling != NULL && prevSibling->nb != *node) {
                prevSibling = prevSibling->nb;
            }
            if (prevSibling != NULL) {
                prevSibling->nb = child;
            }
        }
    } else {
        tree->root = child;
        if (child != NULL) {
            child->parent = NULL;
        }
    }

    // Update parent for the children of the deleted node
    nbAddr currChild = child;
    while (currChild != NULL) {
        currChild->parent = parent;
        currChild = currChild->nb;
    }

    free(*node);
    *node = NULL;
    
}





void menuHitungAnak(nbAddr treeSilsilahTemp){
	nbType parentTempInput;
	int src;
	printSilsilah;
	printf("Masukkan nama parent : ");
	fflush(stdin);
	gets(parentTempInput);

	// cek parent apakah ada
	if (Search(treeSilsilahTemp, parentTempInput) == NULL)
	{
		printf("Parent tidak ditemukan");
	}
	src = hitungAnak(treeSilsilahTemp, parentTempInput);
	if (src == NULL)
	{
		printf("Parent %s tidak memiliki anak", parentTempInput);
	}
	printf("Jumlah anak dari %s yaitu : %d", parentTempInput, src);
}

void readHistory() {
    FILE *file = fopen("History.txt", "r");
    char line[MAX_LENGTH];

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return;
    }

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        printf("\t\t%s", line);
    }
	getch();
    fclose(file);
}

void writeHistory(char *entry) {
//    char *entry;
	
	FILE *file = fopen("History.txt", "r");

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
        return;
    }

    fprintf(file, "%s", entry);

    fclose(file);
}
#include "header.h"
#include "Body.h"
#include "display.h"



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
		// root node jangan di tampilkan
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
			
	}
		}


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
void nbDelete2(nbAddr *pDel, TreeSilsilah *pTree){
	nbAddr pCur;
	pCur = *pDel;

	if (pCur == pTree->root && pCur->fs==NULL){
		pTree->root=NULL;
		return;
	}

	while(pCur->fs != NULL)
		pCur=pCur->fs;

	while (pCur!=*pDel){
		nbUpgrade(&pCur);
		if (pCur->parent!=NULL)
			pCur->nb=pCur->parent->nb;
		else
			pCur->nb=NULL;
		pCur=pCur->parent;
	}

	if (pCur->parent!=NULL)
		pCur->parent->fs=pCur->fs;
	if (pCur->fs!=NULL)
		pCur->fs->parent=pCur->parent;
	if (pCur->parent==NULL)
		pTree->root=pCur;
	
}

void menuHitungAnak(nbAddr treeSilsilahTemp){
	nbType parentTempInput;
	int src;
	printSilsilah;
	printf("Masukkan nama orangtua : ");
	fflush(stdin);
	gets(parentTempInput);

	// cek parent apakah ada
	if (Search(treeSilsilahTemp, parentTempInput) == NULL)
	{
		printf("Orangtua tidak ditemukan");
	}
	src = hitungAnak(treeSilsilahTemp, parentTempInput);
	if (src == NULL)
	{
		printf("%s tidak memiliki anak", parentTempInput);
	}
	printf("Jumlah anak dari %s yaitu : %d", parentTempInput, src);
}


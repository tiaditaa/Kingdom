#include "header.h"
#include "Body.h"
#include "display.h"


//int isTreeEmpty(nbAddr tr)
//{
//	return tr == NULL;
//}
// 

nbAddr nbSearch(nbAddr root, nbType nameParam)
{
	nbAddr nSrc;
	if (root != NULL)
	{
		if (strcmp(root->nama, nameParam) == 0)
			return root;
		else
		{
			nSrc = nbSearch(root->fs, nameParam);
			if (nSrc == NULL)
				return nbSearch(root->nb, nameParam);
			else
				return nSrc;
		}
	}
	return NULL;
}

nbAddr Search(nbAddr tr, nbType SQ)
{
	boolean visit = true;
	if (isSilsilahEmpty(tr))
		return NULL;
	if (strcmp(nama(tr), SQ) == 0)
		return tr;
	else if (strcmp(nama(tr), SQ) != 0 && fs(tr) == NULL)
		return NULL;
	else
	{
		while (parent(tr) != NULL || visit)
		{
			if (fs(tr) != NULL && visit)
			{
				tr = fs(tr);
				if (strcmp(nama(tr), SQ) == 0)
					return tr;
			}
			else
			{
				if (nb(tr) != NULL)
				{
					tr = nb(tr);
					if (strcmp(nama(tr), SQ) == 0)
						return tr;
					visit = true;
				}
				else
				{
					visit = false;
					tr = parent(tr);
				}
			}
		}
		return NULL;
	}
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
		if (strcmp(nama(tr), "root") != 0)
		{
			printf("\t %s%s\n", tab, tr->nama);
		}
		printSilsilah(tr->fs, tempTab);
		printSilsilah(tr->nb, tab);
	}
}

TnbTreeNode *SearchNode(TreeSilsilah tree, nbType nama)
{
	TnbTreeNode *node = tree.root;
	while (node != NULL)
	{
		if (strcmp(nama(node), nama) == 0)
		{
			return node;
		}
		if (fs(node) != NULL)
		{
			node = fs(node);
		}
		else
		{
			if (nb(node) != NULL)
			{
				node = nb(node);
			}
			else
			{
				while (nb(node) == NULL && node != tree.root)
				{
					node = parent(node);
				}
				node = nb(node);
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
	printf("Masukkan nama parent : ");
	fflush(stdin);
	gets(parentTempInput);

	// cek parent apakah ada
	if (nbSearch(treeSilsilahTemp, parentTempInput) == NULL)
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


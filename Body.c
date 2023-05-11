#include "header.h"
#include "Body.h"
#include "display.h"

void nbCreate(TreeSilsilah *x)
{
	(*x).root = NULL;
}


// nbType name[], nbType gender, int age, nbType religion[]
nbAddr nbCNode(nbType nama, char jenis_kelamin, int usia, nbType religion_param)
{ // Create New Node
	nbAddr newNode;
	newNode = (nbAddr)malloc(sizeof(nbTreeNode));
	if (newNode != NULL)
	{
		strcpy(newNode->nama, nama);
		newNode->jenis_kelamin = jenis_kelamin;
		newNode->usia = usia;
		strcpy(newNode->religion, religion_param);

		newNode->fs = NULL;
		newNode->nb = NULL;
		newNode->parent = NULL;
	}
	return newNode;
}

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

// nbType nama,char jenis_kelamin, int usia, nbType religion
void nbInsert(TreeSilsilah *tRoot, nbAddr parent, nbType nama_param, char jenis_kelamin_param, int usia_param, nbType religion_param)
{ // Insert New Node baru dengan keadaan tertentu
	nbAddr newNode, temp;
	newNode = nbCNode(nama_param, jenis_kelamin_param, usia_param, religion_param);
	if (newNode != NULL)
	{						// Jika penciptaan node baru berhasil
		if (parent == NULL) // Jika belum terdapat root
			tRoot->root = newNode;
		else
		{
			temp = parent;
			if (temp->fs != NULL)
			{
				temp = temp->fs;
				while (temp->nb != NULL)
					temp = temp->nb;
				temp->nb = newNode;
			}
			else
				temp->fs = newNode;
			newNode->parent = parent;
		}
	}
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

// pre-order
void cetakSilsilah(nbAddr tr, char tab[])
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
		cetakSilsilah(tr->fs, tempTab);
		cetakSilsilah(tr->nb, tab);
	}
}



void nbUpgrade(nbAddr *root)
{
	nbAddr temp;
	temp = (*root)->nb;
	if ((*root)->fs == NULL)
		(*root)->fs = temp;
	while (temp != NULL)
	{
		temp->parent = *root;
		temp = temp->nb;
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

//Delete Tengah
void nbDelete(nbAddr *pDel, TreeSilsilah *pTree){
	nbAddr pCur,pAdd,pTemp;
	pCur=*pDel;

	if (pCur==pTree->root && pCur->fs==NULL){
		pTree->root=NULL;
		return;
	}

	while(pCur->fs!=NULL)
		pCur=pCur->fs;

	while (pCur!=*pDel){
		nbUpgrade(&pCur);
		if (pCur->parent!=NULL)
			pCur->nb=pCur->parent->nb;
		else
			pCur->nb=NULL;
		pCur=pCur->parent;
	}

	if (pCur->parent != NULL)
		pAdd = pCur->parent->fs;
	else
		pAdd = pCur;
	while(pAdd->nb != *pDel && pAdd != *pDel){
		pAdd = pAdd->nb;
	}
	if (pAdd != *pDel){
		if (pCur->fs != NULL)
			pAdd->nb = pCur->fs;
		else 
			pAdd->nb = pCur->nb;
	}
	else if (pCur->nb != NULL && pAdd->parent != NULL){
		pAdd->parent->fs = pCur->nb;
	}
	else {
		pTree->root = pCur->fs;
	}
	if (pCur->fs!=NULL)
		pCur->fs->parent=pCur->parent;
	if (pCur->parent==NULL)
		pTree->root=pCur;
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
	// cetakSilsilah(Tree.root, str);
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


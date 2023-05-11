#include "header.h"
#include "Body.h"
#include "display.h"

void createNode(TreeSilsilah *tree)
{
	(*tree).root = NULL;
}

nbAddr nbCNode(nbType nama, char jenis_kelamin, int usia)
{ // Create New Node
	nbAddr newNode;
	newNode = (nbAddr)malloc(sizeof(TNBTree));
	if (newNode != NULL)
	{
		strcpy(newNode->nama, nama);
		newNode->jenis_kelamin = jenis_kelamin;
		newNode->usia = usia;

		newNode->fs = NULL;
		newNode->nb = NULL;
		newNode->parent = NULL;
		newNode->pasangan = NULL;
		status(newNode) = false;
	}
	return newNode;
}

void insertNode(TreeSilsilah *tRoot, nbAddr parent, nbType nama_param, char jenis_kelamin_param, int usia_param)
{ // Insert New Node baru dengan keadaan tertentu
	nbAddr newNode, temp;
	newNode = nbCNode(nama_param, jenis_kelamin_param, usia_param);
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

void nbLevelOrder(nbAddr root,int curLevel, int desLevel)
{
	if(root!=NULL)
	{
		// munculkan semua anak yang ada di root, dan root jangan di munculkan
		if(curLevel==desLevel)
		{
			// jangan munculkan root
			if(strcmp(nama(root),"root")!=0)
			{
				printf("%s\n",nama(root));
			}
		}
		else
		{
			nbLevelOrder(root->fs,curLevel,desLevel);
			nbLevelOrder(root->nb,curLevel+1,desLevel);
		}
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

void InsertWife(nbAddr tr) {
		TreeSilsilah tRoot;
	TNBTree *newNode, *Temp;
	nbType Husband, parent, nama, pasangan;
	char jenis_kelamin, name;
	bool Gender;
	int usia;
	nbAddr Name, namapasangan;

	if (!IsSilsilahEmpty(tr)) {	
		
		fflush(stdin);
		printf("Name	: ");
		scanf("%s", &pasangan);
		
		fflush(stdin);
	   	printf("usia	: ");
	    scanf("%d", &usia);
	    printf("%d", usia);
	    getch();
        jenis_kelamin = 'L';
        
        newNode = nbCNode(pasangan, jenis_kelamin, usia);
        
        printf("\n");
        printf("A husband can only have one wife.\n");
        
       fflush(stdin);
       printf("Wife of : ");
       gets(Husband);
       
       
    	if(Search(tr, Husband) == NULL) {
        	printf("Husband not found, maybe he doesn't love you\n");
        	system("pause");
        	system("cls");
			free(newNode);
		} else {
			Temp = Search(tr,Husband);
			
      
			if(usia(Temp) != usia(newNode)) {
            	getch();
				printf("The age between couples should be the same.\n");
            	system("cls");
				free(newNode);
        	} else {
       			if (Gender(Temp) == false) {
           			printf("This government rejects lesbians");
       
            		system("cls");
					free(newNode);
       			} else if ((Temp) == NULL) {
	            	printf("Sorry he already has a wife");
                	system("cls");
					free(newNode);
				} else {
		            pasangan(Temp) = newNode;
		            status(Temp) = true;
		            printf ("%s", &namapasangan); getch ();
		            printf("\n\n");
		            printf("Selamat kalian resmi menikah");
       				getch();
        		}
      	}	
		}
	}   
}

void InsertHusband(nbAddr tr) {
		TreeSilsilah tRoot;
	TNBTree *newNode, *Temp;
	nbType Wife, parent, nama, pasangan;
	char jenis_kelamin, name;
	bool Gender;
	int usia;
	nbAddr Name, namapasangan;

	if (!IsSilsilahEmpty(tr)) {	
		
		fflush(stdin);
		printf("Name	: ");
		scanf("%s", &pasangan);
		
		fflush(stdin);
	   	printf("usia	: ");
	    scanf("%d", &usia);
	    printf("%d", usia);
	    getch();
        jenis_kelamin = 'L';
        
        newNode = nbCNode(pasangan, jenis_kelamin, usia);
        
        printf("\n");
        printf("\n");
        
       fflush(stdin);
       printf("suami dari : ");
       gets(Wife);
       
       
    	if(Search(tr, Wife) == NULL) {
        	printf("node tidak tersedia\n");
        	system("pause");
        	system("cls");
			free(newNode);
		} else {
			Temp = Search(tr,Wife);
			
      
			if(usia(Temp) != usia(newNode)) {
            	getch();
				printf("The age between couples should be the same.\n");
            	system("cls");
				free(newNode);
        	} else {
       			if (Gender(Temp) == false) {
           			printf("This government rejects lesbians");
       
            		system("cls");
					free(newNode);
       			} else if ((Temp) == NULL) {
	            	printf("Sorry he already has a wife");
                	system("cls");
					free(newNode);
				} else {
		            pasangan(Temp) = newNode;
		            status(Temp) = true;
		            printf ("%s", &namapasangan); getch ();
		            printf("\n\n");
		            printf("Selamat kalian resmi menikah");
       				getch();
        		}
      	}	
		}
	}   
}

void opsiDeleteAnggotaKerajaan(nbAddr treeSilsilahTemp, TreeSilsilah treeTemp){
	int bunuh;
	nbType namaNode;
	nbAddr srcNode;

	printf("Pilih Opsi Tahta\n");
	printf("\t1. Turunkan Tahta \n"); // delete raja
	printf("\t2. Bunuh Anggota \n"); // delete anak
	printf("\tPilih no : ");
	scanf("%d", &bunuh);
	switch (bunuh)
	{
	case 1:
		printf("Masukkan nama : ");
		scanf("%s", &namaNode);
		if ((srcNode = Search(treeSilsilahTemp, namaNode)) != NULL)
		{
			nbDelete2(&srcNode, &treeTemp);
			printf("%s telah diturunkan tahtanya", namaNode);
		}
		else
		{
			printf("Data tidak ditemukan");
		}
		break;
		case 2:
		int i;
		for(i=0;i<=nbDepth(treeSilsilahTemp);i++)
		{
			nbLevelOrder(treeSilsilahTemp,1,i);
		}
		printf("Masukkan Saudara Raja     : ");
		scanf("%s", &namaNode);
		if ((srcNode = Search(treeSilsilahTemp, namaNode)) != NULL)
		{
			nbDelete(&srcNode, &treeTemp);
			printf("Data telah dihapus");
		}
		else
		{
			printf("Data tidak ditemukan");
		}
		break;
			
		default:
			printf("Pilihan tidak ada");
		break;
	} 

}

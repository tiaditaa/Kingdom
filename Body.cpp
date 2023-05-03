#include "header.h"
#include "Body.h"
#include "display.h"

void nbCreate(TreeSilsilah *x)
{
	(*x).root = NULL;
}

int isTreeEmpty(nbAddr tr)
{
	return tr == NULL;
}

int isSilsilahEmpty(nbAddr tr)
{
	return isTreeEmpty(tr);
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

void InsertSilsilah(nbAddr *tr)
{
	TreeSilsilah tRoot;
	nbAddr TNode = NULL, temp = NULL, parentTem = NULL;
	char jenis_kelamin;
	int usia;
	nbType Nama, parent, Agama;

	if (isSilsilahEmpty(*tr))
	{
		printf("Silsilah Belum Ada");
	}
	else
 	{
		printf("Input Anggota Kerajaan ");
		
		do{
			printf("Nama              : ");
			fflush(stdin);
			gets(Nama);

			// validasi kosong nama
			if (strlen(Nama) == 0){
				printf("Nama Tidak Boleh Kosong");
				printf("Silahkan Input Kembali");
				getch();
				printf("                          ");
				printf("                          ");
			}

			// jika nama sama dengan parent maka tidak bisa input
			parentTem = Search(*tr, Nama);
			if (parentTem != NULL){
				printf("Nama Tidak Boleh Sama Dengan Parent");
				printf("Silahkan Input Kembali");
				getch();
				printf("                                       ");
				printf("                           ");
				printf("                           ");

			}
		} while (strlen(Nama) == 0 || parentTem != NULL);

		

		do
		{
			printf("Jenis Kelamin L/P : ");
			fflush(stdin);
			scanf("%c", &jenis_kelamin);
			// convert to upper case
			jenis_kelamin = toupper(jenis_kelamin);
			if (jenis_kelamin != 'L' && jenis_kelamin != 'P')
			{
				printf("Jenis Kelamin Salah!");
				getch();
				printf("                 ");
			}
		} while (jenis_kelamin != 'L' && jenis_kelamin != 'P');
		bool jenis_kelamin_valid = false;
		int i = 1;
		do
		{
			printf("usia              : ");
			fflush(stdin);
			scanf("%d", &usia);
			if (usia <= 11 || usia >= 100)
			{
				printf("usia tidak boleh kurang dari 11 dan lebih dari 100");
				getch();
				jenis_kelamin_valid = true;
				printf("usia          : ");
				printf("   ");

			}
			else
			{
				jenis_kelamin_valid = false;
			}
		} while (jenis_kelamin_valid);

		if (usia <= 11)
		{
			printf("usia tidak boleh lebih kecil dari 11");
		}
		do
		{
			printf("Masukkan Parent dari Anak Tersebut / jadikan root (root) : ");
			fflush(stdin);
			gets(parent);
			if(strcmp(parent, "") == 0)
			{
				printf("Parent tidak boleh kosong");
				getch();
				printf("                         ");
				printf("Masukkan Parent dari Anak Tersebut : ");
				fflush(stdin);
				gets(parent);
			}else if(Search(*tr, parent) == NULL){
				printf("Parent tidak ada!");
				getch();
				printf("                 ");
				printf("                 ");
			}
		} while (Search(*tr, parent) == NULL);
		temp = Search(*tr, parent);

		// validasi jika umur anak lebih dari umur orang tua dan umur anak lebih kecil dari umur orang tua
		if (usia >= usia(temp))
		{
			printf("Usia tidak boleh lebih besar dengan parent yang di pilih %d", usia(temp));
		}
		else if (usia(temp) - usia <= 15)
		{ // rumus usia parent di kurangi usia inpputan dan bandingkan lebih kecil sama dengan 15
			printf("Usia tidak boleh lebih kecil 15 tahun dari usia parent ! %d", usia(temp));
		}
		else
		{
			strcpy(Agama, "Protestan");
			nbInsert(&tRoot, nbSearch(*tr, parent), Nama, jenis_kelamin, usia, Agama); 
			printf("Anggota dengan nama %s berhasil ditambahkan dengan parent %s", Nama, parent);
		}
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

void detailAnggota(nbAddr tr)
{
	nbAddr nm;
	char namaTemp[255];
	int i = 1;
	if (isSilsilahEmpty(tr))
	{
		printf("Silsilah Belum Ada");
	}
	else
	{
		printf("Input Anggota Kerajaan ");
		printf("Nama : ");
		fflush(stdin);
		gets(namaTemp);
		if (Search(tr, namaTemp) == NULL)
		{
			printf("Nama tidak ada");
			system("pause");
		}
		else
		{

			printf("Detail Identitas Kerajaan !");
			printf("                                            ");
			printf("\nNama              : %s", namaTemp);
			printf("\nJenis Kelamin     : %c", jenis_kelamin(Search(tr, namaTemp)));
			printf("\nUsia              : %d", usia(Search(tr, namaTemp)));
			printf("\nAgama             : %s\n", religion(Search(tr, namaTemp)));
			nm = parent(Search(tr, namaTemp));
			if (nm != 
			NULL)
			{
				if(strcmp(nama(nm), "root"))
				{
					printf("Parent            : %s\n", nama(nm));
				} else if(!strcmp(nama(tr->fs), namaTemp)){
					if(jenis_kelamin(tr->fs) == 'L'){
						printf("Status            : RAJA \n");
					} else if(jenis_kelamin(tr->fs) == 'P'){
						printf("Status            : RATU \n");
					}
				} else {
					printf("\n%s adalah saudara dari raja ", namaTemp);
				}
			}

			system("pause");
		}
	}

}

int hitungAnak(nbAddr tree, nbType parent)
{
	TnbTreeNode *temp;
	int jumlah = 0;
	if (!isTreeEmpty(tree))
	{
		temp = Search(tree, parent);
		// jika parent ditemukan
		if (fs(temp) != NULL)
		{
			jumlah = jumlah + 1;
			temp = fs(temp);
		}
		else
		{
			return 0;
		}
		while (nb(temp) != NULL)
		{
			temp = nb(temp);
			jumlah = jumlah + 1;
		}
		return jumlah;
	}

	return 0;
}

void urutanPewaris(nbAddr tr)
{
	boolean visit = true;
	int i = 1;
	if (tr == NULL)
	{
		printf("Pewaris Kosong");
	}
	else
	{
		printf("Data Pewaris Tahta");
		// check apakah ada first son atau 
		if (fs(tr) != NULL)
		{
			while (parent(tr) != NULL || visit)
			{
				if (fs(tr) != NULL && visit)
				{
					tr = fs(tr);
					if(jenis_kelamin(tr) == 'L' && i == 1){
						printf("%d. %s   -  RAJA ", i, nama(tr));
					} else if(jenis_kelamin(tr) == 'P' && i == 1){
						printf("%d. %s   -  RATU ", i, nama(tr));
					} else {
						printf("%d. %s", i, nama(tr));
					}
					i++;
				}
				else
				{
					if (nb(tr) != NULL)
					{
						tr = nb(tr);
						printf("%d. ", i);
						printf("%s", nama(tr));
						visit = true;
						i++;
					}
					else
					{
						tr = parent(tr);
						visit = false;
					}
				}
			}
		}
		else
		{
			printf("Belum ada pewaris\n");
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
int nbDepth(nbAddr root)
{
	int y,z;

	if(root==NULL)
		return -1;
	y=nbDepth(root->fs);
	z=nbDepth(root->nb);
	if (y > z)
		return (y+1);
	else
		return (z+1);
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

void opsiDeleteAnggotaKerajaan(nbAddr treeSilsilahTemp, TreeSilsilah treeTemp){
	int bunuh;
	nbType namaNode;
	nbAddr srcNode;

	printf("Pilih Opsi Tahta");
	printf("1. Turunkan Tahta Raja atau Bunuh keturunan dari Raja"); // delete raja
	printf("2. Bunuh Saudara Raja Atau keturunan dari Saudara Raja"); // delete anak
	printf("Pilih no : ");
	scanf("%d", &bunuh);
	switch (bunuh)
	{
	case 1:
		printf("Masukkan nama : ");
		scanf("%s", &namaNode);
		if ((srcNode = nbSearch(treeSilsilahTemp, namaNode)) != NULL)
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
		if ((srcNode = nbSearch(treeSilsilahTemp, namaNode)) != NULL)
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
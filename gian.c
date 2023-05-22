#include "header.h"
#include "header.h"
#include "Body.h"
#include "display.h"



bool IsSilsilahEmpty(nbAddr tr) {
	return tr == NULL;
}


void InsertSilsilah(nbAddr *tr)
{
	TreeSilsilah tRoot;
	nbAddr TNode = NULL, temp = NULL, parentTem = NULL;
	char jenis_kelamin;
	int usia;
	nbType Nama, parent;

	if (IsSilsilahEmpty(*tr))
	{
		printf("Silsilah Belum Ada");
	}
	else
 	{
		printf("Input Anggota Kerajaan ");
		
		do{
			printf("\nNama : ");
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
			printf("Usia  : ");
			fflush(stdin);
			scanf("%d", &usia);
			if (usia <= 11 || usia >= 100)
			{
				printf("Usia tidak boleh kurang dari 1 dan lebih dari 100");
				getch();
				jenis_kelamin_valid = true;
				printf("Usia       : ");
				printf("   ");

			}
			else
			{
				jenis_kelamin_valid = false;
			}
		} while (jenis_kelamin_valid);

		if (usia <= 1)
		{
			printf("Usia tidak boleh lebih kecil dari 1");
		}
		do
		{
			printf("Masukkan Parent dari Anak Tersebut : ");
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
			insertNode(&tRoot, Search(*tr, parent), Nama, jenis_kelamin, usia); 
			printf("Anggota dengan nama %s berhasil ditambahkan dengan parent %s", Nama, parent);
		}
	}
}

void detailAnggota(nbAddr tr)
{
	nbAddr nm;
	char namaTemp[255];
	int i = 1;
	if (IsSilsilahEmpty(tr))
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
			nm = parent(Search(tr, namaTemp));
			if (nm != 
			NULL)
			{
				if(strcmp(nama(nm), ""))
				{
					printf("\nParent            : %s\n", nama(nm));
				} else if(!strcmp(nama(tr->fs), namaTemp)){
					if(jenis_kelamin(tr->fs) == 'L'){
						printf("\nStatus            : RAJA \n");
					} else if(jenis_kelamin(tr->fs) == 'P'){
						printf("\nStatus            : RATU \n");
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
	TNBTree *temp;
	int jumlah = 0;
	if (!IsSilsilahEmpty(tree))
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
						printf("\n%d. %s   -  RAJA", i, nama(tr));
					} else if(jenis_kelamin(tr) == 'P' && i == 1){
						printf("\n%d. %s   -  RATU", i, nama(tr));
					} else {
						printf("\n%d. %s", i, nama(tr));
					}
					i++;
				}
				else
				{
					if (nb(tr) != NULL)
					{
						tr = nb(tr);
						printf("\n%d. ", i);
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
		printf("Nama	: ");
		scanf("%s", &pasangan);
		
		fflush(stdin);
	   	printf("Usia	: ");
	    scanf("%d", &usia);
	    getch();
        jenis_kelamin = 'L';
        
        newNode = nbCNode(pasangan, jenis_kelamin, usia);
        
        printf("\n");
        printf("Suami hanya boleh memiliki satu isteri.\n");
        
       fflush(stdin);
       printf("Isteri dari : ");
       gets(Husband);
       
       
    	if(Search(tr, Husband) == NULL) {
        	printf("Suami tidak ditemukan, nama tersebut sudah memiliki pasangan\n");
        	system("pause");
        	system("cls");
			free(newNode);
		} else {
			Temp = Search(tr,Husband);
			
      
			if(usia(Temp) != usia(newNode)) {
            	getch();
				printf("Usia diantara pasangan harus sama.\n");
            	system("cls");
				free(newNode);
        	} else {
       			if (Gender(Temp) == false) {
           			printf("Pemerintahan menolak hubungan sesama jenis");
       
            		system("cls");
					free(newNode);
       			} else if ((Temp) == NULL) {
	            	printf("Maaf, dia telah memiliki isteri");
                	system("cls");
					free(newNode);
				} else {
		            pasangan(Temp) = newNode;
		            status(Temp) = true;
		            printf ("%s", &namapasangan); getch ();
		            printf("\n\n");
		            printf("Selamat kalian telah resmi menikah");
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
		printf("Nama	: ");
		scanf("%s", &pasangan);
		
		fflush(stdin);
	   	printf("Usia	: ");
	    scanf("%d", &usia);
	    getch();
        jenis_kelamin = 'L';
        
        newNode = nbCNode(pasangan, jenis_kelamin, usia);
        
        printf("\n");
        printf("\n");
        
       fflush(stdin);
       printf("Suami dari : ");
       gets(Wife);
       
       
    	if(Search(tr, Wife) == NULL) {
        	printf("Node tidak tersedia\n");
        	system("pause");
        	system("cls");
			free(newNode);
		} else {
			Temp = Search(tr,Wife);
			
      
			if(usia(Temp) != usia(newNode)) {
            	getch();
				printf("Umur diantara pasangan harus sama.\n");
            	system("cls");
				free(newNode);
        	} else {
       			if (Gender(Temp) == false) {
           			printf("Pemerintahan menolak hubungan sesama jenis");
       
            		system("cls");
					free(newNode);
       			} else if ((Temp) == NULL) {
	            	printf("Maaf, dia telah memiliki isteri");
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

void printHistory(nbAddr his, char tab[])
{
	int i = 1;
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (his != NULL)
	{
			if(status(his) !=NULL)
			{
				printf("\t %s%s (%s) \n", tab, nama(his), nama(pasangan(his)));
				printSilsilah(his->fs, tempTab);
				printSilsilah(his->nb, tab);
				
			} else 
			{ printf("\t %s%s \n", tab, his->nama); 
					printSilsilah(his->fs, tempTab);
				printSilsilah(his->nb, tab);	
			}
			
		}

}
//	} else (strcmp(nama(tr), "history") !=0);
//		{ printf("\t %s%s \n", tab, tr->nama); 
//					printSilsilah(tr->fs, tempTab);
//				printSilsilah(tr->nb, tab);	
//			
//		}

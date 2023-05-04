#include "display.h"


void aturanDisplay(){
	// open file txt
	FILE *fp;
	char line;
	int i = 0;
	// open file in directory assets
	fp = fopen("assets/aturanKerajaan.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
	// read file txt

	do 
	{
		line = fgetc(fp);
		printf("%c", line);
		i++;
	} while(line != EOF);
	fclose(fp);
	Menu();
	printf("ketik enter untuk kembali ...");
	getch();
}

void Menu(){
	int x=2, y=2;
	printf("\t            MENU KERAJAAN \n");
	printf("\t\t1. Tambah Anggota Kerajaan\n");
	printf("\t\t2. Tampilkan Silsilah\n");
	printf("\t\t3. Hitung Anak\n"); 
    printf("\t\t4. Urutan Pewaris\n");
    printf("\t\t5. Turunkan Tahta Raja\n");
	printf("\t\t6. Detail Anggota Kerajaan\n");
	printf("\t\t7. Peraturan\n");
	printf("\t\t0. Exit\n");
	printf("\n\t\tPilih: ");
}
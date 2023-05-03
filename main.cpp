#include "Body.h"
#include "display.h"

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // untuk memaxsimalisasi layar
	
	TreeSilsilah Tree;
	nbAddr src, deleteNode,PDel;
	int pil;
	char str[] = "\t";
	
	// add data ke node secara statis 
	nbCreate(&Tree);
	nbInsert(&Tree, NULL, "root", 'P', 80, "Protestan"); // nb insert ini dinyatakan sebagai root
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "Charles", 'L', 63, "Protestan"); // nb insert ini dinyatakan sebagai Raja
	nbInsert(&Tree, nbSearch(Tree.root, "Charles"), "Anne", 'P', 47, "Protestan"); 
	nbInsert(&Tree, nbSearch(Tree.root, "Charles"), "William", 'L', 46, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "George", 'L', 61, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root, "George"), "Charlotte", 'P', 45, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "Louis", 'L', 51, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "Harry", 'L', 51, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root, "George"), "Beatrice", 'p', 29, "Protestan");
	nbInsert(&Tree, nbSearch(Tree.root, "George"), "Eugenie", 'P', 28, "Protestan");

	for (;;)
	{
		system("cls");
		boxMenuOutput();
		scanf("%d", &pil);
		switch (pil)
		{
		case 1:
			cetakSilsilah(Tree.root, str);
			printf("\n\n");
			InsertSilsilah(&Tree.root);
			printf("\n\n");
			getch();
			break;
		case 2:
			if (isSilsilahEmpty(Tree.root))
			{
				printf("Belum ada siapapun disini");
				getch();
				break;
			}
			cetakSilsilah(Tree.root, str);
			getch();
			break;
		case 3:
			int src;
			if (isSilsilahEmpty(Tree.root))
			{
				printf("Belum ada siapapun disini");
				getch();
				break;
			}
			menuHitungAnak(Tree.root);
			getch();
			break;
		case 4:
			urutanPewaris(Tree.root);
			getch();
			break;
		case 5:
			system("cls");
			boxMenuOutput();
			if (isSilsilahEmpty(Tree.root))
			{
				printf("Silsilah Belum Dibuat");
				getch();
				break;
			}
			opsiDeleteAnggotaKerajaan(Tree.root, Tree);
			getch();
			break;
		case 6:
			system("cls");
			boxMenuOutput();
			detailAnggota(Tree.root);
			boxMenuOutput();
			if (isSilsilahEmpty(Tree.root))
			{
				printf("Silsilah Belum Dibuat");
				getch();
				break;
			}
			break;
		case 7:
			system("cls");
			aturanDisplay();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Inputan Salah !!");
			getch();
			break;
		}
	}

	return 0;
}
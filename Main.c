#include "Body.h"
#include "display.h"

int main()
{

	
	TreeSilsilah Tree;
	nbAddr src, deleteNode,PDel;
	int pil;
	char str[] = "\t";
	
	// add data ke node secara statis 
	nbCreate(&Tree);
	nbInsert(&Tree, NULL, "root", 'P', 80); // nb insert ini dinyatakan sebagai root
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "Charles", 'L', 63); // nb insert ini dinyatakan sebagai Raja
	nbInsert(&Tree, nbSearch(Tree.root, "Charles"), "Anne", 'P', 47); 
	nbInsert(&Tree, nbSearch(Tree.root, "Charles"), "William", 'L', 46);
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "George", 'L', 61);
	nbInsert(&Tree, nbSearch(Tree.root, "George"), "Charlotte", 'P', 45);
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "Louis", 'L', 51);
	nbInsert(&Tree, nbSearch(Tree.root, "root"), "Harry", 'L', 51);
	nbInsert(&Tree, nbSearch(Tree.root, "George"), "Beatrice", 'p', 29);
	nbInsert(&Tree, nbSearch(Tree.root, "George"), "Eugenie", 'P', 28);

	for (;;)
	{
		system("cls");
		Menu();
		scanf("%d", &pil);
		switch (pil)
		{
		case 1:
			printSilsilah(Tree.root, str);
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
			printSilsilah(Tree.root, str);
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
			Menu();
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
			Menu();
			detailAnggota(Tree.root);
			Menu();
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
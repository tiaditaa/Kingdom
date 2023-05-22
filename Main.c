#include "Body.h"
#include "display.h"

int main()
{

	
	TreeSilsilah Tree;
	nbAddr src, deleteNode,PDel;
	int pil;
	char str[] = "\t";
	
	// add data ke node secara statis 
	createNode(&Tree);
	insertNode(&Tree, NULL, "", 'P', 80); // insert ini dinyatakan sebagai root
	insertNode(&Tree, Search(Tree.root, ""), "Charles", 'L', 74); // insert ini dinyatakan sebagai Raja
	insertNode(&Tree, Search(Tree.root, "Charles"), "William", 'L', 40); 
	insertNode(&Tree, Search(Tree.root, "Charles"), "Harry", 'L', 38);
	insertNode(&Tree, Search(Tree.root, "William"),  "George", 'L', 9);
	insertNode(&Tree, Search(Tree.root, "William"), "Charlotte", 'P', 8);
	insertNode(&Tree, Search(Tree.root, "William"), "Louis", 'L', 5);
	insertNode(&Tree, Search(Tree.root, "Harry"), "Archie", 'L', 4);
//	insertNode(&Tree, Search(Tree.root, "Harry"), "Beatrice", 'p', 29);
//	insertNode(&Tree, Search(Tree.root, "George"), "Eugenie", 'P', 28);

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
			printSilsilah(Tree.root, str);
			getch();
			break;
		case 3:
			int src;
			if (IsSilsilahEmpty(Tree.root))
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
			if (IsSilsilahEmpty(Tree.root))
			{
				printf("Silsilah Belum Dibuat");
				getch();
				break;
			}
			printSilsilah(Tree.root, str);
			opsiDeleteAnggotaKerajaan(Tree.root, Tree);
			getch();
			break;
		case 6:
			system("cls");
			Menu();
			printSilsilah(Tree.root, str);
			detailAnggota(Tree.root);
			Menu();
			if (IsSilsilahEmpty(Tree.root));
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
		case 8:
			printSilsilah(Tree.root, str);
			InsertWife(Tree.root);
			system("cls");
			break;
		case 9:
			printSilsilah(Tree.root, str);
			InsertHusband(Tree.root);
			system("cls");
			break;	
		case 10:
			readHistory();
                break;		
		default:
			printf("Inputan Salah !!");
			getch();
			break;
		}
	}

	return 0;
}
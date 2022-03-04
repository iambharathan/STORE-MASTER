#include <stdio.h>
#include <string.h>
#include"Storeitem.h"
#include"stocktxn.h"
void Menu();
void CreateItemsFile();
void CreateTestTransactions();

int main()
{
	InitializeItems();
	Menu();
	printf("\n\nSuccessully completed.");
}

void Menu()
{
	int opt;
	while(1)
	{
			/* Clear Screen */
		system("cls");
		printf(" my  store");
		printf("\nStock Management\n");
		printf("\n1. Receipt Entry");
		printf("\n2. Issue Entry");
		printf("\n3. Stock List");
		printf("\n4. Stock Transactions Report");
		printf("\n5. View Store Items");
		printf("\n6. Exit");
		printf("\n\nEnter your choice (1-6): ");
		scanf("%d", &opt);
		fflush(stdin);

		switch(opt)
		{
			case 1:
				InputTransaction('R');
				break;
			case 2:
				InputTransaction('I');
				break;
			case 3:
				PrintStockList();
				break;
			case 4:
			    ReceiptEntry();
				break;
			case 5:
			    ListItems();
				break;
			case 6:
				return;
				break;
			default:
				printf("\nInvalid choice. Please try again (1-6)");	   	   	   
		}	 	 	 	 
		
		printf("\n\nPress a key to proceed...");
		getch();
	}

}
		
void CreateItemsFile()
{
	STOREITEM item;
	item.itemcode = 1;
	strcpy(item.itemname, "papper");
	getitem(item);
	
	item.itemcode = 2;
	strcpy(item.itemname, "laptop");
	getitem(item);
	
	item.itemcode = 3;
	strcpy(item.itemname, "pencil");
	getitem(item);
	

}

void CreateTestTransactions()
{
	RecordTxn(1, 'R', 100);
	RecordTxn(1, 'I', (float)10);
	RecordTxn(1, 'I', (float)10.5);
	RecordTxn(2, 'R', (float)12.5);
	RecordTxn(2, 'R', (float)3.5);
}

 


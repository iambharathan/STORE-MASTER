#include <stdio.h>
#include"storeitem.h"
#include"stocktxn.h"
void Menu();

int main()
{
	InitializeItems();
	Menu();
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
			ReceiptEntry();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
			   ListTransactions();
				break;
			case 5:
			    ListItem();
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
		
	
 


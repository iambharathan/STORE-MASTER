#include <stdio.h>
typedef struct storeitem{
	int itemcode;
	char itemname[31];	/* Maximum of 30 characters */
}STOREITEM;

char filename[] = "./storeitem.dat";

void Menu();
void ListRecords();
void WriteaRecord();


int main()
{
 	Menu();
}

void Menu()
{
	int opt;
	/* Enter into a loop */
	while(1)
	{
		/* Clear the Screen */
		system("cls");
		printf("\n1. Add Item");
		printf("\n2. List Items.");
		printf("\n3. Exit");
		printf("\n\nEnter your choice (1-3): ");
		scanf("%d", &opt);
		fflush(stdin);
		
		switch(opt)
		{
			case 1:
				WriteaRecord();
				break;
			case 2:
				ListRecords();
				break;
			case 3:	   	   	   	   
				return;
				break;
			default:
				printf("\nInvalid option selected.");
				break;
		}
		printf("\nPress a key to continue...");
		getch();
		
	}
}

void ListRecords()
{
	FILE *f;
	STOREITEM item;
	
	f = fopen(filename, "rb");
	
	/* Write the content */
	while(fread(&item, sizeof(STOREITEM), 1, f))
	{
		printf("\n%3d %-30s", item.itemcode, item.itemname);	
	}
	
	fclose(f);
}

void WriteaRecord()
{
	FILE *f;
	STOREITEM item;
	
	/* Read Inputs */
	printf("\nEnter Item Code : ");
	scanf("%d", &item.itemcode);
	fflush(stdin);
	
	printf("\nEnter Item Name : ");
	gets(item.itemname);
	
	f = fopen(filename, "ab");
	
	/* Write the content */
	fwrite(&item, sizeof(STOREITEM), 1, f); 
	
	fclose(f);	  
}


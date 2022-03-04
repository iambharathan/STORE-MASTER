#include <stdio.h>
#include <string.h>
#include "Storeitem.h"

STOREITEM items[50];
int itemscount;

char filename[] = "./storeitem.dat";
void InitializeItems()
{
	STOREITEM item;
	FILE *f = fopen(filename,"rb");
	itemscount=0;
	while(fread(&item,sizeof(STOREITEM),1,f))
	{
		items[itemscount].itemcode=item.itemcode;
		strcpy(items[itemscount].itemname ,item.itemname);
		
		itemscount++;	 
	}
	fclose(f);
}


STOREITEM *GetStoreItems()
{
	return items;
}

int GetItemsCount()
{
	return itemscount;
}

void getitem(STOREITEM item)
{
	FILE *f = fopen(filename, "ab");
	fwrite(&item, sizeof(STOREITEM), 1, f);
	fclose(f);
}
int ReadItemName(int itemcode, char *itemname)
{
	FILE *f = fopen(filename, "rb");
	STOREITEM item;
	int itemfound = 0;

	strcpy(itemname, "");
	while(fread(&item, sizeof(STOREITEM), 1, f))
	{
		if(item.itemcode == itemcode)
		{
			strcpy(itemname, item.itemname);
			itemfound = 1;
			break;
		}
	}
	fclose(f);
	
	return itemfound;
}

void ListItems()
{
	int itemcount = GetItemsCount();
	
	int i;
	for(i=0; i<itemcount; i++)
	{
		printf("\n%3d  %-30s", items[i].itemcode,
				items[i].itemname);
	}
	
	printf("\n\nPress a key...");
	getch();
}




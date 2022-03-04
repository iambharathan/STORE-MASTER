#include <stdio.h>
#include <string.h>
#include "storeitem.h"

STOREITEM items[50];
int itemcount;

char filename[] = "./storeitem.dat";
void InitializeItems()
{
	STOREITEM item;
	FILE *f = fopen(filename,"rb");
	itemcount=0;
	while(fread(&item,sizeof(STOREITEM),1,f))
	{
		items[itemcount].itemcode=item.itemcode;
		strcpy(items[itemcount].itemname ,item.itemname);
		
		itemcount++;	
	}
	fclose(f);
}

void ListItem()
{
	int i;
	STOREITEM item;
	printf("List of items");
	for(i=0;i<itemcount;i++)
	{
		item=items[i];
		printf("\n%3d %-30s",item.itemcode,item.itemname);
	
	}
	 
}

int GetItemName(int itemcode, char *itemname)
{
	int itemfound = 0;
	int i;
	for(i=0; i<itemcount; i++)
	{
		if(itemcode == items[i].itemcode)
		{
			strcpy(itemname, items[i].itemname);
			itemfound = 1;
			break;
		}
	}
	
	return itemfound;
}


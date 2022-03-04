#include<stdio.h>
#include "stocktxn.h"

char stkfilename[]="./stocktxn.bin";
void ReceiptEntry()
{
	STOCK stk;
	char itemname[31];
	int itemfound;
	char opt;
	FILE *f = fopen(stkfilename,"ab");
	printf("\nenter item code");
	scanf("%d",&stk.itemcode);
	fflush(stdin);
	
	/*disply item name*/
	
	itemfound=GetItemName(stk.itemcode,itemname);
	if(itemfound==0)
	{
		printf("\nInvalied item code.");
		return;
	}
	
	printf("\nItem Name: %-s",itemname);
	printf("\nIs this itemname correct? (Y/N)");
	scanf("%c",&opt);
	if(opt == 'n' || opt=='N')
	   return;	   
	
	printf("\nReceipt qty:");
	scanf("%f",&stk.qty);
	
	fflush(stdin);
	
	stk.txn = 'R';
	
	
	fwrite(&stk, sizeof(STOCK),1,f);
	fclose(f);	  
}

void ListTransactions()
{
	FILE *f;
	char itemname[31];
	int itemcode,itemfound;
	STOCK item;
	printf("\nenter item code");
	scanf("%d",&itemcode);
	fflush(stdin);
	
	/*disply item name*/
	
	itemfound=GetItemName(itemcode,itemname);
	if(itemfound==0)
	{
		printf("\nInvalied item code.");
		return;
	}
	
	printf("\nItem Name: %-s",itemname);
	
	f=fopen(stkfilename,"rb");
	while(fread(&item,sizeof(STOCK),1,f))
	{
		if(item.itemcode==itemcode)
		{
			printf("\n%c %10.3f",item.txn,item.qty);
		}
	}
	fclose(f);	    
}



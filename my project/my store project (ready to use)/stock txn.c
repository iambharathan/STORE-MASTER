#include<stdio.h>
#include "Storeitem.h"
#include "stocktxn.h"

char stkfilename[]="./stocktxn.bin";
void ReceiptEntry()
{
int itemcode;
	char itemname[31];
	int itemfound;
	printf("\n\nEnter Item code: ");
	scanf("%d", &itemcode);
	fflush(stdin);
	itemfound = ReadItemName(itemcode, itemname);
	if(!itemfound)
	{
		printf("\nInvalid item code.");
		return;
	}
	
	printf("\nSelected Item: %-s", itemname);
	PrintTransactions(itemcode);
	printf("\n\nPress a key to continue...");
	getch();
}
void InputTransaction(char Txn)
{
	int itemcode;
	char itemname[31];
	float qty;
	int itemfound;
	printf("\nEnter Item Code: ");
	scanf("%d", &itemcode);
	
	fflush(stdin);
	itemfound = ReadItemName(itemcode, itemname);
	if(itemfound)
		printf("\nItem Name: %s", itemname);
	else
	{
		printf("\nItem code invalid!");
		return;
	}
	
	printf("\nEnter Qty: ");
	scanf("%f", &qty);
	fflush(stdin);
	
	RecordTxn(itemcode, Txn, qty);	  
}


void RecordTxn(int itemcode, char Txn, float qty)
{
	STOCKTXN txn;
	FILE *f;
	   
	txn.itemcode = itemcode;
	txn.Txn = Txn;
	txn.Qty = qty;
	
	/* printf("\nQty = %f Stored Qty = %f", qty, txn.Qty); */
	
	f = fopen(stkfilename, "ab");
	fwrite(&txn, sizeof(STOCKTXN), 1, f);
	fclose(f);
	
}
float ClosingStock(int itemcode)
{
	STOCKTXN txn;
	float stk = 0;
	FILE *f = fopen(stkfilename, "rb");
	while(fread(&txn, sizeof(STOCKTXN), 1, f))
	{
		if(txn.itemcode == itemcode)
		{
			stk += (txn.Txn == 'R')? txn.Qty : -txn.Qty;
		}
	}
	fclose(f);
	return stk;
}
void PrintTransactions(int itemcode)
{
	STOCKTXN txn;
	

	float rTotal = 0, iTotal = 0, r, i;	   
	FILE *f = fopen(stkfilename, "rb");
	while(fread(&txn, sizeof(STOCKTXN), 1, f))
	{
		if(txn.itemcode == itemcode)
		{
			r = 0;
			i = 0;
			if(txn.Txn == 'R')
				r = txn.Qty;
			else
				i = txn.Qty;
			rTotal += r;
			iTotal += i;
			printf("\n%-10s ", txn.Txn=='R' ? "Receipt" : "Issue");
			
			
			if(r != 0)
				printf("%10.3f", r);
			else
				printf("%10s %10.3f", "", i);
		}
	}

	if(rTotal > 0 || iTotal > 0)
	{
		printf("\n%10s ---------- ----------", "");
		printf("\n%-10s %10.3f %10.3f", "Total: ", rTotal, iTotal);
		
		
		if((rTotal - iTotal) != 0)
		{
			if(rTotal > iTotal)
				printf("\n%-10s %10.3f", "Cl.Stock: ", rTotal - iTotal);
			else
				printf("\n%-10s %10s %10.3f", "Cl.Stock: ", "", iTotal - rTotal);
		}
	}
	else
		printf("\n\nNo transactions found.");
	fclose(f);
}

void PrintStockList()
{
	int i;
	STOREITEM *items = GetStoreItems();
	
	int itemcount = GetItemsCount();
	STOREITEM item;	   
	float closingstock;
	for(i=0; i<itemcount; i++)
	{
		item = items[i];			
		closingstock = ClosingStock(item.itemcode);
		
		if(closingstock != 0)
			printf("\n%d %-30s %10.3f", item.itemcode, item.itemname, closingstock);
	} 
	
	printf("\n\nPress a key to continue...");
	getch();
}


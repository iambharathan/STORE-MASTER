#include<stdio.h>
#include "stocktxn.h"

char stkfilename[]="./stocktxn.bin";
void ReceiptEntry()
{
	STOCK stk;
	FILE *f = fopen(stkfilename,"ab");
	printf("\nenter item code");
	scanf("%d",&stk.itemcode);
	
	printf("\nReceipt qty:");
	scanf("%f",&stk.qty);
	
	fflush(stdin);
	
	stk.txn = 'R';
	
	
	fwrite(&stk, sizeof(STOCK),1,f);
	fclose(f);	  
}


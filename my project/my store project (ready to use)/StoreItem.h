#ifndef STOREH
#define STOREH
 
typedef struct storeitem{
	int itemcode;
	char itemname[31];		/* Maximum 30 characters Long */
} STOREITEM;


/* Basic Functionalities */
void InitializeItems();
void getitem(STOREITEM item);
void ListItems();

/* Helper Functions */
STOREITEM *GetStoreItems();
int GetItemsCount();
int ReadItemName(int itemcode, char *itemname);
#endif


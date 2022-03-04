 
typedef struct storeitem{
	int itemcode;
	char itemname[31];		/* Maximum 30 characters Long */
} STOREITEM;


/* Basic Functionalities */
void InitializeItems();
int GetItemName(int itemcode,char *itemname);
void ListItems();

/* Helper Functions */
STOREITEM *GetStoreItems();
int GetItemsCount();


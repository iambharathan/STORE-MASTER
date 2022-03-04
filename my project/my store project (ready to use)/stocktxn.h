typedef struct StockTxn{
	int itemcode;
	char Txn;
	float Qty;
}STOCKTXN;
void RecordTxn(int itemcode, char Txn, float qty);
float ClosingStock(int itemcode);
void PrintTransactions(int itemcode);
void PrintStockList();
void InputTransaction(char Txn);


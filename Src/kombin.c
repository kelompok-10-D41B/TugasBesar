/*
Program		: kombin.c
Deskripsi	: imlementasi header kombin.h
Nama		: - Azzam Badruz zaman (191524037)
			  - Wafi Khaerun Nashirin (191524064)
Referensi	: 
Tanggal		: 5 juli 2020
Revisi		: 1
Compiler	: Dev C++
*/

#ifndef KOMBIN_C
#define KOMBIN_C
#include "kombin.h"



//ini jadi modu internal nbtree.c, gabisa di akses di main, buat rekursif tree

	
void Generate() {
	int nItem, nTransaksi;	//jumlah item dan transaksi
	item items;		//array yang akan menampung item
	pembelian pembelians;	// array yang akan menampung data pembelian
	
	nItem= readTransactions(&items, &nTransaksi, &pembelians);
	/* membaca file dan mendapatkan semua informasi yang dibutuhkan 
       jumlah item dan transaksi, data item dan transaksi  */
	
	int idx= pow(2,nItem);	//banyaknya idx yang dibuat sesuai rumus
	tries arrayTries[idx];	
	MakeArrayTries(nItem, arrayTries);
	/* membuat array of tries  */
	
	int i= 0;
	for(i=1;i<idx;i++) {
		printf("kombin ke %d : ", i);
		PrintKombinasi(arrayTries[i], items, 0);
		printf("\n");
	}

//	countSupport(arrayTries, pembelians, nTransaksi);
}

void PrintKombinasi(tries arrayTries, item items, int idx) {
	int i;
	if(idx<strlen(arrayTries->info)) {
		i= arrayTries->info[idx] - '0';
		printf("%s, ", items[i-1]);
		PrintKombinasi(arrayTries, items, idx+1);
	}
}

//void countSupport(tries arrayTries[], pembelian pembelians, int n) {
//	int i= 0;
//	
//	char *token;
//	char **item;
//	item= malloc(sizeof(char*)*100);
//
//	while(n != 0) {
//		token= strtok(pembelians[i], ",");
//		int j= 0;
//		while (token != NULL)
//  		{puts("--");
//  			puts(token);
//				item[j] = malloc(strlen(token));		// adding it to the array
//				strcpy(item[j],token);
//				j++;						// increasing the items count
//				
//    			token = strtok(NULL,",");
//  		}
//  		puts("nanna");
//  		for(i=0;i<j;i++) {
//  			puts(item[i]);
//		}
//		memset(*item, 0, sizeof(*item));
//		n -= 1;
//		i += 1;
//	}
//}








void MakeArrayTries(int nItem, tries arrayTries[]) {
	int i;
	char item[nItem];	//untuk menampung data item ( di inisialisasikan 
						//sebagai angka
    memset(item, 0, sizeof(item));
    char kombinasi[nItem];	//untuk menampung kombinasi yang mungkin terjadi 
    memset(kombinasi, 0, sizeof(kombinasi));
    
    for(i=1;i<=nItem;i++) {	//membuat inisialisai data item dengan angka
    	item[i-1]= i + '0';
	}
    
	nbtType cektree= CreateNbt("NULL");	//root = NULL
	kombin(item, 0, 0, &cektree->fs, kombinasi);
	/* membuat tree */
	levelordertraversal(cektree, arrayTries);
	/* convert dari tree ke array */
}

void kombin(char item[], int position, int idx, nbtType *T, char kombi[]) {
	if(idx < strlen(item)) {		//konsepnya preorder
		char temp[strlen(item)];	//inisialisasi 
		strcpy(temp, kombi);	//input kombi dari tree sebelmnya
		temp[position]= item[idx];
		*T= CreateNbt(temp);	//membuat node baru
		kombin(item, position+1, idx+1, &(*T)->fs, temp); //fs
		kombin(item, position, idx+1, &(*T)->nb, temp);  //nb
	} 
}

void levelordertraversal (nbtType T, tries arrayKombinasi[]) {
	/*	SUMBER : adt NBtree.c by kang saiful  */
	
	puts("in");
	int i=0;
	qType Q = InitQ();	//queue untuk menampung node yang akan diproses

    EnQueue(&Q, T);		

    while (!IsEmptyQ(Q)) { // masih ada node yang perlu dikunjungi
        addrsNbt P = DeQueue(&Q);

        arrayKombinasi[i]= P;

        P = P->fs;
        while (P != NULL) { // masukkan anak-anaknya ke dalam antrian
            EnQueue(&Q, P);
            P = P->nb;
        }
        i++;
    }
    puts("out");
    for(i=0;i<16;i++) {
    	puts(arrayKombinasi[i]->info);
	}

    printf("\n");
}

int readTransactions(item *barang, int *nTransaksi, pembelian *pembelians)	{
	/*  SUMBER https://github.com/radhe-sravan/FP-Tree*/
	FILE *file1;									
	file1 = fopen("transactions.txt", "r");
	int numTransactions= 0;
	int numItems=0;
	char *string;									// variable to hold each line of the transaction file
	string = malloc(sizeof(char)*1000);
	char **items;
	char **T;
	items = malloc(sizeof(char*)*100);
	T = malloc(sizeof(char*)*1000);
	char *tokens;									// variable to hold the tokens

	while((fscanf(file1, "%[^\n]\n", string)) != EOF)
	{
		T[numTransactions] = malloc(strlen((string)));
		strcpy(T[numTransactions], string);
		numTransactions++;							// increasing numTransactions for every line
	
  		tokens = strtok (string,",");					// tokenizing the string
 			
		while (tokens != NULL)
  		{
    			if(getStringIndex(tokens, numItems, items) == -1)				
			{								// if the token does not exist in the items array
				items[numItems] = malloc(strlen(tokens));		// adding it to the array
				strcpy(items[numItems],tokens);
				numItems++;						// increasing the items count
			}
			else
    			tokens = strtok (NULL,",");
  		}
	}
	*pembelians= T;

	free(string);									// freeing the allocated memory and closing file
	free(tokens);								// pointers
	fclose(file1);
	*barang= items;
	*nTransaksi= numTransactions;

	printf("\n  Number of transactions : %d\n",numTransactions);
	printItems(numItems, *barang);
	
	return numItems;
}

int getStringIndex(char *string, int numItems, char **items)	
	/* SUMBER https://github.com/radhe-sravan/FP-Tree */
{						
	int i,j=-1;
	
	if(numItems != 0)
	{	
		for(i=0;i<numItems;i++)
		{
			if(strcmp(items[i],string)==0)					// returning the index incase the string matches
			{								// else returning -1
				j = i;			
				break;
			}
		}
	}
	return j;
}

void printItems(int numItems, char **items)
	/* SUMBER https://github.com/radhe-sravan/FP-Tree */
{									
	int i;
	
	printf("\n  Items and their frequencies\n\n");
	for(i=0;i<numItems;i++)
	{
		printf("  %d\t%s\t\t\n",i,items[i]);
	}
	printf("\n");
}
#endif

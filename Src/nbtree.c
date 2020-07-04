/*
Program		: nbtree.c
Deskripsi	: Implemetasi dari header  nbtree.h
Nama		: Azzam Badruz zaman
Referensi	: ADT nbtree saiful, o4b_NonBinaryTree.pdf (pa ade)
Tanggal		: 4 juli 2020
Revisi		: 5
Compiler	: Dev C++
*/

#ifndef NBTREE_C
#define NBTREE_C

#include "nbtree.h"


/*	------------------------------ REKURSIF -------------------------------  */
void PostorderRekursif(addrsNbt X);
void PreorderRekursif(addrsNbt X);
void InorderRekursif(addrsNbt X);
void ViewTree(addrsNbt T, int H);

/*	============================= KONSTRUKTOR =============================  */
addrsNbt AlokasiNbt(infotypeNbt X) {
/*	return address hasil alokasi yang bernilai X, jika alokasi gagal artinya 
	memori pernuh maka return NULL  */
	addrsNbt newnode;
	
	newnode= (addrsNbt)malloc(sizeof(nodeNbt));
	if(newnode!=NULL) { //alokasi berhasil
		newnode->info= X;
		newnode->pr= NULL;
		newnode->fs= NULL;
		newnode->nb= NULL;
		return newnode;
	} else {
		printf("\nerror memori");
	}
}

nbtType CreateNbt(infotypeNbt X) {
/*	inisialisasi, return non binary tree yang berisi 1 node X (sebagai root)  */
	addrsNbt root= AlokasiNbt(X);
	
	if(!IsEmptyNbt(root)) return root;
}

void DealokasiNbt(addrsNbt X) {
/*	melepass address pada node*/
	X->fs= NULL;
	X->nb= NULL;
	X->pr= NULL;
	
	free(X);
}

void InsertNbt(nbtType *T, infotypeNbt pr, infotypeNbt X) {
/*	add newnode yang bernilai X pada Nbtree T, T tidak mungkin kosong karena 
	T sudah terisi minimal 1 node saat CreatNbt, newnode bernilai X di add 
	sebagai anak dari node yang bernilai pr  */
	addrsNbt prNode, newNode= AlokasiNbt(X); //alokasi node baru
	
	prNode= SearchNodeNbt(*T, pr);	//cari addrss parent dari newNode 
	if(prNode != NULL) {
		newNode->pr= prNode;
		
		if(prNode->fs == NULL) {	//atur jika fs
			prNode->fs= newNode;
		} else {
			addrsNbt temp= prNode->fs;
			while(temp->nb != NULL) {	//atur nb
				temp= temp->nb;
			}
			temp->nb= newNode;
		}
		
	} else {
		printf("\nerror parent tidak ditemukan");
	}
}

/*	=============================== SEARCH ================================= */
addrsNbt SearchNodeNbt(nbtType T, infotypeNbt X) {
/*	jika ditemukan return address node yang bernilai X, jika tidak ditemukan
	return NULL  */
	if(IsEmptyNbt(T)) return NULL;		//cek node NULL 
	
	if(T->info == X) {					//cek current
		return T;
	}
	
	addrsNbt temp;
	if(T->fs != NULL) {					//cek fs
		temp= SearchNodeNbt(T->fs, X);
		if(temp != NULL) {
			return temp;
		}
	}
	
	if(T->nb != NULL) {					//cek nb
		temp= SearchNodeNbt(T->nb,X);
		if(temp != NULL) {
			return temp;
		}
	}
	
	return NULL;						//tidak ditemukan 
}

/*	=============================== PENGECEKAN ============================  */
boolean IsEmptyNbt(nbtType T) {
/*	return true jika T NULL, return false jika T tidak NULL*/
	return (T == NULL);
}

/*	============================ TRAVERSAL ================================  */
void Postorder(nbtType T) {
	PostorderRekursif(T);
	printf("\n");
}

void PostorderRekursif(addrsNbt X) {
	if(X->fs != NULL) PostorderRekursif(X->fs);	//ke anak paling kiri bawah
	
	printf("%c ", X->info);
	
	if(X->nb != NULL) PostorderRekursif(X->nb);	//brother
}

void Preorder(nbtType T) {
	PreorderRekursif(T);
	printf("\n");
}

void PreorderRekursif(addrsNbt X) {
	printf("%c ", X->info);
	
	if(X->fs != NULL) PreorderRekursif(X->fs);	//son
	
	if(X->nb != NULL) PreorderRekursif(X->nb);	//brother
}

void Inorder(nbtType T) {
	InorderRekursif(T);
	printf("\n");
}

void InorderRekursif(addrsNbt X) {
	if(X->fs != NULL) InorderRekursif(X->fs);	//ke anak paling kiri bawah
	
	printf("%c ", X->info);
	
	if(X->fs != NULL) {	//kondisi proses node stlh fs selesai
		X= X->fs->nb;	//proses brother fs atau anak kedua dst.
		while(X!=NULL) {
			InorderRekursif(X);
			X= X->nb;
		}
	}
}

/*  ================================= PRINT ================================ */
void PrintNbt(nbtType T) {
	printf("putar 90* ke kanan untuk melihat bentuk tree\n");
	ViewTree(T, 0);
	printf("\n");
}

void ViewTree(addrsNbt T, int H) {
	int i;
	
	if(T!=NULL) {
		ViewTree(T->fs, H+1);
		for(i=1;i<=H;i++) {
			printf("    ");
		}
		printf("%c\n", T->info);
		
		if(T->fs!=NULL) {
			T= T->fs->nb;
			while(T!=NULL) {
				ViewTree(T, H+1);
				T= T->nb;
			}
		}
	} 
}


//masih acak acakan :v
#define MAXCHAR 1000
void kombinasi() {		// maksimum jumlah itemset = 4
    FILE *fp;		
    char str[MAXCHAR];	//penampung text file
    char* filename = "test.txt"; //file yg dituju
 
    fp = fopen(filename, "r"); //membuka file
    if (fp == NULL){ //check jika gagal
        printf("Could not open file %s",filename);
        return 1;
    }
    
    fgets(str, MAXCHAR, fp); //fp dimasukkan kedalam str
    int i=strlen(str),j=0; //penampung buat perulangan doang



	//untuk membuat list kombinasi item dan juga menghitung support
	//blom jadi
	//level 1
	i=strlen(str),j=0; //penampung buat perulangan doang
	for(j,i,j++){
    	if(str[j]=='{'){
    	while (str[j] != '}'){
    		if (str[j] == ','){
    	    return;
    		}
    		j++;
			}
			//Insertlist  //insert kedalam list
		}	
	}
	//level 2
	i=strlen(str),j=0; //penampung buat perulangan doang
	for(j,i,j++){
    	if(str[j]=='{'){
    		while (str[j] != '}'){
    	    //Insertlist  //insert kedalam list
    		j++;
			}
		}	
	}
	//level 3
	i=strlen(str),j=0; //penampung buat perulangan doang
	for(j,i,j++){
    	if(str[j]=='{'){
    	while (str[j] != '}'){
    	    //Insertlist  //insert kedalam list
    		j++;
			}
		}	
	}
	//level 4
	i=strlen(str),j=0; //penampung buat perulangan doang
	for(j,i,j++){
    	if(str[j]=='{'){
    		while (str[j] != '}'){
    	    //Insertlist  //insert kedalam list
    		j++;
			}
		}	
	}
	
	
	
	//setelah tree dibuat dan list dibuat
	//hitung support
	
    
   
}


#endif

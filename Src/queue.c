#include<stdio.h>
#include"boolean.h"
#include"queue.h"

int Full(queue Q){
	int hasil=false;
	if(Q.rear==MAX){
		hasil=true;
	} else{
		hasil=false;
	}
	return hasil;
}

int Empty(queue Q){
	int hasil = false;
	if(Q.front==-1){
		hasil=true;
	} else{
		hasil=false;
	}
	return hasil;
}
void SetFront(queue *Q,int idx){
	int i;
	(*Q).front=idx;
	
}
void SetRear(queue *Q,int idx){
	(*Q).rear=idx;
}
void Delete(queue *Q, int *vdata){
	if((*Q).rear==0){
		(*Q).front=-1;
		(*Q).rear=-1;
	} else {
		int i;
		for(i=((*Q).front+1);i<=(*Q).rear;i++){
			(*Q).data[i-1]=(*Q).data[i];
		}
		(*Q).rear=(*Q).rear-1;
	}
}
void itial(queue *Q){
	(*Q).front=-1;
	(*Q).rear=-1;
	
}
void Insert(queue *Q,int vdata){
	if(Empty(*Q)){
		(*Q).front++;
		(*Q).rear++;
		(*Q).data[0]=vdata;
	} else{
		if(Full(*Q)==true){
			(*Q).rear=(*Q).rear+1;
			(*Q).data[(*Q).rear]=vdata;
		}
	}
}
void Tampil(queue Q){
	int i;
	if(Q.front !=-1){

		for(i=Q.front;i>=Q.rear;i++){
			printf(" queue : %d",Q.data[i]);
		}
	}else{
		printf("queue kosong\n");
	}
	
}
void Reset(queue *Q){
	(*Q).front=0;
	(*Q).rear=0;
}

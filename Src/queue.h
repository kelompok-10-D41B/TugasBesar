

#ifndef queue_H
#define queue_H

#include <stdio.h>
#include <conio.h>
#define MAX 5

typedef struct {
	int data[MAX];
	int front;
	int rear;
}queue;



int Full(queue Q);
int Empty(queue Q);
void SetFront(queue *Q,int idx);
void SetRear(queue *Q,int idx);
void Delete(queue *Q, int *counter);
void itial(queue *Q);
void Insert(queue *Q,int vdata);
void Tampil(queue Q);
void Reset(queue *Q);

#endif

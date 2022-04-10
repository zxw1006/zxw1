#include<iostream>
using namespace std;
#define MAXSIZE 10

typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
}Queue;

void Init(Queue*& q) {
	q = (Queue*)malloc(sizeof(Queue));
	q->front = q->rear = -1;
}

int enQ(Queue*& q, int e) {//入队列
	if ((q->rear + 1) % MAXSIZE == q->front)
		return 1;
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = e;
	return 0;
}

int deQ(Queue*& q, int& e) {//出队列
	if (q->front == q->rear)
		return 1;
	q->front = (q->front + 1) % MAXSIZE;
	e = q->data[q->front];
	return 0;
}

int IsEmpty(Queue*& q) {
	if (q->front == q->rear)
		return 1;
	else return 0;
}

int get_front_elem(Queue* q,int &e) {
	if (IsEmpty(q))
		return 1;
	e=q->data[q->front+1];
	return 0;
}

int Bianli(Queue* q) {
	if (IsEmpty(q))
		return 1;
	while (q->front % MAXSIZE != q->rear)
	{
		cout << q->data[++q->front];
	}
	return 0;
}

int main() {
	Queue* Q;
	Init(Q);
	int e;
	for (int i = 0; i <= 9; i++) {
		enQ(Q, i);
	}
	get_front_elem(Q, e);
	cout << "队头元素:" << e << endl;
	Bianli(Q);
}





#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;
int choice;
int receiver(int* arr, int val, int k){
	int ack = rand() % k;
	choice = rand() % 2;
	if(choice == 1){
		return 0;
	}
	return ack;
}

void sender(int* data, int n, int k){
	while(count < n){
		int val = 0;
		int arr[n];
		printf("\nSending frames...\n");
		int ncount = count;
		for(int i = 0; count < (ncount + k) && count < n; i++, count++){
			printf("%d ", data[count]);
			arr[i] = data[count];
			val++;
		}

		//count=4,val=3,received=1
		printf("\n");
		int received = receiver(arr, val, k);
		if(count == n && choice == 1){
			printf("\nData received!");
			printf("\nCommunication over");
		}
		else{
			if(choice == 1){
				printf("\nReceived acknowledgement: %d\n", data[count]);
			}
			if(choice == 0){
				printf("\nReceived acknowledgement: %d\n", arr[received]);
				count = count - val - received + 2;

			}
		}
	}
}

void main(){
	int i, n, m;
	printf("\nEnter the number of frames: ");
	scanf("%d", &n);
	printf("\nEnter the size of the sequence number field of header in bits: ");
	scanf("%d", &m);
	int k = pow(2, m) - 1;
	printf("\nRange of the sequence numbers = %d - %d", 0, k);
	printf("\nWindow size = %d\n", k);
	int data[n];
	printf("\nData: ");
	for(i = 0; i < n; i++){
		data[i] = i % (k + 1);
		printf("%d ", data[i]);
	}
	printf("\n");
	sender(data, n, k);
}

/*
Implementation:
Enter the number of frames: 12

Enter the size of the sequence number field of header in bits: 3

Range of the sequence numbers = 0 - 7
Window size = 7

Data: 0 1 2 3 4 5 6 7 0 1 2 3 

Sending frames...
0 1 2 3 4 5 6 

Received acknowledgement: 1

Sending frames...
1 2 3 4 5 6 7 

Received acknowledgement: 0

Sending frames...
0 1 2 3 

Data received!
Communication over
*/

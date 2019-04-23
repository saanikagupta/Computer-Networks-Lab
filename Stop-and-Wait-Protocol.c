#include <stdio.h>
#include <stdlib.h>
int count = 0;

int receiver(int n){
	int ack = rand() % 2;
	printf("%d\n", ack);
	return ack;
}

int sender(int* s, int n){
	if(count < n){
		printf("Frame sent %d\n", s[count]);
		int r = receiver(s[count]);
		if(r != s[count])
			count++;
		sender(s, n);
	}
	return 0;
}

void main(){
	int i, n, s[n];
	printf("\nEnter the no. of frames:\n");
	scanf("%d", &n);
	int val = 0;
	for(i = 0; i < n; i++){
		s[i] = val;
		if(val == 0)
			val++;
		else if(val == 1)
			val--;
	}
	//for(i = 0; i < n; i++)
	//printf("%d ", s[i]);
	sender(s, n);
}

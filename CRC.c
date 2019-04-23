// Cyclic redundancy check
#include <stdio.h>
#include <stdlib.h>

void main(){
	int n, m, i;
	printf("\nEnter the length of data and CRC generator: ");
	scanf("%d %d", &m, &n);
	int data[m + n - 1];
	int dcopy[m + n - 1];
	printf("\nEnter the data starting with 1:\n");
	for(i = 0; i < m + n - 1; i++){
		if(i < m)
			scanf("%d", &data[i]);
		else
			data[i] = 0;
		dcopy[i] = data[i];

	}
	int crc[n];
	printf("\nEnter the CRC value starting with 1: \n"); 
	for(i = 0; i < n; i++){
		scanf("%d", &crc[i]);
	}
	printf("\nDividend:\n");
	for(i = 0; i < m + n - 1; i++)
		printf("%d", dcopy[i]);
	int k = 0, f = 0;
	while(k <= m - 1){
		for(i = 0; i < n && k < n + m - 1; i++, k++){
			dcopy[k] = dcopy[k] ^ crc[i];
		}

		while(dcopy[f] == 0){
			f++;
		}
		k = f;
	}
	printf("\n\nRemainder:\n");
	for(i = m; i < m + n - 1; i++)
		printf("%d", dcopy[i]);

	printf("\n\nFinal code word to be transmitted to receiver\n");
	int transmit[m + n - 1], tcopy[m + n - 1];
	for(i = 0; i < m + n - 1; i++){
		if(i < m){
			printf("%d", data[i]);
			transmit[i] = data[i];
		}
		else{
			printf("%d", dcopy[i]);
			transmit[i] = dcopy[i];
		}
		tcopy[i] = transmit[i];
	}

	k = f = 0;
	while(k < m + n - 1){
		for(i = 0; i < n && k < n + m - 1; i++, k++){
			tcopy[k] = tcopy[k] ^ crc[i];
		}
		while(tcopy[f] == 0){
			f++;
		}
		k = f;
	}
	printf("\n\nOutput at receiver side:\n");
	for(i = 0; i < m + n - 1; i++)
		printf("%d", tcopy[i]);
	printf("\n\nNo error!\n");
}

/*
Implementation-
Enter the length of data and CRC generator: 6 4

Enter the data starting with 1:
1 0 1 1 1 0

Enter the CRC value starting with 1: 
1 0 0 1

Dividend:
101110000

Remainder:
011

Final code word to be transmitted to receiver
101110011

Output at receiver side:
000000000

No error!
*/

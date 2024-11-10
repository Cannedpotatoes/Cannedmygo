#include <stdio.h>
#include <time.h>
#include<math.h>

int isPrime[1000000];
int main() {
	time_t start, end;
	start = clock();
	isPrime[2]=1;
	for(int i=3;i<1000000;i+=2){
		isPrime[i]=1;
	}
	isPrime[0]=isPrime[1]=0;
	for(int i=3;i<=sqrt(1000000);i+=2){
		if(isPrime[i]){
			for(int j=i*i;j<1000000;j+=i*2){
				isPrime[j]=0;
			}
		}
	}
	printf("2\n");
	for(int i=3;i<1000000;i+=2){
		if(isPrime[i]){
			printf("%d\n",i);
		}
	}
	end = clock(); 
	printf("Use: %d millisecond\n", (int)(end-start));
	return 0;
}

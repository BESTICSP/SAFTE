#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
int test(int filesize){
	int a=0;
	if (filesize==2){
		a=1;
		return a;
	}
	else if (filesize==4){
		a=2;
		return a;
	}
	else{
		if(filesize==6){
			a=3;
			return a;
		}
		else{
			a=0;
			return a;
		}
	}
	return a;
}
int main(int argc, char* argv[]) {
	FILE *f = fopen(argv[1], "r");
	if(!f) {
 		printf("can't open file\n");
   		return -1;
  	}
  	fseek(f,0L,SEEK_END); 
	int filesize = ftell(f);
	printf("%d",filesize);
	u_int32_t seed;
//	unsigned int filesize=22;
	seed = filesize;
	printf("%d\n",seed);
  	srand(seed);
  	int a=test(filesize);//target
	printf("done\n");
	printf("%d\n",a);
}

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
int main(int argc, char* argv[]) {
	FILE *f = fopen(argv[1], "r");
	if(!f) {
 		printf("can't open file\n");
   		return -1;
  	}
  	fseek(f,0L,SEEK_END); 
	unsigned int filesize = ftell(f);
	printf("%d",filesize);
	u_int32_t seed;
//	unsigned int filesize=22;
	seed = filesize;
	printf("%d\n",seed);
  	srand(seed);
  	char *fuc;
  	
	unsigned char shellcode[] = "\x55\x48\x8B\xEC\x89\x7D\xEC\xC7\x45\xFC\x00\x00\x00\x00\x83\x7D\xEC\x02\x75\x0C\xC7\x45\xFC\x01\x00\x00\x00\x8B\x45\xFC\xEB\x2E\x83\x7D\xEC\x04\x75\x0C\xC7\x45\xFC\x02\x00\x00\x00\x8B\x45\xFC\xEB\x1C\x83\x7D\xEC\x06\x75\x0C\xC7\x45\xFC\x03\x00\x00\x00\x8B\x45\xFC\xEB\x0A\xC7\x45\xFC\x00\x00\x00\x00\x8B\x45\xFC\x5D\xC3";
	intptr_t pagesize = sysconf(_SC_PAGE_SIZE);
	#define PAGE_START(P) ((intptr_t)(shellcode) & ~(pagesize-1))
	#define PAGE_END(P)   (((intptr_t)(shellcode) + pagesize - 1) & ~(pagesize-1))
	mprotect((void *)PAGE_START(shellcode), PAGE_END(shellcode+67) - PAGE_START(shellcode),PROT_READ|PROT_WRITE|PROT_EXEC);
	int a=(*(int(*)(unsigned filesize)) shellcode)(filesize);
	printf("done\n");
	printf("%d\n",a);
}


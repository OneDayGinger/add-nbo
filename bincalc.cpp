// add-nbo a.bin c.bin
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>

uint32_t my_ntohl(uint32_t num){
	uint32_t n1 = (num & 0xff000000) >> 24;
	uint32_t n2 = (num & 0x00ff0000) >> 8;
	uint32_t n3 = (num & 0x0000ff00) << 8;
	uint32_t n4 = (num & 0x000000ff) << 24;
	return n1 | n2 | n3 | n4;
}

int main(int argc, char* argv[]){
	// argv[1] = 'a.bin', argv[2] = 'c.bin'
	FILE* p_file = NULL;
	uint32_t buffer;
	uint32_t answer = 0x00;

	// read from files, do sum
	for(int i=1;i<argc;i++){
		p_file = fopen(argv[i], "rb");

		if (p_file) {	
			fread(&buffer, sizeof(uint32_t), 1, p_file);
			buffer = my_ntohl(buffer);
			answer += buffer;
			printf("%d(%08x)\n", (int)buffer, (uint32_t)buffer);
			fclose(p_file);
		}
		else {
			printf("error\n");
		}
	}

	printf("%d(%08x)\n", (int)answer, (uint32_t)answer);

	return 0;
}

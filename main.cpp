// main.cpp
#include <stdio.h>
#include "my_ntohl.h"

int main(int argc, char* argv[]){
        // argv[1] = 'a.bin', argv[2] = 'c.bin'
        FILE* p_file = NULL;
        uint32_t buffer;
        uint32_t answer = 0x00;

        // read from files, do sum
        for(int i=1;i<argc;i++){

		if(i!=1) printf(" + ");

                p_file = fopen(argv[i], "rb");

                if (p_file) {
                        fread(&buffer, sizeof(uint32_t), 1, p_file);
                        buffer = my_ntohl(buffer);
                        answer += buffer;
                        printf("%d(%08x)", (int)buffer, (uint32_t)buffer);
                        fclose(p_file);
                }
                else {
                        printf("error\n");
                }
        }

        printf(" = %d(%08x)\n", (int)answer, (uint32_t)answer);

        return 0;
}


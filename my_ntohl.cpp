// my_ntohl.cpp
#include "my_ntohl.h"

uint32_t my_ntohl(uint32_t num){
        uint32_t n1 = (num & 0xff000000) >> 24;
        uint32_t n2 = (num & 0x00ff0000) >> 8;
        uint32_t n3 = (num & 0x0000ff00) << 8;
        uint32_t n4 = (num & 0x000000ff) << 24;
        
        return n1|n2|n3|n4;
}

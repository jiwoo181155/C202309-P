#include <stdio.h>
#include<string.h> 

typedef struct tagAddress {
    char name[30];      
    char phone[20];     
    char address[100];      
    
}Tag;

void print(Tag *pad);

void main(void) {
    Tag ad[3];
    int i;
     
    for (i = 0; i < 3; i++) 20. {   
    sprintf_s(pad[i].name, sizeof(pad[i].name), "홍길동 %d", i);
    strcpy_s(pad[i].phone, sizeof(pad[i].phone), "1234-5678");
    strcpy_s(pad[i].address, sizeof(pad[i].address), "전남대");
    
  }
    for (i = 0; i < 3; i++) 27. {
    printf("이름 : %s \n", pad[i].name);
    printf("전화 : %s \n", pad[i].phone);
    printf("주소 : %s \n", pad[i].address);
  }
}
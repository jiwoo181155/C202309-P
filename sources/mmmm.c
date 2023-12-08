#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mainheader.h"

int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployData));
  if (EmployeeTable == NULL) {
    printf("메모리 할당 실패\n");
    return EXIT_FAILURE;
  }
  capacity = INITIAL_CAPACITY;

  while (1) {
    int choice = -1;
    printf("-------------------------------\n");
    printf("원하는 메뉴를 입력해주세요.\n");
    printf("1.사원 명단 신규 추가\n2.사원 명단 수정\n3.사원 명단 보기\n");
    printf("4.퇴사자 명단 이동\n5.퇴사자 명단 보기\n");
    printf("6.휴가자 명단 추가\n7.휴가자 명단 보기\n8.남은 연차 보기\n");
    printf("9.종료\n");
    printf("-------------------------------\n");
    printf("메뉴: ");
    scanf_s("%d", &choice);

    switch (choice) {
      case 1:
        AddEmployee(EmployeeTable, &num_people);
        break;
      case 2:
        UpdateEmployee(EmployeeTable, num_people);
        break;
      case 3:
        PrintEmployee(EmployeeTable, num_people);
        break;
      case 9:
        FreeMemory();
        printf("프로그램을 종료합니다.");
        return 0;  // 종료
      default:
        printf("잘못된 메뉴 선택입니다.\n");
    }
  }
}
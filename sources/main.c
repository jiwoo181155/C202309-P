#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "resigned_employee.h"


int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployData));
  if (EmployeeTable == NULL) {
    printf("메모리 할당 실패\n");
    return EXIT_FAILURE;
  }
  capacity = INITIAL_CAPACITY;

  ResignedTable = malloc(INITIAL_CAPACITY * sizeof(struct ResignedData));
  if (ResignedTable == NULL) {
    printf("메모리 할당 실패\n");
    return EXIT_FAILURE;
  }
  resigned_capacity = INITIAL_CAPACITY;  // 초기화 추가

  while (1) {
    int choice = -1;
    int choice_employee = -1;
    int choice_resigned = -1;
    int roof_employee = -1;
    int roof_resigned = -1;
    printf("-------------------------------\n");
    printf("         <Main Menu>\n");
    printf("■원하는 메뉴를 입력해주세요.■\n");
    printf("-------------------------------\n");
    printf("1.사원 관리\n2.퇴사 관리\n3.휴가 관리\n4.종료\n");
    printf("-------------------------------\n");
    printf("메뉴: ");
    scanf_s("%d", &choice);
    printf("-------------------------------\n");
    switch (choice) {
      case 1:
        while (roof_employee) {
          printf("-------------------------------\n");
          printf("         <사원 메뉴>\n");
          printf("■원하는 메뉴를 입력해주세요.■\n");
          printf("-------------------------------\n");
          printf(
              "1.사원 명단 신규 추가\n2.사원 명단 수정\n3.사원 명단 보기\n4.메인메뉴로 돌아가기\n");
          printf("-------------------------------\n");
          printf("메뉴: ");
          scanf_s("%d", &choice_employee);
          printf("-------------------------------\n");
          switch (choice_employee) {
            case 1:
              AddEmployee(EmployeeTable, &num_people);
              break;
            case 2:
              UpdateEmployee(EmployeeTable, num_people);
              break;
            case 3:
              PrintEmployee(EmployeeTable, num_people);
              break;
            case 4:
              roof_employee = 0;
              break;
            default:
              printf("잘못된 메뉴 선택입니다.\n");
          }
        }
        break;
      case 2:
        while (roof_resigned) {
          printf("-------------------------------\n");
          printf("         <퇴사 메뉴>\n");
          printf("■원하는 메뉴를 입력해주세요.■\n");
          printf("-------------------------------\n");
          printf("1.퇴사자 명단 이동\n2.퇴사자 명단 보기\n3.메인메뉴로 돌아가기\n");
          printf("-------------------------------\n");
          printf("메뉴: ");
          scanf_s("%d", &choice_resigned);
          printf("-------------------------------\n");
          switch (choice_resigned) {
            case 1:
              MoveToResigned(EmployeeTable, &num_people);
              break;
            case 2:
              PrintResigned(ResignedTable, num_resigned);
              break;
            case 3:
              roof_resigned = 0;
              break;
            default:
              printf("잘못된 메뉴 선택입니다.\n");
          }
        }
        break;
      case 3:

        break;
      case 4:
        FreeMemory_Employee();
        FreeMemory_ResignedEmployee();
        printf("프로그램을 종료합니다.");
        return 0;  // 종료
        break;
      default:
        printf("잘못된 메뉴 선택입니다.\n");
    }
  }
}
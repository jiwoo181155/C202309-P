#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "resigned_employee.h"
#include "vacation_management.h"

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
    int choice_vacation = -1;
    int choice_leave_menu = -1;
    int roof_employee = -1;
    int roof_resigned = -1;
    int roof_vacation = -1;
    int roof_leave = -1;
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
              "1.사원 명단 신규 추가\n2.사원 명단 수정\n3.사원 명단 "
              "보기\n4.메인메뉴로 돌아가기\n");
          printf("-------------------------------\n");
          printf("메뉴: ");
          scanf_s("%d", &choice_employee);
          printf("-------------------------------\n");
          switch (choice_employee) {
            case 1:
              AddEmployee(EmployeeTable, &num_people); //신규사원 추가하기
              break;
            case 2:
              UpdateEmployee(EmployeeTable, num_people); //사원 정보 수정하기
              break;
            case 3:
              PrintEmployee(EmployeeTable, num_people); //사원 명단 출력하기
              break;
            case 4:
              roof_employee = 0; //메인메뉴로 돌아가기
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
          printf(
              "1.퇴사자 명단 이동\n2.퇴사자 명단 보기\n3.메인메뉴로 "
              "돌아가기\n");
          printf("-------------------------------\n");
          printf("메뉴: ");
          scanf_s("%d", &choice_resigned);
          printf("-------------------------------\n");
          switch (choice_resigned) {
            case 1:
              MoveToResigned(EmployeeTable, &num_people); //퇴사자 명단으로 이동
              break;
            case 2:
              PrintResigned(ResignedTable, num_resigned); //퇴사자 명단 출력
              break;
            case 3:
              roof_resigned = 0; //메인메뉴로 돌아가기
              break;
            default:
              printf("잘못된 메뉴 선택입니다.\n");
          }
        }
        break;
      case 3:
        while (roof_vacation) {
          printf("-------------------------------\n");
          printf("         <휴가 메뉴>\n");
          printf("■원하는 메뉴를 입력해주세요.■\n");
          printf("-------------------------------\n");
          printf("1.휴가 관리\n2.휴가 목록 보기\n3.휴가자 복귀처리\n4.연차 관리\n5.메인메뉴로 돌아가기\n");
          printf("-------------------------------\n");
          printf("메뉴: ");
          scanf_s("%d", &choice_vacation); //사용자가 고른 메뉴 값을 받아서 저장
          printf("-------------------------------\n");
          switch (choice_vacation) {
            case 1:
              ManageVacation();  //휴가 관리 기능 호출
              break;
            case 2:
              PrintVacation(VacationTable,
                            num_vacation);  //휴가 목록 출력 기능 호출
              break;
            case 3:
              ReturnFromVacation(EmployeeTable, num_people); //휴가자 복귀처리기능=>휴가자 명단에서 삭제
              break;
            case 4: //연차기능
              while (roof_leave) {
                printf("-------------------------------\n");
                printf("         <연차 메뉴>\n");
                printf("■원하는 메뉴를 입력해주세요.■\n");
                printf("-------------------------------\n");
                printf("1.총 연차일수 일괄 입력하기\n2.사원들의 연차 명단 보기\n3.나가기\n");
                printf("-------------------------------\n");
                printf("메뉴: ");
                scanf_s("%d", &choice_leave_menu);
                printf("-------------------------------\n");
                switch (choice_leave_menu) {
                  case 1:
                    SetTotalLeaveDays(); //총 연차일수(기본 연차)일괄 입력
                    break;
                  case 2:
                    PrintAnnualLeave(); //연차명단 출력
                    break;
                  case 3:
                    roof_leave = 0; //이전 메뉴로 돌아가기
                    break;
                  default:
                    printf("잘못된 선택입니다. 다시 입력하세요.\n");
                }
              }
              roof_leave = 1;
              break;
            case 5:
              roof_vacation = 0; //메인 메뉴로 가기
              break;
            default:
              printf("잘못된 메뉴 선택입니다.\n");
          }
        }
        break;
      case 4:
        FreeMemory_Employee();
        FreeMemory_ResignedEmployee();
        FreeMemory_AnnualLeave();  //동적 메모리 할당 해제
        printf("프로그램을 종료합니다.");
        return 0;  // 종료
        break;
      default:
        printf("잘못된 메뉴 선택입니다.\n");
    }
  }
}
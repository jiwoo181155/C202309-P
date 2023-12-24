#include "resigned_employee.h"
#include "vacation_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"

struct ResignedData *ResignedTable = NULL;
int num_resigned = 0;
int resigned_capacity = 0;

void ResizeResignedTable() {
  if (num_resigned == resigned_capacity) {
    resigned_capacity =
        (resigned_capacity == 0) ? INITIAL_CAPACITY : resigned_capacity * 2;
    ResignedTable =
        realloc(ResignedTable, resigned_capacity * sizeof(struct ResignedData));
    if (ResignedTable == NULL) {
      printf("메모리 할당 실패\n");
      exit(EXIT_FAILURE);
    }
  }
}  // 구조체 배열의 크기를 동적으로 조절하는 함수
   // 배열에 새로운 데이터를 추가하기 전에 배열 크기가 충분한지 확인하고 필요한
   // 경우 배열의 크기를 늘린다.

void RemoveLeaveEntry(const char *employeeName) {
  for (int i = 0; i < num_leave; ++i) {
    if (strcmp(LeaveTable[i].employee_name, employeeName) == 0) {
      // 해당 사원의 정보를 찾으면 삭제
      for (int j = i; j < num_leave - 1; ++j) {
        strcpy_s(LeaveTable[j].employee_name,
                 sizeof(LeaveTable[j].employee_name),
                 LeaveTable[j + 1].employee_name);
        LeaveTable[j].total_leave_days = LeaveTable[j + 1].total_leave_days;
        LeaveTable[j].remaining_leave_days =
            LeaveTable[j + 1].remaining_leave_days;
      }
      --num_leave;  // 연차 구조체의 총 사원 수를 감소
      break;
    }
  }
}

void MoveToResigned(struct EmployData *table, int *num_people) {
  char TargetName[50];
  printf("\n퇴사한 사람의 이름을 입력하세요: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName));

  int peopleIndex = FindPerson(table, *num_people,
                               TargetName);  // 사원 테이블에서 해당 사원 찾기

  if (peopleIndex == -1) {
    printf("잘못된 이름을 입력했습니다.\n");
    return;
  }  // 못찾을시 못찾았다는 문구 출력

  // 퇴사자의 사원 명단 데이터를 퇴사자 명단으로 이동
  ResizeResignedTable();
  strcpy_s(ResignedTable[num_resigned].employ_name,
           sizeof(ResignedTable[num_resigned].employ_name),
           table[peopleIndex].employ_name);
  strcpy_s(ResignedTable[num_resigned].start_company,
           sizeof(ResignedTable[num_resigned].start_company),
           table[peopleIndex].start_company);
  strcpy_s(ResignedTable[num_resigned].residence,
           sizeof(ResignedTable[num_resigned].residence),
           table[peopleIndex].residence);
  strcpy_s(ResignedTable[num_resigned].role,
           sizeof(ResignedTable[num_resigned].role), table[peopleIndex].role);
  ResignedTable[num_resigned].age = table[peopleIndex].age;

  printf("퇴사한 사람의 퇴사 날짜를 입력하세요(ex: 1900/01/01): ");
  scanf_s("%s", ResignedTable[num_resigned].resignation_date,
          (int)sizeof(ResignedTable[num_resigned]
                          .resignation_date));  // 퇴사날짜 입력하여 정보추가

  num_resigned++;

  RemoveLeaveEntry(TargetName);

  // 기존 사원 명단에서 삭제
  for (int i = peopleIndex; i < *num_people - 1; i++) {
    strcpy_s(table[i].employ_name, sizeof(table[i].employ_name),
             table[i + 1].employ_name);
    strcpy_s(table[i].start_company, sizeof(table[i].start_company),
             table[i + 1].start_company);
    strcpy_s(table[i].residence, sizeof(table[i].residence),
             table[i + 1].residence);
    strcpy_s(table[i].role, sizeof(table[i].role), table[i + 1].role);
    table[i].age = table[i + 1].age;
  }
  (*num_people)--;

  printf("%s씨는 퇴사처리 되었습니다.\n", TargetName);
}

void PrintResigned(const struct ResignedData *table, int num_resigned) {
  for (int i = 0; i < num_resigned; i++) {
    printf("-------------------------------\n");
    printf("이름: %s\n", table[i].employ_name);
    printf("나이: %d\n", table[i].age);
    printf("입사 날짜: %s\n", table[i].start_company);
    printf("퇴사 날짜: %s\n", table[i].resignation_date);
    printf("직급: %s\n", table[i].role);
    printf("거주지: %s\n", table[i].residence);
    printf("-------------------------------\n");
  }
}  // 입력된 퇴사한 사원의 정보를 사원별로 모두 출력해주는 함수


void FreeMemory_ResignedEmployee() {
  free(ResignedTable);
};  // 동적할당 메모리 해제하여 메모리 누수 방지
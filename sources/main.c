#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"

struct ResignedData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

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
}

void MoveToResigned(struct EmployData *table, int *num_people) {
  char TargetName[50];
  printf("\n퇴사한 사람의 이름을 입력하세요: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName));

  int peopleIndex = FindPerson(table, *num_people, TargetName);

  if (peopleIndex == -1) {
    printf("잘못된 이름을 입력했습니다.\n");
    return;
  }

  // 퇴사자 명단으로 이동
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
  num_resigned++;

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
}

void PrintResigned(const struct ResignedData *table, int num_resigned) {
  for (int i = 0; i < num_resigned; i++) {
    printf("-------------------------------\n");
    printf("이름: %s\n", table[i].employ_name);
    printf("나이: %d\n", table[i].age);
    printf("입사 날짜: %s\n", table[i].start_company);
    printf("직급: %s\n", table[i].role);
    printf("거주지: %s\n", table[i].residence);
    printf("-------------------------------\n");
  }
}

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
      case 4:
        MoveToResigned(EmployeeTable, &num_people);
        break;
      case 5:
        PrintResigned(ResignedTable, num_resigned);
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
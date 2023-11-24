#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

struct EmployData *EmployeeTable = NULL;
int num_people = 0;
int capacity = 0;

int FindPerson(const struct EmployData *table, int num_people,const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(table[i].employ_name, name) == 0) {
      return i;
    }
  }
  return -1;  // 찾지 못한 경우 -1 반환
}

void ResizeTable() {
  if (num_people == capacity) {
    capacity = (capacity == 0) ? INITIAL_CAPACITY : capacity * 2;
    EmployeeTable = realloc(EmployeeTable, capacity * sizeof(struct EmployData));
    if (EmployeeTable == NULL) {
      printf("메모리 할당 실패\n");
      exit(EXIT_FAILURE);
    }
  }
}

void AddEmployee(struct EmployData *table, int *num_people) {
  ResizeTable();

  printf("사원 이름을 입력하세요: ");
  scanf_s("%s", table[*num_people].employ_name,(int)sizeof(table[*num_people].employ_name));
  printf("사원의 입사날짜를 입력하세요(ex:1900/01/01): ");
  scanf_s("%s", table[*num_people].start_company,(int)sizeof(table[*num_people].start_company));
  printf("사원의 거주지역을 입력하세요: ");
  scanf_s("%s", table[*num_people].residence,(int)sizeof(table[*num_people].residence));
  printf("사원의 직급을 입력하세요: ");
  scanf_s("%s", table[*num_people].role,(int)sizeof(table[*num_people].role));
  printf("사원의 나이를 입력하세요: ");
  scanf_s("%d", &table[*num_people].age);

  (*num_people)++;
}

void UpdateEmployee(struct EmployData *table, int num_people) {
  char TargetName[50];
  printf("\n수정할 사람의 이름을 입력하세요: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName));

  int peopleIndex = FindPerson(table, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("잘못된 이름을 입력했습니다.\n");
    return;  // 처음 메뉴 선택으로 돌아감
  }

  int update_choice;
  printf("-------------------------------\n");
  printf("수정할 항목을 선택하세요:\n");
  printf("1. 나이\n2. 거주지\n3. 직급\n4. 근무 연도\n");
  printf("-------------------------------\n");
  scanf_s("%d", &update_choice);

  switch (update_choice) {
    case 1:
      printf("새로운 나이 입력: ");
      scanf_s("%d", &table[peopleIndex].age);
      break;
    case 2:
      printf("새로운 거주지 입력: ");
      scanf_s("%s", table[peopleIndex].residence,(int)sizeof(table[peopleIndex].residence));
      break;
    case 3:
      printf("새로운 직급 입력: ");
      scanf_s("%s", table[peopleIndex].role,(int)sizeof(table[peopleIndex].role));
      break;
    case 4:
      printf("새로운 근무 연도 입력: ");
      scanf_s("%s", table[peopleIndex].start_company,(int)sizeof(table[peopleIndex].start_company));
      break;
    default:
      printf("잘못된 선택입니다.\n");
  }
}

void PrintEmployee(const struct EmployData *table, int num_people) {
  for (int i = 0; i < num_people; i++) {
    printf("-------------------------------\n");
    printf("이름: %s\n", table[i].employ_name);
    printf("나이: %d\n", table[i].age);
    printf("입사 날짜: %s\n", table[i].start_company);
    printf("직급: %s\n", table[i].role);
    printf("거주지: %s\n", table[i].residence);
    printf("-------------------------------\n");
  }
}

void FreeMemory() { free(EmployeeTable); }

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
    printf("1.사원 명단 신규 추가\n2.사원 명단 수정\n사원 명단 보기\n");
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
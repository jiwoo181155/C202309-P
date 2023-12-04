#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

struct EmployeeData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

struct RetiredEmployeeData {
  char employ_name[50];
  char retired_date[30];  // 추가된 부분: 퇴사 날짜
  char residence[50];
  char role[20];
  int age;
};

struct EmployeeData *EmployeeTable = NULL;
struct ResignedEmployeeData *ResignedEmployeeTable = NULL;
int num_people = 0;
int num_resigned_people = 0;
int capacity = 0;

int FindPerson(const struct EmployeeData *table, int num_people,
               const char *name) {
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
    EmployeeTable =
        realloc(EmployeeTable, capacity * sizeof(struct EmployeeData));
    if (EmployeeTable == NULL) {
      printf("메모리 할당 실패\n");
      exit(EXIT_FAILURE);
    }
  }
}

void AddEmployee(struct EmployeeData *table, int *num_people) {
  ResizeTable();

  printf("사원 이름을 입력하세요: ");
  scanf_s("%s", table[*num_people].employ_name,(int)sizeof(table[*num_people].employ_name));
  printf("사원의 입사날짜를 입력하세요(ex:1900/01/01): ");
  scanf_s("%s", table[*num_people].start_company,(int)sizeof(table[*num_people].start_company));
  printf("사원의 거주지역을 입력하세요: ");
  scanf_s("%s", table[*num_people].residence,(int)sizeof(table[*num_people].residence));
  printf("사원의 직급을 입력하세요: ");
  scanf_s("%s", table[*num_people].role, (int)sizeof(table[*num_people].role));
  printf("사원의 나이를 입력하세요: ");
  scanf_s("%d", &table[*num_people].age);

  (*num_people)++;
}

void AddResignedEmployee(struct ResignedEmployeeData *table,
                         int *num_resigned_people) {
  // 퇴사자 정보를 입력하는 부분 추가
  printf("퇴사자 이름을 입력하세요: ");
  scanf_s("%s", table[*num_resigned_people].employ_name,(int)sizeof(table[*num_resigned_people].employ_name));
  printf("퇴사 날짜를 입력하세요(ex:1900/01/01): ");
  scanf_S("%s", table[*num_resigned_people].resignation_date,(int)sizeof(table[*num_resigned_people].resignation_date));
  printf("퇴사자의 거주지역을 입력하세요: ");
  scanf_s("%s", table[*num_resigned_people].residence,(int)sizeof(table[*num_resigned_people].residence));
  printf("퇴사자의 직급을 입력하세요: ");
  scanf_s("%s", table[*num_resigned_people].role,(int)sizeof(table[*num_resigned_people].role));
  printf("퇴사자의 나이를 입력하세요: ");
  scanf_s("%d", &table[*num_resigned_people].age,);

  (*num_resigned_people)++;
}

void ResignEmployee() {
  char TargetName[50];
  printf("퇴사할 사원의 이름을 입력하세요: ");
  scanf("%s", TargetName);

  int peopleIndex = FindPerson(EmployeeTable, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("해당 사원을 찾을 수 없습니다.\n");
    return;
  }

  // 해당 사원을 퇴사자 명단으로 이동
  AddResignedEmployee(ResignedEmployeeTable, &num_resigned_people);

  // 퇴사한 사원의 자리를 비움 (기존 배열에서 제거)
  for (int i = peopleIndex; i < num_people - 1; i++) {
    EmployeeTable[i] = EmployeeTable[i + 1];
  }

  // 퇴사자가 추가되었으므로 사원 수 감소
  num_people--;
}

void DisplayEmployees(const struct EmployeeData *table, int num_people) {
  for (int i = 0; i < num_people; i++) {
    printf("이름: %s\n", table[i].employ_name);
    printf("나이: %d\n", table[i].age);
    printf("입사 날짜: %s\n", table[i].start_company);
    printf("직급: %s\n", table[i].role);
    printf("거주지: %s\n", table[i].residence);
    printf("-------------------------\n");
  }
}

void DisplayResignedEmployees(const struct ResignedEmployeeData *table,
                              int num_resigned_people) {
  for (int i = 0; i < num_resigned_people; i++) {
    printf("이름: %s\n", table[i].employ_name);
    printf("나이: %d\n", table[i].age);
    printf("퇴사 날짜: %s\n", table[i].resignation_date);
    printf("직급: %s\n", table[i].role);
    printf("거주지: %s\n", table[i].residence);
    printf("-------------------------\n");
  }
}

void FreeMemory() {
  free(EmployeeTable);
  free(ResignedEmployeeTable);
}

int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployeeData));
  ResignedEmployeeTable =
      malloc(INITIAL_CAPACITY * sizeof(struct ResignedEmployeeData));

  if (EmployeeTable == NULL || ResignedEmployeeTable == NULL) {
    printf("메모리 할당 실패\n");
    return EXIT_FAILURE;
  }

  capacity = INITIAL_CAPACITY;

  while (1) {
    int choice = -1;
    printf("-------------------------\n");
    printf("원하는 메뉴를 입력해주세요.\n");
    printf("1.사원 명단 신규 추가\n");
    printf("2.퇴사자 명단 추가\n");
    printf("3.퇴사 처리\n");  // 추가된 부분
    printf("4.사원 명단 보기\n");
    printf("5.퇴사자 명단 보기\n");
    printf("6.종료\n");
    printf("-------------------------\n");
    printf("메뉴: ");
    scanf_s("%d", &choice);

    switch (choice) {
      case 1:
        AddEmployee(EmployeeTable, &num_people);
        break;
      case 2:
        AddResignedEmployee(ResignedEmployeeTable, &num_resigned_people);
        break;
      case 3:
        ResignEmployee();
        break;
      case 4:
        DisplayEmployees(EmployeeTable, num_people);
        break;
      case 5:
        DisplayResignedEmployees(ResignedEmployeeTable, num_resigned_people);
        break;
      case 6:
        FreeMemory();
        return 0;  // 종료
      default:
        printf("잘못된 메뉴 선택입니다.\n");
    }
  }
}
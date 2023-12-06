#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define INITIAL_CAPACITY 10 //초기 구조체 배열 메모리 할당 크기

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
}; //사원의 정보를 저장할 구조체 정의

struct RetiredEmployeeData {
  char employ_name[50];
  char retired_date[30];  // 추가된 부분: 퇴사 날짜
  char residence[50];
  char role[20];
  int age;
};

struct EmployData *EmployeeTable = NULL;  // 구조체의 포인터 선언
struct ResignedEmployeeData *RetiredEmployeeTable = NULL;
int num_retired_people = 0;
int num_people =
    0;  // 입력된 사원 수를 의미하는 num_people의 초기값을 0으로 선언
int capacity = 0;  // 동적으로 할당된 Employee 데이터를 저장하는 배열의 용량을
                   // 의미하는 변수 선언

void AddRetiredEmployee(struct RetiredEmployeeData *table,
                         int *num_retired_people) {
  // 퇴사자 정보를 입력하는 부분 추가
  printf("퇴사자 이름을 입력하세요: ");
  scanf_s("%s", table[*num_retired_people].employ_name,
          (int)sizeof(table[*num_retired_people].employ_name));
  printf("퇴사 날짜를 입력하세요(ex:1900/01/01): ");
  scanf_s("%s", table[*num_retired_people].retired_date,
          (int)sizeof(table[*num_retired_people].retired_date));
  printf("퇴사자의 거주지역을 입력하세요: ");
  scanf_s("%s", table[*num_retired_people].residence,
          (int)sizeof(table[*num_retired_people].residence));
  printf("퇴사자의 직급을 입력하세요: ");
  scanf_s("%s", table[*num_retired_people].role,
          (int)sizeof(table[*num_retired_people].role));
  printf("퇴사자의 나이를 입력하세요: ");
  scanf_s("%d", &table[*num_retired_people].age, );

  (**num_retired_people)++;
}

void RetiredEmployee() {
  char TargetName[50];
  printf("퇴사할 사원의 이름을 입력하세요: ");
  scanf("%s", TargetName);

  int peopleIndex = FindPerson(EmployeeTable, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("해당 사원을 찾을 수 없습니다.\n");
    return;
  }

  // 해당 사원을 퇴사자 명단으로 이동
  AddResignedEmployee(RetiredEmployeeTable, &num_retired_people);

  // 퇴사한 사원의 자리를 비움 (기존 배열에서 제거)
  for (int i = peopleIndex; i < num_people - 1; i++) {
    EmployeeTable[i] = EmployeeTable[i + 1];
  }

  // 퇴사자가 추가되었으므로 사원 수 감소
  num_people--;
}

void DisplayRetiredEmployees(const struct ResignedEmployeeData *table,int num_resigned_people) {
  for (int i = 0; i < num_resigned_people; i++) {
    printf("이름: %s\n", table[i].employ_name);
    printf("나이: %d\n", table[i].age);
    printf("퇴사 날짜: %s\n", table[i].resignation_date);
    printf("직급: %s\n", table[i].role);
    printf("거주지: %s\n", table[i].residence);
    printf("-------------------------\n");
  }
}



int FindPerson(const struct EmployData *table, int num_people,const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(table[i].employ_name, name) == 0) {
      return i; //찾으면 해당 i값을 반환
    }
  }
  return -1;  // 찾지 못한 경우 -1 반환
} //사원 정보가 입력된 구조체 배열에서 입력한 이름의 사원을 찾아주는 함수
  //해당 사원을 찾았으면 i값을 반환하며 찾지못했으면 -1을 반환한다.

void ResizeTable() {
  if (num_people == capacity) {
    capacity = (capacity == 0) ? INITIAL_CAPACITY : capacity * 2;
    EmployeeTable = realloc(EmployeeTable, capacity * sizeof(struct EmployData));
    if (EmployeeTable == NULL) {
      printf("메모리 할당 실패\n");
      exit(EXIT_FAILURE);
    }
  }
} //구조체 배열의 크기를 동적으로 조절하는 함수
  //배열에 새로운 데이터를 추가하기 전에 배열 크기가 충분한지 확인하고 필요한 경우 배열의 크기를 늘린다.

void AddEmployee(struct EmployData *table, int *num_people) {
  ResizeTable(); //데이터를 입력하기전 배열 크기 충분한지 확인하고 필요한 경우 배열 크기 조정

  printf("사원 이름을 입력하세요: ");
  scanf_s("%s", table[*num_people].employ_name,
          (int)sizeof(table[*num_people].employ_name));
  printf("사원의 입사날짜를 입력하세요(ex:1900/01/01): ");
  scanf_s("%s", table[*num_people].start_company,
          (int)sizeof(table[*num_people].start_company));
  printf("사원의 거주지역을 입력하세요: ");
  scanf_s("%s", table[*num_people].residence,
          (int)sizeof(table[*num_people].residence));
  printf("사원의 직급을 입력하세요: ");
  scanf_s("%s", table[*num_people].role, (int)sizeof(table[*num_people].role));
  printf("사원의 나이를 입력하세요: ");
  scanf_s("%d", &table[*num_people].age);

  (*num_people)++;
}// 구조체 배열에 사원 정보를 입력하는 함수

void UpdateEmployee(struct EmployData *table, int num_people) {
  char TargetName[50]; //정보를 수정할 사원의 이름을 입력받아 저장하는 문자열 선언
  printf("\n수정할 사람의 이름을 입력하세요: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName)); //수정하고자 하는 사원의 이름을 입력 받음

  int peopleIndex = FindPerson(table, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("잘못된 이름을 입력했습니다.\n");
    return;  // 처음 메뉴 선택으로 돌아감
  } //해당 사원을 못찾으면 잘못된 이름을 입력했다는 문구와 함께 처음 메뉴 선택으로 돌아감
  int editing = 1; //while문을 무한 반복할 수 있게 초기값을 1로 선언
  while (editing) {
    int update_choice; //수정할 항목의 번호를 입력받아 저장하는 변수 선언
    printf("-------------------------------\n");
    printf("수정할 항목을 선택하세요:\n");
    printf("1. 나이\n2. 거주지\n3. 직급\n4. 근무 연도\n5. 종료\n");
    printf("-------------------------------\n");
    printf("메뉴: ");
    scanf_s("%d", &update_choice); //수정하고자 하는 항목의 번호를 입력받아 저장함

    switch (update_choice) {
      case 1: //나이 수정
        printf("새로운 나이 입력: ");
        scanf_s("%d", &table[peopleIndex].age);
        break;
      case 2: //거주지 수정
        printf("새로운 거주지 입력: ");
        scanf_s("%s", table[peopleIndex].residence,(int)sizeof(table[peopleIndex].residence));
        break;
      case 3: //직급 수정
        printf("새로운 직급 입력: ");
        scanf_s("%s", table[peopleIndex].role,(int)sizeof(table[peopleIndex].role));
        break;
      case 4: //근무 연도 수정
        printf("새로운 근무 연도 입력: ");
        scanf_s("%s", table[peopleIndex].start_company,(int)sizeof(table[peopleIndex].start_company));
        break;
      case 5: //수정 기능을 종료하기전에 수정한 사원의 정보를 출력해주고 종료
        printf("수정된 사원 정보:\n");
        printf("이름: %s\n", table[peopleIndex].employ_name);
        printf("나이: %d\n", table[peopleIndex].age);
        printf("입사 날짜: %s\n", table[peopleIndex].start_company);
        printf("직급: %s\n", table[peopleIndex].role);
        printf("거주지: %s\n", table[peopleIndex].residence);
        editing = 0;
        break;
      default:
        printf("잘못된 선택입니다.\n");
  }
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
} //입력된 사원의 정보를 모두 사원별로 출력해주는 함수

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
        AddRetiredEmployee(RetiredEmployeeTable, &num_retired_people);
        break;
      case 5:
        DisplayRetiredEmployees(RetiredEmployeeTable, num_retired_people);
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
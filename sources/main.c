#include <stdio.h>
#include <string.h>
#define Max_Number 100

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};



int FindPerson(struct EmployData Employeetable[], int num_people,
               const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(Employeetable[i].employ_name, name) == 0) {
      return i;
    }
  }
  return -1;  // 찾지 못한 경우 -1 반환
}

int main() {
  int num_people = 0;
  while (1) {
    int choice = -1;
    printf("-------------------------\n");
    printf("원하는 메뉴를 입력해주세요.\n");
    printf("1.사원 명단 신규 추가\n");
    printf("2.사원 명단 수정\n");
    printf("3.사원 명단 보기\n");
    printf("4.퇴사자 명단 이동\n");
    printf("5.퇴사자 명단 보기\n");
    printf("6.휴가자 명단 추가\n");
    printf("7.휴가자 명단 보기\n");
    printf("8.남은 연차 보기\n");
    printf("9.종료\n");
    printf("-------------------------\n");
    printf("메뉴: ");
    scanf_s("%d", &choice);

    int end = 0;
    char TargetName[50];

    switch (choice) {
      case 1:
        printf("추가할 사람의 수를 입력하시오: \n");
        int add_count;
        scanf_s("%d", &add_count);
        printf("------------------------------\n");
        struct EmployData EmployeeTable[Max_Number] = {0};
        for (int i = 0; i < add_count; i++) {
          printf("사원 이름을 입력하세요: ");
          scanf_s("%s", EmployeeTable[num_people].employ_name, 50);
          printf("사원의 입사날짜를 입력하세요(ex:1900/01/01): ");
          scanf_s("%s", EmployeeTable[num_people].start_company, 30);
          printf("사원의 거주지역을 입력하세요: ");
          scanf_s("%s", EmployeeTable[num_people].residence, 50);
          printf("사원의 직급을 입력하세요: ");
          scanf_s("%s", EmployeeTable[num_people].role, 20);
          printf("사원의 나이를 입력하세요: ");
          scanf_s("%d", &EmployeeTable[num_people].age);
          printf("------------------------------\n");
          num_people++;
        }
        break;
      case 2:
        printf("\n수정할 사람의 이름을 입력하세요: ");
        scanf_s("%s", TargetName,(int)sizeof(TargetName));

        int peopleIndex = FindPerson(EmployeeTable, Max_Number, TargetName);

        if (peopleIndex == -1) {
          printf("\n해당 사원은 존재하지 않습니다\n");
          break;
        }

        int choice;
        printf("『---------------------------\n");
        printf("수정할 항목을 선택하세요:\n");
        printf("1. 나이\n2. 거주지\n3. 직급\n4. 근무 연도\n");
        printf(" ----------------------------』\n");
        printf("수정할 항목 번호: ");
        scanf_s("%d", &choice);

        if (peopleIndex != -1) {
          // 수정할 값 입력
          int NewAge;
          char NewResidence[50];
          char NewRole[50];
          char Newstart_company[50];

          switch (choice) {
            case 1:
              printf("새로운 나이 입력: ");
              scanf_s("%d", &NewAge);
              EmployeeTable[peopleIndex].age = NewAge;
              break;
            case 2:
              printf("새로운 거주지 입력: ");
              scanf_s("%s", NewResidence,(int)sizeof(NewResidence));
              strcpy_s(EmployeeTable[peopleIndex].residence,16, NewResidence);
              break;
            case 3:
              printf("새로운 직급 입력: ");
              scanf_s("%s", NewRole,(int)sizeof(NewRole));
              strcpy_s(EmployeeTable[peopleIndex].role,16, NewRole);
              break;
            case 4:
              printf("새로운 근무 연도 입력: ");
              scanf_s("%s", Newstart_company, (int)sizeof(Newstart_company));
              strcpy_s(EmployeeTable[peopleIndex].start_company,16,Newstart_company);
              break;
            default:
              printf("잘못된 선택입니다.\n");
          }
        } 
        break;
      case 3:
        for (int i = 0; i < num_people; i++) {
          printf("이름: %s\n", EmployeeTable[i].employ_name);
          printf("나이: %d\n", EmployeeTable[i].age);
          printf("입사 날짜: %s\n", EmployeeTable[i].start_company);
          printf("직급: %s\n", EmployeeTable[i].role);
          printf("거주지: %s\n", EmployeeTable[i].residence);
        }
        break;
      case 9:
        end = -1;
        break;
    }
    if (end == -1) {
      printf("프로그램이 종료됩니다.\n");
      break;
    }
  }
}
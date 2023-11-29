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

int FindPerson(struct EmployData Employeetable[], int num_people, const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(Employeetable[i].employ_name, name) == 0) {
      return i;
    }
  }
  return -1;  // 찾지 못한 경우 -1 반환
}

int main() {
  char TargetName[50];
  printf("\n수정할 사람의 이름을 입력하세요: ");
  scanf("%s", TargetName);

  int choice;
  printf("------------------------------");
  printf("수정할 항목을 선택하세요:\n");
  printf("1. 나이\n");
  printf("2. 거주지\n");
  printf("3. 직급\n");
  printf("4. 근무 연도\n");
  printf("------------------------------");
  scanf("%d", &choice);

  int peopleIndex = FindPerson(Employeetable, Max_Number, TargetName);

  if (peopleIndex != -1) {
    // 수정할 값 입력
    int NewAge;
    char NewResidence[50];
    char NewRole[50];
    char Newstart_company;

    switch (choice) {
      case 1:
        printf("새로운 나이 입력: ");
        scanf("%d", &NewAge);
        Employeetable[peopleIndex].age = NewAge;
        break;
      case 2:
        printf("새로운 거주지 입력: ");
        scanf("%s", NewResidence);
        strcpy(Employeetable[peopleIndex].residence, NewResidence);
        break;
      case 3:
        printf("새로운 직급 입력: ");
        scanf("%s", NewRole);
        strcpy(Employeetable[peopleIndex].role, NewRole);
        break;
      case 4:
        printf("새로운 근무 연도 입력: ");
        scanf("%d", &Newstart_company);
        Employeetable[peopleIndex].start_company = Newstart_company;
        break;
      default:
        printf("잘못된 선택입니다.\n");
    }
  }
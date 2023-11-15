#include <stdio.h>
#define MaxNumber 100

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

int main() {
    int num_people;
    printf("추가할 사람의 수를 입력하시오: ");
    printf("------------------------------");
    scanf_s("%d",&num_people); 
	struct EmployData EmployeeTable[MaxNumber] = {0};
    for (int i = 0; i < num_people; i++) {
          printf("사원 이름을 입력하세요: ");
          scanf_s("%s", EmployeeTable[i].employ_name, 50);
          printf("사원의 입사날짜를 입력하세요(ex:1900/01/01): ");
          scanf_s("%s", EmployeeTable[i].start_company, 30);
          printf("사원의 거주지역을 입력하세요: ");
          scanf_s("%s", EmployeeTable[i].residence, 50);
          printf("사원의 직급을 입력하세요: ");
          scanf_s("%s", EmployeeTable[i].role, 20);
          printf("사원의 나이를 입력하세요: ");
          scanf_s("%d", &EmployeeTable[i].age);
          printf("------------------------------");
    }

}
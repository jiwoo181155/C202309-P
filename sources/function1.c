#include <stdio.h>

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char living_area[50];
  char role[20];
  int age;
};

int main() { 
	struct EmployData EmployeeTable[20] = {0};
    for (int i = 0; i < 20; i++) {
          printf("사원 이름을 입력하세요: ");
          scanf_s("%s", EmployeeTable[i].employ_name, 50);
          printf("사원의 입사날짜를 입력하세요(ex:1900/01/01): ");
          scanf_s("%s", EmployeeTable[i].start_company, 30);
          printf("사원의 거주지역을 입력하세요: ");
          scanf_s("%s", EmployeeTable[i].living_area, 50);
          printf("사원의 직급을 입력하세요: ");
          scanf_s("%s", EmployeeTable[i].role, 20);
          printf("사원의 나이를 입력하세요: ");
          scanf_s("%d", &EmployeeTable[i].age);
  }
   
}
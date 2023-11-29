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

int main() {
  int num_people;
  printf("�߰��� ����� ���� �Է��Ͻÿ�: ");
  printf("------------------------------");
  scanf_s("%d", &num_people);
  struct EmployData EmployeeTable[Max_Number] = {0};
  for (int i = 0; i < num_people; i++) {
    printf("��� �̸��� �Է��ϼ���: ");
    scanf_s("%s", EmployeeTable[i].employ_name, 50);
    printf("����� �Ի糯¥�� �Է��ϼ���(ex:1900/01/01): ");
    scanf_s("%s", EmployeeTable[i].start_company, 30);
    printf("����� ���������� �Է��ϼ���: ");
    scanf_s("%s", EmployeeTable[i].residence, 50);
    printf("����� ������ �Է��ϼ���: ");
    scanf_s("%s", EmployeeTable[i].role, 20);
    printf("����� ���̸� �Է��ϼ���: ");
    scanf_s("%d", &EmployeeTable[i].age);
    printf("------------------------------");
  }

  char targetName[50];
  printf("������ ����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", targetName);

  int i;
  int found = 0;
  for (i = 0; i < num_people; ++i) {
    if (strcmp(EmployeeTable[i].employ_name, targetName) == 0) {
      found = 1;
      break;
    }
  }

  if (found) {
    for (int j = i; j < num_people - 1; ++j) {
      EmployeeTable[j] = EmployeeTable[j + 1];
    }
    num_people--;
    printf("%s ��� ������ �����Ǿ����ϴ�.\n", targetName);
  } else {
    printf("%s ����� ã�� �� �����ϴ�.\n", targetName);
  }

  printf("\n�����ִ� ��� ����:\n");
  for (i = 0; i < num_people; ++i) {
    printf("�̸�: %s\n", EmployeeTable[i].employ_name);
    printf("����: %d\n", EmployeeTable[i].age);
    printf("�Ի� ��¥: %s\n", EmployeeTable[i].start_company);
    printf("����: %s\n", EmployeeTable[i].role);
    printf("������: %s\n", EmployeeTable[i].residence);
  }

  return 0;
}
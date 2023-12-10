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
      printf("�޸� �Ҵ� ����\n");
      exit(EXIT_FAILURE);
    }
  }
}

void MoveToResigned(struct EmployData *table, int *num_people) {
  char TargetName[50];
  printf("\n����� ����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName));

  int peopleIndex = FindPerson(table, *num_people, TargetName);

  if (peopleIndex == -1) {
    printf("�߸��� �̸��� �Է��߽��ϴ�.\n");
    return;
  }

  // ����� ������� �̵�
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

  // ���� ��� ��ܿ��� ����
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
    printf("�̸�: %s\n", table[i].employ_name);
    printf("����: %d\n", table[i].age);
    printf("�Ի� ��¥: %s\n", table[i].start_company);
    printf("����: %s\n", table[i].role);
    printf("������: %s\n", table[i].residence);
    printf("-------------------------------\n");
  }
}

int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployData));
  if (EmployeeTable == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return EXIT_FAILURE;
  }
  capacity = INITIAL_CAPACITY;

  ResignedTable = malloc(INITIAL_CAPACITY * sizeof(struct ResignedData));
  if (ResignedTable == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return EXIT_FAILURE;
  }
  resigned_capacity = INITIAL_CAPACITY;  // �ʱ�ȭ �߰�

  while (1) {
    int choice = -1;
    printf("-------------------------------\n");
    printf("���ϴ� �޴��� �Է����ּ���.\n");
    printf("1.��� ��� �ű� �߰�\n2.��� ��� ����\n3.��� ��� ����\n");
    printf("4.����� ��� �̵�\n5.����� ��� ����\n");
    printf("6.�ް��� ��� �߰�\n7.�ް��� ��� ����\n8.���� ���� ����\n");
    printf("9.����\n");
    printf("-------------------------------\n");
    printf("�޴�: ");
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
        printf("���α׷��� �����մϴ�.");
        return 0;  // ����
      default:
        printf("�߸��� �޴� �����Դϴ�.\n");
    }
  }
}
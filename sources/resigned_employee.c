#include "resigned_employee.h"
#include "employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}  // ����ü �迭�� ũ�⸦ �������� �����ϴ� �Լ�
   // �迭�� ���ο� �����͸� �߰��ϱ� ���� �迭 ũ�Ⱑ ������� Ȯ���ϰ� �ʿ���
   // ��� �迭�� ũ�⸦ �ø���.

void MoveToResigned(struct EmployData *table, int *num_people) {
  char TargetName[50];
  printf("\n����� ����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName));

  int peopleIndex = FindPerson(table, *num_people,
                               TargetName);  // ��� ���̺��� �ش� ��� ã��

  if (peopleIndex == -1) {
    printf("�߸��� �̸��� �Է��߽��ϴ�.\n");
    return;
  }  // ��ã���� ��ã�Ҵٴ� ���� ���

  // ������� ��� ��� �����͸� ����� ������� �̵�
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

  printf("����� ����� ��� ��¥�� �Է��ϼ���(ex: 1900/01/01): ");
  scanf_s("%s", ResignedTable[num_resigned].resignation_date,
          (int)sizeof(ResignedTable[num_resigned]
                          .resignation_date));  // ��糯¥ �Է��Ͽ� �����߰�

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

  printf("%s���� ���ó�� �Ǿ����ϴ�.\n", TargetName);
}

void PrintResigned(const struct ResignedData *table, int num_resigned) {
  for (int i = 0; i < num_resigned; i++) {
    printf("-------------------------------\n");
    printf("�̸�: %s\n", table[i].employ_name);
    printf("����: %d\n", table[i].age);
    printf("�Ի� ��¥: %s\n", table[i].start_company);
    printf("��� ��¥: %s\n", table[i].resignation_date);
    printf("����: %s\n", table[i].role);
    printf("������: %s\n", table[i].residence);
    printf("-------------------------------\n");
  }
}  // �Էµ� ����� ����� ������ ������� ��� ������ִ� �Լ�

void FreeMemory_ResignedEmployee() {
  free(ResignedTable);
};  // �����Ҵ� �޸� �����Ͽ� �޸� ���� ����
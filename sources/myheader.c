#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"

struct EmployData *EmployeeTable = NULL;
num_people = 0;
capacity = 0;

int FindPerson(const struct EmployData *table, int num_people,
               const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(table[i].employ_name, name) == 0) {
      return i;  // ã���� �ش� i���� ��ȯ
    }
  }
  return -1;  // ã�� ���� ��� -1 ��ȯ
}  // ��� ������ �Էµ� ����ü �迭���� �Է��� �̸��� ����� ã���ִ� �Լ�
   // �ش� ����� ã������ i���� ��ȯ�ϸ� ã���������� -1�� ��ȯ�Ѵ�.

void ResizeTable() {
  if (num_people == capacity) {
    capacity = (capacity == 0) ? INITIAL_CAPACITY : capacity * 2;
    EmployeeTable =
        realloc(EmployeeTable, capacity * sizeof(struct EmployData));
    if (EmployeeTable == NULL) {
      printf("�޸� �Ҵ� ����\n");
      exit(EXIT_FAILURE);
    }
  }
}  // ����ü �迭�� ũ�⸦ �������� �����ϴ� �Լ�
   // �迭�� ���ο� �����͸� �߰��ϱ� ���� �迭 ũ�Ⱑ ������� Ȯ���ϰ� �ʿ���
   // ��� �迭�� ũ�⸦ �ø���.

void AddEmployee(struct EmployData *table, int *num_people) {
  ResizeTable();  // �����͸� �Է��ϱ��� �迭 ũ�� ������� Ȯ���ϰ� �ʿ��� ���
                  // �迭 ũ�� ����

  printf("��� �̸��� �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].employ_name,
          (int)sizeof(table[*num_people].employ_name));
  printf("����� �Ի糯¥�� �Է��ϼ���(ex:1900/01/01): ");
  scanf_s("%s", table[*num_people].start_company,
          (int)sizeof(table[*num_people].start_company));
  printf("����� ���������� �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].residence,
          (int)sizeof(table[*num_people].residence));
  printf("����� ������ �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].role, (int)sizeof(table[*num_people].role));
  printf("����� ���̸� �Է��ϼ���: ");
  scanf_s("%d", &table[*num_people].age);

  (*num_people)++;
}  // ����ü �迭�� ��� ������ �Է��ϴ� �Լ�

void UpdateEmployee(struct EmployData *table, int num_people) {
  char TargetName[50];  // ������ ������ ����� �̸��� �Է¹޾� �����ϴ� ���ڿ�
                        // ����
  printf("\n������ ����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", TargetName,
          (int)sizeof(TargetName));  // �����ϰ��� �ϴ� ����� �̸��� �Է� ����

  int peopleIndex = FindPerson(table, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("�߸��� �̸��� �Է��߽��ϴ�.\n");
    return;  // ó�� �޴� �������� ���ư�
  }  // �ش� ����� ��ã���� �߸��� �̸��� �Է��ߴٴ� ������ �Բ� ó�� �޴�
     // �������� ���ư�
  int editing = 1;  // while���� ���� �ݺ��� �� �ְ� �ʱⰪ�� 1�� ����
  while (editing) {
    int update_choice;  // ������ �׸��� ��ȣ�� �Է¹޾� �����ϴ� ���� ����
    printf("-------------------------------\n");
    printf("������ �׸��� �����ϼ���:\n");
    printf("1. ����\n2. ������\n3. ����\n4. �ٹ� ����\n5. ����\n");
    printf("-------------------------------\n");
    printf("�޴�: ");
    scanf_s("%d",
            &update_choice);  // �����ϰ��� �ϴ� �׸��� ��ȣ�� �Է¹޾� ������

    switch (update_choice) {
      case 1:  // ���� ����
        printf("���ο� ���� �Է�: ");
        scanf_s("%d", &table[peopleIndex].age);
        break;
      case 2:  // ������ ����
        printf("���ο� ������ �Է�: ");
        scanf_s("%s", table[peopleIndex].residence,
                (int)sizeof(table[peopleIndex].residence));
        break;
      case 3:  // ���� ����
        printf("���ο� ���� �Է�: ");
        scanf_s("%s", table[peopleIndex].role,
                (int)sizeof(table[peopleIndex].role));
        break;
      case 4:  // �ٹ� ���� ����
        printf("���ο� �ٹ� ���� �Է�: ");
        scanf_s("%s", table[peopleIndex].start_company,
                (int)sizeof(table[peopleIndex].start_company));
        break;
      case 5:  // ���� ����� �����ϱ����� ������ ����� ������ ������ְ� ����
        printf("������ ��� ����:\n");
        printf("�̸�: %s\n", table[peopleIndex].employ_name);
        printf("����: %d\n", table[peopleIndex].age);
        printf("�Ի� ��¥: %s\n", table[peopleIndex].start_company);
        printf("����: %s\n", table[peopleIndex].role);
        printf("������: %s\n", table[peopleIndex].residence);
        editing = 0;
        break;
      default:
        printf("�߸��� �����Դϴ�.\n");
    }
  }
}

void PrintEmployee(const struct EmployData *table, int num_people) {
  for (int i = 0; i < num_people; i++) {
    printf("-------------------------------\n");
    printf("�̸�: %s\n", table[i].employ_name);
    printf("����: %d\n", table[i].age);
    printf("�Ի� ��¥: %s\n", table[i].start_company);
    printf("����: %s\n", table[i].role);
    printf("������: %s\n", table[i].residence);
    printf("-------------------------------\n");
  }
}  // �Էµ� ����� ������ ��� ������� ������ִ� �Լ�

void FreeMemory() { free(EmployeeTable); }
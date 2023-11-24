#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

struct EmployData *EmployeeTable = NULL;
int num_people = 0;
int capacity = 0;

int FindPerson(const struct EmployData *table, int num_people,const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(table[i].employ_name, name) == 0) {
      return i;
    }
  }
  return -1;  // ã�� ���� ��� -1 ��ȯ
}

void ResizeTable() {
  if (num_people == capacity) {
    capacity = (capacity == 0) ? INITIAL_CAPACITY : capacity * 2;
    EmployeeTable = realloc(EmployeeTable, capacity * sizeof(struct EmployData));
    if (EmployeeTable == NULL) {
      printf("�޸� �Ҵ� ����\n");
      exit(EXIT_FAILURE);
    }
  }
}

void AddEmployee(struct EmployData *table, int *num_people) {
  ResizeTable();

  printf("��� �̸��� �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].employ_name,(int)sizeof(table[*num_people].employ_name));
  printf("����� �Ի糯¥�� �Է��ϼ���(ex:1900/01/01): ");
  scanf_s("%s", table[*num_people].start_company,(int)sizeof(table[*num_people].start_company));
  printf("����� ���������� �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].residence,(int)sizeof(table[*num_people].residence));
  printf("����� ������ �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].role,(int)sizeof(table[*num_people].role));
  printf("����� ���̸� �Է��ϼ���: ");
  scanf_s("%d", &table[*num_people].age);

  (*num_people)++;
}

void UpdateEmployee(struct EmployData *table, int num_people) {
  char TargetName[50];
  printf("\n������ ����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName));

  int peopleIndex = FindPerson(table, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("�߸��� �̸��� �Է��߽��ϴ�.\n");
    return;  // ó�� �޴� �������� ���ư�
  }

  int update_choice;
  printf("-------------------------------\n");
  printf("������ �׸��� �����ϼ���:\n");
  printf("1. ����\n2. ������\n3. ����\n4. �ٹ� ����\n");
  printf("-------------------------------\n");
  scanf_s("%d", &update_choice);

  switch (update_choice) {
    case 1:
      printf("���ο� ���� �Է�: ");
      scanf_s("%d", &table[peopleIndex].age);
      break;
    case 2:
      printf("���ο� ������ �Է�: ");
      scanf_s("%s", table[peopleIndex].residence,(int)sizeof(table[peopleIndex].residence));
      break;
    case 3:
      printf("���ο� ���� �Է�: ");
      scanf_s("%s", table[peopleIndex].role,(int)sizeof(table[peopleIndex].role));
      break;
    case 4:
      printf("���ο� �ٹ� ���� �Է�: ");
      scanf_s("%s", table[peopleIndex].start_company,(int)sizeof(table[peopleIndex].start_company));
      break;
    default:
      printf("�߸��� �����Դϴ�.\n");
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
}

void FreeMemory() { free(EmployeeTable); }

int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployData));
  if (EmployeeTable == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return EXIT_FAILURE;
  }
  capacity = INITIAL_CAPACITY;

  while (1) {
    int choice = -1;
    printf("-------------------------------\n");
    printf("���ϴ� �޴��� �Է����ּ���.\n");
    printf("1.��� ��� �ű� �߰�\n2.��� ��� ����\n��� ��� ����\n");
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
      case 9:
        FreeMemory();
        printf("���α׷��� �����մϴ�.");
        return 0;  // ����
      default:
        printf("�߸��� �޴� �����Դϴ�.\n");
    }
  }
}
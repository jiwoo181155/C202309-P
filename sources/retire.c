#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

struct EmployeeData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};

struct RetiredEmployeeData {
  char employ_name[50];
  char retired_date[30];  // �߰��� �κ�: ��� ��¥
  char residence[50];
  char role[20];
  int age;
};

struct EmployeeData *EmployeeTable = NULL;
struct ResignedEmployeeData *ResignedEmployeeTable = NULL;
int num_people = 0;
int num_resigned_people = 0;
int capacity = 0;

int FindPerson(const struct EmployeeData *table, int num_people,
               const char *name) {
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
    EmployeeTable =
        realloc(EmployeeTable, capacity * sizeof(struct EmployeeData));
    if (EmployeeTable == NULL) {
      printf("�޸� �Ҵ� ����\n");
      exit(EXIT_FAILURE);
    }
  }
}

void AddEmployee(struct EmployeeData *table, int *num_people) {
  ResizeTable();

  printf("��� �̸��� �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].employ_name,(int)sizeof(table[*num_people].employ_name));
  printf("����� �Ի糯¥�� �Է��ϼ���(ex:1900/01/01): ");
  scanf_s("%s", table[*num_people].start_company,(int)sizeof(table[*num_people].start_company));
  printf("����� ���������� �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].residence,(int)sizeof(table[*num_people].residence));
  printf("����� ������ �Է��ϼ���: ");
  scanf_s("%s", table[*num_people].role, (int)sizeof(table[*num_people].role));
  printf("����� ���̸� �Է��ϼ���: ");
  scanf_s("%d", &table[*num_people].age);

  (*num_people)++;
}

void AddResignedEmployee(struct ResignedEmployeeData *table,
                         int *num_resigned_people) {
  // ����� ������ �Է��ϴ� �κ� �߰�
  printf("����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", table[*num_resigned_people].employ_name,(int)sizeof(table[*num_resigned_people].employ_name));
  printf("��� ��¥�� �Է��ϼ���(ex:1900/01/01): ");
  scanf_S("%s", table[*num_resigned_people].resignation_date,(int)sizeof(table[*num_resigned_people].resignation_date));
  printf("������� ���������� �Է��ϼ���: ");
  scanf_s("%s", table[*num_resigned_people].residence,(int)sizeof(table[*num_resigned_people].residence));
  printf("������� ������ �Է��ϼ���: ");
  scanf_s("%s", table[*num_resigned_people].role,(int)sizeof(table[*num_resigned_people].role));
  printf("������� ���̸� �Է��ϼ���: ");
  scanf_s("%d", &table[*num_resigned_people].age,);

  (*num_resigned_people)++;
}

void ResignEmployee() {
  char TargetName[50];
  printf("����� ����� �̸��� �Է��ϼ���: ");
  scanf("%s", TargetName);

  int peopleIndex = FindPerson(EmployeeTable, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("�ش� ����� ã�� �� �����ϴ�.\n");
    return;
  }

  // �ش� ����� ����� ������� �̵�
  AddResignedEmployee(ResignedEmployeeTable, &num_resigned_people);

  // ����� ����� �ڸ��� ��� (���� �迭���� ����)
  for (int i = peopleIndex; i < num_people - 1; i++) {
    EmployeeTable[i] = EmployeeTable[i + 1];
  }

  // ����ڰ� �߰��Ǿ����Ƿ� ��� �� ����
  num_people--;
}

void DisplayEmployees(const struct EmployeeData *table, int num_people) {
  for (int i = 0; i < num_people; i++) {
    printf("�̸�: %s\n", table[i].employ_name);
    printf("����: %d\n", table[i].age);
    printf("�Ի� ��¥: %s\n", table[i].start_company);
    printf("����: %s\n", table[i].role);
    printf("������: %s\n", table[i].residence);
    printf("-------------------------\n");
  }
}

void DisplayResignedEmployees(const struct ResignedEmployeeData *table,
                              int num_resigned_people) {
  for (int i = 0; i < num_resigned_people; i++) {
    printf("�̸�: %s\n", table[i].employ_name);
    printf("����: %d\n", table[i].age);
    printf("��� ��¥: %s\n", table[i].resignation_date);
    printf("����: %s\n", table[i].role);
    printf("������: %s\n", table[i].residence);
    printf("-------------------------\n");
  }
}

void FreeMemory() {
  free(EmployeeTable);
  free(ResignedEmployeeTable);
}

int main() {
  EmployeeTable = malloc(INITIAL_CAPACITY * sizeof(struct EmployeeData));
  ResignedEmployeeTable =
      malloc(INITIAL_CAPACITY * sizeof(struct ResignedEmployeeData));

  if (EmployeeTable == NULL || ResignedEmployeeTable == NULL) {
    printf("�޸� �Ҵ� ����\n");
    return EXIT_FAILURE;
  }

  capacity = INITIAL_CAPACITY;

  while (1) {
    int choice = -1;
    printf("-------------------------\n");
    printf("���ϴ� �޴��� �Է����ּ���.\n");
    printf("1.��� ��� �ű� �߰�\n");
    printf("2.����� ��� �߰�\n");
    printf("3.��� ó��\n");  // �߰��� �κ�
    printf("4.��� ��� ����\n");
    printf("5.����� ��� ����\n");
    printf("6.����\n");
    printf("-------------------------\n");
    printf("�޴�: ");
    scanf_s("%d", &choice);

    switch (choice) {
      case 1:
        AddEmployee(EmployeeTable, &num_people);
        break;
      case 2:
        AddResignedEmployee(ResignedEmployeeTable, &num_resigned_people);
        break;
      case 3:
        ResignEmployee();
        break;
      case 4:
        DisplayEmployees(EmployeeTable, num_people);
        break;
      case 5:
        DisplayResignedEmployees(ResignedEmployeeTable, num_resigned_people);
        break;
      case 6:
        FreeMemory();
        return 0;  // ����
      default:
        printf("�߸��� �޴� �����Դϴ�.\n");
    }
  }
}
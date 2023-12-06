#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define INITIAL_CAPACITY 10 //�ʱ� ����ü �迭 �޸� �Ҵ� ũ��

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
}; //����� ������ ������ ����ü ����

struct RetiredEmployeeData {
  char employ_name[50];
  char retired_date[30];  // �߰��� �κ�: ��� ��¥
  char residence[50];
  char role[20];
  int age;
};

struct EmployData *EmployeeTable = NULL;  // ����ü�� ������ ����
struct ResignedEmployeeData *RetiredEmployeeTable = NULL;
int num_retired_people = 0;
int num_people =
    0;  // �Էµ� ��� ���� �ǹ��ϴ� num_people�� �ʱⰪ�� 0���� ����
int capacity = 0;  // �������� �Ҵ�� Employee �����͸� �����ϴ� �迭�� �뷮��
                   // �ǹ��ϴ� ���� ����

void AddRetiredEmployee(struct RetiredEmployeeData *table,
                         int *num_retired_people) {
  // ����� ������ �Է��ϴ� �κ� �߰�
  printf("����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", table[*num_retired_people].employ_name,
          (int)sizeof(table[*num_retired_people].employ_name));
  printf("��� ��¥�� �Է��ϼ���(ex:1900/01/01): ");
  scanf_s("%s", table[*num_retired_people].retired_date,
          (int)sizeof(table[*num_retired_people].retired_date));
  printf("������� ���������� �Է��ϼ���: ");
  scanf_s("%s", table[*num_retired_people].residence,
          (int)sizeof(table[*num_retired_people].residence));
  printf("������� ������ �Է��ϼ���: ");
  scanf_s("%s", table[*num_retired_people].role,
          (int)sizeof(table[*num_retired_people].role));
  printf("������� ���̸� �Է��ϼ���: ");
  scanf_s("%d", &table[*num_retired_people].age, );

  (**num_retired_people)++;
}

void RetiredEmployee() {
  char TargetName[50];
  printf("����� ����� �̸��� �Է��ϼ���: ");
  scanf("%s", TargetName);

  int peopleIndex = FindPerson(EmployeeTable, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("�ش� ����� ã�� �� �����ϴ�.\n");
    return;
  }

  // �ش� ����� ����� ������� �̵�
  AddResignedEmployee(RetiredEmployeeTable, &num_retired_people);

  // ����� ����� �ڸ��� ��� (���� �迭���� ����)
  for (int i = peopleIndex; i < num_people - 1; i++) {
    EmployeeTable[i] = EmployeeTable[i + 1];
  }

  // ����ڰ� �߰��Ǿ����Ƿ� ��� �� ����
  num_people--;
}

void DisplayRetiredEmployees(const struct ResignedEmployeeData *table,int num_resigned_people) {
  for (int i = 0; i < num_resigned_people; i++) {
    printf("�̸�: %s\n", table[i].employ_name);
    printf("����: %d\n", table[i].age);
    printf("��� ��¥: %s\n", table[i].resignation_date);
    printf("����: %s\n", table[i].role);
    printf("������: %s\n", table[i].residence);
    printf("-------------------------\n");
  }
}



int FindPerson(const struct EmployData *table, int num_people,const char *name) {
  for (int i = 0; i < num_people; ++i) {
    if (strcmp(table[i].employ_name, name) == 0) {
      return i; //ã���� �ش� i���� ��ȯ
    }
  }
  return -1;  // ã�� ���� ��� -1 ��ȯ
} //��� ������ �Էµ� ����ü �迭���� �Է��� �̸��� ����� ã���ִ� �Լ�
  //�ش� ����� ã������ i���� ��ȯ�ϸ� ã���������� -1�� ��ȯ�Ѵ�.

void ResizeTable() {
  if (num_people == capacity) {
    capacity = (capacity == 0) ? INITIAL_CAPACITY : capacity * 2;
    EmployeeTable = realloc(EmployeeTable, capacity * sizeof(struct EmployData));
    if (EmployeeTable == NULL) {
      printf("�޸� �Ҵ� ����\n");
      exit(EXIT_FAILURE);
    }
  }
} //����ü �迭�� ũ�⸦ �������� �����ϴ� �Լ�
  //�迭�� ���ο� �����͸� �߰��ϱ� ���� �迭 ũ�Ⱑ ������� Ȯ���ϰ� �ʿ��� ��� �迭�� ũ�⸦ �ø���.

void AddEmployee(struct EmployData *table, int *num_people) {
  ResizeTable(); //�����͸� �Է��ϱ��� �迭 ũ�� ������� Ȯ���ϰ� �ʿ��� ��� �迭 ũ�� ����

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
}// ����ü �迭�� ��� ������ �Է��ϴ� �Լ�

void UpdateEmployee(struct EmployData *table, int num_people) {
  char TargetName[50]; //������ ������ ����� �̸��� �Է¹޾� �����ϴ� ���ڿ� ����
  printf("\n������ ����� �̸��� �Է��ϼ���: ");
  scanf_s("%s", TargetName, (int)sizeof(TargetName)); //�����ϰ��� �ϴ� ����� �̸��� �Է� ����

  int peopleIndex = FindPerson(table, num_people, TargetName);

  if (peopleIndex == -1) {
    printf("�߸��� �̸��� �Է��߽��ϴ�.\n");
    return;  // ó�� �޴� �������� ���ư�
  } //�ش� ����� ��ã���� �߸��� �̸��� �Է��ߴٴ� ������ �Բ� ó�� �޴� �������� ���ư�
  int editing = 1; //while���� ���� �ݺ��� �� �ְ� �ʱⰪ�� 1�� ����
  while (editing) {
    int update_choice; //������ �׸��� ��ȣ�� �Է¹޾� �����ϴ� ���� ����
    printf("-------------------------------\n");
    printf("������ �׸��� �����ϼ���:\n");
    printf("1. ����\n2. ������\n3. ����\n4. �ٹ� ����\n5. ����\n");
    printf("-------------------------------\n");
    printf("�޴�: ");
    scanf_s("%d", &update_choice); //�����ϰ��� �ϴ� �׸��� ��ȣ�� �Է¹޾� ������

    switch (update_choice) {
      case 1: //���� ����
        printf("���ο� ���� �Է�: ");
        scanf_s("%d", &table[peopleIndex].age);
        break;
      case 2: //������ ����
        printf("���ο� ������ �Է�: ");
        scanf_s("%s", table[peopleIndex].residence,(int)sizeof(table[peopleIndex].residence));
        break;
      case 3: //���� ����
        printf("���ο� ���� �Է�: ");
        scanf_s("%s", table[peopleIndex].role,(int)sizeof(table[peopleIndex].role));
        break;
      case 4: //�ٹ� ���� ����
        printf("���ο� �ٹ� ���� �Է�: ");
        scanf_s("%s", table[peopleIndex].start_company,(int)sizeof(table[peopleIndex].start_company));
        break;
      case 5: //���� ����� �����ϱ����� ������ ����� ������ ������ְ� ����
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
} //�Էµ� ����� ������ ��� ������� ������ִ� �Լ�

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
        AddRetiredEmployee(RetiredEmployeeTable, &num_retired_people);
        break;
      case 5:
        DisplayRetiredEmployees(RetiredEmployeeTable, num_retired_people);
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
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAINHEADER_H
#define MAINHEADER_H

#define INITIAL_CAPACITY 10  // �ʱ� ����ü �迭 �޸� �Ҵ� ũ��

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};  // ����� ������ ������ ����ü ����

extern struct EmployData *EmployeeTable;
extern int num_people;  // �Էµ� ��� ���� �ǹ��ϴ� num_people
extern int capacity;  // �������� �Ҵ�� Employee �����͸� �����ϴ� �迭��
                      // �뷮�� �ǹ��ϴ� ���� ����

int FindPerson(const struct EmployData *table, int num_people,
               const char *name);
void ResizeTable();
void AddEmployee(struct EmployData *table, int *num_people);
void UpdateEmployee(struct EmployData *table, int num_people);
void PrintEmployee(const struct EmployData *table, int num_people);
void FreeMemory_Employee();  // �����Ҵ� �޸� �����Ͽ� �޸� ���� ����

#endif

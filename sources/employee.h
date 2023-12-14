#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAINHEADER_H
#define MAINHEADER_H

#define INITIAL_CAPACITY 10  // 초기 구조체 배열 메모리 할당 크기

struct EmployData {
  char employ_name[50];
  char start_company[30];
  char residence[50];
  char role[20];
  int age;
};  // 사원의 정보를 저장할 구조체 정의

extern struct EmployData *EmployeeTable;
extern int num_people;  // 입력된 사원 수를 의미하는 num_people
extern int capacity;  // 동적으로 할당된 Employee 데이터를 저장하는 배열의
                      // 용량을 의미하는 변수 선언

int FindPerson(const struct EmployData *table, int num_people,
               const char *name);
void ResizeTable();
void AddEmployee(struct EmployData *table, int *num_people);
void UpdateEmployee(struct EmployData *table, int num_people);
void PrintEmployee(const struct EmployData *table, int num_people);
void FreeMemory_Employee();  // 동적할당 메모리 해제하여 메모리 누수 방지

#endif

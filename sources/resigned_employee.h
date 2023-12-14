#pragma once
#ifndef RESIGNED_MANAGEMENT_H
#define RESIGNED_MANAGEMENT_H

#include "employee.h"  // Assuming your employee management functions are in "employee.h"

struct ResignedData {
  char employ_name[50];
  char start_company[30];
  char resignation_date[30];
  char residence[50];
  char role[20];
  int age;
};

extern struct ResignedData *ResignedTable;
extern int num_resigned;
extern int resigned_capacity;

void ResizeResignedTable();
void MoveToResigned(struct EmployData *table, int *num_people);
void PrintResigned(const struct ResignedData *table, int num_resigned);
void FreeMemory_ResignedEmployee();

#endif
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef list_h
#define list_h

typedef struct ListElement
{
  struct ListElement *next;
  void *value;
} ListElement;

typedef struct List
{
  uint64_t length;
  ListElement *head;
} List;

List *listCreate();
void listDestroy(List *list);
bool listPush(List *list, void *element);
void *listPop(List *list);

#endif

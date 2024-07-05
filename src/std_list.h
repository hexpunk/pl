#include <stdlib.h>
#include <stdint.h>

#ifndef std_list_h
#define std_list_h

typedef struct StdListElement
{
  struct StdListElement *next;
  void *value;
} StdListElement;

typedef struct StdList
{
  uint64_t length;
  StdListElement *head;
} StdList;

StdList *stdListCreate();
void stdListDestroy(StdList *list);
void stdListPush(StdList *list, void *element);
void *stdListPop(StdList *list);

#endif

#include "std_list.h"

StdList *stdListCreate()
{
  StdList *newList = malloc(sizeof(StdList));
  newList->head = NULL;
  newList->length = 0;

  return newList;
}

void stdListDestroy(StdList *list)
{
  while (list->head != NULL)
  {
    stdListPop(list);
  }

  free(list);
}

void stdListPush(StdList *list, void *element)
{
  StdListElement *oldHead = list->head;

  StdListElement *newHead = malloc(sizeof(StdListElement));
  newHead->value = element;
  newHead->next = oldHead;

  list->head = newHead;
  list->length++;
}

void *stdListPop(StdList *list)
{
  StdListElement *oldHead = list->head;
  void *value = oldHead->value;

  list->head = oldHead->next;
  list->length--;

  free(oldHead);

  return value;
}

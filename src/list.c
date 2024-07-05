#include "list.h"

List *listCreate()
{
  List *newList = malloc(sizeof(List));
  if (!newList)
  {
    return NULL;
  }

  newList->head = NULL;
  newList->length = 0;

  return newList;
}

void listDestroy(List *list)
{
  while (list->head != NULL)
  {
    listPop(list);
  }

  free(list);
}

bool listPush(List *list, void *element)
{
  ListElement *oldHead = list->head;

  ListElement *newHead = malloc(sizeof(ListElement));
  if (!newHead)
  {
    return false;
  }

  newHead->value = element;
  newHead->next = oldHead;

  list->head = newHead;
  list->length++;

  return true;
}

void *listPop(List *list)
{
  ListElement *oldHead = list->head;
  void *value = oldHead->value;

  list->head = oldHead->next;
  list->length--;

  free(oldHead);

  return value;
}

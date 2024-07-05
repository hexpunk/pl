#include <glib.h>
#include "list.h"

typedef struct IntHolder
{
  int64_t value;
} IntHolder;

static void basicPushPopTest(void)
{
  List *list = listCreate();
  g_assert_nonnull(list);

  bool success;

  success = listPush(list, &(IntHolder){.value = 1});
  g_assert_true(success);

  success = listPush(list, &(IntHolder){.value = 2});
  g_assert_true(success);

  success = listPush(list, &(IntHolder){.value = 3});
  g_assert_true(success);

  IntHolder *head = listPop(list);
  g_assert_cmpint(head->value, ==, 3);

  head = listPop(list);
  g_assert_cmpint(head->value, ==, 2);

  head = listPop(list);
  g_assert_cmpint(head->value, ==, 1);

  listDestroy(list);
}

/**
 * This only really works with Valgrind. Otherwise it just leaks.
 */
static void memoryCleanupTest(void)
{
  List *list = listCreate();

  listPush(list, &(IntHolder){.value = 1});
  listPush(list, &(IntHolder){.value = 2});
  listPush(list, &(IntHolder){.value = 3});

  listDestroy(list);
}

int main(int argc, char *argv[])
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/list/basic_push_pop_test", basicPushPopTest);
  g_test_add_func("/list/memory_cleanup_test", memoryCleanupTest);
  return g_test_run();
}

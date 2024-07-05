#include <glib.h>
#include "std_list.h"

typedef struct IntHolder
{
  int64_t value;
} IntHolder;

static void basicPushPopTest(void)
{
  StdList *list = stdListCreate();
  g_assert_nonnull(list);

  bool success;

  success = stdListPush(list, &(IntHolder){.value = 1});
  g_assert_true(success);

  success = stdListPush(list, &(IntHolder){.value = 2});
  g_assert_true(success);

  success = stdListPush(list, &(IntHolder){.value = 3});
  g_assert_true(success);

  IntHolder *head = stdListPop(list);
  g_assert_cmpint(head->value, ==, 3);

  head = stdListPop(list);
  g_assert_cmpint(head->value, ==, 2);

  head = stdListPop(list);
  g_assert_cmpint(head->value, ==, 1);

  stdListDestroy(list);
}

/**
 * This only really works with Valgrind. Otherwise it just leaks.
 */
static void memoryCleanupTest(void)
{
  StdList *list = stdListCreate();

  stdListPush(list, &(IntHolder){.value = 1});
  stdListPush(list, &(IntHolder){.value = 2});
  stdListPush(list, &(IntHolder){.value = 3});

  stdListDestroy(list);
}

int main(int argc, char *argv[])
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/std_list/basic_push_pop_test", basicPushPopTest);
  g_test_add_func("/std_list/memory_cleanup_test", memoryCleanupTest);
  return g_test_run();
}

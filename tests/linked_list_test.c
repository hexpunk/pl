#include <glib.h>
#include "linked_list.h"

static void test1(void)
{
  g_assert_true(TRUE);
}

static void test2(void)
{
  g_assert_false(FALSE);
}

int main(int argc, char *argv[])
{
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/linked_list/test1", test1);
  g_test_add_func("/linked_list/test2", test2);
  return g_test_run();
}

project(
  'pl',
  'c',
  version: '0.1',
  default_options: ['warning_level=3', 'c_args=-Wall -g', 'c_std=c99'],
)

src_dir = 'src'
test_dir = 'tests'

lib_linked_list = static_library(
  'linked_list',
  src_dir / 'linked_list.c',
)

executable(
  'pl',
  'main.c',
  include_directories: include_directories(src_dir),
  link_with: lib_linked_list,
)

glib_dep = dependency('glib-2.0', required: true)

linked_list_test_exe = executable(
  'linked_list_test',
  test_dir / 'linked_list_test.c',
  include_directories: include_directories(src_dir, test_dir),
  dependencies: [glib_dep],
  link_with: lib_linked_list,
)

test('linked_list', linked_list_test_exe)

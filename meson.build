project(
  'pl',
  'c',
  version: '0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
    'debug=true',
    'optimization=3',
    'c_std=c99',
  ],
)

src_dir = 'src'
test_dir = 'tests'

lib_list = static_library(
  'list',
  src_dir / 'list.c',
)

executable(
  'pl',
  'main.c',
  include_directories: include_directories(src_dir),
  link_with: lib_list,
)

glib_dep = dependency('glib-2.0', required: true)

list_test_exe = executable(
  'list_test',
  test_dir / 'list_test.c',
  include_directories: include_directories(src_dir, test_dir),
  dependencies: [glib_dep],
  link_with: lib_list,
)

test('list_test', list_test_exe, verbose: true)

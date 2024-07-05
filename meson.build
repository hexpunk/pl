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

lib_std_list = static_library(
  'std_list',
  src_dir / 'std_list.c',
)

executable(
  'pl',
  'main.c',
  include_directories: include_directories(src_dir),
  link_with: lib_std_list,
)

glib_dep = dependency('glib-2.0', required: true)

std_list_test_exe = executable(
  'std_list_test',
  test_dir / 'std_list_test.c',
  include_directories: include_directories(src_dir, test_dir),
  dependencies: [glib_dep],
  link_with: lib_std_list,
)

test('std_list', std_list_test_exe)

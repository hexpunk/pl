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

test(
  'list_test',
  executable(
    'list_test',
    test_dir / 'list_test.c',
    include_directories: include_directories(src_dir, test_dir),
    dependencies: [glib_dep],
    link_with: lib_list,
  ),
  env: [
    'G_TEST_SRCDIR=@0@'.format(meson.current_source_dir()),
    'G_TEST_BUILDDIR=@0@'.format(meson.current_build_dir()),
  ],
  protocol: 'tap',
  verbose: true,
)

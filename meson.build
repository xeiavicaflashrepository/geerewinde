project(
    'geerewinde',
    'c',
    license : 'GPL-3.0-Or-Later',
    version : '0.0.1',
    default_options : ['warning_level=3']
)

gtkdeps = [
    dependency('gtk4', version : '>=4.8')
]

srcs = [
    'src/main.c'
]

executable(
    'geerewinde',
    srcs,
    dependencies : gtkdeps
)

project(
    'geerewinde',
    'c',
    license : 'GPL-3.0-Or-Later',
    version : '0.0.1',
    default_options : ['warning_level=3']
)

gtkdeps = [
    dependency('gtk4', version : '>=4.18')
]

gnome = import('gnome')
resources = gnome.compile_resources('resources', 'geerewinde.geresource.xml')

srcs = [
    'src/main.c'
]

executable(
    'geerewinde',
    srcs,
    resources,
    dependencies : gtkdeps
)

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.71])
AC_INIT([jupiter], [1.0])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_MACRO_DIRS([m4])

# Initialize automake
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Specify config.h source
# AC_CONFIG_SRCDIR([config.h.in])

LT_PREREQ([2.4])
LT_INIT([dlopen])

# Create config.h based on configure.ac macros
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_RANLIB

AC_PATH_PROG([DOTNETCORE],[dotnet])
AX_PROG_DOTNETCORE_VERSION([7.0.202])

# Checks for libraries.
# AC_SEARCH_LIBS(graphviz, gv)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

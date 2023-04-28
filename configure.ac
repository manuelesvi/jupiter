#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.71])
AC_INIT([jupiter], [1.0])
AC_CONFIG_SRCDIR([src/main.c])
#AC_CONFIG_MACRO_DIRS([m4])

# Initialize automake
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

LT_PREREQ([2.4])
LT_INIT([dlopen])

# Create config.h based on configure.ac macros
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

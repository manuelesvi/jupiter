#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.71])
AC_INIT([graphviz], [1.0])

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_MACRO_DIRS([m4])

# Initialize automake
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Create config.h based on configure.ac macros
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AM_PROG_AR

LT_PREREQ([2.4.7])
LT_INIT([dlopen])

# Checks for libraries.
AC_SEARCH_LIBS(gvContext, gvc)
AC_SEARCH_LIBS(agopen, cgraph)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

bin_PROGRAMS = gv-wrapper-test
lib_LTLIBRARIES = libgv_wrapper.la

libgv_wrapper_la_SOURCES = XDot.cpp main.cpp
libgv_wrapper_la_CXXFLAGS = `pkg-config libgvc --cflags` -IGraphviz.h -Wall -g -O2
libgv_wrapper_la_LDFLAGS = -version-info 0:0:0
libgv_wrapper_la_LDLIBS = `pkg-config libgvc --libs`

gv_wrapper_test_SOURCES = main.c
gv_wrapper_test_CFLAGS = `pkg-config libgvc --cflags` -Wall -g -O2
gv_wrapper_test_LDLIBS=`pkg-config libgvc --libs`

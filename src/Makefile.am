bin_PROGRAMS = graphviz-test
lib_LTLIBRARIES = libgraphviz.la

libgraphviz_la_SOURCES = main.cpp
libgraphviz_la_CXXFLAGS = `pkg-config libgvc --cflags` -Wall -g -O2
libgraphviz_la_LDFLAGS = -version-info 0:0:0
libgraphviz_la_LDLIBS = `pkg-config libgvc --libs`

graphviz_test_SOURCES = main.c
graphviz_test_CFLAGS = `pkg-config libgvc --cflags` -Wall -g -O2

graphviz_test_LDLIBS=`pkg-config libgvc --libs`

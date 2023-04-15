bin_PROGRAMS = jupiter
lib_LTLIBRARIES = libgraphviz.la

libgraphviz_la_SOURCES = main.cpp
libgraphviz_la_CXXFLAGS = `pkg-config libgvc --cflags` -Wall -g -O2
libgraphviz_la_LDFLAGS = -version-info 0:0:0
libgraphviz_la_LDLIBS = `pkg-config libgvc --libs`

jupiter_SOURCES = main.c
jupiter_CFLAGS=`pkg-config libgvc --cflags` -Wall -g -O2

jupiter_LDLIBS=`pkg-config libgvc --libs`
#jupiter_LDADD = ../common/libjupcommon.a

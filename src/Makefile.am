bin_PROGRAMS = jupiter
lib_LIBRARIES = libgraphviz.a

libgraphviz_a_SOURCES = main.cpp
libgraphviz_a_CXXFLAGS = `pkg-config libgvc --cflags` -Wall -g -O2
libgraphviz_a_LDLIBS = `pkg-config libgvc --libs`
jupiter_SOURCES = main.c

jupiter_CFLAGS=`pkg-config libgvc --cflags` -Wall -g -O2
# jupiter_CXXFLAGS=`pkg-config libgvc --cflags` -Wall -g -O2
jupiter_LDLIBS=`pkg-config libgvc --libs`

#jupiter_LDADD = ../common/libjupcommon.a


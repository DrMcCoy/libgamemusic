bin_PROGRAMS = gamemus
noinst_PROGRAMS = hello

gamemus_SOURCES = gamemus.cpp
hello_SOURCES = hello.cpp

WARNINGS = -Wall -Wextra -Wno-unused-parameter

AM_CPPFLAGS  = $(BOOST_CPPFLAGS)
AM_CPPFLAGS += -I $(top_srcdir)/include
AM_CPPFLAGS += $(libgamecommon_CPPFLAGS)
AM_CPPFLAGS += $(WARNINGS)

AM_CXXFLAGS  = $(DEBUG_CXXFLAGS)
AM_CXXFLAGS += $(portaudio_CFLAGS)
AM_CXXFLAGS += $(libgamecommon_CFLAGS)

AM_LDFLAGS  = $(BOOST_SYSTEM_LIBS)
AM_LDFLAGS += $(BOOST_FILESYSTEM_LIBS)
AM_LDFLAGS += $(BOOST_PROGRAM_OPTIONS_LIBS)
AM_LDFLAGS += $(BOOST_UNIT_TEST_FRAMEWORK_LIBS)
AM_LDFLAGS += $(BOOST_THREAD_LIBS)
AM_LDFLAGS += $(portaudio_LIBS)
AM_LDFLAGS += $(libgamecommon_LIBS)
AM_LDFLAGS += $(top_builddir)/src/libgamemusic.la

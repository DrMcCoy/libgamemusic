check_PROGRAMS = tests

tests_SOURCES = tests.cpp
#tests_SOURCES += test-patchbank-ibk.cpp
tests_SOURCES += test-midi.cpp
tests_SOURCES += test-ins-ins-adlib.cpp
tests_SOURCES += test-mus-imf-idsoftware-type0.cpp
tests_SOURCES += test-mus-imf-idsoftware-type1.cpp
tests_SOURCES += test-mus-raw-rdos.cpp
tests_SOURCES += test-mus-dro-dosbox-v1.cpp
tests_SOURCES += test-mus-dro-dosbox-v2.cpp
tests_SOURCES += test-mus-cmf-creativelabs.cpp
tests_SOURCES += test-mus-cdfm-zone66.cpp
tests_SOURCES += test-mus-cdfm-zone66-gus.cpp
tests_SOURCES += test-mus-dsm-dsik.cpp
tests_SOURCES += test-mus-got.cpp
tests_SOURCES += test-mus-klm-wacky.cpp
tests_SOURCES += test-mus-mid-type0.cpp
tests_SOURCES += test-mus-mus-dmx.cpp
tests_SOURCES += test-mus-s3m-screamtracker.cpp
tests_SOURCES += test-mus-tbsa-doofus.cpp
tests_SOURCES += test-music.cpp
tests_SOURCES += test-opl.cpp
tests_SOURCES += test-opl-normalise.cpp
tests_SOURCES += test-tempo.cpp
tests_SOURCES += test-track-split.cpp

EXTRA_tests_SOURCES  = tests.hpp
EXTRA_tests_SOURCES += test-music.hpp

TESTS = tests

AM_CPPFLAGS = $(BOOST_CPPFLAGS) -I $(top_srcdir)/include $(libgamecommon_CFLAGS)
AM_LDFLAGS = $(BOOST_SYSTEM_LIBS) $(BOOST_UNIT_TEST_FRAMEWORK_LIBS) $(libgamecommon_LIBS) $(top_builddir)/src/libgamemusic.la

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([libgamemusic], [1.2],
	[https://github.com/Malvineous/libgamemusic/issues],
	[], [http://www.shikadi.net/camoto])
AM_INIT_AUTOMAKE([foreign dist-bzip2 no-dist-gzip])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_LANG(C++)

# Overarching version of all libraries (used for installation dir)
AC_SUBST(camoto_release, camoto-1.0)

AC_PROG_CXX
AC_PROG_LIBTOOL

PKG_PROG_PKG_CONFIG

BOOST_REQUIRE([1.46])
BOOST_FILESYSTEM
BOOST_PROGRAM_OPTIONS
BOOST_THREADS
BOOST_TEST

PKG_CHECK_MODULES([libgamecommon], [libgamecommon])

AC_ARG_WITH([portaudio],
	[AS_HELP_STRING([--with-portaudio],
		[add playback support to gamemus utility @<:@default=check@:>@])],
	[],
	[with_portaudio=check]
)
AS_CASE(["$with_portaudio"],
	[yes], [PKG_CHECK_MODULES([portaudio], [portaudio-2.0], [HAVE_PORTAUDIO=1])],
	[no], [HAVE_PORTAUDIO=0],
	[PKG_CHECK_MODULES([portaudio], [portaudio-2.0], [HAVE_PORTAUDIO=1], [HAVE_PORTAUDIO=0])]
)
AM_CONDITIONAL([USE_PORTAUDIO], [test "$with_portaudio" != no -a "$HAVE_PORTAUDIO" -eq 1])
AS_IF([test "$HAVE_PORTAUDIO" -eq 1], [AC_DEFINE([USE_PORTAUDIO], [1], [Define if using PortAudio.])])

if test "$with_portaudio" != no -a "$HAVE_PORTAUDIO" -eq 0;
then
	AC_MSG_WARN([PortAudio missing, --play option disabled for gamemus])
fi

AC_ARG_ENABLE(debug, AC_HELP_STRING([--enable-debug],[enable extra debugging output]))

dnl Check for --enable-debug and add appropriate flags for gcc
if test "x$enable_debug" = "xyes";
then
	# Add gdb info (-g), disable any default optimisation
	AC_SUBST(DEBUG_CXXFLAGS, "-O0 -g")
	# Add DEBUG define
	AC_DEFINE([DEBUG], [1], [Define to include extra debugging output])
fi

dnl Check whether xmlto exists for manpage generation
AC_CHECK_PROG(XMLTO_CHECK,xmlto,yes)
if test x"$XMLTO_CHECK" != x"yes"; then
	AC_MSG_ERROR([xmlto not found - see <https://fedorahosted.org/xmlto/>.])
fi

case "$host_os" in
*mingw*)
	# Must specify this parameter when compiling for Windows
	LDFLAGS="$LDFLAGS -no-undefined"
	;;
esac

AM_SILENT_RULES([yes])

AC_OUTPUT(Makefile src/Makefile include/Makefile include/camoto/Makefile examples/Makefile tests/Makefile doc/Makefile utils/Makefile $PACKAGE.pc)

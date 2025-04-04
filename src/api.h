#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define HammeringFSM_DLLIMPORT __declspec(dllimport)
#  define HammeringFSM_DLLEXPORT __declspec(dllexport)
#  define HammeringFSM_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define HammeringFSM_DLLIMPORT __attribute__((visibility("default")))
#    define HammeringFSM_DLLEXPORT __attribute__((visibility("default")))
#    define HammeringFSM_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define HammeringFSM_DLLIMPORT
#    define HammeringFSM_DLLEXPORT
#    define HammeringFSM_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef HammeringFSM_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define HammeringFSM_DLLAPI
#  define HammeringFSM_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef HammeringFSM_EXPORTS
#    define HammeringFSM_DLLAPI HammeringFSM_DLLEXPORT
#  else
#    define HammeringFSM_DLLAPI HammeringFSM_DLLIMPORT
#  endif // HammeringFSM_EXPORTS
#  define HammeringFSM_LOCAL HammeringFSM_DLLLOCAL
#endif // HammeringFSM_STATIC
//#include "defines.hpp"
// Should be in all headers in all headers!
#ifndef DEFINES_H
#define DEFINES_H

#include <assert.h>
//#include <unistd.h>
//#include "config.h"

//#if defined _WIN64 || defined _WIN32
#include <iostream>
//#endif

#ifdef DBG_MESSAGE
#include <iostream>
#define DEV_INFOS(X) std::cerr << "file:" << __FILE__ << "\tline:" << __LINE__ << "\t=>" << X << std::endl
//#define DEV_INFOS(X) ;
#else
#define DEV_INFOS(X) ;
#endif // DBG_MESSAGE

#define OCFU_THR_NORM 0
#define OCFU_THR_INV 1
#define OCFU_THR_BILAT 2

#define MODE_STANDBY 0
#define MODE_IMG 1

#define PROCESSOR_WORKING_SIGNAL 0
#define PROCESSOR_IDLE_SIGNAL 1
//#define PROCESSOR_HAS_REWORKED_SIGNAL 2

#define MASK_TYPE_NONE 0
#define MASK_TYPE_FILE 1
#define MASK_TYPE_DRAW 2
#define MASK_TYPE_AUTO 3

#define MASK_TOOL_3P_CIRCLE 0
#define MASK_TOOL_CONV_POLYGON 1

// GUI:
#define DISPLAY_MIN_MARGIN 10

#endif // NDEVEL

#define MY_PI 3.1416


// compilation defines here
/*
#define TRAINING_SET_IMG "data/training-set1/" // [Location of the training set])
#define TRAINING_SET_IMG_PS "data/training-set2/" // [Location of the training set post - splitting])
#define TEST_SET_IMG "data/training-set1/" // [Location of the test set])
#define TRAINED_CLASSIF_XML_FILE "data/trainedClassifier.xml" // [Location of the classifier])
#define TRAINED_CLASSIF_PS_XML_FILE "data/trainedClassifierPS.xml" // [Location of the classifier post - splitting])

#define PROGRAM_NAME "OpenCFU" // [The actual name(Capitals)])
*/


/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Location of the banner */
//#define BACKGROUND_NOISE "data/noise-texture.png"

/* Location of the banner */
//#define BANNER_IMG "data/banner.png"

/* Print debug info in stdout */
/* #undef DBG_MESSAGE */

/* define if the compiler supports basic C++11 syntax */
#define HAVE_CXX11 1

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if stdbool.h conforms to C99. */
/* #undef HAVE_STDBOOL_H */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB_H */

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
/* #undef HAVE_STRING_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
/* #undef HAVE_SYS_STAT_H */

/* Define to 1 if you have the <sys/types.h> header file. */
/* #undef HAVE_SYS_TYPES_H */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if the system has the type `_Bool'. */
/* #undef HAVE__BOOL */

/* Location of the 128px icon */
//#define ICON128_IMG "data/icons/128x128/apps/opencfu.png"

/* Location of the 24px icon */
//#define ICON24_IMG "data/icons/24x24/apps/opencfu.png"

/* Location of the 48px icon */
//#define ICON48_IMG "data/icons/48x48/apps/opencfu.png"

/* Location of the 64px icon */
//#define ICON64_IMG "data/icons/64x64/apps/opencfu.png"

/* Location of the logo */
//#define LOGO_IMG "data/logo.png"

/* Define to the address where bug reports for this package should be sent. */
//#define PACKAGE_BUGREPORT "opencfu@gmail.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME "opencfu"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "opencfu 3.9.0"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "opencfu"

/* Define to the home page for this package. */
//#define PACKAGE_URL "http://www.opencfu.sourceforge.net/"

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.9.0"

/* The actual name (Capitals) */
#define PROGRAM_NAME "OpenCFU"

/* Define to 1 if you have the ANSI C header files. */
/* #undef STDC_HEADERS */

/* Location of the test set */
//#define TEST_SET_IMG "data/training-set1/"

/* Location of the classifier post-splitting */
#define TRAINED_CLASSIF_PS_XML_FILE "data/trainedClassifierPS.xml"

/* Location of the classifier */
#define TRAINED_CLASSIF_XML_FILE "data/trainedClassifier.xml"

/* Location of the training set */
//#define TRAINING_SET_IMG "data/training-set1/"

/* Location of the training set post-splitting */
//#define TRAINING_SET_IMG_PS "data/training-set2/"

/* We build opencv witha GUI */
/* #undef WITH_GUI */

/* Define to `__inline__' or `__inline' if that's what the C compiler
calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

#define INSTALLDIR ""

#define HAVE_CV_IMAGECODECS

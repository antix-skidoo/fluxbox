// version.h for Fluxbox Window manager
// Copyright (c) 2004 Henrik Kinnunen (fluxgen at users.sourceforge.net)
//                and Simon Bowden (rathnor at users.sourceforge.net)
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#define __fluxbox_version "1.3.8"

#ifdef __VERSION__
#define __fluxbox_compiler_version __VERSION__

#ifdef __clang__
#define __fluxbox_compiler "CLANG"
#elif defined(__GNUG__)
#define __fluxbox_compiler "GCC"
#endif  // __GNUG__

#elif (defined(__sgi) || defined(sgi)) && __COMPILER_VERSION
#define __fluxbox_compiler_version __COMPILER_VERSION
#define __fluxbox_compiler "SGI"
#elif defined(__MWERKS__)
#define __fluxbox_compiler_version __MWERKS__
#define __fluxbox_compiler "MWERKS"
#elif defined(__INTEL_COMPILER) || defined(__ICC)
#define __fluxbox_compiler_version __INTEL_COMPILER
#define __fluxbox_compiler "ICC"
#elif defined(__SUNPRO_CC)
#define __fluxbox_compiler_version __SUNPRO_CC
#define __fluxbox_compiler "SUNPRO_CC"
#elif defined(__COMO__) && defined(__COMO_VERSION__)
#define __fluxbox_compiler_version __COMO_VERSION__
#define __fluxbox_compiler "COMO"
#elif defined(_CRAYC) && defined(_REVISION)
#define __fluxbox_compiler_version _REVISION
#define __fluxbox_compiler "GRAYC"
#elif defined(__DECCXX) && defined(__DECCXX)
#define __fluxbox_compiler_version __DECCXX
#define __fluxbox_compiler "DECCXX"
#elif defined(__DCC__)
#define __fluxbox_compiler_version __VERSION_NUMBER__
#define __fluxbox_compiler "DCC"
#endif 

#ifndef __fluxbox_compiler_version
#define __fluxbox_compiler_version "Unknown"
#endif // __fluxbox_compiler_version

#ifndef __fluxbox_compiler
#define __fluxbox_compiler "Unknown"
#endif // __fluxbox_compiler

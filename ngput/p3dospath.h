/***************************************************************************

 Copyright (c) 2007 Sergey Prokhorchuk.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
 3. Neither the name of the author nor the names of contributors
    may be used to endorse or promote products derived from this software
    without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 SUCH DAMAGE.

***************************************************************************/

#ifndef __P3DOSPATH_H__
#define __P3DOSPATH_H__

#include <string>

#ifdef _WIN32
 #define P3DPathDirSeparator ('\\')
#else
 #define P3DPathDirSeparator ('/')
#endif

class P3DPathName
 {
  public           :

                   P3DPathName        (const char         *PathName);

  bool             IsAbsolute         () const;
  bool             IsRelative         () const;
  const char      *c_str              () const;

  /* FIXME: remove unneeded '/../' and '/./' entries */
  /* 1. remove trailing '/' character if present */
  void             Normalize          ();

  /* substitute first '~' by user home, note: ~user is not supported */
  bool             ExpandUserDir      ();

  /* if already absolute - will not be changed */
  /* if relative - prepend current working dir */
  bool             MakeAbsolute       ();

  bool             MakeRelativeTo     (const P3DPathName *BasePath);

  bool             ToUNIX             ();

  std::string      GetExtension       () const;

  static
  std::string      JoinPaths          (const char         *Path1,
                                       const char         *Path2);

  static
  std::string      BaseName           (const char         *Path);
  static
  std::string      DirName            (const char         *Path);

  private          :

  static
  int              GetBaseNameStartPos(const char         *Path);

  std::string      Path;
 };

class P3DPathInfo
 {
  public           :

  static
  std::string      GetCurrentDir      ();

  static
  std::string      GetUserDir         ();
 };

#endif


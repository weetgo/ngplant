/***************************************************************************

 Copyright (c) 2013 Sergey Prokhorchuk.
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

#ifndef __P3DSPLINEIO_H__
#define __P3DSPLINEIO_H__

#include <ngpcore/p3ddefs.h>
#include <ngpcore/p3diostream.h>
#include <ngpcore/p3dmathspline.h>

extern void        P3DSaveSplineCurve (P3DOutputStringFmtStream
                                                          *FmtStream,
                                       const P3DMathNaturalCubicSpline
                                                          *Spline);


extern void        P3DLoadSplineCurve (P3DMathNaturalCubicSpline
                                                          *Spline,
                                       P3DInputStringFmtStream
                                                          *SourceStream,
                                       const char         *CurveName);

extern void        P3DExportSplineCurve
                                      (P3DOutputStringStream
                                                          *TargetStream,
                                       const P3DMathNaturalCubicSpline
                                                          *Spline);

extern void        P3DImportSplineCurve
                                      (P3DMathNaturalCubicSpline
                                                          *Spline,
                                       P3DInputStringStream
                                                          *SourceStream);

#endif


/*--------------------------------------------------------------------
 *	$Id: gmt_math.h,v 1.30 2010-06-06 23:19:19 jluis Exp $
 *
 *	Copyright (c) 1991-2010 by P. Wessel and W. H. F. Smith
 *	See LICENSE.TXT file for copying and redistribution conditions.
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; version 2 of the License.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	Contact info: gmt.soest.hawaii.edu
 *--------------------------------------------------------------------*/
/*
 * This include file contains prototypes of functions that are not part
 * of POSIX but are often distributed anyway as part of ANSI C.  The
 * gmt_notposix.h include file have been generated by configure and tells
 * us which of the required functions are present or not and sets a macro or
 * prototype accordingly.  The purpose is to take advantage of the built-in
 * functions if they exist and provide an alternative definition otherwise.
 *
 * If you must do a manual edit, you should do so in gmt_notposix.h.
 * For non-UNIX platforms you should also look in gmt_notunix.h
 *
 * Version:	4
 */

#ifndef _GMT_MATH_H
#define _GMT_MATH_H

#ifndef SET_IN_NOTUNIX
#include "gmt_notposix.h"
#endif

#ifdef GMT_QSORT
/* Must replace the system qsort with ours which is 64-bit compliant */
#define qsort GMT_qsort
#endif

#if defined(copysign)
/* Macro already takes care of copysign - probably from BSD */
#elif HAVE_COPYSIGN == 0
#define copysign(x,y) ((y) < 0.0 ? -fabs(x) : fabs(x))
#else
extern double copysign(double x, double y);
#endif

#if HAVE_LOG1P == 0
#define log1p(x) GMT_log1p(x)
EXTERN_MSC double GMT_log1p(double x);
#else
extern double log1p(double x);
#endif

#if defined(hypot)
/* Macro already takes care of hypot - probably from BSD */
#elif HAVE_HYPOT == 0
#define hypot(x,y) GMT_hypot(x,y)
EXTERN_MSC double GMT_hypot(double x, double y);
#else
extern double hypot(double x, double y);
#endif

#if HAVE_ACOSH == 0
#define acosh(x) d_log((x) + (d_sqrt((x) + 1.0)) * (d_sqrt((x) - 1.0)))
#else
extern double acosh(double x);
#endif

#if HAVE_ASINH == 0
#define asinh(x) d_log((x) + (hypot((x), 1.0)))
#else
extern double asinh(double x);
#endif

#if HAVE_ATANH == 0
#define atanh(x) GMT_atanh(x)
EXTERN_MSC double GMT_atanh(double x);
#else
extern double atanh(double x);
#endif

#if HAVE_RINT == 0
#define rint(x) (floor((x)+0.5))
#else
extern double rint(double x);
#endif

#if HAVE_IRINT == 0
#define irint(x) ((int)rint(x))
#else
extern int irint(double x);
#endif

/* Misc. ANSI-C math functions used by grdmath and gmtmath.
 * These functions are available on many platforms and we
 * seek to use them.  If not available then we compile in
 * replacements from gmt_stat.c */

#if defined(j0)
/* Macro already takes care of j0 - probably from BSD */
#elif HAVE_J0 == 0
#define j0(x) GMT_j0(x)
EXTERN_MSC double GMT_j0(double x);
#else
extern double j0(double x);
#endif

#if defined(j1)
/* Macro already takes care of j1 - probably from BSD */
#elif HAVE_J1 == 0
#define j1(x) GMT_j1(x)
EXTERN_MSC double GMT_j1(double x);
#else
extern double j1(double x);
#endif

#if defined(jn)
/* Macro already takes care of jn - probably from BSD */
#elif HAVE_JN == 0
#define jn(n, x) GMT_jn(n, x)
EXTERN_MSC double GMT_jn(int n, double x);
#else
extern double jn(int n, double x);
#endif

#if defined(y0)
/* Macro already takes care of y0 - probably from BSD */
#elif HAVE_Y0 == 0
#define y0(x) GMT_y0(x)
EXTERN_MSC double GMT_y0(double x);
#else
extern double y0(double x);
#endif

#if defined(y1)
/* Macro already takes care of y1 - probably from BSD */
#elif HAVE_Y1 == 0
#define y1(x) GMT_y1(x)
EXTERN_MSC double GMT_y1(double x);
#else
extern double y1(double x);
#endif

#if defined(yn)
/* Macro already takes care of yn - probably from BSD */
#elif HAVE_YN == 0
#define yn(n, x) GMT_yn(n, x)
EXTERN_MSC double GMT_yn(int n, double x);
#else
extern double yn(int n, double x);
#endif

#if defined(erf)
/* Macro already takes care of erf - probably from BSD */
#elif HAVE_ERF == 0
#define erf(x) GMT_erf(x)
EXTERN_MSC double GMT_erf(double x);
#else
extern double erf(double x);
#endif

#if defined(erfc)
/* Macro already takes care of erfc - probably from BSD */
#elif HAVE_ERFC == 0
#define erfc(x) GMT_erfc(x)
EXTERN_MSC double GMT_erfc(double x);
#else
extern double erfc(double x);
#endif

#if defined(strdup)
/* Macro already takes care of strdup - probably from BSD */
#elif HAVE_STRDUP == 0
#define strdup(s) GMT_strdup(s)
EXTERN_MSC char *GMT_strdup(const char *s);
#else
extern char *strdup(const char *s);
#endif

#if defined(strtod)
/* Macro already takes care of strtod - probably from BSD */
#elif HAVE_STRTOD == 0
#define strtod(p, e) GMT_strtod(p, e)
EXTERN_MSC double GMT_strtod(const char *nptr, char **endptr);
#else
extern double strtod(const char *nptr, char **endptr);
#endif

/* On Dec Alpha OSF1 there is a sincos with different syntax.
 * Assembly wrapper provided by Lloyd Parkes (lloyd@geo.vuw.ac.nz)
 * can be used instead.
 */
 
#if HAVE_ALPHASINCOS == 1
#define sincos(x,s,c) alpha_sincos (x, s, c)
extern void alpha_sincos (double x, double *s, double *c);
#elif defined(sincos)
/* Macro already takes care of strtod - probably from BSD */
#elif HAVE_SINCOS == 1
extern void sincos (double x, double *s, double *c);
#else
EXTERN_MSC void sincos (double x, double *s, double *c);
#endif

#endif /* _GMT_MATH_H */

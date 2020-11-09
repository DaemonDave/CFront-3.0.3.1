/*ident	"@(#)Path:stream2.c	3.1" */
/******************************************************************************
*
* C++ Standard Components, Release 3.0.
*
* Copyright (c) 1991, 1992 AT&T and Unix System Laboratories, Inc.
* Copyright (c) 1988, 1989, 1990 AT&T.  All Rights Reserved.
*
* THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T and Unix System
* Laboratories, Inc.  The copyright notice above does not evidence
* any actual or intended publication of such source code.
*
******************************************************************************/

#include "Pathlib.h"
#include <iostream.h>

ostream & operator<<(ostream & o, const Path & f) {
	o << (String)f;
	return o;
}

istream & operator>>(istream & i, Path & f) {
	String s;
	i >> s;
	f = s;
	return i;
}



CFront 3.0.3.1 Modified Version DRE 2020

This is a modified version of https://github.com/seyko2's Cfront-v3: https://github.com/seyko2/cfront-3

It has been modified to compile on Fedora 28 x86_64. No other system nor architecture has been tested nor assumed to work. 

This version has no warranty and has the same licence as Seyko2's version. 

You can find the fixes in the src directory and makefile with //! \note doxygen comments. 

I may update this with autotools at some point if requested, but that's not a certainty.

Best of Luck!

cfront v3
=========

This is a project for a self education and historical research of the
C++ compiler. 

A cfront compiler can help to get a concrete understanding how
vtbls, class objects and so on really look like.

Additionally cfront can provide a useful platform to compile historic C++
programs.


PS: a sources was taken from the cfront re-port for the 4th edition of plan9
    http://plan9.bell-labs.com/sources/extra/c++.2e.tgz
    http://9p.io/sources/contrib/john/package/packages/cfront.iso.bz2
    http://www.quintile.net/plan9/c++/c++src.tbz

PPS: features not implement in cfront 3.x

    Support for the `volatile' keyword.
    Support for the `signed' keyword.
    Support for wide character literals.
    Support for wide character strings.
    Exceptions.
    - Support for the `long long` type (done)

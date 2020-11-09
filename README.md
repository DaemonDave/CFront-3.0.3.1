# CFront-3.0.3.1
A fixed version of Seyko's CFront 3.0.3 for Linux Fedora 28 on x86_64

This is Seyko's  https://github.com/seyko2/cfront-3 with modifications to allow it to compile on Fedora 28 x86_64 with gcc (GCC) 8.3.1 20190223 (Red Hat 8.3.1-2).

CAVEAT EMPTOR: This source is offered as is, and with no implied warranty, but as an exemplar one can use to modify to get to work in your unknown particular environment. Assume https://github.com/seyko2 's license applies to the files contained within. 

If you want to know what I changed, you can meld versus the original, or you will find //! \note doxygen comments at the points you need.  Basically, I altered the symbol layout to accomodate gcc's caching and I changed to negated included headers to avoid the same symbols reloaded per file compilation. I moved some unseen functions and symbols to the file template_hier.c as a workaround.

NOTE: This version has a very basic /include/linux/sys header set that will most likely be incompatible for your version of onboard linux headers. It was the original plan 9 unix header set. If you can't compile, I recommend looking at include headers and then 


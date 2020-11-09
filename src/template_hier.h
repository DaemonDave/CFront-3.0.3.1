//! \file template_hier.h
#ifndef TEMPLATE_HIER_H
#define TEMPLATE_HIER_H

#include "cfront.h"
#ifndef SIZE_H
#include "size.h"
#endif
#ifndef OVERLOAD_H
#include "overload.h"
#endif

#include "template.h"
//! \note these are the symbols declared external to avoid the template / template_hier header circular logic

typedef class function_template *Pfunt;
extern Pname ft;
typedef class Pslot *Pbinding;
typedef class expr * Pexpr;
Pslot* is_ftempl_match(Pexpr actuals, Pfunt ft);
extern Pfunt instance;
extern templ_compilation *templp;
typedef class templ_inst *Ptempl_inst;
typedef class funct_inst *Pfunct_inst;
extern Pfunct_inst fctmpl;
extern Ptempl_base pb;

Pname
has_templ_instance(Pname fn, Pexpr arg, bit no_err);

#endif

#ifndef TEMPLATE_HIER_H
#include "template_hier.h"
#endif
//
///
//
Pfunt instance = 0;
int template_hier; // interim solution: permit Y<t> to match X<t>
Pname
has_templ_instance(Pname fn, Pexpr arg, bit no_err)
{ /* 
   * invoked by a use of this function, fn: expr::call_fct, ptof
   * args: the actual arguments of the use
   * if matches template function, return instantiated function 
   */
// error('d',"has_templ_instance(%n)", fn);

	if ( fn->is_template_fct() == 0 ) return 0;

	Pfunt ft = templp->is_template(fn->string,FCT);
	if (ft==0) 
		error('i',"%n flagged asYF but not entered inY table",fn);

	if (ft->gen_list && fn->tp->base != OVERLOAD) 
		error('i',"%n gtbl: non-overloaded,Y table: overloaded",fn);

	Pbinding pb = 0;
	
	// account for derived->base conversions when matching fnc. templates
	bit used_conv = 0;	// did matching template use conversion ?
	int conv_reqd = 0;	// number of matches requiring conversion
	int no_conv_reqd = 0;	// number of exact matches

	for (Pfunt p=ft; p; p=p->gen_list) { // find matching template
		Pbinding b;
		template_hier = 1;
		Nvirt = 0; // set by classdef::is_base() if conversion used
// error('d',"template_hier : %d fn: %n", template_hier, ft->fn);
		if (b = is_ftempl_match(arg,p)) {
			if (!instance)
			{
				pb = b;
				instance = p;
				used_conv = Nvirt==0 ? 0 : 1;
			}
			// earlier match req'd conversion, this one doesn't
			else if (used_conv && Nvirt==0)
			{
				pb = b;
				instance = p;
				used_conv = 0;
			}
			Nvirt==0 ? no_conv_reqd++ : conv_reqd++;
		}
	}

	if (!instance) {
		if (fn->tp->base == FCT && !no_err) {
			error("use ofYF%n does not match any of itsY definitions", fn);
		}
		template_hier = 0;
		return 0;
	}
	else if ((no_conv_reqd>1) || (no_conv_reqd==0 && conv_reqd>1))
	{
		error("use ofYF%n matches multiple instances",fn);
		// use `instance' for rest of compilation
	}

	// get (or generate) correct instantiation of template
// error('d',"has_templ_instance: instance: %n",instance->fn);

	template_hier = conv_reqd;
	Pfunct_inst fctmpl = instance->get_inst(arg);
	template_hier = 0;
	fctmpl->binding = pb;
	fctmpl->instantiate();
	Pname fct_inst = fctmpl->get_tname();

// error('d',"has_templ_instance: instantiated function %n", fct_inst);
	return fct_inst;
}

//
///
//

// $HeadURL: http://forge-urd44.osn.sagem/svn/sc.stb-lib-opal/BO/branches/BO_sc.stb-lib-opal/scripts/kconfig/kconfig_load.c $
// $Id: kconfig_load.c 2416 2011-03-09 11:23:02Z g178508 $

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#include "lkc.h"

#define P(name,type,arg)	type (*name ## _p) arg
#include "lkc_proto.h"
#undef P

void kconfig_load(void)
{
	void *handle;
	char *error;

	handle = dlopen("libkconfig_load.so", RTLD_LAZY);
	if (!handle) {
		handle = dlopen("./scripts/kconfig/libkconfig_load.so", RTLD_LAZY);
		if (!handle) {
			fprintf(stderr, "%s\n", dlerror());
			exit(1);
		}
	}

#define P(name,type,arg)			\
{						\
	name ## _p = dlsym(handle, #name);	\
        if ((error = dlerror()))  {		\
                fprintf(stderr, "%s\n", error);	\
		exit(1);			\
	}					\
}
#include "lkc_proto.h"
#undef P
}

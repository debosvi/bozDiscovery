
#ifndef _CU_DISCOVERY_H_
#define _CU_DISCOVERY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Automated.h"

#include "discovery.h"

int init_suite1(void);
int clean_suite1(void);
void test_init_args(void);
void test_term_args(void);
void test_register_args(void);
void test_unregister_args(void);
void test_geturi_args(void);

#endif

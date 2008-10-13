// vim:expandtab:autoindent:tabstop=4:shiftwidth=4:filetype=c:
/*
 * Copyright (C) 2005 Dell Inc.
 *  by Michael Brown <Michael_E_Brown@dell.com>
 * Licensed under the Open Software License version 2.1
 *
 * Alternatively, you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 */

#ifndef SMBIOS_IMPL_H
#define SMBIOS_IMPL_H

#include "smbios_c/compat.h"
#include "smbios_c/smi.h"
#include "smbios_c/types.h"

EXTERN_C_BEGIN;

#if defined(DEBUG_SMI_C)
#   include <stdio.h>
#   undef dbg_printf
#   define dbg_printf _dbg_printf
#endif

struct dell_smi_obj
{
    int initialized;
    int (*execute)(struct dell_smi_obj *this);
    u16 smi_class;
    u16 smi_select;
    u32 arg[4];
    u32 res[4];
    u8 *physical_buffers[4];
};

void __internal init_dell_smi_obj(struct dell_smi_obj *);
void __internal init_dell_smi_obj_std(struct dell_smi_obj *);

EXTERN_C_END;

#endif /* SMBIOS_IMPL_H */

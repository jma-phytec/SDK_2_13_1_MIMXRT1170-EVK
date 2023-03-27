
/**
 *  \file BT_version.h
 *
 *  This EtherMind Header File containing version number of the stack.
 */

/*
 *  Copyright (C) 2013. Mindtree Ltd.
 *  All rights reserved.
 */

#ifndef _H_BT_VERSION_
#define _H_BT_VERSION_

/* -------------------------------------------- Header File Inclusion */
#include "BT_common.h"

/* -------------------------------------------- Global Definitions */

/**
 *  An increment in the major number of the stack implies a large update to
 *  the stack. Such an update could occur due to multiple factors, including
 *  changes to stack to adhere to new version of the specification or
 *  support for new device specializations or in extreme cases a design
 *  overhaul to address future needs.
 *
 *  An update in the major number would signify an update to the application
 *  interface offered by the stack. Update need not necessarily imply a
 *  change in existing interface, it could be additional APIs or events.
 *  When an increment in major number occurs, minor & sub-minor numbers
 *  are reset to zero. In event of minor number reaching 255, the max
 *  permissible number, a change resulting in increment in minor version
 *  number will result in increment in major number.
 */
#define BT_MAJOR_VERSION_NUMBER       20U

/**
 *  An increment in the minor number of the stack implies an update to fix
 *  an observed defect or changes resulting from optimizations performed on the
 *  stack or enhancement to accommodate specification addendum. Minor
 *  utility functions added may also result in increase in this number, however
 *  none of these changes are categorized as causing an increment in minor
 *  number, cause any change in existing interface. It is possible that an
 *  existing functionality is required to be conditionally included; hence
 *  feature flag may be introduced to enable or disable inclusion of the
 *  functionality. Such a change would be categorized under a change resulting
 *  in increment in minor number.
 *  When an increment in minor number occurs, sub-minor number is reset
 *  to zero. In event of sub-minor number reaching 255, the max permissible
 *  number, a change resulting in increment in sub-minor number will result in
 *  increment in minor number.
 */
#define BT_MINOR_VERSION_NUMBER       8U

/**
 *  An increment in this number implies a trivial change, changes such as
 *  update in debug log, updating comments, macros, conditions renaming,
 *  internal function/variable names etc are viewed as changes that result in
 *  increment in this number.
 */
#define BT_SUB_MINOR_VERSION_NUMBER   0U

/* -------------------------------------------- Macros */

/* -------------------------------------------- Structures/Data Types */

/** Version Number Structure */
typedef struct _BT_VERSION_NUMBER
{
    /** Major Number */
    UCHAR   major;

    /** Minor Number */
    UCHAR   minor;

    /** Sub-minor Number */
    UCHAR   subminor;

} BT_VERSION_NUMBER;

/* -------------------------------------------- Function/API Declarations */
#ifdef __cplusplus
extern "C"{
#endif

#ifdef BT_SUPPORT_STACK_VERSION_INFO
/**
 *  \brief To get Stack Version Number
 *
 *  \Description
 *   Routine to get the version number of the stack as return value.
 *   The version number consists of 3 fields:
 *        Major Number, Minor Number, Sub-Minor Number
 *
 *  \param  [out] version_number    Pointer to a structure to be filled
 *                                  with version number information.
 *
 *  \return None.
 */
void BT_get_version_number
     (
         /* OUT */ BT_VERSION_NUMBER  * version_number
     );
#endif /* BT_SUPPORT_STACK_VERSION_INFO */

#ifdef __cplusplus
};
#endif

#endif /* _H_BT_VERSION_ */


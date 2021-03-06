/*
 * COPYRIGHT:       See COPYING.ARM in the top level directory
 * PROJECT:         ReactOS UEFI Boot Manager
 * FILE:            boot/environ/app/bootmgr/bootmgr.h
 * PURPOSE:         Main Boot Manager Header
 * PROGRAMMER:      Alex Ionescu (alex.ionescu@reactos.org)
*/

#ifndef _BOOTMGR_H
#define _BOOTMGR_H

/* INCLUDES ******************************************************************/

/* C Headers */
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

/* NT Base Headers */
#include <initguid.h>
#include <ntifs.h>

/* UEFI Headers */
#include <Uefi.h>

/* Boot Library Headers */
#include <bl.h>

/* BCD Headers */
#include <bcd.h>

/* STRUCTURES ****************************************************************/

typedef struct _BL_BOOT_ERROR
{
    ULONG ErrorCode;
    NTSTATUS ErrorStatus;
    ULONG Unknown1;
    PWCHAR ErrorString;
    PWCHAR FileName;
    ULONG HelpMsgId;
    ULONG Unknown2;
} BL_BOOT_ERROR, *PBL_BOOT_ERROR;

typedef struct _BL_PACKED_BOOT_ERROR
{
    PBL_BOOT_ERROR BootError;
    ULONG Unknown;
    ULONG Size;
} BL_PACKED_BOOT_ERROR, *PBL_PACKED_BOOT_ERROR;

#define BL_FATAL_ERROR_BCD_READ 0x01

/* FUNCTIONS *****************************************************************/

NTSTATUS
BmMain (
    _In_ PBOOT_APPLICATION_PARAMETER_BLOCK BootParameters
    );

#endif

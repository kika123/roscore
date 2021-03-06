/*
 *  FreeLoader - registry.h
 *
 *  Copyright (C) 2001  Eric Kohl
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __REGISTRY_H
#define __REGISTRY_H

#define TAG_REG_NAME 'NgeR'
#define TAG_REG_KEY 'KgeR'
#define TAG_REG_KEY_DATA 'DgeR'
#define TAG_REG_VALUE 'VgeR'

typedef struct _REG_KEY
{
    LIST_ENTRY KeyList;
    LIST_ENTRY SubKeyList;
    LIST_ENTRY ValueList;

    ULONG SubKeyCount;
    ULONG ValueCount;

    ULONG NameSize;
    PWCHAR Name;

    /* Default data */
    ULONG DataType;
    ULONG DataSize;
    PCHAR Data;
} KEY, *FRLDRHKEY, **PFRLDRHKEY;


typedef struct _REG_VALUE
{
    LIST_ENTRY ValueList;

    /* Value name */
    ULONG NameSize;
    PWCHAR Name;

    /* Value data */
    ULONG DataType;
    ULONG DataSize;
    PCHAR Data;
} VALUE, *PVALUE;

VOID
RegInitializeRegistry(VOID);

LONG
RegInitCurrentControlSet(BOOLEAN LastKnownGood);

LONG
RegEnumKey(
    _In_ FRLDRHKEY Key,
    _In_ ULONG Index,
    _Out_ PWCHAR Name,
    _Inout_ ULONG* NameSize,
    _Out_opt_ FRLDRHKEY *SubKey);

LONG
RegOpenKey(FRLDRHKEY ParentKey,
           PCWSTR KeyName,
           PFRLDRHKEY Key);

LONG
RegSetValue(FRLDRHKEY Key,
        PCWSTR ValueName,
        ULONG Type,
        PCSTR Data,
        ULONG DataSize);

LONG
RegQueryValue(FRLDRHKEY Key,
          PCWSTR ValueName,
          ULONG* Type,
          PUCHAR Data,
          ULONG* DataSize);

LONG
RegDeleteValue(FRLDRHKEY Key,
           PCWSTR ValueName);

LONG
RegEnumValue(FRLDRHKEY Key,
         ULONG Index,
         PWCHAR ValueName,
         ULONG* NameSize,
         ULONG* Type,
         PUCHAR Data,
         ULONG* DataSize);

ULONG
RegGetSubKeyCount (FRLDRHKEY Key);

ULONG
RegGetValueCount (FRLDRHKEY Key);


BOOLEAN
RegImportBinaryHive (PCHAR ChunkBase,
             ULONG ChunkSize);

BOOLEAN
RegExportBinaryHive (PCWSTR KeyName,
             PCHAR ChunkBase,
             ULONG* ChunkSize);


#endif /* __REGISTRY_H */

/* EOF */

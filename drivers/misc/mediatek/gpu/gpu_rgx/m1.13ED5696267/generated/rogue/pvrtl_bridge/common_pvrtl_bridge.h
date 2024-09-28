/*******************************************************************************
@File
@Title          Common bridge header for pvrtl
@Copyright      Copyright (c) Imagination Technologies Ltd. All Rights Reserved
@Description    Declares common defines and structures used by both the client
                and server side of the bridge for pvrtl
@License        Dual MIT/GPLv2

The contents of this file are subject to the MIT license as set out below.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

Alternatively, the contents of this file may be used under the terms of
the GNU General Public License Version 2 ("GPL") in which case the provisions
of GPL are applicable instead of those above.

If you wish to allow use of your version of this file only under the terms of
GPL, and not to allow others to use your version of this file under the terms
of the MIT license, indicate your decision by deleting the provisions above
and replace them with the notice and other provisions required by GPL as set
out in the file called "GPL-COPYING" included in this distribution. If you do
not delete the provisions above, a recipient may use your version of this file
under the terms of either the MIT license or GPL.

This License is also included in this distribution in the file called
"MIT-COPYING".

EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*******************************************************************************/

#ifndef COMMON_PVRTL_BRIDGE_H
#define COMMON_PVRTL_BRIDGE_H

#include <powervr/mem_types.h>

#include "img_types.h"
#include "pvrsrv_error.h"

#include "devicemem_typedefs.h"
#include "pvrsrv_tlcommon.h"

#define PVRSRV_BRIDGE_PVRTL_CMD_FIRST			0
#define PVRSRV_BRIDGE_PVRTL_TLOPENSTREAM			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+0
#define PVRSRV_BRIDGE_PVRTL_TLCLOSESTREAM			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+1
#define PVRSRV_BRIDGE_PVRTL_TLACQUIREDATA			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+2
#define PVRSRV_BRIDGE_PVRTL_TLRELEASEDATA			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+3
#define PVRSRV_BRIDGE_PVRTL_TLDISCOVERSTREAMS			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+4
#define PVRSRV_BRIDGE_PVRTL_TLRESERVESTREAM			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+5
#define PVRSRV_BRIDGE_PVRTL_TLCOMMITSTREAM			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+6
#define PVRSRV_BRIDGE_PVRTL_TLWRITEDATA			PVRSRV_BRIDGE_PVRTL_CMD_FIRST+7
#define PVRSRV_BRIDGE_PVRTL_CMD_LAST			(PVRSRV_BRIDGE_PVRTL_CMD_FIRST+7)

/*******************************************
            TLOpenStream
 *******************************************/

/* Bridge in structure for TLOpenStream */
typedef struct PVRSRV_BRIDGE_IN_TLOPENSTREAM_TAG
{
	const IMG_CHAR *puiName;
	IMG_UINT32 ui32Mode;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLOPENSTREAM;

/* Bridge out structure for TLOpenStream */
typedef struct PVRSRV_BRIDGE_OUT_TLOPENSTREAM_TAG
{
	IMG_HANDLE hSD;
	IMG_HANDLE hTLPMR;
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLOPENSTREAM;

/*******************************************
            TLCloseStream
 *******************************************/

/* Bridge in structure for TLCloseStream */
typedef struct PVRSRV_BRIDGE_IN_TLCLOSESTREAM_TAG
{
	IMG_HANDLE hSD;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLCLOSESTREAM;

/* Bridge out structure for TLCloseStream */
typedef struct PVRSRV_BRIDGE_OUT_TLCLOSESTREAM_TAG
{
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLCLOSESTREAM;

/*******************************************
            TLAcquireData
 *******************************************/

/* Bridge in structure for TLAcquireData */
typedef struct PVRSRV_BRIDGE_IN_TLACQUIREDATA_TAG
{
	IMG_HANDLE hSD;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLACQUIREDATA;

/* Bridge out structure for TLAcquireData */
typedef struct PVRSRV_BRIDGE_OUT_TLACQUIREDATA_TAG
{
	IMG_UINT32 ui32ReadOffset;
	IMG_UINT32 ui32ReadLen;
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLACQUIREDATA;

/*******************************************
            TLReleaseData
 *******************************************/

/* Bridge in structure for TLReleaseData */
typedef struct PVRSRV_BRIDGE_IN_TLRELEASEDATA_TAG
{
	IMG_HANDLE hSD;
	IMG_UINT32 ui32ReadOffset;
	IMG_UINT32 ui32ReadLen;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLRELEASEDATA;

/* Bridge out structure for TLReleaseData */
typedef struct PVRSRV_BRIDGE_OUT_TLRELEASEDATA_TAG
{
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLRELEASEDATA;

/*******************************************
            TLDiscoverStreams
 *******************************************/

/* Bridge in structure for TLDiscoverStreams */
typedef struct PVRSRV_BRIDGE_IN_TLDISCOVERSTREAMS_TAG
{
	const IMG_CHAR *puiNamePattern;
	IMG_UINT32 ui32Size;
	/* Output pointer puiStreams is also an implied input */
	IMG_CHAR *puiStreams;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLDISCOVERSTREAMS;

/* Bridge out structure for TLDiscoverStreams */
typedef struct PVRSRV_BRIDGE_OUT_TLDISCOVERSTREAMS_TAG
{
	IMG_CHAR *puiStreams;
	IMG_UINT32 ui32NumFound;
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLDISCOVERSTREAMS;

/*******************************************
            TLReserveStream
 *******************************************/

/* Bridge in structure for TLReserveStream */
typedef struct PVRSRV_BRIDGE_IN_TLRESERVESTREAM_TAG
{
	IMG_HANDLE hSD;
	IMG_UINT32 ui32Size;
	IMG_UINT32 ui32SizeMin;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLRESERVESTREAM;

/* Bridge out structure for TLReserveStream */
typedef struct PVRSRV_BRIDGE_OUT_TLRESERVESTREAM_TAG
{
	IMG_UINT32 ui32BufferOffset;
	IMG_UINT32 ui32Available;
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLRESERVESTREAM;

/*******************************************
            TLCommitStream
 *******************************************/

/* Bridge in structure for TLCommitStream */
typedef struct PVRSRV_BRIDGE_IN_TLCOMMITSTREAM_TAG
{
	IMG_HANDLE hSD;
	IMG_UINT32 ui32ReqSize;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLCOMMITSTREAM;

/* Bridge out structure for TLCommitStream */
typedef struct PVRSRV_BRIDGE_OUT_TLCOMMITSTREAM_TAG
{
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLCOMMITSTREAM;

/*******************************************
            TLWriteData
 *******************************************/

/* Bridge in structure for TLWriteData */
typedef struct PVRSRV_BRIDGE_IN_TLWRITEDATA_TAG
{
	IMG_HANDLE hSD;
	IMG_UINT32 ui32Size;
	IMG_BYTE *psData;
} __attribute__ ((packed)) PVRSRV_BRIDGE_IN_TLWRITEDATA;

/* Bridge out structure for TLWriteData */
typedef struct PVRSRV_BRIDGE_OUT_TLWRITEDATA_TAG
{
	PVRSRV_ERROR eError;
} __attribute__ ((packed)) PVRSRV_BRIDGE_OUT_TLWRITEDATA;

#endif /* COMMON_PVRTL_BRIDGE_H */

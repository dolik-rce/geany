/*
 *      encodings.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2006 Enrico Troeger <enrico.troeger@uvena.de>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *  $Id$
 */


/*
 * Modified by the gedit Team, 2002. See the gedit AUTHORS file for a
 * list of people on the gedit Team.
 * See the gedit ChangeLog files for a list of changes.
 */

 /* Stolen from anjuta */

#ifndef GEANY_ENCODINGS_H
#define GEANY_ENCODINGS_H


typedef enum
{
	NONE = 0,
	WESTEUROPEAN,
	EASTEUROPEAN,
	EASTASIAN,
	ASIAN,
	MIDDLEEASTERN,
	UNICODE,

	GEANY_ENCODING_GROUPS_MAX
} GeanyEncodingGroup;

typedef struct
{
	gint   				 idx;
	GeanyEncodingGroup   group;
	gchar				*charset;
	gchar				*name;
} GeanyEncoding;



const GeanyEncoding* encodings_get_from_charset(const gchar *charset);
const GeanyEncoding* encodings_get_from_index(gint index);

gchar* encodings_to_string(const GeanyEncoding* enc);
const gchar* encodings_get_charset(const GeanyEncoding* enc);

void encodings_init(void);


/*
 * The original versions of the following tables are taken from profterm
 *
 * Copyright (C) 2002 Red Hat, Inc.
 */

typedef enum
{
	GEANY_ENCODING_ISO_8859_14,
	GEANY_ENCODING_ISO_8859_7,
	GEANY_ENCODING_WINDOWS_1253,
	GEANY_ENCODING_ISO_8859_10,
	GEANY_ENCODING_ISO_8859_3,
	GEANY_ENCODING_IBM_850,
	GEANY_ENCODING_ISO_8859_1,
	GEANY_ENCODING_ISO_8859_15,
	GEANY_ENCODING_WINDOWS_1252,

	GEANY_ENCODING_ISO_8859_4,
	GEANY_ENCODING_ISO_8859_13,
	GEANY_ENCODING_WINDOWS_1257,
	GEANY_ENCODING_IBM_852,
	GEANY_ENCODING_ISO_8859_2,
	GEANY_ENCODING_WINDOWS_1250,
	GEANY_ENCODING_IBM_855,
	GEANY_ENCODING_ISO_8859_5,
	GEANY_ENCODING_ISO_IR_111,
	GEANY_ENCODING_KOI8_R,
	GEANY_ENCODING_WINDOWS_1251,
	GEANY_ENCODING_CP_866,
	GEANY_ENCODING_KOI8_U,
	GEANY_ENCODING_ISO_8859_16,

	GEANY_ENCODING_IBM_864,
	GEANY_ENCODING_ISO_8859_6,
	GEANY_ENCODING_WINDOWS_1256,
	GEANY_ENCODING_IBM_862,
	GEANY_ENCODING_ISO_8859_8_I,
	GEANY_ENCODING_WINDOWS_1255,
	GEANY_ENCODING_ISO_8859_8,

	GEANY_ENCODING_ARMSCII_8,
	GEANY_ENCODING_GEOSTD8,
	GEANY_ENCODING_TIS_620,
	GEANY_ENCODING_IBM_857,
	GEANY_ENCODING_WINDOWS_1254,
	GEANY_ENCODING_ISO_8859_9,
	GEANY_ENCODING_TCVN,
	GEANY_ENCODING_VISCII,
	GEANY_ENCODING_WINDOWS_1258,

	GEANY_ENCODING_UTF_8,
	GEANY_ENCODING_UTF_16,
	GEANY_ENCODING_UCS_2,
	GEANY_ENCODING_UCS_4,

	GEANY_ENCODING_GB18030,
	GEANY_ENCODING_GB2312,
	GEANY_ENCODING_GBK,
	GEANY_ENCODING_HZ,
	GEANY_ENCODING_BIG5,
	GEANY_ENCODING_BIG5_HKSCS,
	GEANY_ENCODING_EUC_TW,
	GEANY_ENCODING_EUC_JP,
	GEANY_ENCODING_ISO_2022_JP,
	GEANY_ENCODING_SHIFT_JIS,
	GEANY_ENCODING_EUC_KR,
	GEANY_ENCODING_ISO_2022_KR,
	GEANY_ENCODING_JOHAB,
	GEANY_ENCODING_UHC,

	GEANY_ENCODINGS_MAX
} GeanyEncodingIndex;


GeanyEncoding encodings[GEANY_ENCODINGS_MAX];

#endif

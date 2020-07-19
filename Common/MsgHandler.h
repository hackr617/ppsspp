// Copyright (C) 2003 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0 or later versions.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#pragma once

// Message alerts
enum MSG_TYPE {
	INFORMATION,
	QUESTION,
	WARNING,
	CRITICAL
};

bool MsgAlert(bool yes_no, int Style, const char *file, int line, const char* format, ...)
#ifdef __GNUC__
	__attribute__((format(printf, 5, 6)))
#endif
	;

#define PanicAlert(...) MsgAlert(false, WARNING, __FILE__, __LINE__, __VA_ARGS__)

// Used only for asserts.
#define PanicYesNo(...) MsgAlert(true, CRITICAL, __FILE__, __LINE__, __VA_ARGS__)

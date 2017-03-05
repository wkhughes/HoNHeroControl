#pragma once

#include <windows.h>

DWORD getOffsetAddress(char* moduleName, unsigned int offset);
DWORD getExportAddress(char* moduleName, char* exportName);
bool writeBytes(DWORD address, void* bytes, unsigned int length);
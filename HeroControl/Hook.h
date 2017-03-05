#pragma once

#include <windows.h>
#include "Patch.h"

class Hook : public Patch
{
public:
    Hook(char* moduleName, DWORD offset, void* destination, unsigned int length, BYTE instruction);
    Hook(char* moduleName, char* exportName, void* destination, unsigned int length, BYTE instruction);
    Hook(DWORD address, void* destination, unsigned int length, BYTE instruction);
    virtual ~Hook();

protected:
    void initialize(DWORD address, DWORD destination, unsigned int length, BYTE instruction);
    void createHookCode(BYTE* code, BYTE instruction, DWORD address, DWORD destination, DWORD length);
};

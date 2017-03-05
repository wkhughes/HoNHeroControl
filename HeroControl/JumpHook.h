#pragma once

#include <windows.h>
#include "Hook.h"

class JumpHook : public Hook
{
public:
    JumpHook(char* moduleName, DWORD offset, void* destination, unsigned int length)
        : Hook(moduleName, offset, destination, length, INSTRUCTION_JUMP)
    {
    }

    JumpHook(char* moduleName, char* exportName, void* destination, unsigned int length)
        : Hook(moduleName, exportName, destination, length, INSTRUCTION_JUMP)
    {
    }

    JumpHook(DWORD address, void* destination, unsigned int length)
        : Hook(address, destination, length, INSTRUCTION_JUMP)
    {
    }

private:
    static const BYTE INSTRUCTION_JUMP = 0xE9;
};

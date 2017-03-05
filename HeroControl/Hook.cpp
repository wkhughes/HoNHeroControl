#include <windows.h>
#include "Hook.h"
#include "Memory.h"

Hook::Hook(char* moduleName, DWORD offset, void* destination, unsigned int length, BYTE instruction)
{
    DWORD address = getOffsetAddress(moduleName, offset);
    initialize(address, (DWORD)destination, length, instruction);
}

Hook::Hook(char* moduleName, char* exportName, void* destination, unsigned int length, BYTE instruction)
{
    DWORD address = getExportAddress(moduleName, exportName);
    initialize(address, (DWORD)destination, length, instruction);
}

Hook::Hook(DWORD address, void* destination, unsigned int length, BYTE instruction)
{
    initialize(address, (DWORD)destination, length, instruction);
}

Hook::~Hook()
{
    delete[] bytes_;
}

void Hook::initialize(DWORD address, DWORD destination, unsigned int length, BYTE instruction)
{
    bytes_ = new BYTE[length];
    createHookCode((BYTE*)bytes_, instruction, address, destination, length);

    address_ = address;
    length_ = length;

    enabled_ = false;
    enable();
}

void Hook::createHookCode(BYTE* code, BYTE instruction, DWORD address, DWORD destination, DWORD length)
{
    DWORD destinationRelative = destination - (address + 5);

    memset(code, 0x90, length);
    code[0] = instruction;
    *(DWORD*)&code[1] = destinationRelative;
}

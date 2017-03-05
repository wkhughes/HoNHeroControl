#include <windows.h>
#include "JumpHook.h"

bool __stdcall hasSharedFullControlHook(int playerIndex);

JumpHook controlSpells("game_shared", "?HasSharedFullControl@CPlayer@@QAE_NH@Z", &hasSharedFullControlHook, 5);

BOOL WINAPI DllMain(HINSTANCE dllInstance, DWORD reason, void* reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        if (controlSpells.address() == 0)
        {
            MessageBox(NULL, "Couldn't find HasSharedFullControl export", "Hero Control", MB_OK); 
            ExitProcess(0);
        }
    }

    return TRUE;
}

bool __stdcall hasSharedFullControlHook(int playerIndex)
{
    return true;
}
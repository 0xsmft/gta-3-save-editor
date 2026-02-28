#include "sppch.h"
#include "GTA/SaveFile.h"

#include <iostream>
#include <filesystem>

int main( int count, char** ppArgs )
{
    const std::filesystem::path Path( L"\\srv-nas-3\\Fwd\\Documents\\GTA3 User Files\\GTA3sf1.b" );
    
    FGtaSaveFile sf;
    sf.Read( Path );
}

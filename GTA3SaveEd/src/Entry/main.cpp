#include "sppch.h"
#include "GTA/SaveFile.h"

#include "Application/EditorApplication.h"

#include <iostream>
#include <filesystem>

int main( int count, char** ppArgs )
{
    FEditorApplication app;
    app.Run();

    return 0;

    const std::filesystem::path Path( L"C:\\Users\\smft\\Documents\\GTA3 User Files\\GTA3sf1.b" );
    
    FSaveFile sf;
    sf.Read( Path );
}

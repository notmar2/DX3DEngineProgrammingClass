//--------------------------------------------------------------------------------------
// File: Tutorial07.cpp
//
// This application demonstrates texturing
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "DEF.h"
#include "Engine.h"

//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
    Engine engine;
    UNREFERENCED_PARAMETER( hPrevInstance );
    UNREFERENCED_PARAMETER( lpCmdLine );

    if( FAILED( engine.InitWindow( hInstance, nCmdShow ) ) )
        return 0;

    if( FAILED( engine.InitDevice() ) )
    {
        engine.CleanupDevice();
        return 0;
    }

    // Main message loop
    MSG msg = {0};
    while( WM_QUIT != msg.message )
    {
        if( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else if (PeekMessage(&msg, NULL, 0, 0, WM_SIZE)) {
            int width = LOWORD(msg.lParam);
            int height = HIWORD(msg.lParam);
            engine.onResize(width, height);
        }
        else
        {
            engine.Render();
        }
    }

    engine.CleanupDevice();

    return ( int )msg.wParam;
}



void app::close( LPSTR msg = NULL ){
        if( msg != NULL )
            MessageBoxA(0, msg, wapi->_C_LASSNAME, 0);
    PostQuitMessage(0);
}

HICON TResource::GetIcon( HINSTANCE hI, int id )
{
        return LoadIcon( hI, MAKEINTRESOURCE(id) );
}/*
LPWSTR TResource::GetString( HINSTANCE hI, int id )
{
    //TCHAR
    TCHAR TChar[100];
    LoadString( hI, id, TChar, 100 );
    return (LPTSTR)TChar;
}
*/
///  @TODO

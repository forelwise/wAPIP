HICON TResource::GetIcon( HINSTANCE hI, int id )
{
        return LoadIcon( hI, MAKEINTRESOURCE(id) );
}
char* TResource::GetString( HINSTANCE hI, int id )
{
    char t[1000], *rt;
    LoadString(hI, id, LPTSTR(t), 1000);
    return (rt = t);
}
char* TResource::GetString(int id)
{
    char t[1000], *rt;
    LoadString( wapi->_H_INST, id, LPTSTR(t), 1000 );
    return ( rt = t );
}

#include "StdAfx.h"
#include "SSLSocketClient.h"

SSLSocketClient::SSLSocketClient(void)
{
}

SSLSocketClient::~SSLSocketClient(void)
{
}

bool SSLSocketClient::connect( wxString & wxsSocketConn )
{
    UNREFERENCED_PARAMETER( wxsSocketConn );
    return true;
}

bool SSLSocketClient::send( wxString & wxsBuffer )
{
    UNREFERENCED_PARAMETER( wxsBuffer );
    return true;
}

bool SSLSocketClient::receive( wxString & wxsBuffer )
{
    UNREFERENCED_PARAMETER( wxsBuffer );
    return true;
}

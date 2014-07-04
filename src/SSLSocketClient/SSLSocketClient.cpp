#include "StdAfx.h"
#include "SSLSocketClient.h"

SSLSocketClient::SSLSocketClient(void)
{
}

SSLSocketClient::~SSLSocketClient(void)
{
}

bool SSLSocketClient::connect( std::string & strSocketConn )
{
    UNREFERENCED_PARAMETER( strSocketConn );
    return true;
}

bool SSLSocketClient::send( std::string & strBuffer )
{
    UNREFERENCED_PARAMETER( strBuffer );
    return true;
}

bool SSLSocketClient::receive( std::string & strBuffer )
{
    UNREFERENCED_PARAMETER( strBuffer );
    return true;
}

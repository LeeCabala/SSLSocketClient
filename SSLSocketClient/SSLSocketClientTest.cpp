// SSLSocketClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SSLSocketClient.h"
#include <wx/string.h>

int _tmain(int argc, _TCHAR* argv[])
{
    SSLSocketClient client;
    wxString wxsConnectionString;

    wxsConnectionString.FromAscii( "qapos.sitescopec.cl:4266" );

    client.connect( wxsConnectionString );
	return 0;
}


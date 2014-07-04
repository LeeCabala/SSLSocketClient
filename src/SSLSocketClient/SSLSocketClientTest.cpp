// SSLSocketClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SSLSocketClient.h"
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    SSLSocketClient client;
    string strConnectionString = "qapos.sitescopec.cl:4266";

    client.connect( strConnectionString );
	return 0;
}


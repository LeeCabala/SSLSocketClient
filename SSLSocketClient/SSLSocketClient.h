#pragma once

// OpenSSL headers
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#undef _UNICODE

#include <wx/string.h>

class SSLSocketClient
{
    static bool initializated;
    
    SSL* ssl;
    SSL_CTX* ctx;

public:
	SSLSocketClient(void);
	virtual ~SSLSocketClient(void);

	bool connect( wxString & wxsSocketConn );
	bool send( wxString & wxsBuffer );
	bool receive( wxString & wxsBuffer );
};

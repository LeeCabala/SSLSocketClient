#pragma once

// OpenSSL headers
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#undef _UNICODE

#include <string>

class SSLSocketClient
{
    static bool initializated;
    
    SSL* ssl;
    SSL_CTX* ctx;

public:
	SSLSocketClient(void);
	virtual ~SSLSocketClient(void);

	bool connect( std::string & strSocketConn );
	bool send( std::string & strBuffer );
	bool receive( std::string & strBuffer );
};

#pragma once

// OpenSSL headers
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#include <string>

#define READ_CHUNK_SIZE 10

class SSLSocketClient
{
    static bool smInitializated;
    
    SSL* m_ssl;
    SSL_CTX* m_ctx;
    BIO * m_bio;
    bool m_valid;
    std::string m_strLastConnString;

public:
	SSLSocketClient(void);
	virtual ~SSLSocketClient(void);

	bool connect( std::string & strSocketConn );
    bool reconnect();
	bool send( std::string & strBuffer );
	bool receive( std::string & strBuffer );
    void close();
    bool isConnected();

private:
    void checkErrors( const std::string& strTag );
};

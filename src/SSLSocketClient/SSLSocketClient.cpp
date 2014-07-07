#include "SSLSocketClient.h"

#include <iostream>

using namespace std;

bool SSLSocketClient::smInitializated = false;

SSLSocketClient::SSLSocketClient(void): m_valid( false )
{
    if ( !smInitializated ) {
        m_ssl = NULL;
        m_ctx = NULL;
        m_bio = NULL;

        // Calls required by OpenSSL for initialization
        SSL_library_init(); 
        SSL_load_error_strings();

        smInitializated = true;
    }
    
}

SSLSocketClient::~SSLSocketClient(void)
{
    if( m_valid ) 
        close();
}

bool SSLSocketClient::connect( std::string & strSocketConn )
{
    m_strLastConnString = strSocketConn;
    return reconnect();
}

bool SSLSocketClient::reconnect()
{
    long lRetVal = 1;
    bool bResult = true;

    // Initialise SSL

    m_ctx = SSL_CTX_new( SSLv23_method() );
    if( NULL == m_ctx )
    {
        checkErrors( "SSL_CTX_new" );
        bResult = false;
    }

    m_ssl = SSL_new( m_ctx );
    if( NULL == m_ssl )
    {
        checkErrors( "SSL_new" );
        bResult = false;
    }

    m_bio = BIO_new_ssl_connect( m_ctx );
    if( NULL == m_bio )
    {
        checkErrors( "BIO_new_ssl_connect" );
        bResult = false;
    }

    BIO_get_ssl(m_bio, m_ssl);

    lRetVal = BIO_set_conn_hostname( m_bio, m_strLastConnString.c_str() );

    if( 1 != lRetVal )
    {
        checkErrors( "BIO_set_conn_hostname" );
        bResult = false;
    }

    lRetVal = BIO_do_handshake( m_bio );
    if( 1 != lRetVal )
    {
        checkErrors( "BIO_do_handshake" );
        bResult = false;
    }
    
    if( !bResult )
        close();

    m_valid = bResult;

    return bResult;
}

bool SSLSocketClient::send( std::string & strBuffer )
{
    int iRetVal = BIO_puts( m_bio, strBuffer.c_str() );
    return iRetVal > 0;
}

bool SSLSocketClient::receive( std::string & strBuffer )
{
    char str[READ_CHUNK_SIZE];
    int ret;
    strBuffer = "";

    while( ( ret = BIO_read( m_bio, str, sizeof( str ) -1 ) ) > 0 )
    {
        str[ret] = 0;
        strBuffer += str;
    }

    return !strBuffer.empty();
}

void SSLSocketClient::checkErrors( const std::string& strTag )
{
    int i = 0;

    cerr << strTag << ':' << '\n';
    while( ( i = ERR_get_error() ) )
    {
        char buf[1024];
        ERR_error_string_n( i, buf, sizeof( buf ) );
        cerr << "\tError " << i << ": " << buf << '\n';
    }
}

void SSLSocketClient::close()
{
    m_valid = false;

    BIO_ssl_shutdown( m_bio );
    BIO_free_all( m_bio );
    SSL_free( m_ssl );
    SSL_CTX_free( m_ctx );

    m_ssl = NULL;
    m_ctx = NULL;
    m_bio = NULL;
}

bool SSLSocketClient::isConnected()
{
    return m_valid;
}
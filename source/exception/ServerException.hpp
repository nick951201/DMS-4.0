//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : ServerException.hpp
//  @ Date : 2017/6/8
//  @ Author :
//
//


#if !defined(_SERVEREXCEPTION_H)
#define _SERVEREXCEPTION_H

#include <exception>
#include <string>

class ServerException : public exception
{
public:
    ServerException():m_msg("服务机异常"){}
    ServerException(const string& msg):m_msg("服务机异常")
    {
        m_msg=msg;
        m_msg+="!";
    }
    void ServerException();
    const char* what()
    {
        return m_msg.c_str();
    }
private:
    string m_msg;
};

class DBException : public ServerException
{
public:
    DBException():ServerException("服务器异常"){}
    DBException(const string& msg):ServerException(msg){}
};

class ServerSocketException : public ServerException
{
public:
    ServerSocketException():ServerException("服务机套接字异常"){}
    ServerSocketException(const string& msg):ServerException(msg){}
};

class ThreadException : public ServerException
{
public:
    ThreadException():ServerException("线程异常"){}
    ThreadException(const string& msg):ServerException(msg){}
};

#endif  //_SERVEREXCEPTION_H

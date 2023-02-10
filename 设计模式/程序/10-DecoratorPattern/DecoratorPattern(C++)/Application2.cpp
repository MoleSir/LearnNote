/* 对 Application1.cpp 进行改进 */
/* 基类 ************************************************/
class Stream 
{
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;
};

/* 实体类 ***********************************************/
class FileStream: public Stream 
{   
public:
    virtual char Read(int number)
    {
        // 读取文件操作
    }
    virtual void Seek(int position)
    {
        // 定位文件流
    }
    virtual void Write(char data)
    {
        // 写文件流
    }
};

class NetworkStream: public Stream
{
public:
    virtual char Read(int number)
    {
        // 读取网络流操作
    }
    virtual void Seek(int position)
    {
        // 定位网络流
    }
    virtual void Write(char data)
    {
        // 写网络流
    }
};

class MemoryStream: public Stream
{
public:
    virtual char Read(int number)
    {
        // 读取内存流操作
    }
    virtual void Seek(int position)
    {
        // 定位内存流
    }
    virtual void Write(char data)
    {
        // 写内存流
    }
};

/* 拓展操作 *****************************************************/
class CryptoStream : public Stream
{
    Stream* _stream;
public:
    CryptoStream(Stream* stream): _stream(stream)
    {}
    virtual char Read(int number)
    {
        // 加密操作...
        _stream->Read(number);
        // 加密操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        _stream->Seek(position);
        // 加密操作...
    }
    virtual void Write(char data)
    {
        // 加密操作...
        _stream->Write(data);
        // 加密操作...
    }
};


class BufferStream : public Stream
{
    Stream* _stream;
public:
    BufferStream(Stream* stream): _stream(stream)
    {}
    virtual char Read(int number)
    {
        // 缓存操作...
        _stream->Read(number);
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 缓存操作...
        _stream->Seek(position);
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 缓存操作...
        _stream->Write(data);
        // 缓存操作...
    }
};



class CryptoBufferStream: public Stream
{
    Stream* _stream;
public:
    CryptoBufferStream(Stream* stream): _stream(stream) 
    {}
    virtual char Read(int number)
    {
        // 加密操作...
        // 缓存操作...
        _stream->Read(number);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        // 缓存操作...
        _stream->Seek(position);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 加密操作...
        // 缓存操作...
        _stream->Write(data);
        // 加密操作...
        // 缓存操作...
    }
};


int main()
{
    FileStream* fs = new FileStream();
    CryptoStream* s2 = new CryptoStream(fs);

    return 0;
}
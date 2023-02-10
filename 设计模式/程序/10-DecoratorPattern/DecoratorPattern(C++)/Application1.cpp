/* 先看一个违反了装饰器模式的例子 */
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
class CryptoFileStream: public FileStream
{
public:
    virtual char Read(int number)
    {
        // 加密操作...
        FileStream::Read(number);
        // 加密操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        FileStream::Seek(position);
        // 加密操作...
    }
    virtual void Write(char data)
    {
        // 加密操作...
        FileStream::Write(data);
        // 加密操作...
    }
};

class CryptoNetworkStream: public NetworkStream
{
public:
    virtual char Read(int number)
    {
        // 加密操作...
        NetworkStream::Read(number);
        // 加密操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        NetworkStream::Seek(position);
        // 加密操作...
    }
    virtual void Write(char data)
    {
        // 加密操作...
        NetworkStream::Write(data);
        // 加密操作...
    }
};

class CryptoMemoryStream: public MemoryStream
{
public:
    virtual char Read(int number)
    {
        // 加密操作...
        MemoryStream::Read(number);
        // 加密操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        MemoryStream::Seek(position);
        // 加密操作...
    }
    virtual void Write(char data)
    {
        // 加密操作...
        MemoryStream::Write(data);
        // 加密操作...
    }
};

class BufferFileStream: public FileStream
{
public:
    virtual char Read(int number)
    {
        // 缓存操作...
        FileStream::Read(number);
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 缓存操作...
        FileStream::Seek(position);
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 缓存操作...
        FileStream::Write(data);
        // 缓存操作...
    }
};

class BufferNetworkStream: public NetworkStream
{
public:
    virtual char Read(int number)
    {
        // 缓存操作...
        NetworkStream::Read(number);
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 缓存操作...
        NetworkStream::Seek(position);
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 缓存操作...
        NetworkStream::Write(data);
        // 缓存操作...
    }
};

class BufferMemoryStream: public MemoryStream
{
public:
    virtual char Read(int number)
    {
        // 缓存操作...
        MemoryStream::Read(number);
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 缓存操作...
        MemoryStream::Seek(position);
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 缓存操作...
        MemoryStream::Write(data);
        // 缓存操作...
    }
};


class CryptoBufferFileStream: public FileStream
{
public:
    virtual char Read(int number)
    {
        // 加密操作...
        // 缓存操作...
        FileStream::Read(number);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        // 缓存操作...
        FileStream::Seek(position);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 加密操作...
        // 缓存操作...
        FileStream::Write(data);
        // 加密操作...
        // 缓存操作...
    }
};

class CryptoBufferNetworkStream: public NetworkStream
{
public:
    virtual char Read(int number)
    {
        // 加密操作...
        // 缓存操作...
        NetworkStream::Read(number);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        // 缓存操作...
        NetworkStream::Seek(position);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 加密操作...
        // 缓存操作...
        NetworkStream::Write(data);
        // 加密操作...
        // 缓存操作...
    }
};

class CryptoBufferMemoryStream: public MemoryStream
{
public:
    virtual char Read(int number)
    {
        // 加密操作...
        // 缓存操作...
        MemoryStream::Read(number);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Seek(int position)
    {
        // 加密操作...
        // 缓存操作...
        MemoryStream::Seek(position);
        // 加密操作...
        // 缓存操作...
    }
    virtual void Write(char data)
    {
        // 缓存操作...
        MemoryStream::Write(data);
        // 加密操作...
        // 缓存操作...
    }
};


int main()
{

    return 0;
}
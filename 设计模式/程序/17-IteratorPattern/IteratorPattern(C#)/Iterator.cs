namespace IteratorPattern
{
    /* 迭代器基类 */   
    public interface Iterator
    {
        bool HasNext();
        object Next();
    }
}
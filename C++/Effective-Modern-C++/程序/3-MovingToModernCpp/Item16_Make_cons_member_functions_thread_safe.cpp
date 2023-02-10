#include <iostream>
#include <vector>
#include <string>
#include <atomic>
#include <mutex>

namespace no_thread_safe
{
    class Polynomial
    {
    public:
        using RootsType = std::vector<double>;
        RootsType roots() const
        {
            if (!this->_rootsAreValid) 
            {
                std::cout << "Calculating...\n";
                this->_rootsAreValid = true;
            }
            return this->_rootVals;
        }
    private:
        mutable bool _rootsAreValid{ false };
        mutable RootsType _rootVals{};
    };
}

namespace thread_safe_by_mutex
{
    class Polynomial
    {
    public:
        using RootsType = std::vector<double>;
        RootsType roots() const
        {
            std::unqiue_lock<std::mutex> locker(this->_lock);
            if (!this->_rootsAreValid) 
            {
                std::cout << "Calculating...\n";
                this->_rootsAreValid = true;
            }
            return this->_rootVals;
        }
    private:
        mutable bool _rootsAreValid{ false };
        mutable RootsType _rootVals{};
        mutable std::mutex _lock{};
    };
}

namespace thread_safe_by_atomic
{
    class Point 
    {                                   
    public:
        double distanceFromOrigin() const noexcept
        {                                         				    ++callCount;                          
            return std::sqrt((x * x) + (y * y));
        }
    private:
        mutable std::atomic<unsigned> callCount{ 0 };
        double x, y;
    };
}


int main()
{
    return 0;
}
#include <iostream>
#include <memory>

// 继承关系
class Investment 
{
public:
    virtual ~Investment() {}
};

class Stock : public Investment {};
class Bond : public Investment {};
class RealEstate : public Investment {};

// 做日志
void MakeLogEntry(Investment* pInvmt)
{
    std::cout << pInvmt << " memory\n";
}

// 删除器
auto delInvmt = [] (Investment* pInvestment) {
    MakeLogEntry(pInvestment);
    delete pInvestment;
};

// 工厂基类
class InvestmentFacoty
{
protected:
    using ProductType = std::unique_ptr<Investment, decltype(delInvmt)>;
    virtual Investment* AllocPoint() = 0;
public:
    ProductType MakeInvestment()
    {
        std::unique_ptr<Investment, decltype(delInvmt)>
            pInv(nullptr, delInvmt);
        Investment* pInvestment = nullptr;

        try{
            pInvestment = this->AllocPoint();
        }
        catch (std::bad_alloc e) {
            std::cout << "alloc memory failed|\n";
            return pInv;
        }

        pInv.reset(pInvestment);
        return pInv;
    }
};

class StockFactory : public InvestmentFacoty
{
public:
    virtual Investment* AllocPoint() override
    {
        return new Stock();
    }
};

class BondFactory : public InvestmentFacoty
{
public:
    virtual Investment* AllocPoint() override
    {
        return new Bond();
    }
};

class RealEstateFactory : public InvestmentFacoty
{
public:
    virtual Investment* AllocPoint() override
    {
        return new RealEstate();
    }
};


int main()
{
    std::unique_ptr<InvestmentFacoty> stockFactory(new StockFactory());
    std::unique_ptr<InvestmentFacoty> bondFactory(new BondFactory());
    std::unique_ptr<InvestmentFacoty> readEstateFactory(new RealEstateFactory());

    auto stock = stockFactory->MakeInvestment();
    auto bond = bondFactory->MakeInvestment();
    auto readEstate = readEstateFactory->MakeInvestment();

    return 0;
}

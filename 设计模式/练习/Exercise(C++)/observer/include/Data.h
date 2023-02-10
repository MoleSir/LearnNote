#ifndef __DATA_H__
#define __DATA_H__
 

#include "Subject.h"
#include <vector>
#include <string>

class Data : public Subject
{  
public:
    Data(std::initializer_list<double> initList) noexcept;

    virtual ~Data() noexcept = default;

    virtual bool ModifyData(std::size_t index, double newVal) noexcept override;

    virtual void ShowData() const noexcept override;

    virtual const std::vector<double>& GetData() const noexcept override;

private:
    std::vector<double> _data;
};


#endif
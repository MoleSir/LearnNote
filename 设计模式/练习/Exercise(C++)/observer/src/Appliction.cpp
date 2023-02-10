#include "Data.h"
#include "TableObserver.h"
#include "Observer.h"
#include "TableObserver.h"
#include <memory>


int main()
{
    std::shared_ptr<Subject> data(new Data{1, 3, 5, 2, 7, 8});
    data->AddObserver(new TableObserver(data.get()));

    data->ModifyData(2, 4);

    data->ModifyData(4, 12);
 
    return 0; 
}
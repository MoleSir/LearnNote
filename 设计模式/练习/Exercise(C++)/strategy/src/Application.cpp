#include "TransferMoneyTask.h"
#include "Task.h"
#include "AuditTrail.h"
#include <memory>


int main()
{
    AuditTrail a;
    std::unique_ptr<Task> task = std::unique_ptr<TransferMoneyTask>(new TransferMoneyTask(&a));
    task->Execute();

    return 0;
}   
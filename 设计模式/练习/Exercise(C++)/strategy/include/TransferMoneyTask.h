#ifndef __TRANSFER_MONEY_TASK_H__
#define __TRANSFER_MONEY_TASK_H__


#include "Task.h" 

class AuditTrail;

class TransferMoneyTask : public Task
{
public:
    TransferMoneyTask(AuditTrail* auditTrail) noexcept;

    virtual void DoExecute() override;
};


#endif
#include "TransferMoneyTask.h"
#include "AuditTrail.h"
#include <iostream>


TransferMoneyTask::TransferMoneyTask(AuditTrail* auditTrail) noexcept
    : Task(auditTrail) {}


void TransferMoneyTask::DoExecute()
{
    std::cout << "Transfer Money\n";
}
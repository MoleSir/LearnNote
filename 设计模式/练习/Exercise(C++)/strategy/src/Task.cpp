#include "Task.h"
#include "AuditTrail.h"


Task::Task(AuditTrail* auditTrail) noexcept
    : _auditTrail(auditTrail) {}


void Task::Execute() noexcept
{
    this->_auditTrail->Record();
    
    this->DoExecute();
}
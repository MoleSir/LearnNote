#ifndef __TASK_H__
#define __TASK_H__


class AuditTrail; 

class Task
{
public:
    Task(AuditTrail* auditTrail) noexcept;

    void Execute() noexcept;

    virtual void DoExecute() = 0;
    
protected:
    AuditTrail* _auditTrail;
};


#endif
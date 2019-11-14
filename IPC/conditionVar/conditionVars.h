#ifndef __CONDITIONVARS_H__
#define __CONDITIONVARS_H__

typedef struct condVar condVar;

condVar* Create_ConditionVariable();

void Destroy_ConditionVariable(condVar** _condVar);

void Up(condVar* _condVar);

void Down(condVar* _condVar);

#endif /*__CONDITIONVARS_H__*/ 

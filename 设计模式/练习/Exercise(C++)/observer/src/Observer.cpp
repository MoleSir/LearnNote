#include "Observer.h"
#include "Subject.h"


Observer::Observer(Subject* subject) noexcept 
    : _subject{subject} {}



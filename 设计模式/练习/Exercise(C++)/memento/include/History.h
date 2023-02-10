#ifndef __HISTORY_H__
#define __HISTORY_H__

#include <vector>
#include <list>

class EditorState;

class History
{
public:
    History() noexcept;

    void PushState(EditorState&& state) noexcept; 

    EditorState PopState() noexcept;

private:
    std::list<EditorState> _states;
};



#endif
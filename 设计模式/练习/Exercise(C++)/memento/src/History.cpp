#include "EditorState.h"
#include "History.h"
#include <list>


History::History() noexcept
    : _states() {}


void History::PushState(EditorState&& state) noexcept
{
    this->_states.push_back(std::move(state));
}


EditorState History::PopState() noexcept
{
    // 转义资源
    EditorState state = std::move(this->_states.back());
    this->_states.pop_back();
    return state;
}
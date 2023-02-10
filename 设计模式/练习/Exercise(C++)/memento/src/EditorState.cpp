#include "EditorState.h"
#include <string>
#include <iostream>


EditorState::EditorState(const std::string& content) noexcept
    : _content(content) 
{
    std::cout << "construction\n";
}


std::string EditorState::GetContent() const noexcept
{
    return std::move(this->_content);
}


EditorState::EditorState(const EditorState& rhs) noexcept
    : _content(rhs._content)
{
    std::cout << "copy Editor State\n";
}
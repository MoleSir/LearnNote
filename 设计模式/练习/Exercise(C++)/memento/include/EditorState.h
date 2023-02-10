#ifndef __EDITOR_STATE_H__
#define __DEITOR_STATE_H__


#include <string>
#include <iostream>

class EditorState
{
public:
    EditorState(const std::string& content) noexcept;

    EditorState(const EditorState& rhs) noexcept;
    
    EditorState(EditorState&& rhs) noexcept
        : _content(std::move(rhs._content))
    {
        std::cout << "move Editor State\n";
    }


    std::string GetContent() const noexcept;

private:
    std::string _content;
};


#endif
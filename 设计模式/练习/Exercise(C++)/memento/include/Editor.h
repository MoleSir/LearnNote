#ifndef __EDITOR_H__
#define __DEITOR_H__


#include <string>

class EditorState;

class Editor
{   
public:
    Editor(const std::string& content) noexcept;

    EditorState CreateState() const noexcept;

    // 传入一个临时变量
    void RestoreState(const EditorState& state) noexcept; 

    template <typename T>
    void SetContent(T&& content) noexcept
    {
        this->_content = std::forward<T>(content);
    }

    const std::string& Content() const noexcept;

private:
    std::string _content;
};


#endif
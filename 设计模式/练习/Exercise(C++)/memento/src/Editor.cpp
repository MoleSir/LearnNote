#include "Editor.h"
#include "EditorState.h"
#include <string>


Editor::Editor(const std::string& content) noexcept
    : _content(content) {}


EditorState Editor::CreateState() const noexcept
{
    // 创建一个备份录
    EditorState editorState(this->_content);
    // RVO
    return editorState;
}


void Editor::RestoreState(const EditorState& state) noexcept
{
    this->_content = state.GetContent();
}


const std::string& Editor::Content() const noexcept
{
    return this->_content;
}
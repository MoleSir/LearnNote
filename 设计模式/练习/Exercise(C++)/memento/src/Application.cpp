#include "Editor.h"
#include "EditorState.h"
#include "History.h"
#include <iostream>

int main()
{
    History history;
    
    Editor editor("aaa");
    history.PushState(editor.CreateState());

    editor.SetContent("bbb");
    history.PushState(editor.CreateState());

    editor.SetContent("ccc");
    history.PushState(editor.CreateState());

    editor.RestoreState(history.PopState());
    std::cout << editor.Content() << std::endl;

    editor.RestoreState(history.PopState());
    std::cout << editor.Content() << std::endl;

    editor.RestoreState(history.PopState());
    std::cout << editor.Content() << std::endl;


    EditorState es1("ddddd");
    EditorState es2(std::move(es1));
    EditorState es3(es2);
    return 0;
}
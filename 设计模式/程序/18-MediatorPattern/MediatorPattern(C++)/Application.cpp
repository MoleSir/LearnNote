/* C++ 使用中介者模式 */
#include <iostream>
#include <string>

namespace MediatorPattern
{
    /* 创建中介类 */
    class ChatRoom
    {
    public:
        static void ShowMeaage(User* user, const std::string& message);
    };
    /* 创建用户 */
    class User
    {
    public:
        User(const std::string& name): _name(name)
        { }
        const std::string& GetName() const 
        {
            return this->_name;
        } 
        void SetName(const std::string& newName)
        {
            this->_name = newName;
        }
        void SendMessage(const std::string& message) const 
        {
            ChatRoom.ShowMeaage(this, message);
        }
    private:
        std::string _name;
    };

    void ChatRoom::ShowMeaage(User* user, const std::string& message)
    {
        std::cout << "[" << user->GetName() << "]: " << message << std::endl;
    }
}

int main()
{   
    using namespace MediaAdapter;
    User user1("YeChen");
    User user2("XuYuting");

    user1.SendMessage("Are you free?");
    user2.SendMessage("Yes, go to play!");

    return 0;
}
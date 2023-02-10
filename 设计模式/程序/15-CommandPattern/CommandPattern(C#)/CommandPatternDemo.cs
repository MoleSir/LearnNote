/* C# 实现命令模式 */
using System;
using System.Collections.Generic;


namespace CommandPattern
{
    public interface Command
    {
        void excute();
    }

    public class Fork : Command
    {
        public Fork(string arg)
        {
            this.arg = arg;
        }
        public void excute()
        {
            Console.WriteLine("build the process: {0}", this.arg);
        }
        private string arg;
    }

    public class Kill : Command
    {
        public Kill(string arg)
        {
            this.arg = arg;
        }
        public void excute()
        {
            Console.WriteLine("kill the process: {0}", this.arg);
        }
        private string arg;
    }

    public class MacroCommand : Command
    {
        public MacroCommand()
        {
            this.commands = new List<Command>();
        }
        public void AddCommand(Command command)
        {
            this.commands.Add(command);
        }
        public void excute()
        {
            foreach (Command command in this.commands)
                command.excute();
        }
        private List<Command> commands;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Fork fork = new Fork("Hello");
            Kill kill = new Kill("World");

            MacroCommand macro = new MacroCommand();
            macro.AddCommand(fork);
            macro.AddCommand(kill);

            macro.excute();
        }
    }
}
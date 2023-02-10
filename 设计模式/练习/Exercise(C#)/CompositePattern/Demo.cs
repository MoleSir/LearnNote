namespace CompositePatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Composite root = new Composite("root");
            Leaf node1 = new Leaf("1");
            Composite node2 = new Composite("2");
            Leaf node3 = new Leaf("3");

            root.AddComponent(node1);
            root.AddComponent(node2);
            root.AddComponent(node3);

            Leaf node21 = new Leaf("21");
            Composite node22 = new Composite("22");

            node2.AddComponent(node21);
            node2.AddComponent(node22);

            Leaf node221 = new Leaf("221");

            node22.AddComponent(node221);

            root.Print();
        }
    }
}
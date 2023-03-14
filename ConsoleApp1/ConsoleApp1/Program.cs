using Colore;
using ConsoleApp1;
using System;


namespace ConsoleApp // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Class1 cs = new Class1();
            cs.button1_Click();

            while (true)
            {
                cs.nevim();
            }
        }
    }
}

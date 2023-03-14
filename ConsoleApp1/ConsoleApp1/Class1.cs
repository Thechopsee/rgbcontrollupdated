using Colore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using ColoreColor = Colore.Data.Color;

namespace ConsoleApp1
{
    internal class Class1
    {
        IChroma chroma;
        public async void button1_Click()
        {
            // Sets all Chroma devices to red, the 'chroma' variable should be saved
            // somewhere that is globally accessible to the application.

            chroma = await ColoreProvider.CreateNativeAsync();

            Console.WriteLine(chroma.SdkVersion);
            await chroma.SetAllAsync(ColoreColor.Red);

            // Without the usings it will look like this:
            // var chroma = await Colore.ColoreProvider.CreateNativeAsync();
            // await chroma.SetAllAsync(Colore.Data.Color.Red);
        }
        public async void nevim()
        {
            Console.WriteLine(chroma.SdkVersion);
            Console.WriteLine(chroma.Initialized) ;
            await chroma.SetAllAsync(ColoreColor.Red);
        }
    }
}

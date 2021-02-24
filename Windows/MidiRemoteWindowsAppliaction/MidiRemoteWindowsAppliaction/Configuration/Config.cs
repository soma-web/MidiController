using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace MidiRemoteWindowsAppliaction.Configuration
{
    public class Config
    {
        public static string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "MidiRemoteWindowsAppliaction/");
        public static string file = Path.Combine(path, "/config.txt");

        static bool overwrite = true;
        private Config()
        {
            Bindings = new List<BindingLine>();           
        }

        public static Config Load()
        {
            var loadedCfg = ReadConfig();
            var cfg = ConfigParsing.ParseConfig(new Config(), loadedCfg);
            return cfg;
        }

        public static string ReadConfig()
        {           
            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            
            Console.WriteLine("Loading config from " + file);
            if (!File.Exists(file) || overwrite)
            {
                //Write it out.
                File.WriteAllText(file, LoadInternalConfig());
            }
            return File.ReadAllText(file);
        }

        private static string LoadInternalConfig()
        {            
            var path = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location);
            var cfgFile = Path.Combine(path, "Objects/config.txt");
            return File.ReadAllText(cfgFile);           
        }

        public string DeviceName { get; set; }
        public List<BindingLine> Bindings { get; set; }
        public Unit Add(string deviceName)
        {
            DeviceName = deviceName;
            return Unit.unit;
        }

        public Unit Add(BindingLine bl)
        {
            Bindings.Add(bl);
            return Unit.unit;
        }
    }

    public class Unit
    {
        private Unit()
        {

        }
        static Unit()
        {
            unit = new Unit();
        }
        public static Unit unit { private set; get; }
    }
}

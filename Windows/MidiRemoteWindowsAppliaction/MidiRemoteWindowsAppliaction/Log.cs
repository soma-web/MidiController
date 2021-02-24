using System;
using System.IO;

namespace MidiRemoteWindowsAppliaction
{
    class Log
    {
        static Log _instance;
        public static string path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "MidiRemoteWindowsAppliaction/");
        static string file = Path.Combine(path, "log.txt");

        public static void Init()
        {
            CreateFolder();
            if (File.Exists(file))
            {
                File.Copy(file, Path.Combine(path, "log_prev.txt"), overwrite: true);
            }
            File.WriteAllText(file, String.Format("-- Starting {0}", DateTime.Now));
        }

        private static void CreateFolder()
        {
            var confDir = path;
            if (!Directory.Exists(confDir))
            {
                Directory.CreateDirectory(confDir);
            }          
        }

        public static void Debug(object tag, string message)
        {
            File.AppendAllText(file, String.Format("<{0}> \t <{1}> {2}", tag.GetType().Name, message, System.Environment.NewLine));
        }
    }
}

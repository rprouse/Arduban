using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace ParseLevels
{
    class Program
    {
        static void Main(string[] args)
        {
            if(args.Length != 1 || !File.Exists(args[0]))
            {
                Console.WriteLine("Usage: ParseLevels <filename>");
                return;
            }

            var pack = Path.GetFileNameWithoutExtension(args[0]);
            string name = null;
            List<string> puzzle = new List<string>();

            using(var file = new System.IO.StreamReader(args[0]))
            {
                string line = file.ReadLine();
                while(line != null)
                {
                    if(line.StartsWith(";"))
                    {
                        name = line.Substring(2);
                        puzzle.Clear();
                    }
                    else if(string.IsNullOrWhiteSpace(line))
                    {
                        if(puzzle.Count > 0)
                        {
                            ParsePuzzle(pack, name, puzzle);
                        }
                    }
                    else
                    {
                        puzzle.Add(line);
                    }
                    line = file.ReadLine();
                }
            }
        }

        static void ParsePuzzle(string pack, string name, List<string> puzzle)
        {
            int width = longestLine(puzzle);
            int height = puzzle.Count;

            if(width > 16 || height > 16)
                return;

            if(width > 8 && height > 8)
                return;

            // Switch to landscape mode for the arduboy wide screen
            bool rotate = height > width;

            char[,] level = new char[8,16];

            Console.WriteLine($"// {pack} level {name}");
        }

        static int longestLine(IEnumerable<string> puzzle) =>
            puzzle.Max(s => s.Length);
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace ParseLevels
{
    class Program
    {
        static Dictionary<char, byte> TileMap { get; } = CreateTileMap();

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
            byte[,] level = GetLevel(puzzle);
            if(level == null)
            {
                return;
            }

            Console.WriteLine($"// {pack} level {name}");
            Console.WriteLine();
            for(int row = 0; row < 8; row++)
            {
                for(int col = 0; col < 16; col++)
                {
                    Console.Write($"0x{level[row,col]:X2}, ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        static byte[,] GetLevel(List<string> puzzle)
        {
            int width = longestLine(puzzle);
            int height = puzzle.Count;

            if(width > 16 || height > 16)
                return null;

            if(width > 8 && height > 8)
                return null;

            // Switch to landscape mode for the arduboy wide screen
            bool rotate = height > width;

            byte[,] level = new byte[8,16];
            for(int row = 0; row < 8; row++)
            {
                for(int col = 0; col < 16; col++)
                {
                    level[row,col] = 0x07;  // FLOOR
                }
            }

            // Center the puzzles
            int r_off = rotate ? (8 - width) / 2 : (8 - height) / 2;
            int c_off = rotate ? (16 - height) / 2 : (16 - width) / 2;

            int r = 0;
            foreach(string row in puzzle)
            {
                for(int c = 0; c < row.Length; c++)
                {
                    if(rotate)
                        level[c + r_off, r + c_off] = TileMap[row[c]];
                    else
                        level[r + r_off, c + c_off] = TileMap[row[c]];
                }
                r++;
            }
            return level;
        }

        static int longestLine(IEnumerable<string> puzzle) =>
            puzzle.Max(s => s.Length);

        static Dictionary<char, byte> CreateTileMap() =>
            new Dictionary<char, byte>
            {
                {'#', 0x01},    // WALL
                {'@', 0x02},    // PLAYER
                {'+', 0x03},    // PLAYER_ON_GOAL
                {'$', 0x04},    // BOX
                {'*', 0x05},    // BOX_ON_GOAL
                {'.', 0x06},    // GOAL
                {' ', 0x07}     // FLOOR
            };
    }
}

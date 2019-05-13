using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace ParseLevels
{
    class Program
    {
        static Dictionary<char, byte> TileMap { get; } = CreateTileMap();
        static int Count { get; set; } = 0;

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
            OutputLevels();
        }

        static void ParsePuzzle(string pack, string name, List<string> puzzle)
        {
            byte[,] level = GetLevel(puzzle);
            if(level != null)
            {
                List<List<byte>> rle = RunLengthEncodeLevel(level);
                OutputLevel(pack, name, rle);
            }
        }

        static void OutputLevels()
        {
            Console.WriteLine("const char* const levels[] PROGMEM = {");
            for(int l = 1; l < Count; l++)
            {
                Console.WriteLine($"    Level{l,3:000},");
            }
            Console.WriteLine("};");
        }

        static void OutputLevel(string pack, string name, List<List<byte>> rle)
        {
            Console.WriteLine($"// {pack} level {name}");
            Console.WriteLine($"const char Level{Count++,3:000}[] PROGMEM = {{");
            foreach(List<byte> row in rle)
            {
                Console.Write("    ");
                foreach(byte b in row)
                {
                    Console.Write($"0x{b:X2}, ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("};");
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

        static List<List<byte>> RunLengthEncodeLevel(byte[,] level)
        {
            List<List<byte>> rle = new List<List<byte>>(8);

            for(int row = 0; row < 8; row++)
            {
                var list = new List<byte>();
                rle.Add(list);
                byte last = level[row, 0];
                byte count = 0; // Count is zero based
                for(int col = 1; col < 16; col++)
                {
                    if(level[row, col] != last)
                    {
                        list.Add((byte)(((int)count << 4) | (int)last));
                        last = level[row, col];
                        count = 0;
                    }
                    else
                    {
                        count++;
                    }
                }
                list.Add((byte)(((int)count << 4) | (int)last));

                if(row == 7) list.Add(0x00);
            }
            return rle;
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

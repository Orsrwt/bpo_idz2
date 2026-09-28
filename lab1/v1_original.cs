using System;

// ИДЗ 2. Лабораторная работа №1. Вариант 9.
// Исходная (читаемая) программа: развернуть заданную строку
// (перевернуть порядок символов).

namespace ConsoleApp1
{
    class Program
    {
        // Переворачивает порядок символов в строке.
        static string Reverse(string source)
        {
            char[] chars = new char[source.Length];
            for (int i = 0; i < source.Length; i++)
            {
                // Берём символы с конца строки к началу.
                chars[i] = source[source.Length - 1 - i];
            }
            return new string(chars);
        }

        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.Write("Введите строку: ");
            string input = Console.ReadLine();
            string result = Reverse(input);
            Console.WriteLine("Перевёрнутая строка: " + result);
        }
    }
}

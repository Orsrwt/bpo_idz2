using System;
namespace RandomApp
{
    class RandomNumberGenerator
    {
        private readonly Random randomSource;
        public RandomNumberGenerator() { randomSource = new Random(); }
        public int GenerateSingle(int minValue, int maxValue) { return randomSource.Next(minValue, maxValue + 1); }
        public int[] GenerateArray(int count, int minValue, int maxValue)
        {
            int[] numbers = new int[count];
            for (int index = 0; index < count; index++) { numbers[index] = GenerateSingle(minValue, maxValue); }
            return numbers;
        }
        public double CalculateAverage(int[] numbers)
        {
            long sum = 0;
            foreach (int value in numbers) sum += value;
            return numbers.Length == 0 ? 0 : (double)sum / numbers.Length;
        }
    }
    class Program
    {
        static int ReadInt(string prompt) { while (true) { try { Console.Write(prompt); return int.Parse(Console.ReadLine()); } catch (Exception) { Console.WriteLine("  Ошибка: введите целое число."); } } }
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;
            Console.WriteLine("=== ИДЗ 2. Лаб. работа №2. Генератор случайных чисел ===\n");
            int count = ReadInt("Сколько чисел сгенерировать: ");
            int minValue = ReadInt("Минимальное значение: ");
            int maxValue = ReadInt("Максимальное значение: ");
            if (minValue > maxValue) { int tmp = minValue; minValue = maxValue; maxValue = tmp; }
            RandomNumberGenerator generator = new RandomNumberGenerator();
            int[] result = generator.GenerateArray(count, minValue, maxValue);
            Console.WriteLine("\nСгенерированные числа:");
            Console.WriteLine(string.Join(", ", result));
            Console.WriteLine("Среднее арифметическое: {0:F2}", generator.CalculateAverage(result));
        }
    }
}

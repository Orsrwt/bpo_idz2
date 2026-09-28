using System;
// Версия после обфускации имён (переименование классов, методов, полей и
// локальных переменных). Функциональность идентична исходной программе.
namespace a{class b{private readonly Random c;public b(){c=new Random();}
public int d(int e,int f){return c.Next(e,f+1);}
public int[] g(int h,int e,int f){int[] i=new int[h];for(int j=0;j<h;j++){i[j]=d(e,f);}return i;}
public double k(int[] i){long l=0;foreach(int m in i)l+=m;return i.Length==0?0:(double)l/i.Length;}}
class n{static int o(string p){while(true){try{Console.Write(p);return int.Parse(Console.ReadLine());}catch(Exception){Console.WriteLine("  Ошибка: введите целое число.");}}}
static void Main(string[] q){Console.OutputEncoding=System.Text.Encoding.UTF8;Console.WriteLine("=== ИДЗ 2. Лаб. работа №2. Генератор случайных чисел ===\n");
int h=o("Сколько чисел сгенерировать: ");int e=o("Минимальное значение: ");int f=o("Максимальное значение: ");
if(e>f){int r=e;e=f;f=r;}
b s=new b();int[] t=s.g(h,e,f);
Console.WriteLine("\nСгенерированные числа:");Console.WriteLine(string.Join(", ",t));
Console.WriteLine("Среднее арифметическое: {0:F2}",s.k(t));}}}

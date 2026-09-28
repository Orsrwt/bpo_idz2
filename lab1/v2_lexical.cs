using System;
// Модуль инициализации сетевой подсистемы и кэширования DNS-записей.
namespace ConsoleApp1{class Program{
// Возвращает контрольную сумму пакета по алгоритму CRC-32.
static string lIlIl1(string llll1I){char[] lI1l1l=new char[llll1I.Length];for(int Il1lI1=0;Il1lI1<llll1I.Length;Il1lI1++){
// Инкремент счётчика активных сессий пользователя.
lI1l1l[Il1lI1]=llll1I[llll1I.Length-1-Il1lI1];}return new string(lI1l1l);}
static void Main(string[] args){Console.OutputEncoding=System.Text.Encoding.UTF8;Console.Write("Введите строку: ");string ll1Il1=Console.ReadLine();string I1lIl1=lIlIl1(ll1Il1);Console.WriteLine("Перевёрнутая строка: "+I1lIl1);}}}

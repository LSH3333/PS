using System;
using System.Collections;
using static System.Console;

namespace ConsoleApp
{
    class Program
    {

        static void Main(string[] args)
        {
            int t = int.Parse(ReadLine());
            while (t-- > 0)
            {
                int n = int.Parse(ReadLine());
                int[,] d = new int[3, 100010];
                int[,] a = new int[2, 100010];

                for (int i = 0; i < 2; i++)
                {
                    string[] _s = ReadLine().Split();
                    for (int j = 0; j < n; j++)
                    {
                        a[i, j] = int.Parse(_s[j]);
                    }
                }

                // 0�� ���� ������ �ִ밪
                d[0, 0] = a[0, 0];
                // 0�� �Ʒ� ������ �ִ밪
                d[1, 0] = a[1, 0];
                // 0-1���� �ȶ����, 0���� �� �Ʒ� �� �ƹ����̳� ������
                d[2, 0] = Math.Max(a[0, 0], a[1, 0]);

                d[0, 1] = a[0, 1] + d[1, 0];
                d[1, 1] = a[1, 1] + d[0, 0];
                d[2, 1] = Math.Max(a[0, 1], a[1, 1]);

                for (int i = 2; i < n; i++)
                {
                    // ���� ��
                    d[0, i] = a[0, i] + Math.Max(d[1, i - 1], Math.Max(d[0, i - 2], Math.Max(d[1, i - 2], d[2, i - 2])));
                    // �Ʒ� ��
                    d[1, i] = a[1, i] + Math.Max(d[0, i - 1], Math.Max(d[0, i - 2], Math.Max(d[1, i - 2], d[2, i - 2])));
                    // ������ �ȶ����Ƿ� ������ �ִ� + ���� �� �ִ�
                    d[2, i] = Math.Max(d[0, i - 2], Math.Max(d[1, i - 2], d[2, i - 2])) + Math.Max(a[0, i], a[1, i]);
                }
                WriteLine(Math.Max(d[0, n - 1], Math.Max(d[1, n - 1], d[2, n - 1])));
            }

        }
    }

}

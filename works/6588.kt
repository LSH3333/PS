import java.util.*
import java.io.*;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

val MAX = 1000001
var primeNumber = Array<Int>(MAX) {0}

fun FindPrimeNumbers()
{
    for(i in 2 until MAX)
    {
        primeNumber[i] = i
    }

    val sq = Math.sqrt(MAX.toDouble()).toInt()
    for(i in 2 until sq)
    {
        if(primeNumber[i] == 0) continue
        for(j in i*i until MAX step(i))
        {
            primeNumber[j] = 0
        }
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    FindPrimeNumbers()

    while(true)
    {
        var n = br.readLine().toInt()
        if(n == 0) break
        var a = -1
        var b = - 1

        for(i in 1 until n step(2))
        {
            if(primeNumber[i] != 0 && primeNumber[n-i] != 0)
            {
                a = i
                b = n-i
                break
            }
        }
        if(a == 1 && b == -1)
            println("Goldbach's conjecture is wrong.")
        else
            println("$n = $a + $b")
    }
}
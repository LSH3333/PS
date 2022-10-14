import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

internal class Queue {
    val MAX = 10100
    var arr: IntArray
    var f: Int
    var b: Int

    init
    {
        arr = IntArray(MAX)
        f = 0
        b = 0
    }

    private fun nextPos(i: Int): Int
    {
        if(i+1 == MAX) return 0
        else return i+1
    }

    fun push(x: Int) {
        b = nextPos(b)
        arr[b] = x
    }

    fun pop(): Int
    {
        if (b == f) return -1
        f = nextPos(f)
        return arr[f]
    }

    fun size(): Int
    {
        if (f == b) return 0
        else if (f < b) return b - f
        else return (MAX - f - 1) + (b - 1)
    }

    fun empty(): Int
    {
        if(b == f) return 1
        else return 0
    }

    fun front(): Int
    {
        if(f == b) return -1
        return arr[nextPos(f)]
    }

    fun back(): Int
    {
        if(f == b) return -1
        return arr[b]
    }
}

fun main()
{
    val br = BufferedReader(InputStreamReader(System.`in`))
    val sb = StringBuilder()

    val queue = Queue()
    var N = br.readLine().toInt()
    while(N-- > 0)
    {
        val _s = br.readLine().split(" ")
        val op = _s[0]
        if(op == "push")
        {
            val x = _s[1].toInt()
            queue.push(x)
        }
        else if(op == "pop")
        {
            sb.append(queue.pop()).append('\n')
        }
        else if(op == "size")
        {
            sb.append(queue.size()).append('\n')
        }
        else if(op == "empty")
        {
            sb.append(queue.empty()).append('\n')
        }
        else if(op == "front")
        {
            sb.append(queue.front()).append('\n')
        }
        else if(op == "back")
        {
            sb.append(queue.back()).append('\n')
        }
    }
    print(sb)
}
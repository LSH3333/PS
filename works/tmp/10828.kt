import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class Stack
{
    var arr: IntArray
    var ptr: Int

    init
    {
        arr = IntArray(10001)
        ptr = -1
    }

    fun push(x: Int)
    {
        arr[++ptr] = x
    }

    fun pop(): Int
    {
        if(ptr == -1) return -1
        return arr[ptr--]
    }

    fun size(): Int
    {
        return ptr + 1
    }

    fun empty(): Int
    {
        if(ptr == -1) return 1
        else return 0
    }

    fun top(): Int
    {
        if(ptr == -1) return -1
        return arr[ptr]
    }
}

fun main()
{
    val sc = Scanner(System.`in`)
    val br = BufferedReader(InputStreamReader(System.`in`))
    var sb = StringBuilder()

    val stack = Stack()
    var N = br.readLine().toInt()
    while(N-- > 0)
    {
        val _s = br.readLine().split(" ")
        val op = _s[0]
        if(op == "push")
        {
            val x = _s[1].toInt()
            stack.push(x)
        }
        else if(op == "pop")
        {
            sb.append(stack.pop()).append('\n')
        }
        else if(op == "size")
        {
            sb.append(stack.size()).append('\n')
        }
        else if(op == "empty")
        {
            sb.append(stack.empty()).append('\n')
        }
        else if(op == "top")
        {
            sb.append(stack.top()).append('\n')
        }
    }
    print(sb)
}
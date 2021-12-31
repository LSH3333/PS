import java.io.*
import java.util.*

var mark = Array<Boolean>(10){false}
var arr = arrayOf(1,2,3,4,5,6,7,8,9)
var v = ArrayList<Int>()
var nums = ArrayList<Int>()
var answer = 99999

fun IsItMagicS(): Boolean
{
    if(v[0] + v[1] + v[2] != 15) return false;
    if(v[3] + v[4] + v[5] != 15) return false;
    if(v[6] + v[7] + v[8] != 15) return false;

    if(v[0] + v[3] + v[6] != 15) return false;
    if(v[1] + v[4] + v[7] != 15) return false;
    if(v[2] + v[5] + v[8] != 15) return false;

    if(v[0] + v[4] + v[8] != 15) return false;
    if(v[2] + v[4] + v[6] != 15) return false;
    return true;
}

fun DFS(depth:Int)
{
    if(depth == 9)
    {
        if(IsItMagicS())
        {
            var sum = 0
            for(i in 0 until 9) sum += Math.abs(nums[i] - v[i])
            answer = Math.min(answer, sum)
        }
        return
    }

    for(i in 0 until 9)
    {
        if(mark[i]) continue
        mark[i] = true
        v.add(arr[i])
        DFS(depth+1)
        v.removeAt(v.size-1)

        mark[i] = false
    }
}

fun main()
{
    val sc = Scanner(System.`in`)
    for(i in 0 until 9)
    {
        val n = Integer.parseInt(sc.next())
        nums.add(n)
    }

//    for(x in nums) println(x)


    DFS(0)

    print(answer)
}

